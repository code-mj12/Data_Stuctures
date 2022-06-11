#include <iostream>
using namespace std;
#include "Task2.h"

int main() {
	int arr[4] = { 0 };
	Array <int> a(arr, 4);
	a.Insert_at_end(5);
	a.Insert_at_end(4);
	a.Insert_at_end(6);
	a.Insert_at_end(1);
	a.print();
	a.Remove_data_item(4);
	a.print();
	a.Insert_in_middle(9, 2);
	a.print();
	int yt =a.IsEmpty();
	if (yt == 0) {
		cout << "False" << endl;
	}
	else {
		cout << "True" << endl;
	}
	a.Clear_the_list();
	a.print();
	return 0;
}