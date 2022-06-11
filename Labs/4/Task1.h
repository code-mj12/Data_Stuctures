#pragma once
#include <iostream>
using namespace std;
template <class T>

T amount(int n_scp, bool waf, string flavour) {
	int price = 0;
	price = n_scp * 50;
	if (n_scp > 3) {
		return -1;
	}
	if (waf == true) {
		price += n_scp * 10;
	}
	if (flavour == "chocolate") {
		price += n_scp * 10;
	}

	return price;

}

