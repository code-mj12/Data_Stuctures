#pragma once
#include <iostream>
using namespace std;

class mat_id
{
	int r, c;
	char l;
public:
	mat_id() {
		r = 0;
		c = 0;
		l = '\0';
	};
	mat_id(int r1, int c1, char l1) {
		r = r1;
		c = c1;
		l = l1;
	}
	int getr() {
		return r;
	}
	int getc() {
		return c;
	}
	char getl() {
		return l;
	}
	

};
