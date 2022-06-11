#pragma once
#pragma once
#ifndef CITIZENSDB_H
#define CITIZENSDB_H
#include <string>
#include <iostream>
#include<sstream>
#include <fstream>
using namespace std;


template <class T>
class DataPipeline {
	/*	A linkedlist based queue to implement databases
		Implement additional functions as per requirement
	*/

public:
	DataPipeline() {
		/*fstream f1;
		fstream f2;
		fstream f3;
		string word;
		f1.open("CBID.txt");
		f2.open("CCID.txt");
		f3.open("CCND.txt");
		while (f1>>word)
		{

		}
		*/
	}

	T front() {
		return T();
	}
	T back() {
		return T();
	}
	T enqueue(T) {
	}

	T dequeue() {
		return T();
	}

	bool is_empty() {
		return;
	}
};

class AD {

	/* Implement a stack for your Alien Database operations */
public:
	AD() {

	}

	void push_roll(int value) {

	}

	void top() {

		return;//ADTop;
	}

	void pop() {

	}

	bool is_empty() {
		return true;
	}

	void empty() {
		while (!is_empty()) {
			pop();
		}
	}
};

struct CBID_NODE {
	CBID_NODE* next, * previous;		//doubly
	int cnic;
	string name;
	string fname;
	string gender;
	string address;
	string nationality;
};
CBID_NODE* top;
struct CCID_NODE {
	CCID_NODE* first, * next, * previous;
	int cnic;
	string charges;
	string punishment;
	string fine;
};

struct CCND_NODE {
	int cnic;
	string number;
	string network;
	string adate;
	string ddate;
	string status;
	CCND_NODE* next, * previous;
};


template <class T>
class Database {

