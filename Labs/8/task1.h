#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int day;
	int month;
	int year;
	Date(){}
	Date(int val1, int val2, int val3)
	{
		this->day = val1;
		this->month = val2;
		this->year = val3;
	}
};

class EmployeeID
{
public:
	int start;
	int end;
	friend bool operator== (EmployeeID id1, EmployeeID id2)
	{
		return (id1.start == id2.start && id1.end == id2.end);
	}
};

struct Node {
	EmployeeID emp_id;
	string NIC;
	Date jdate;
	int salary;
	int bonus;
	Node* next;
};

class List {
	Node* head;
public:
	List() {
		head = NULL;
	}
	bool isEmpty() {
		return head == NULL;
	}
	void insert(int index, EmployeeID x, string n)  {
		if (index < 0) return ;
		int currIndex = 1;
		Node* currNode = head;
		while (currNode && index > currIndex) {
			currNode = currNode->next;
			currIndex++;

		}
		if (index > 0 && currNode == NULL) return ;
		Node* newNode = new Node;
		newNode->emp_id.end= x.end;
		newNode->emp_id.start = x.start;
		newNode->jdate.day = 11;
		newNode->jdate.month = 11;
		newNode->jdate.year = 2011;
		newNode->NIC = n;
		if (index == 0) {
			newNode->next = head;
			head = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}
	void remove(EmployeeID x) {
		Node* prev = nullptr;
		Node* curr = head;
		int index = 1;
		while (!(curr->emp_id == x)) {
			prev = curr;
			curr = curr->next;
			index++;
		}
		if(curr)
			if (prev) {
				prev->next = curr->next;
				delete curr;
			}
			else {
				head = curr->next;
				delete curr;
			}
	}
	void UpdateSalary(int sal, EmployeeID id) {
		Node* curr = head;
		int currid = 1;
		while (curr && (!(curr->emp_id == id)) ) {
			curr = curr->next;
			currid++;
		}
		curr->salary = sal;
	}
	void UpdateBonus(int bon, EmployeeID id) {
		Node* curr = head;
		while (curr && (!(curr->emp_id == id)) ) {
			curr = curr->next;
		}
		curr->bonus = bon;
	}
	void clear() {
		Node* curr=head;
		while (curr) {
			Node* olnode = curr;
			curr = curr->next;
			delete olnode;
		}
	}
	void display() {
		Node* curr=head;
		while(curr->next ){
			cout <<"NIC: "<<curr->NIC<< "   EMP-id: " << curr->emp_id.start<<"i-"<<curr->emp_id.end << "  Salary: " << curr->salary << "  Bonus: " << curr->bonus<<" Date: "<<curr->jdate.day<<"/"<<curr->jdate.month << "/" << curr->jdate.year << endl << endl << endl;
			curr = curr->next;
		}
	}
	void Dsort(){
		Node* currNode = head, * index = NULL;
		if (head == NULL) return;

		while (currNode != NULL) {
			index = currNode->next;
			while (index != NULL)
			{
				if (currNode->salary < index->salary) {
					int temp = currNode->salary;
					EmployeeID te = currNode->emp_id;
					int tb = currNode->bonus;
					string tn = currNode->NIC;
					currNode->salary = index->salary;
					currNode->bonus = index->bonus;
					currNode->emp_id = index->emp_id;
					currNode->NIC = index->NIC;
					index->salary = temp;
					index->emp_id = te;
					index->bonus = tb;
					index->NIC = tn;
				}
				index = index->next;
			}
			currNode = currNode->next;
		}
	}

	~List(){
		Node* curr = head;
		while (curr) {
			Node* olnode = curr;
			curr = curr->next;
			delete olnode;
		}
	}
};