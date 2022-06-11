#pragma once
#include <iostream>
using namespace std;

void Pairs() {
	int ar[50];
	for (int i = 0; i < 50; i++)
	{
		ar[i] = i;
	}
	for (int i = 0; i < 50; i++)
	{
		//cout << "ggg" << endl;
		for (int j = 0; j < 50; j++)
		{
			for (int k = 0; k < 50; k++)
			{
				if (ar[i] == ar[j] + ar[j + k]) {
					cout << ar[i] << " is sum of ( " << ar[j] << ", " << ar[j + k] << ") " << endl;
				}
			}

		}
	}

	cout << endl << endl;
}
