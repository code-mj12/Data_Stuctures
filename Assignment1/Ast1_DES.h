#pragma once
#include<iostream>
#include <string>
using namespace std;
//key tester functions


string initKeyPermutation(string key) { //one time function call
	string bin;
	char ck[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	char temp;
	for (int i = 0; i < 16; i++)
	{
		temp = key.at(i);
		//cout << temp;
		if (temp == ck[0]) {
			string tp = "0000";
			bin.append(tp);
		}
		else if (temp == ck[1]) {
			string tp = "0001";
			bin.append(tp);
		}
		else if (temp == ck[2]) {
			string tp = "0010";
			bin.append(tp);
		}
		else if (temp == ck[3]) {
			string tp = "0011";
			bin.append(tp);
		}
		else if (temp == ck[4]) {
			string tp = "0100";
			bin.append(tp);
		}
		else if (temp == ck[5]) {
			string tp = "0101";
			bin.append(tp);
		}
		else if (temp == ck[6]) {
			string tp = "0110";
			bin.append(tp);
		}
		else if (temp == ck[7]) {
			string tp = "0111";
			bin.append(tp);
		}
		else if (temp == ck[8]) {
			string tp = "1000";
			bin.append(tp);
		}
		else if (temp == ck[9]) {
			string tp = "1001";
			bin.append(tp);
		}
		else if (temp == ck[10]) {
			string tp = "1010";
			bin.append(tp);
		}
		else if (temp == ck[11]) {
			string tp = "1011";
			bin.append(tp);
		}
		else if (temp == ck[12]) {
			string tp = "1100";
			bin.append(tp);
		}
		else if (temp == ck[13]) {
			string tp = "1101";
			bin.append(tp);
		}
		else if (temp == ck[14]) {
			string tp = "1110";
			bin.append(tp);
		}
		else if (temp == ck[15]) {
			string tp = "1111";
			bin.append(tp);
		}
	}
	int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
	string newbin;
	for (int i = 0; i < 56; i++)
	{
		int n = PC1[i];
		char nt = bin.at(n-1);
		std::string nt1(1, nt);
		newbin.append(nt1);
	}
	return newbin;
}

string halfCircularShift(string half_key, int index) { //shift 
	int round_shifts[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	string newkey = half_key;
	string new2;

	char  tp = half_key.at(0);
	std::string tps(1, tp);		//for if shifting round is 1
	string new1 = newkey.substr(1, newkey.length());
	new2 = new1.append(tps);
	for (int i = 1; i < index; i++)
	{
		if (round_shifts[i] == 1) {
			char gh = new2.at(0);
			std::string ghs(1, gh);		//for if shifting round is 1
			new1 = new2.substr(1, newkey.length());
			new2 = new1.append(ghs);
		}
		else {
			char gh = new2.at(0);
			char gh1 = new2.at(1);
			std::string ghs2(1, gh);
			std::string ghs3(1, gh1);
			//for if shifting round is 1
			new1 = new2.substr(2, newkey.length());
			new2 = new1.append(ghs2);
			new2 = new1.append(ghs3);
		}
	}
	return new2;
}

string roundPermutation(string key) {  //56 to 48 bit conversion
	int PC2[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
	string newbin = "";
	for (int i = 0; i < 48; i++)
	{
		int n = PC2[i];
		char nt = key.at(n - 1);
		std::string nt1(1, nt);
		//cout << nt;
		newbin.append(nt1);
	}

	return newbin;
	
}

string initTextPermutation(string key) {
	string bin;
	char ck[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	char temp;
	for (int i = 0; i < 16; i++)
	{
		temp = key.at(i);
		//cout << temp;
		if (temp == ck[0]) {
			string tp = "0000";
			bin.append(tp);
		}
		else if (temp == ck[1]) {
			string tp = "0001";
			bin.append(tp);
		}
		else if (temp == ck[2]) {
			string tp = "0010";
			bin.append(tp);
		}
		else if (temp == ck[3]) {
			string tp = "0011";
			bin.append(tp);
		}
		else if (temp == ck[4]) {
			string tp = "0100";
			bin.append(tp);
		}
		else if (temp == ck[5]) {
			string tp = "0101";
			bin.append(tp);
		}
		else if (temp == ck[6]) {
			string tp = "0110";
			bin.append(tp);
		}
		else if (temp == ck[7]) {
			string tp = "0111";
			bin.append(tp);
		}
		else if (temp == ck[8]) {
			string tp = "1000";
			bin.append(tp);
		}
		else if (temp == ck[9]) {
			string tp = "1001";
			bin.append(tp);
		}
		else if (temp == ck[10]) {
			string tp = "1010";
			bin.append(tp);
		}
		else if (temp == ck[11]) {
			string tp = "1011";
			bin.append(tp);
		}
		else if (temp == ck[12]) {
			string tp = "1100";
			bin.append(tp);
		}
		else if (temp == ck[13]) {
			string tp = "1101";
			bin.append(tp);
		}
		else if (temp == ck[14]) {
			string tp = "1110";
			bin.append(tp);
		}
		else if (temp == ck[15]) {
			string tp = "1111";
			bin.append(tp);
		}
	}
	int PC1[64] = { 58 , 50 , 42 , 34 , 26 , 18 , 10 , 2, 60 , 52 , 44 , 36 , 28 , 20 , 12 , 4, 62 , 54 , 46 , 38 , 30 , 22 , 14 , 6, 64 , 56 , 48 , 40 , 32 , 24 , 16 , 8, 57 , 49 , 41 , 33 , 25 , 17 , 9 , 1, 59 , 51 , 43 , 35 , 27 , 19 , 11 , 3, 61 , 53 , 45 , 37 , 29 , 21 , 13 , 5, 63 , 55 , 47 , 39 , 31 , 23 , 15 , 7};
	string newbin;
	//cout << endl<<bin;
	for (int i = 0; i < 64; i++)
	{
		int n = PC1[i];
		char nt = bin.at(n - 1);
		std::string nt1(1, nt);
		newbin.append(nt1);
	}

	return newbin;

}

string expandHalfText(string rightHalfText) {
	int EXPANSION_TABLE[48] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
	string ebin ="";
	for (int i = 0; i < 48; i++)
	{
		char ch = rightHalfText.at(EXPANSION_TABLE[i]-1);
		std::string sh(1, ch);
		ebin.append(sh);
	}
	return ebin;
}

string XOR(string text, string key) {
	string nbin = "";
	for (int i = 0; i < 48; i++)
	{
		char ch1 = text.at(i);
		char ch2 = key.at(i);
		if ((ch1 == '0' && ch2 == '0') || (ch1 == '1' && ch2 == '1')) {
			string a = "0";
			nbin.append(a);
		}
		else if ((ch1 == '1' && ch2 == '0') || (ch1 == '0' && ch2 == '1')) {
			string a = "1";
			nbin.append(a);
		}
	}
	return nbin;
}

string calcSBox(string text) {
	
	int Box1[4][16] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7} ,
						{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
						{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
						{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};
	int	Box2[4][16] = {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
						{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
						{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
						{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};
	int	Box3[4][16] =  {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
						{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
						{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
						{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}};
	int Box4[4][16] = { {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
						{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
						{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
						{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}};
	int Box5[4][16] = {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
						{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
						{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
						{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}};
	int Box6[4][16] ={{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
						{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
						{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
						{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
						};
	int Box7[4][16] ={{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
						{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
						{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
						{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
						};
	int Box8[4][16] ={{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
					{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
					{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
					{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
					};
	string bin = "";
	string ntxt = text;
	for (int i = 0; i < 8; i++)
	{
		string s1 = ntxt.substr(i*6, (i*6+6));
		char ch0 = s1.at(0), ch1 = s1.at(1), ch2 = s1.at(2), ch3 = s1.at(3), ch4 = s1.at(4), ch5 = s1.at(5);
		string sb1 = "";
		string sb2 = "";
		sb1.push_back(ch0);
		sb1.push_back(ch5);
		sb2.push_back(ch1);
		sb2.push_back(ch2);
		sb2.push_back(ch3);
		sb2.push_back(ch4);
		int r = 0, c = 0;
		//for rows
		if (sb1 == "00") {
			r = 0;
		}
		else if (sb1 == "01") {
			r = 1;
		}
		else if (sb1 == "10") {
			r = 2;
		}
		else if (sb1 == "11") {
			r = 3;
		}
		//for columns
		if (sb2 == "0001") {
			c = 1;
		}
		else if (sb2 == "0010") {
			c = 2;
		}
		else if (sb2 == "0011") {
			c = 3;
		}
		else if (sb2 == "0100") {
			c = 4;
		}
		else if (sb2 == "0101") {
			c = 5;
		}
		else if (sb2 == "0110") {
			c = 6;
		}
		else if (sb2 == "0111") {
			c = 7;
		}
		else if (sb2 == "1000") {
			c = 8;
		}
		else if (sb2 == "1001") {
			c = 9;
		}
		else if (sb2 == "1010") {
			c = 10;
		}
		else if (sb2 == "1011") {
			c = 11;
		}
		else if (sb2 == "1100") {
			c = 12;
		}
		else if (sb2 == "1101") {
			c = 13;
		}
		else if (sb2 == "1110") {
			c = 14;
		}
		else if (sb2 == "1111") {
			c = 15;
		}
		int vl;
		int b1 = Box1[r][c], b2 = Box2[r][c], b3 = Box3[r][c], b4 = Box4[r][c], b5 = Box5[r][c], b7 = Box7[r][c], b8 = Box8[r][c], b6 =Box6[r][c];
		if (i == 0) {
			vl = b1;
		}
		else if (i == 1) {
			vl = b2;
		}
		else if (i == 2) {
			vl = b3;
		}
		else if (i == 3) {
			vl = b4;
		}
		else if (i == 4) {
			vl = b5;
		}
		else if (i == 5) {
			vl = b6;
		}
		else if (i == 6) {
			vl = b7;
		}
		else {
			vl = b8;
		}
		//convert to binary
		
		if (vl == 0) {
			string tp = "0000";
			bin.append(tp);
		}
		else if (vl == 1) {
			string tp = "0001";
			bin.append(tp);
		}
		else if (vl == 2) {
			string tp = "0010";
			bin.append(tp);
		}
		else if (vl == 3) {
			string tp = "0011";
			bin.append(tp);
		}
		else if (vl == 4) {
			string tp = "0100";
			bin.append(tp);
		}
		else if (vl == 5) {
			string tp = "0101";
			bin.append(tp);
		}
		else if (vl == 6) {
			string tp = "0110";
			bin.append(tp);
		}
		else if (vl == 7) {
			string tp = "0111";
			bin.append(tp);
		}
		else if (vl == 8) {
			string tp = "1000";
			bin.append(tp);
		}
		else if (vl == 9) {
			string tp = "1001";
			bin.append(tp);
		}
		else if (vl == 10) {
			string tp = "1010";
			bin.append(tp);
		}
		else if (vl == 11) {
			string tp = "1011";
			bin.append(tp);
		}
		else if (vl == 12) {
			string tp = "1100";
			bin.append(tp);
		}
		else if (vl == 13) {
			string tp = "1101";
			bin.append(tp);
		}
		else if (vl == 14) {
			string tp = "1110";
			bin.append(tp);
		}
		else if (vl == 15) {
			string tp = "1111";
			bin.append(tp);
		}
	}
	return bin;
}