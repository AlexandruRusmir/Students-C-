#ifndef STUDENT_H
#define STUDENT_H
#include <bits/stdc++.h>
#include "Disciplina.h"
using namespace std;

class Student
{
    public:
        Student(char num[], char nr_mat[], int vars, float med, vector<Disciplina> l);
        Student(const Student &x);
        const char * get_nume();
        const char * get_nr();
        const int get_varsta();
        const int get_numar_discipline();
        const vector<Disciplina> get_discipline();
        void set_nume(char *num);
        void set_nr(char *nr);
        void set_varsta(int v);
        void set_discipline(vector<Disciplina> v);
        friend ostream& operator << (ostream& ,const Student&);
        friend ofstream& operator << (ofstream& ,const Student&);
        virtual ~Student();
    protected:
    private:
        char *nume;
        char *nr_matricol;
        int varsta;
        int numar_discipline;
        vector<Disciplina> v_discipline;
};

#endif // STUDENT_H
