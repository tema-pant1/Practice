#pragma once
#include <string>
#include <iostream>

class person {
private:
    std::string name;
    int id;

protected:
    void ignore(std::istream& is = std::cin, const char delim = '\n') const;
    virtual void data() const;
    virtual void get();

public:
    person(const std::string& nm = "none.", int i = -1) : name(nm), id(i) {}
    virtual ~person() = 0;
    virtual void set();
    virtual void show() const;
};

class teacher : virtual public person {
private:
    std::string subject;

protected:
    virtual void data() const;
    virtual void get();

public:
    teacher() : person(), subject("none.") {}
    teacher(const std::string& nm, int i, const std::string& sub = "none.") : 
                                                person(nm, i), subject(sub) {}
    teacher(const person& per, const std::string& sub = "none.") : person(per), subject(sub) {}
    virtual void set();
    virtual void show() const; 

};


class coach : virtual public person {
private:
    std::string sport;

protected:
    virtual void data() const;
    virtual void get();

public:
    coach() : person(), sport("none.") {}
    coach(const std::string& nm, int i, const std::string& sp = "none.") :
                                              person(nm, i), sport(sp) {}
    coach(const person& per, const std::string& sp = "none.") : person(per), sport(sp) {}
    virtual void set();
    virtual void show() const;

};

class teacherCoach : public teacher, public coach {
protected:
    virtual void data() const;
    virtual void get();

public:
    teacherCoach() {}
    teacherCoach(const std::string& nm, int i, const std::string& sub, const std::string& sp) :
                                        person(nm, i), teacher(nm, i, sub), coach(nm, i, sp) {}
    teacherCoach(const person& p, const std::string& sub, const std::string& sp) : 
                                        person(p), teacher(p, sub), coach(p, sp) {}
    teacherCoach(const teacher& t, const std::string& sub, const std::string& sp) :
                                        person(t), teacher(t, sub), coach(t, sp) {}
    teacherCoach(const coach& c, const std::string& sub, const std::string& sp) :
                                        person(c), teacher(c, sub), coach(c, sp) {}
    virtual void set();
    virtual void show() const;
};