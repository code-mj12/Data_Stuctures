#include "Ast1_DES.h"
#include <string>
#include<iostream>
using namespace std;

int main() {
	const string text = "011100010001011100111010101011000110110000100001";
	calcSBox(text);


	//cout << "hhhhhhhh" << endl;
	string s =initKeyPermutation("1234567890ABCDEF");
	cout << s << endl;
	const string permutedKey = "11110000110011001010101000011010010111000110111010001111";
	if (s == permutedKey)
		cout << endl << "YES-----------" << endl;

	const string leftHalfKey = "1111000011001100101010100001";
	const string rightHalfKey = "1010010111000110111010001111";
	const string shiftedLeftHalf = "1110000110011001010101000011";
	const string shiftedRightHalf = "0100101110001101110100011111";
	string s2 = halfCircularShift(leftHalfKey, 1);
	if (s2 == shiftedLeftHalf) {
		cout << endl << "YES-----------NO" << endl;
	}
	/*string a;
	string  v = "0000";
	string  c = "1000";
	a.append(v);
	cout << a << endl;
	a.append(c);
	cout << a << endl;
	return 0;*/
}