#pragma once

class Plorg {
private:
    static const int LEN = 20;
    char name[LEN];
    int CI;

public:
    Plorg ( const char* nm = "Plorga", int cont_ind = 50);
    void set_CI(int cont_ind) {CI = cont_ind;}
    void show() const;
};