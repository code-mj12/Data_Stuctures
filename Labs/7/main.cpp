#include<iostream>
using namespace std;
#include "Task1.h"

int main() {
	List<int> list;
	list.InsertNode(0, 1, "Maji", 10); 
	list.InsertNode(1, 2, "fdvf", 23);
	list.InsertNode(0, 3, "fdvf", 21);
	list.InsertNode(0, 4, "fdvf", 24);
	list.InsertNode(0, 5, "fdvf", 25);
	list.InsertNode(0, 6, "fdvf", 26);
	list.InsertNode(0, 7, "fdvf", 27);
	list.InsertNode(0, 8, "fdvf", 28);
	list.InsertNode(0, 9, "fdvf", 28);
	list.InsertNode(0, 10, "fdvf", 28);
	list.InsertNode(0, 10, "fdvf", 25);
	list.Dsort();
	list.Displaylist();
	cout <<endl<< "Sorted in Asceding" << endl;
	list.Asort();
	list.Displaylist();

}
