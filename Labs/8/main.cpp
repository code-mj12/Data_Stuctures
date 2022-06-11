#include<iostream>
//#include "task1.h"
#include "task2.h"
using namespace std;

int main() {
	EmployeeID e1,e2,e3,e4,e5;
	e1.start = 19;
	e1.end = 1234;
	e2.start = 19;
	e2.end = 2345;
	e3.start = 19;
	e3.end = 5467;
	e4.start = 19;
	e4.end = 4566;
	e5.start = 19;
	e5.end = 6783;
	
/*	List f;
	f.insert(0,e1,"12345");
	f.insert(1,e2,"12346");
	f.insert(2,e3, "12347");
	f.insert(3, e4, "12348");
	f.insert(4, e5, "12349");

	f.UpdateSalary(1000, e1);
	f.UpdateSalary(2000, e2);
	f.UpdateSalary(5000, e3);
	f.UpdateSalary(3000, e4);
	f.UpdateSalary(6000, e5);
	f.UpdateBonus(500, e1);
	f.UpdateBonus(300, e2);
	f.UpdateBonus(200, e3);
	f.UpdateBonus(600, e4);
	f.UpdateBonus(400, e5);
	cout << "First display" << endl;
	f.display();
	f.remove(e3);
	cout << "Removed" << endl;
	f.display();
	cout << endl << "Sorted list:  " << endl;
	f.Dsort();
	f.display();
	*/
	
	DList df;
	df.insert(0, e1 );
	df.insert(1, e2 );
	df.insert(2, e3 );
	df.insert(3, e4 );
	df.insert(4, e5 );

	df.UpdateSalary(1000, e1);
	df.UpdateSalary(2000, e2);
	df.UpdateSalary(5000, e3);
	df.UpdateSalary(3000, e4);
	df.UpdateSalary(6000, e5);
	df.UpdateBonus(500, e1);
	df.UpdateBonus(300, e2);
	df.UpdateBonus(200, e3);
	df.UpdateBonus(600, e4);
	df.UpdateBonus(400, e5);
	cout << "First display" << endl;
	df.display();
	df.remove(e3);
	cout << "Removed" << endl;
	df.display();
	cout << endl << "Sorted list:  " << endl;
	df.Dsort();
	df.display();
	
}