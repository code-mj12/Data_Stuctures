/*#pragma once
#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    string stu_no;
    Node* next;
};
Node* top;

class stack {

public:
    void push(string);
    string pop();
    void display();
    bool check() {
        while (top != NULL)
        {
            string a;
            a = pop();
            if (a == pop()) {

            }
            else {
                return false;
            }
        }
        return true;
    }
};

void stack::push(string a)
{
    struct Node* newNode = new Node;
    //fill data part
    for (int i = 0; a[i] != '\0'; i++)
    {
        char  ch = a.at(i);
        std::string s(1, ch);
        //cout << s << endl;
        if (s == "{" || s == "}"  ) {
            newNode->stu_no = a;
        }
    }
    //link part
    newNode->next = top;
    //make newnode as top/head
    top = newNode;
}
string stack::pop()
{
    if (top == NULL) {
        cout << "List is empty!" << endl;
        return 0;
    }
    return top->stu_no;
    top = top->next;
    
}
void stack::display()
{
    if (top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        cout << temp->stu_no << " ";
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}*/
template <typename N>
struct Snode
{
    N data;
    Snode<N>* next;
    Snode(char d)
    {
        data = d;
        next = NULL;
    }
};

template <typename N>
class Stack
{
    Snode<N>* head;

public:


    Stack()
    {
        head = nullptr;
    }

    void push(N data)
    {
        Snode<N>* temp = new Snode<N>(data);
        if (!temp)
        {
            exit(1);
        }
        temp->next = head;
        head = temp;
    }

    N pop()
    {
        Snode<N>* temp;
        if (head == nullptr)
        {
            exit(1);
        }
        else
        {
            temp = head;
            N d = temp->data;
            head = head->next;
            temp->next = nullptr;
            free(temp);
            return d;
        }
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void clear()
    {
        Snode<N>* current;
        Snode<N>* current_next;
        current = head;
        while (current != nullptr)
        {
            current_next = current->next;
            free(current);
            current = current_next;
        }
    }

    ~Stack()
    {}


};
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;


