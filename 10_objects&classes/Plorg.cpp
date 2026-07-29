#include "Plorg.h"
#include <iostream>
#include <cstring>

Plorg::Plorg(const char* nm, int cont_ind)
{
    if (strlen(nm) >= LEN)
    {
        std::cout << "Warning! Name for plorg is too long. Max 19 characters.\n";
        std::cout << "Name will be set to Plorga.\n";
        strcpy(name, "Plorga");
    } else strcpy(name, nm);
    CI = cont_ind;
}

void Plorg::show() const
{
    std::cout << "Plorg " << name << " has contentment index " << CI << std::endl;
}