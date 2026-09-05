#pragma once

#include "cd.h"

class classic : public cd {
private:
    char* composition;

public:
    classic(const char* cmp, const char* perf, const char* lb, int s, double pltm);
    classic(const classic& c);
    classic();
    classic& operator=(const classic& c);
    virtual ~classic();
    virtual void report() const;
};