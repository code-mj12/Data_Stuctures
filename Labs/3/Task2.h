#pragma once
#include <iostream>
using namespace std;

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

string func(string a, int n) {
	if (a.length() == 26 && n==0) { return "NOPE"; } //checks
		char lets[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		char s[26];
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < a.length(); j++)
			{
				if (a.at(j) == lets[i]) {
					lets[i] = 0;
				}
			}
		}
		int  j = 0;
		for (int i = 0; i < a.length(); i++, j++)
		{
			if (lets[j] != 0) {
				s[i] = lets[j];
			}
			else { i--; }
		}

		string q = convertToString(s, a.length());
		return q;
	
}
