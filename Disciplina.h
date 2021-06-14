#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <bits/stdc++.h>
using namespace std;

class Disciplina
{
    public:
        Disciplina(char num[], float n);
        Disciplina(const Disciplina &x);
        const char * get_nume();
        const float get_nota();
        friend ostream& operator << (ostream& ,const Disciplina&);
        friend ofstream& operator << (ofstream& ,const Disciplina&);
        virtual ~Disciplina();
    protected:
    private:
        char *nume;
        float nota;
};

#endif // DISCIPLINA_H
