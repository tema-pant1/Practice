#include "resource.h"
#include <cstring>
#include <iostream>

resource::resource(const char* Id, int pr)
{
    id = new char[std::strlen(Id)+1];
    std::strcpy(id, Id);
    priority = pr;
}

resource::resource(const resource& rsc)
{
    id = new char[std::strlen(rsc.id) + 1];
    std::strcpy(id, rsc.id);
    priority = rsc.priority;
}

resource& resource::operator=(const resource& rsc)
{
    if (this == &rsc)
        return *this;

    delete [] id;

    id = new char[std::strlen(rsc.id) + 1];
    std::strcpy(id, rsc.id);
    priority = rsc.priority;
    return *this;
}

void resource::show() const
{
    std::cout << "id: " << id << std::endl;
    std::cout << "priority: " << priority << std::endl;
}

resource::~resource()
{
    delete[] id;
}

void taggedResource::show() const
{
    resource::show();
    std::cout << "tag: " << tag << std::endl;
}

void resource::setId(const char* Id)
{
    delete[] id;
    id = new char[std::strlen(Id)+1];
    std::strcpy(id, Id);
}

namedResource::namedResource(const char* Id, int pr, const char* nm) : resource(Id, pr)
{
    name = new char[std::strlen(nm) + 1];
    std::strcpy(name, nm);
}

namedResource::namedResource(const namedResource& nr) : resource(nr)
{
    name = new char[std::strlen(nr.name) + 1];
    std::strcpy(name, nr.name);
}

namedResource::~namedResource()
{
    delete[] name;
}

namedResource& namedResource::operator=(const namedResource& nr) 
{
    if (this == &nr)
        return *this;

    resource::operator=(nr);
    delete[] name;
     name = new char[std::strlen(nr.name) + 1];
    std::strcpy(name, nr.name);
    return *this;
}

void namedResource::show() const
{
    resource::show();
    std::cout << "name: " << name << std::endl;
}