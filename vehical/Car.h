#ifndef CAR_H
#define CAR_H

#include"Vehical.h"
class Car:public Vehical
{
        private:
        double parCharge;
        double extracharge;

        public:
        Car(int h);

        double calculateCharges() override;
        void display() override;
        ~Car() override;

        inline double calExtraCharges();
};

#endif