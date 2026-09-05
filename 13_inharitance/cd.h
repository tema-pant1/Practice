#pragma once

class cd {
private:
    char* performers;
    char* label;
    int selections;
    double playtime;

public:
    cd(const char* perf, const char* lb, int s, double pltm);
    cd(const cd& d);
    cd();
    cd& operator=(const cd& d);
    virtual ~cd();
    virtual void report() const;
};

