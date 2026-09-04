
class cd {
private:
    char performers[50];
    char label[20];
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