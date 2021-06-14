#include "Disciplina.h"
#include <bits/stdc++.h>
using namespace std;

Disciplina::Disciplina(char num[], float n)
{
    if(num != NULL)
    {
        this->nume = new char[strlen(num)+1];
        strcpy(this->nume, num);
    }
    else
        this->nume = NULL;
    this->nota = n;
}

Disciplina::Disciplina(const Disciplina &x)
{
    if(x.nume != NULL)
    {
        this->nume = new char[strlen(x.nume)+1];
        strcpy(this->nume, x.nume);
    }
    else
        this->nume = NULL;

    this->nota = x.nota;
}

const float Disciplina::get_nota()
{
    return this->nota;
}

const char * Disciplina::get_nume()
{
    return this->nume;
}

ostream& operator << (ostream& ost,const Disciplina& x)
{
    cout << "\n\t\tNumele materiei: " << x.nume << ", nota: " << x.nota;
}

ofstream& operator << (ofstream& fout,const Disciplina& x)
{
     fout << x.nume << "\n" << x.nota;
}

Disciplina::~Disciplina()
{
    if(this->nume != NULL)
        delete this->nume;
}
