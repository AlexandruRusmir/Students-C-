#include <iostream>
#include <fstream>
#include <list>
#include "Student.h"
#include "Disciplina.h"
using namespace std;


void antet(); ///Optiunile de operatii asupra listei de studenti
void meniu(int); ///Meniul de unde se alege operatia dorita asupra listei de studenti
void adaugare(); ///Adaugarea unui student nou in lista
void afisare(); ///Afisarea tuturor studentilor din lista la momentul respectiv
void afisare_student(); ///Afisarea unui anumit student din lista
void actualizare(); ///Modificarea datelor despre un anumit student
void stergere(); ///Stergerea tuturor datelor despre un anumit student
void restantieri(); ///Afisarea tuturor studentilor restantieri
void citire_fisier(char string[]); ///Citirea din fisierea pentru a vedea daca au ramas date de la apelari trecute ale programului
void scriere_fisier(char string[]); ///Scrierea tuturor studentilor in fisier

list <Student> lista_Studenti;

int main()
{
    int a;
    citire_fisier("date.txt");

    do
    {
        antet();
        cout << "Selectati cifra operatiei dorite(1-6) sau orice alta cifra pentru a opri aplicatia: \n";
        cin >> a;
        meniu(a);
    }
    while (a>=1 && a<=6);

    cout << "\nAplicatia se inchide...";

    scriere_fisier("date.txt");
    return 0;
}

void antet()
{
    system("cls");
    cout << "--------------------------------------------------------------------------------------------------------------------------\n";
    cout << "1. Afisarea tuturor studentilor\n2. Afisare unui anumit student\n3. Adaugarea unui student\n4. Actualizarea unui student\n5. Stergerea unui student\n6. Afisarea studentilor restantieri\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------\n\n";
}

void meniu(int a)
{
    if (a==1)
        afisare();

    else if (a==2)
        afisare_student();

    else if (a==3)
        adaugare();

    else if (a==4)
        actualizare();

    else if (a==5)
        stergere();

    else if (a==6)
        restantieri();
}

void adaugare()
{
    char num[50], nr[30], ma[30];
    int v, n;
    float no;
    vector<Disciplina> vec;
    cin.get();
    cout << "\n\tIntroduceti numele: ";
    cin.getline(num, 50);
    cout << "\n\tIntroduceti numarul matricol: ";
    cin.getline(nr, 30);
    for(list<Student>::iterator it = lista_Studenti.begin();it != lista_Studenti.end();++it)
            if(strcmp(it->get_nr(), nr)==0)
            {
                cout << "\nVa rugam introduceti un numar matricol care nu este luat!";
                cin.get();
                return;
            }

    cout << "\n\tIntroduceti varsta: ";
    cin >> v;
    cout << "\n\tIntroduceti numarul de discipline: ";
    cin >> n;
    cin.get();
    for(int i=0; i<n; i++)
    {
        cout << "\n\t\tIntroduceti numele disciplinei: ";
        cin.getline(ma, 30);
        cout << "\n\t\tIntroduceti nota la aceasta disciplina: ";
        cin >> no;
        cin.get();
        Disciplina * d = new Disciplina(ma, no);
        vec.push_back(*d);
    }
    Student * x = new Student(num, nr, v, n, vec);
    lista_Studenti.push_back(*x);
}

void afisare()
{
    cout << "Lista studentilor:\n";
    if(lista_Studenti.empty() == true)
        cout << "\tLista de studenti este goala!";

    for(list<Student>::iterator it=lista_Studenti.begin(); it!=lista_Studenti.end(); ++it)
    {
        cout << *it;
        cout << "\n";
    }

    cout << "\nApasati ENTER pentru a continua";
    cin.get();
    cin.get();
}


void afisare_student()
{
    char nr_matricol[30], *nr;
    cin.get();
    cout << "Introduceti numarul matricol al studentului: ";
    cin.getline(nr_matricol, 30);
                    if(nr_matricol != NULL)
                    {
                        nr = new char[strlen(nr_matricol)+1];
                        strcpy(nr, nr_matricol);
                    }
                    else
                        nr = NULL;
    for(list<Student>::iterator it = lista_Studenti.begin();it != lista_Studenti.end();++it)
            if(strcmp(it->get_nr(), nr)==0)
                cout << *it;
    cout << "\nApasati ENTER pentru a continua";
    cin.get();
}

