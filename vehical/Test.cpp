#include<iostream>
#include<string>
#include "Vehical.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

template<typename T> 

bool isValidDiscount(const T& inputcode, const T& validcode){
	
	return (inputcode==validcode);

}


int main(){
		
	char vtype;
	int hrs;
	
	
	// 1. Vehicle Selection
	while(true){
		cout<<"Enter type of vehicle('C' for car and 'T' for truck)"<<endl;
		cin>>vtype;
		vtype = toupper(vtype);
		
		if(vtype=='C' || vtype=='T')
        {
		       break;
		}
		
		cout<<"Invalid Vehicle Type"<<endl;
		}
	
	
	// 2. Hours Validation	
	while(true){
	
		cout<<"Enter Parking hours: "<<endl;
		cin>>hrs;
		
		if(hrs > 0){

			break;
		}
	
		cout<<"Parking hours must be positive"<<endl;
	}
	
	
	Vehical *vptr = nullptr;
	
	
		if(vtype=='C'){
		
			vptr = new Car(hrs);

            Vehical::receiptCount++;
			vptr->calculateCharges();
			vptr->display();
			
		}else
        {
		
			string code;	
			
			cout<<"Enter Discount code if available(or press enter to skip):"<<endl;
			cin.ignore();
			getline(cin,code);
			
			bool discountApplied = isValidDiscount(code,string("TRUCK50"));
			vptr = new Truck(hrs, discountApplied);

             Vehical::receiptCount++;

			vptr->calculateCharges();
			vptr->display();
		
		}
		
	

	return 0;
}
