#include<iostream>
using namespace std;

int main(){
	int a=5;
	int b=10;

	const int* ptr1 = &a;//pointer to const int  --- *ptr is read only

	int* const ptr2 = &a;//const pointer to int ---ptr2 cannot point elsewhere

       //*ptr1= 20; //error
	ptr1 = &b;

	//ptr2 = &b //error
	*ptr2 = 30;

	cout<<"a = "<<a<<std::endl;
	cout<<"b = "<<b<<std::endl;

	return 0;
}
