#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str = "Hello World";

	cout<<"Length: " << str.length()<<endl;
	cout<<"size:" <<str.size()<<endl;

	cout<<"First Character:"<<str[0]<<endl;
	cout<<"Substring:"<<str.substr(0,5)<<endl;

	cout<<"Find World:"<<str.find ("World")<<endl;

	str.append("C++");
	cout<<"After append: "<<str<<endl;

	str.insert(6,"Beautiful");
	cout<<"after insert : "<<str<<endl;

	str.erase(6,10);
	cout<<"After erase : "<<str<<endl;

	str.replace(0,5,"hi");
	cout<<"After replace : "<<str<<endl;

	return 0;
}