void actualizare()
{
    char nr[30];
    int a;
    cin.get();
    cout << "\n\tIntroduceti numarul matricol: ";
    cin.getline(nr, 30);
    for(list<Student>::iterator it=lista_Studenti.begin(); it!=lista_Studenti.end(); ++it)
        if(strcmp(it->get_nr(), nr)==0)
            do
            {
                cout << "\n";
                cout << *it;
                cout << "\n";
                cout << "\n\t1. Schimbare numelui studentului\n\t2. Schimbarea numarului matricol\n\t3. Schimbarea varstei\n\t4. Schimbare listei de discipline\n";
                cout << "\nSelectati cifra operatiei dorite(1-4) sau orice alta cifra pentru a opri aplicatia: ";
                cin >> a;
                if(a==1)
                {
                    char num[50], *nume;
                    cin.get();
                    cout << "\n\tIntroduceti noul numele: ";
                    cin.getline(num, 50);
                    if(num != NULL)
                    {
                        nume = new char[strlen(num)+1];
                        strcpy(nume, num);
                    }
                    else
                        nume = NULL;
                    it->set_nume(nume);
                }

                else if(a==2)
                {
                    char nr_matricol[30], *nr;
                    cin.get();
                    cout << "\n\tIntroduceti noul numar matricol: ";
                    cin.getline(nr_matricol, 50);
                    if(nr_matricol != NULL)
                    {
                        nr = new char[strlen(nr_matricol)+1];
                        strcpy(nr, nr_matricol);
                    }
                    else
                        nr = NULL;
                    for(list<Student>::iterator it2 = lista_Studenti.begin();it2 != lista_Studenti.end();++it2)
                        if(strcmp(it2->get_nr(), nr)==0)
                        {
                            cout << "\nVa rugam introduceti un numar matricol care nu este luat!";
                            cin.get();
                            continue;
                            continue;
                        }
                    it->set_nr(nr);
                }
                else if(a==3)
                {
                    int v;
                    cout << "\n\tIntroduceti noua varsta: ";
                    cin >> v;
                    it->set_varsta(v);
                }
                else if(a==4)
                {
                    char ma[30];
                    float no;
                    vector<Disciplina> vec = it->get_discipline();
                    cin.get();
                    cout << "\n\tIntroduceti numele materiei pe care doriti sa o schimbati: ";
                    bool sw=false;
                    cin.getline(ma, 30);
                    for(int i=0; i<vec.size(); i++)
                        if(strcmp(ma, vec[i].get_nume())==0)
                        {
                            cout << "\n\t\tIntroduceti noul nume al disciplinei: ";
                            cin.getline(ma, 30);
                            cout << "\n\t\tIntroduceti noua nota la aceasta disciplina: ";
                            cin >> no;
                            cin.get();
                            Disciplina * d = new Disciplina(ma, no);
                            vec[i] = *d;
                            sw = true;
                        }
                    if(sw==false)
                        cout << "\n\tNu a fost gasita materia! Apasati tasta ENTER pentru a continua.";
                    cin.get();
                    it->set_discipline(vec);
                }
            }
            while (a>=1 && a<=4);
}

void stergere()
{
    char nr_matricol[30], *nr;
    cin.get();
    cout << "Introduceti numarul matricol al studentului: ";
    cin.getline(nr_matricol, 30);
                    if(nr_matricol != NULL)
                    {
                        nr = new char[strlen(nr_matricol)+1];
                        strcpy(nr, nr_matricol);
                    }
                    else
                        nr = NULL;
    for(list<Student>::iterator it = lista_Studenti.begin();it != lista_Studenti.end();++it)
                if(strcmp(it->get_nr(), nr)==0)
                    lista_Studenti.erase(it--);

    cout << "\nApasati ENTER pentru a continua";
    cin.get();
}

void restantieri()
{
    cout << "Lista studentilor restantieri:\n";
    if(lista_Studenti.empty() == true)
        cout << "\tLista de studenti este goala!";

    for(list<Student>::iterator it=lista_Studenti.begin(); it!=lista_Studenti.end(); ++it)
    {
        vector<Disciplina> vec = it->get_discipline();
        int nr = it->get_numar_discipline();
        double sum=0;
        for(int i=0; i<nr; i++)
            sum += vec[i].get_nota();

        if((double)sum/nr<5)
        {
            cout << *it;
            cout << "\n";
        }
    }

    cout << "\nApasati ENTER pentru a continua";
    cin.get();
    cin.get();
}

void citire_fisier(char str[])
{
    ifstream fin(str);
    if(fin.peek() != ifstream::traits_type::eof())
    {

        char num[50], nr[30],ma[50];
        int v, n;
        float no;

        vector<Disciplina> vec;
        while(!fin.eof())
        {
        fin.getline(num, 50);
        fin.getline(nr, 30);
        fin >> v;
        fin >> n;
        fin.get();

        for(int i=0; i<n; i++)
        {
            fin.getline(ma, 30);
            fin >> no;
            fin.get();
            Disciplina * d = new Disciplina(ma, no);
            vec.push_back(*d);
        }
        Student * x = new Student(num, nr, v, n, vec);
        lista_Studenti.push_back(*x);
        vec.clear();
        n = 0;
        }
    }
    if(!lista_Studenti.empty())
        lista_Studenti.pop_back();
    fin.close();
}
void scriere_fisier(char str[])
{
    if(str!=NULL)
    {
        ofstream fout(str);
        for(list<Student>::const_iterator it = lista_Studenti.begin();it != lista_Studenti.end();++it)
            fout<<*it;
    }
}