	CBID_NODE* CBIDh;
	CCID_NODE* CCIDh;
	CCND_NODE* CCNDh;
	//DataPipeline<string> dataPipeline;

public:
	Database(const T& filename, const T& filename1, const T& filename2) {
		/*
			Initialize the data from the given file and populate database
		*/
		//fstream f1;
		//fstream f2;
		//fstream f3;
		//string line;
		CBIDh = nullptr; CCIDh = nullptr;  CCNDh = nullptr;
		/*f1.open("CBID.txt");
		f2.open("CCID.txt");
		f3.open("CCND.txt");
		CCND_NODE* newnode1 = new CCND_NODE;
		CCID_NODE* newnode2 = new CCID_NODE;
		CBID_NODE* curr = CBIDh;
		CCID_NODE* curr1 = CCIDh;
		CCND_NODE* curr2 = CCNDh;
		while (getline(f1,line))
		{
			CBID_NODE* newnode = new CBID_NODE;
			istringstream ss(line);
			string word;
			ss >> word;
			newnode->cnic = stoi(word);
			ss >> word;
			newnode->name = word;
			ss >> word;
			newnode->fname = word;
			ss >> word;
			newnode->gender = word;
			ss >> word;
			newnode->address = word;
			newnode->address += " ";
			ss >> word;
			newnode->address += word;
			newnode->address += " ";
			ss >> word;
			newnode->address += word;
			ss >> word;
			newnode->nationality = word;
			static int count = 0;
			if (curr == nullptr) {
				newnode->next = nullptr;
				newnode->previous = nullptr;
				CBIDh = newnode;
				curr = CBIDh;
				//cout << "ff" << endl;
			}
			else {
				newnode->previous = curr;
				newnode->next = curr->next;
				curr->next = newnode;
				curr = newnode;
				//cout << curr->cnic<<endl;
			}
		}

		while (getline(f2, line))
		{
			CCID_NODE* newnode = new CCID_NODE;
			istringstream ss(line);
			string word;
			ss >> word;
			int f = 0;
			newnode->cnic = stoi(word);
			ss >> word;
			newnode->charges = word;
			ss >> word;
			if (word.length() < 3) {
				newnode->punishment = word;
				newnode->punishment += " ";
				ss >> word;
			}
			newnode->punishment += word;
			newnode->punishment += " ";
			ss >> word;
			newnode->punishment += word;
			newnode->punishment += " ";
			ss >> word;
			newnode->punishment += word;
			ss >> word;
			//cout << word<<endl;
			newnode->fine = word;
			if (curr1 == nullptr) {
				newnode->next = nullptr;
				newnode->previous = nullptr;
				CCIDh = newnode;
				curr1 = CCIDh;
			//	cout << "ff" << endl;
			}
			else {
				newnode->previous = curr1;
				newnode->next = curr1->next;
				curr1->next = newnode;
				curr1 = newnode;
			//	cout << curr1->cnic<<endl;
			}

		}

		while (getline(f3, line))
		{
			CCND_NODE* newnode = new CCND_NODE;
			istringstream ss(line);
			string word;
			ss >> word;
			newnode->cnic = stoi(word);
			ss >> word;
			newnode->number = word;
			ss >> word;
			newnode->network= word;
			ss >> word;
			newnode->adate= word;
			ss >> word;
			newnode->ddate= word;
			ss >> word;
			newnode->status = word;
			if (curr2 == nullptr) {
				newnode->next = nullptr;
				newnode->previous = nullptr;
				CCNDh = newnode;
				curr2 = CCNDh;
				//cout << "ff" << endl;
			}
			else {
				newnode->previous = curr2;
				newnode->next = curr2->next;
				curr2->next = newnode;
				curr2 = newnode;
				//cout << curr2->number<<endl;
			}

		}*/
	}
	void opp() {
		fstream f1;
		fstream f2;
		fstream f3;
		string line;
		f1.open("CBID.txt");
		f2.open("CCID.txt");
		f3.open("CCND.txt");
		CBID_NODE* curr = CBIDh;
		CCID_NODE* curr1 = CCIDh;
		CCND_NODE* curr2 = CCNDh;
		while (getline(f1, line))
		{
			CBID_NODE* newnode = new CBID_NODE;
			istringstream ss(line);
			string word;
			ss >> word;
			newnode->cnic = stoi(word);
			ss >> word;
			newnode->name = word;
			ss >> word;
			newnode->fname = word;
			ss >> word;
			newnode->gender = word;
			ss >> word;
			newnode->address = word;
			newnode->address += " ";
			ss >> word;
			newnode->address += word;
			newnode->address += " ";
			ss >> word;
			newnode->address += word;
			ss >> word;
			newnode->nationality = word;
			if (curr == nullptr) {
				newnode->next = nullptr;
				newnode->previous = nullptr;
				CBIDh = newnode;
				curr = CBIDh;
				//cout << "ff" << endl;
			}
			else {
				newnode->previous = curr;
				newnode->next = curr->next;
				curr->next = newnode;
				curr = newnode;
				//cout << curr->cnic<<endl;
			}
		}

		while (getline(f2, line))
		{
			CCID_NODE* newnode = new CCID_NODE;
			istringstream ss(line);
			string word;
			ss >> word;
			int f = 0;
			newnode->cnic = stoi(word);
			ss >> word;
			newnode->charges = word;
			ss >> word;
			if (word.length() < 3) {
				newnode->punishment = word;
				newnode->punishment += " ";
				ss >> word;
			}
			newnode->punishment += word;
			newnode->punishment += " ";
			ss >> word;
			newnode->punishment += word;
			newnode->punishment += " ";
			ss >> word;
			newnode->punishment += word;
			ss >> word;
			//cout << word<<endl;
			newnode->fine = word;
			if (curr1 == nullptr) {
				newnode->next = nullptr;
				newnode->previous = nullptr;
				CCIDh = newnode;
				curr1 = CCIDh;
				//	cout << "ff" << endl;
			}
			else {
				newnode->previous = curr1;
				newnode->next = curr1->next;
				curr1->next = newnode;
				curr1 = newnode;
				//	cout << curr1->cnic<<endl;
			}

		}

		while (getline(f3, line))
		{
			CCND_NODE* newnode = new CCND_NODE;
			istringstream ss(line);
			string word;
			ss >> word;
			newnode->cnic = stoi(word);
			ss >> word;
			newnode->number = word;
			ss >> word;
			newnode->network = word;
			ss >> word;
			newnode->adate = word;
			ss >> word;
			newnode->ddate = word;
			ss >> word;
			newnode->status = word;
			if (curr2 == nullptr) {
				newnode->next = nullptr;
				newnode->previous = nullptr;
				CCNDh = newnode;
				curr2 = CCNDh;
				//cout << "ff" << endl;
			}
			else {
				newnode->previous = curr2;
				newnode->next = curr2->next;
				curr2->next = newnode;
				curr2 = newnode;
				//cout << curr2->number<<endl;
			}

		}
		f1.close();
		f2.close();
		f3.close();
	}
	/*Return a string in following format "Name FName Gender Address Nationality Crimes(if any) Charges punishment fine number network activation_date deactivation_date status"
	 Refer to test cases for further clerification*/
	T CBID_Search_by_CNIC(int cnic) {

		string ans = "";
		CBID_NODE* curr = CBIDh;
		return CBIDh->name;
		//cout<<curr->cnic<<endl;
		while (curr && curr->cnic != cnic)
		{
			curr = curr->next;
		}
		if (curr != nullptr) {
			//cout << curr->cnic << endl;
			ans += curr->name;
			ans += " ";
			ans += curr->fname;
			ans += " ";
			ans += curr->gender;
			ans += " ";
			ans += curr->address;
			ans += " ";
			ans += curr->nationality;
			CCID_NODE* curr1 = CCIDh;
			while (curr1 && curr1->cnic != cnic)
			{
				curr1 = curr1->next;
			}
			if (curr1 != nullptr) {
				ans += " ";
				ans += curr1->charges;
				ans += " ";
				ans += curr1->punishment;
				ans += " ";
				ans += curr1->fine;
			}
			CCND_NODE* curr2 = CCNDh;
			while (curr2 && curr2->cnic != cnic)
			{
				curr2 = curr2->next;
			}
			if (curr2 != nullptr) {
				ans += " ";
				ans += curr2->number;
				//cout << curr2->number << "  thi" << endl;
				ans += " ";
				ans += curr2->network;
				ans += " ";
				ans += curr2->adate;
				ans += " ";
				ans += curr2->ddate;
				ans += " ";
				ans += curr2->status;
			}
		}
		return ans;
	}
	T CCID_Search_by_CNIC(int cnic) {
		string ans = "";
		CBID_NODE* curr = CBIDh;
		//cout<<curr->cnic<<endl;
		while (curr && curr->cnic != cnic)
		{
			curr = curr->next;
		}
		if (curr != nullptr) {
			//cout << curr->cnic << endl;
			ans += curr->name;
			ans += " ";
			ans += curr->fname;
			ans += " ";
			ans += curr->gender;
			ans += " ";
			ans += curr->address;
			ans += " ";
			ans += curr->nationality;
			CCID_NODE* curr1 = CCIDh;
			while (curr1 && curr1->cnic != cnic)
			{
				curr1 = curr1->next;
			}
			if (curr1 != nullptr) {
				ans += " ";
				ans += curr1->charges;
				ans += " ";
				ans += curr1->punishment;
				ans += " ";
				ans += curr1->fine;
			}
			CCND_NODE* curr2 = CCNDh;
			while (curr2 && curr2->cnic != cnic)
			{
				curr2 = curr2->next;
			}
			if (curr2 != nullptr) {
				ans += " ";
				ans += curr2->number;
				//cout << curr2->number << "  thi" << endl;
				ans += " ";
				ans += curr2->network;
				ans += " ";
				ans += curr2->adate;
				ans += " ";
				ans += curr2->ddate;
				ans += " ";
				ans += curr2->status;
			}
		}
		return ans;
	}
	T CCND_Search_by_CNIC(int cnic) {

		return CBID_Search_by_CNIC(cnic);
	}

