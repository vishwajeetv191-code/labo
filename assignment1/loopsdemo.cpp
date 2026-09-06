#include<iostream>
using namespace std;

// For loop execution used when number of execution is pre defined
void forLoop(){
    int n;

    cout<<"enter limit: ";
    cin>>n;

    for(int i=0; i<n ; i++)
    {
	    cout<<i<<" ";
    }
    cout<<endl;
}

// while loop execution no. of execution is not defined
void whileLoop(){
	int num;
        int i =1;
	cout<<"Enter limit: ";
	cin>>num;

	while(i <= num){
		cout<<i<<" ";
		i++;
	}
	cout<<endl;
}

// do while execute loop atleast  once
void doWhileLoop(){
	int n;

	cout<<"enter number : ";
	cin>>n;

	int i=1;

	do{
		cout<<i<<" ";
		i++;
	}while(i<=n);

	cout<<endl;
}	

int main(){
 int choise;

 do{
	 cout<<"1.For loop"<<endl;
	 cout<<"2.while loop"<<endl;
	 cout<<"3.dowhile loop"<<endl;

	 cout<<"enter your choise : "<<endl;
	 cin>>choise;

	 // execution using switch cases
	 switch(choise)
	 {
		 case 1:
			 forLoop();
			 break;

	         case 2:
			 whileLoop();
			 break;
		case 3:
			 doWhileLoop();
			 break;
	        case 4:
			 cout<<"Programe end "<<endl;
			 break;
		default:
			 cout<<"Invalid input"<<endl;

	}
 }while(choise !=4);

 return 0;
}
