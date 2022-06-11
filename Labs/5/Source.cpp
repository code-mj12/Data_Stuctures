#include <iostream>
using namespace std;
#include "../Lab5/Task.h"
#include "../Lab5/atm.h"

int main() {
	ATM<int> a;
	a.createaccount();
	cout << "Debit by 50" << endl;
	a.debit(50);
	cout << "Credit by 80" << endl;
	a.credit(80);
	cout << "Balance " << endl;
	cout << a.getamount();
}