	bool updateCBIDName(T Name, int cnic) {
		/*update and return true when cnic found else return false*/
		CBID_NODE* curr = CBIDh;
		while (curr && curr->cnic != cnic) {
			curr = curr->next;
		}
		if (!(curr)) {
			return false;
		}
		else {
			curr->name = Name;
			cout << curr->name << endl;
			return true;
		}
	}

	bool updateCBIDFName(T Father_Name, int cnic) {
		/*update and return true when cnic found else return false*/
		CBID_NODE* curr = CBIDh;
		while (curr && curr->cnic != cnic) {
			curr = curr->next;
		}
		if (!(curr)) {
			return false;
		}
		else {
			curr->fname = Father_Name;
			cout << curr->fname << endl;
			return true;
		}
	}

	bool updateCBIDAddress(T Address, int cnic) {
		CBID_NODE* curr = CBIDh;
		while (curr && curr->cnic != cnic) {
			curr = curr->next;
		}
		if (!(curr)) {
			return false;
		}
		else {
			curr->address = Address;
			cout << curr->address << endl;
			return true;
		}
	}

	bool updateCBIDNationality(T Nationality, int cnic) {
		CBID_NODE* curr = CBIDh;
		while (curr && curr->cnic != cnic) {
			curr = curr->next;
		}
		if (!(curr)) {
			return false;
		}
		else {
			curr->nationality = Nationality;
			cout << curr->nationality << endl;
			return true;
		}
	}
	bool addCrime(int cnic, T charges, T punishment, T fine) {
		CBID_NODE* curr = CBIDh;
		CCID_NODE* cg = CCIDh;
		while (curr && curr->cnic != cnic) {
			curr = curr->next;
		}
		if (!(curr)) {
			return false;
		}

		else {//add new node
			while (cg->next) {
				cg = cg->next;
			}
			CCID_NODE* newnode = new CCID_NODE;
			newnode->cnic = cnic;
			newnode->fine = fine;
			newnode->charges = charges;
			newnode->punishment = punishment;
			newnode->previous = cg;
			newnode->next = cg->next;
			cg->next = newnode;
			cg = newnode;
			cout << cg->first << endl;
			return true;
		}
	}

