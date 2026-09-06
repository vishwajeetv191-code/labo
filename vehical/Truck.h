#ifndef TRUCK_H
#define TRUCK_H

#include"Vehical.h"
class Truck:public Vehical
{
        private:
        double parCharge;
        double extracharge;
        bool discount;

        public:
        Truck(int h, bool hasDiscount = false);
        

        double calculateCharges() override;
        double calculateCharges(double discountAmount);
        void display() override;

        inline double calExtraCharges();
        ~Truck();
};

#endif