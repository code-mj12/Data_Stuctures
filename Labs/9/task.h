#pragma once
#include <iostream>
using namespace std;

class DynIntQueue
{
private:
	struct QueueNode // Structure to define linked list node
	{
		string value;
		QueueNode* next;
	};
	QueueNode* front; // pointer to the first node
	QueueNode* rear; // pointer to the last node
	int numItems; // Number of nodes in the linked list
public:
	DynIntQueue(void);
	~DynIntQueue(void);
	void enqueue(string);
	string dequeue(void);
	bool isEmpty(void);
	void makeNull(void);
	DynIntQueue concat(DynIntQueue arr[], int size) {
		DynIntQueue ret;
		string ans = "";
		for (int i = 0; i < 4; i++)
		{
			while (!(arr[i].isEmpty())) {
				ans += arr[i].dequeue();
			}
			ret.enqueue(ans);
			ans = "";
		}
		return ret;
	}
	void print() {
		QueueNode* curr = front;
		for (int i = 0; i < numItems; i++)
		{
			cout << curr->value << "->";
			curr = curr->next;
		}
	}
	void broke(string a) {
		for (int i = 0; a[i] != '\0' ; i++)
		{
			char  ch = a.at(i);
			std::string s(1, ch);
			//cout << s << endl;
			enqueue(s);
		}
	}
};

DynIntQueue::DynIntQueue(void)
{
	front = nullptr;
	rear = nullptr;
	numItems = 0;
}


bool DynIntQueue::isEmpty(void)
{
	if (numItems)
		return false;
	else
		return true;

}

void DynIntQueue::enqueue(string num)
{
	QueueNode* newNode;
	newNode = new QueueNode;
	newNode->value = num;
	newNode->next = nullptr;
	if (isEmpty()) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	//cout << newNode->value << endl;
	numItems++;
}

string DynIntQueue::dequeue(void)
{
	QueueNode* temp;
	string num;
	if (isEmpty()) {
		cout << "The queue is empty.\n";
	}
	else {
		num = front->value;
		temp = front->next;
		//cout << "The queue is empty.\n";
		delete front;
		front = temp;
		numItems--;
		if (!numItems) rear = nullptr;
	}
	return num;
}

DynIntQueue::~DynIntQueue(void)
{
	makeNull();
}
void DynIntQueue::makeNull(void)
{
	while (!isEmpty()) {
		dequeue();
	}
}