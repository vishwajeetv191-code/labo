#ifndef VEHICAL_H
#define VEHICAL_H

class Vehical{

    protected:
    int hours;

    public:
    Vehical(int h);

    
    virtual double calculateCharges() = 0;
    virtual void display();
    static int receiptCount;
    virtual ~Vehical();
};

#endif