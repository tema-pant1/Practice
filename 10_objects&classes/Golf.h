#pragma once

class golf {
private:
    static const int LEN = 40;
    char fullname[LEN];
    int handicap;

public:
    golf(const char* name = "", int hc = 0);
    int SetGolf();
    void SetHandicap(int hc);
    void Show() const;

};