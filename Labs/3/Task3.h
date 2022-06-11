#pragma once
#include <iostream>
using namespace std;

int m2ma(int M1[][10], int M2[][10], int r1,int c1, int r2, int c2) {
	int sum = 0;
	//taking transpose
	int t[10][10];
	if (c1 != r2)
	{
		for (int i = 0; i < r2; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				t[j][i] = M2[i][j];
			}
		}

		//output transpose
		cout << "taranspose : " << endl;

		for (int i = 0; i < c2; i++)
		{
			for (int j = 0; j < r1; j++)
			{
				M2[i][j] = t[i][j];
				cout << t[i][j] << "  ";
			}
			cout << endl;
		}
	}
	for (int i = 0; i < r1; i++)
	{
		cout << "[ " ;
		for (int j = 0; j < c2; j++)
		{
			int t = 0;
			for (int k = 0; k < c1; k++)
			{
				//int o = M1[i][k] * M2[k][j];
				sum += M1[i][k] * M2[k][j];
				t += M1[i][k] * M2[k][j];
				//cout << o << "  dd  ";
			}
			cout << " " << t << " ";
		}
		cout << " ]" << endl;
	}
	//cout << endl << sum;
	return sum;
}