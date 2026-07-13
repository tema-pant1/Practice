#include <iostream>


struct applicant
{
    char name[30];
    int credit_ratings[3];
};

void f1(applicant* a);

const char* f2(const applicant * a1, const applicant * a2);

int main()
{
    void (*p1)(applicant*) = &f1;
    const char* (*p2)(const applicant*, const applicant*);
    void (*ap[5])(applicant*);
    const char* (*pa[10])(const applicant * a1, const applicant * a2);
    return 0;
}