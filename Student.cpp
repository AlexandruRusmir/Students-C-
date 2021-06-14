#include "Student.h"
#include "Disciplina.h"
#include <bits/stdc++.h>
using namespace std;
Student::Student(char num[], char nr_mat[], int vars, float med, vector<Disciplina> v)
{
    if(num != NULL)
    {
        this->nume = new char[strlen(num)+1];
        strcpy(this->nume, num);
    }
    else
        this->nume = NULL;

    if(nr_mat != NULL)
    {
        this->nr_matricol = new char[strlen(nr_mat)+1];
        strcpy(this->nr_matricol, nr_mat);
    }
    else
        this->nr_matricol = NULL;

    this->varsta = vars;
    this->numar_discipline = v.size();
    this->v_discipline = v;
}

Student::Student(const Student &x)
{
    if(x.nume != NULL)
    {
        this->nume = new char[strlen(x.nume)+1];
        strcpy(this->nume, x.nume);
    }
    else
        this->nume = NULL;

    if(x.nr_matricol != NULL)
    {
        this->nr_matricol = new char[strlen(x.nr_matricol)+1];
        strcpy(this->nr_matricol, x.nr_matricol);
    }
    else
        this->nr_matricol = NULL;

    this->varsta = x.varsta;
    this->numar_discipline = x.numar_discipline;
    this->v_discipline = x.v_discipline;
}

const char * Student::get_nume()
{
    return this->nume;
}

const char * Student::get_nr()
{
    return this->nr_matricol;
}

const int Student::get_varsta()
{
    return this->varsta;
}

const int Student::get_numar_discipline()
{
    return this->numar_discipline;
}

const vector<Disciplina> Student::get_discipline()
{
    return this->v_discipline;
}

void Student::set_nume(char *num)
{
    if(num != NULL)
        strcpy(this->nume, num);
}

void Student::set_nr(char *nr)
{
    if(nr != NULL)
        strcpy(this->nr_matricol, nr);
}

void Student::set_varsta(int v)
{
    this->varsta = v;
}

void Student::set_discipline(vector<Disciplina> v)
{
    this->v_discipline = v;
}

ostream& operator << (ostream& ost,const Student& x)
{
     cout << "\n\tNume student: " << x.nume << "\n\tNumarul matricol:" << x.nr_matricol << "\n\tVarsta: " << x.varsta;
     cout << "\n\tDiscipline:";
     for(vector<Disciplina>::const_iterator it=x.v_discipline.begin(); it!=x.v_discipline.end(); ++it)
            cout << "\t" << *it;
}

ofstream& operator << (ofstream& fout,const Student& x)
{
     fout << x.nume << "\n" << x.nr_matricol << "\n" << x.varsta;
     fout << "\n";
     fout << x.numar_discipline << "\n";
     for(vector<Disciplina>::const_iterator it=x.v_discipline.begin(); it!=x.v_discipline.end(); ++it)
            fout << *it << "\n";
}

Student::~Student()
{
    if(this->nume != NULL)
        delete this->nume;
    if(this->nr_matricol != NULL)
        delete this->nr_matricol;
}
