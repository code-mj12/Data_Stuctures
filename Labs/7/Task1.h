
#include <iostream>
using namespace std;

struct Node {
	int data;
	int index;
	Node* next;
};

class List {
private:
	Node* head;

public:
	List(void) { head = NULL; } // constructor
	
	~List(void) {
		Node* currNode = head;
		Node* nextNode = NULL;
		while (currNode != NULL)
		{
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}

	}// destructor
	
	bool IsEmpty() { return head == NULL; }
	
	Node* InsertNode(int x) {
		int index = x % 10;
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
		newNode->index = index;
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
	int search(int x) {
			Node* currNode = head;
			int currIndex = 1;
			while (currNode && currNode->data != x) {
				currNode = currNode->next;
				currIndex++;
			}
			if (currNode) return currIndex;
			return 0;
	}
	int DeleteNode(double x){
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
		}
		return 0;
	}
	void DisplayList(void){
		int num = 0;
		Node* currNode = head;
		while (currNode != NULL) {
			cout << currNode->data << endl;
			currNode = currNode->next;
			num++;
		}
		cout << "Number of nodes in the list: " << num << endl;
	}

};



int main() {
	List m;
	m.InsertNode(10);
	m.InsertNode(11);
	m.DisplayList();
}