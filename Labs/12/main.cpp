#include <iostream>
using namespace std;

struct Node {
	int data;
	int index;
	Node* next;
};
int ain=0;
class List {
private:
	Node* head;

public:
	List(void) { head = NULL; } // constructor
	bool IsEmpty() { return head == NULL; }
	Node* InsertNode(int x) {
		int in = x % 10;
		int index = ain++;
		if (index < 0) return NULL;
		int currIndex = 1;
		Node* currNode = head;
		while (currNode && index > currIndex) {
			currNode = currNode->next;
			currIndex++;
		}
		if (index > 0 && currNode == NULL) return NULL;
		Node* newNode = new Node;
		newNode->data = x;
		newNode->index = in;
		if (index == 0) {
			newNode->next = head;
			head = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
		}
		return newNode;

	}
	int search(int x){
		Node* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data != x) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) return currNode->index;

		return 0;
	}
	int DeleteNode(double x) {
		Node* prevNode = NULL;
		Node* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data != x) {

			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {

			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
			ain--;
		}
		return 0;
	}
	void DisplayList(void){
		int num = 0;
		Node* currNode = head;
		while (currNode != NULL) {
			cout << currNode->data <<" and index is " << currNode->index<<endl;
			currNode = currNode->next;
			num++;
		}
	}
	~List(void) {
		Node* currNode = head;
		Node* nextNode = NULL;
		while (currNode != NULL)
		{
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}
	}
};


struct Node2 {
	char data;
	int freq;
	Node2* next;
};
int ain2 = 0;
class List2 {
private:
	Node2* head;

public:
	List2(void) { head = NULL; } // constructor
	Node2* add(char data, int x)
	{
		Node2* newnode = new Node2;
		newnode->data = data;
		newnode->freq = x;
		newnode->next = NULL;
		return newnode;
	}

	Node2* insert(string text)
	{
		head = add(text[0],0);
		Node2* curr = head;
		int freq;
		for (int i = 1; i < text.size(); i++) {
			for (int j = 0; j < text.size(); j++)
			{
				freq = 2;
			}
			curr->next = add(text[i],freq);
			curr = curr->next;
		}
		return head;
	}

	void print()
	{
		Node2* curr = head;
		while (curr != NULL) {
			cout << curr->data << " -> "<<curr->freq<<endl;
			curr = curr->next;
		}
	}
};





int main() {
	cout << "----TASK 1---" << endl;
	List m;
	m.InsertNode(11);
	m.InsertNode(12);
	m.InsertNode(13);
	m.InsertNode(14);
	m.InsertNode(15);
	m.DisplayList();

	cout << "After delete 12" << endl;
	m.DeleteNode(12);
	m.DisplayList();

	cout << "Search 15 index: " << m.search(15) << endl;

	cout << "----Task 2----" << endl;

	string text = "ababcd";
	List2 k;
	k.insert(text);
	k.print();

}