	bool updateCrime(int cnic, T charges, T punishment, T fine) {
		CCID_NODE* curr = CCIDh;
		while (curr && curr->cnic != cnic) {
			curr = curr->next;
		}
		if (!(curr)) {
			return false;
		}
		else {
			curr->cnic = cnic;
			curr->charges = charges;
			curr->punishment = punishment;
			curr->fine = fine;
			cout << curr->cnic << curr->charges << curr->punishment << endl;
			return true;
		}
	}

	bool deleteCrime(int cnic, T charges, T punishment, T fine) {//dete node
		/*update and return true when crime found else return false*/
		CCID_NODE* curr = CCIDh;
		while (curr && curr->cnic != cnic)
		{
			curr = curr->next;
		}
		if (curr) {
			CCID_NODE* old = curr;
			//bunch of code
			old->previous->next = old->next;
			old->next->previous = old->previous;
			curr = old->previous;
			delete old;
			return true;
		}
		else {
			return false;
		}
	}

	int addNumber(int cnic, int number) {
		int numbe = 0;
		CCND_NODE* curr = CCNDh;
		CCND_NODE* st = curr;
		while (curr->next) {
			if (curr->cnic == cnic) {
				numbe++;
				st = curr;
			}
			curr = curr->next;
		}
		if (numbe < 5) {
			CCND_NODE* newnode = new CCND_NODE;
			newnode->cnic = cnic;
			newnode->adate = st->adate;
			newnode->ddate = st->ddate;
			newnode->network = st->network;
			newnode->status = st->status;
			newnode->number = number;
			newnode->next = nullptr;
			newnode->previous = curr;
			curr->next = newnode;
			curr = newnode;
			numbe++;
		}
		/*return number of cell-numbers registered on given cnic after adding this number*/
		return numbe;
	}

	int checkRegistred_No(int cnic) {
		int number = 0;
		/*return number of cell-numbers registered on given cnic*/
		CCND_NODE* curr = CCNDh;
		while (curr->next) {
			if (curr->cnic == cnic) {
				number++;
			}
			curr = curr->next;
		}
		return number;
	}

	CCND_NODE& swap(T cnic, T cnic1, T number, T number1) {//only ccnd

		return;
	}

	AD& declareAlien() {
		/*For Implementation of this function, Refer to CBID point 'iv', CCID point 'vi' and CCND point 'vii'. Also,
		write test-cases for this function yourself*/
		CBID_NODE* curr = CBIDh;
		while (curr && curr->nationality != "Alien") {
			curr = curr->next;
		}
		CBID_NODE* temp = new CBID_NODE;

		// Put top pointer reference into temp link  
		/*temp->link = top;

		// Make temp as top of Stack
		top = temp;*/
		return;//top;
	}

	bool verifyAlienDBUpdate(T cnic, AD) {
		/*Verify that given CNIC is moved from CBID to AD, Also add test-case for this function yourself*/
	}

	int printcount() {//currindex
		int total = 0;
		/*Print count of cell phone numbers registered on each network. For example: (Telenor= 10, Jazz= 5, Ufone= 8, Zong= 9, Total= 32)
		 Return total*/
		CCND_NODE* curr = CCNDh;
		while (curr)
		{
			curr = curr->next;
			total++;
		}
		return total;
	}
	void Display_AD() {
		/*Display data as instructed in point (xiv) of PDF*/
	}

	~Database() {
		/* deallocate and cleanup */
		CBID_NODE* curr = CBIDh;
		CCID_NODE* curr1 = CCIDh;
		CCND_NODE* curr2 = CCNDh;
		while (curr) {
			CBID_NODE* old = curr;
			curr = curr->next;
			delete old;
		}
		while (curr1) {
			CCID_NODE* old = curr1;
			curr1 = curr1->next;
			delete old;
		}
		while (curr2) {
			CCND_NODE* old = curr2;
			curr2 = curr2->next;
			delete old;
		}
	}
};

#endif
