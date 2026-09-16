#pragma once
#include <string>
#include <iostream>

class person {
private:
    std::string name;
    int id;

protected:
    void ignore(std::istream& is = std::cin, const char delim = '\n') const;

public:
    person(const std::string& nm = "none.", int i = -1);
    virtual ~person() = 0;
    virtual void set();
    virtual void show() const;
};

class teacher : public person {
private:
    std::string subject;

public:
    teacher() : person(), subject("none.") {}
    teacher(const std::string& nm, int i, const std::string& sub = "none.") : 
                                                person(nm, i), subject(sub) {}
    teacher(const person& per, const std::string& sub = "none.") : person(per), subject(sub) {}
    virtual void set();
    virtual void show() const; 
};


class coach : public person {
private:
    std::string sport;

public:
    coach() : person(), sport("none.") {}
    coach(const std::string& nm, int i, const std::string& sp = "none.") :
                                                            sport(sp) {}
    coach(const person& per, const std::string& sp = "none.") : person(per), sport(sp) {}
    virtual void set();
    virtual void show() const;
};