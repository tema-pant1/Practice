

class shape {
protected:
    double x;
    double y;

public:
    shape(double X = 0.0, double Y = 0.0) : x(X), y(Y) {} 
    virtual double area() const = 0;
    virtual void info() const = 0;
    virtual void move(double nx, double ny);
    virtual ~shape() {}
};

class rectangle : public shape {
private:
    double width;
    double height;

public:
    rectangle(double X = 0.0, double Y = 0.0, 
              double w = 0.0, double h = 0.0) : shape(X, Y), width(w), height(h) {}
    
    virtual double area() const {return width*height;};
    virtual void info() const;

    virtual ~rectangle() {}
};

class triangle : public shape {
private:
    double base;
    double height;

public:
    triangle(double X = 0.0, double Y = 0.0,
             double b = 0.0, double h = 0.0) : shape(X, Y), base(b), height(h) {}
    
    virtual double area() const {return 0.5 * base * height;}
    virtual void info() const;
    
    ~triangle() {}
};