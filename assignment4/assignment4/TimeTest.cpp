#include<iostream>
#include"Time.h"
using namespace std;

int main() {
    // Create Time objects using parameterized constructor
    Time t1;
    //parameterized constructor
    Time t2(10,30); // 10 hours and 30 minutes
    Time t3(5, 45); // 2 hours and 45 minutes
   
    // Display the initial times
    cout << "Initial Times:" << endl;
    t1.display();
    t2.display();
    t3.display();

    // Add two Time objects
    Time t4 = t2 + t3;
    cout << "After Addition:" << endl;
    t4.display();

    // Subtract two Time objects
    Time t5 = t2 - t3;
    cout << "After Subtraction:" << endl;
    t5.display();

   //5.Assignment
   t1 = t2;
   cout << "After Assignment (t1 = t2):" << endl;
   t1.display();

   //6. chained assignment
   Time t6, t7;
    t6 = t7 = t3;

    cout << "After Chained Assignment (t6 = t7 = t3):" << endl;
    t6.display();
    t7.display();

    //7. Prefix increment
    cout << "Prefix Increment :" << endl;
    Time t8(11,59);
    cout << "Before Increment: ";
    t8.display();
    ++t8;
    cout << "After Increment: ";
    t8.display();

    //8. Postfix increment
    cout << "Postfix Increment :" << endl;
    Time t9(11,59);
    cout << "Before Increment: ";
    t9.display();
    Time oldTime = t9++;
    cout<<"Returned old value =";
    oldTime.display();

    cout<<"After t9++: ";
    t9.display();

    //9. Prefix decrement
    Time t10(11, 0);
    cout << "Prefix Decrement :" << endl;
    cout << "Before --t10: ";
    t10.display();
    --t10;
    cout << "After --t10: ";
    t10.display();

    //10. Postfix decrement
    Time t11(11, 0);
    cout << "Postfix Decrement :" << endl;
    cout << "Before t11--: ";
    t11.display();
    Time oldTime2 = t11--;

    cout << "Returned old value =";
    oldTime2.display();

    cout << "New t11 value: ";
    t11.display();

    return 0;
}