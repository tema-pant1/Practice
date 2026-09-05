#include <cstring>
#include <iostream>
#include "cd.h"


cd::cd(const char* perf, const char* lb, int s, double pltm)
{
    performers = new char[std::strlen(perf) + 1];
    std::strcpy(performers, perf);
    label = new char[std::strlen(lb) + 1];
    std::strcpy(label, lb);
    selections = s;
    playtime = pltm;
}

cd::cd(const cd& d) : cd(d.performers, d.label, d.selections, d.playtime)
{
    
}

cd::cd() : cd("none.", "none.", 0, 0)
{

}

cd& cd::operator=(const cd& d)
{
    if (this == &d)
        return *this;
    
    delete[] performers;
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    delete[] label;
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

cd::~cd() 
{   
    delete[] performers;
    delete[] label;
}

void cd::report() const
{
    using std::cout;
    using std::endl;

    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

