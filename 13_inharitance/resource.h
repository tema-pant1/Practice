
class resource {
private:
    char* id;
    int priority;

public:
    resource(const char* Id = "none.", int pr = 0);
    resource(const resource& rsc);
    resource& operator=(const resource& rsc);
    virtual void show() const;
    virtual ~resource();
    void setId(const char* Id);
};

class taggedResource : public resource {
private:
    int tag;

public:
    taggedResource(const char* Id = "none.", int pr = 0, int tg = 0) : resource(Id, pr), tag(tg) {}
    virtual void show() const;
};

class namedResource : public resource {
private:
    char* name;

public:
    namedResource(const char* Id = "none.", int pr = 0, const char* nm = "none.");
    namedResource(const namedResource& nr);
    virtual ~namedResource();
    namedResource& operator=(const namedResource& nr);
    virtual void show() const;
};