#include "Task1.h"
#include "Task2.h"
#include "Task4.h"
#include "Task3.h"
#include "mat_id.h"
#include "Task5.h"
#include <iostream>
using namespace std;

int main() {

	//-----------Task 4-----------
	Pairs();



	/*
	int ar1[3] = { 1,2,3 };
	int ar2[3] = { 5,6,3};
	
	int* t = Union<int>(ar1, ar2, 3, 3);
	int* z = Intersection<int>(ar1, ar2, 3, 3);
	for (int i = 0; i < 5; i++)
	{
		cout <<"Union "<< t[i] << endl;
	}

	for (int i = 0; i < 1; i++)
	{
		cout << endl << "Intersection  " << z[i] << endl;
	}
	string a = "abc";
	string k =func(a, 0);
	cout << endl << k << endl;


	// task3
	int r1,r2, c1,c2, i, j, b;
	int q[10][10];
	int m[10][10];
	cout << "enter the number of row=";
	cin >> r1>>r2;
	cout << "enter the number of column=";
	cin >> c1>>c2;
	cout << "enter the first matrix element=\n";
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			cin >> q[i][j];
		}
	}
	//output array 1
	cout << "Array 1: " << endl;

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			cout << q[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "enter the second matrix element=\n";
	for (i = 0; i < r2; i++)
	{
		for (j = 0; j < c2; j++)
		{
			cin >> m[i][j];
		}
	}
	cout << "Array 2: " << endl;

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}
	
	m2ma(q,m,r1,c1,r2,c2);
	*/
	mat_id M3(50, 10, 'A'), M4(10, 20, 'B'), M5(20,5,'C');
	int ip = noep(M3, M4, M5, 2);
	cout <<endl<< "For this matrix the number of multiplication is :  " << ip << endl;
}