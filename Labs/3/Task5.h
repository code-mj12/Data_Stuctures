#pragma once
#include "mat_id.h"
#include <iostream>
using namespace std;

int noep(mat_id M1, mat_id M2, mat_id M3 = mat_id() , int bt = 0) {
	int m1[100][100], m2[100][100],m3[100][100],m4[100][100];
	
	//intializing first array
	for (int i = 0; i < M1.getr(); i++)
	{
		for (int j = 0; j < M1.getc(); j++)
		{
			m1[i][j] = 1;
		}
	}
	//intializing second array
	for (int i = 0; i < M2.getr(); i++)
	{
		for (int j = 0; j < M2.getc(); j++)
		{
			m2[i][j] = 1;
		}
	}
	//intializing third array
	if (M3.getr() != 0) {
		for (int i = 0; i < M3.getr(); i++)
		{
			for (int j = 0; j < M3.getc(); j++)
			{
				m3[i][j] = 1;
			}
		}
	}

	int count = 0;
	//counter start
	if (bt == 0) {
		for (int i = 0; i < M1.getr(); i++)
		{
			for (int j = 0; j < M2.getc(); j++)
			{
				for (int k = 0; k < M1.getc(); k++)
				{
					//[i][k] * m2[k][j];
					count++;
					//cout << o << "  dd  ";
				}
			}
		}
		return count;
	}
	else if (bt == 1) {
		for (int i = 0; i < M1.getr(); i++)
		{
			for (int j = 0; j < M2.getc(); j++)
			{
				for (int k = 0; k < M1.getc(); k++)
				{
					m4[i][j] +=m1[i][k] * m2[k][j];
					count++;
					//cout << o << "  dd  ";
				}
			}
		}

		for (int i = 0; i < M1.getr(); i++)
		{
			for (int j = 0; j < M3.getc(); j++)
			{
				for (int k = 0; k < M3.getr(); k++)
				{
					m3[i][j] += m1[i][k] * m2[k][j];
					count++;
					//cout << o << "  dd  ";
				}
			}
		}
		return count;
	}

	else if (bt == 2) {
		for (int i = 0; i < M2.getr(); i++)
		{
			for (int j = 0; j < M3.getc(); j++)
			{
				for (int k = 0; k < M2.getc(); k++)
				{
					m4[i][j] += m1[i][k] * m2[k][j];
					count++;
					//cout << o << "  dd  ";
				}
			}
		}

		for (int i = 0; i < M1.getr(); i++)
		{
			for (int j = 0; j < M3.getc(); j++)
			{
				for (int k = 0; k < M1.getc(); k++)
				{
					count++;
					//cout << o << "  dd  ";
				}
			}
		}
		return count;
	}
}