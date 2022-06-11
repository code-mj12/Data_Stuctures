#pragma once
#include<iostream>
#include<functional>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
#include<string>
#include<fstream>
using namespace std;


template <typename T>
class node {
public:
    int key;
    T value1;
    int height;
    node<T>* left;
    node<T>* right;
    node(int k, T v) {
        value1 = v;
        height = 1;
        key = k;
        left = NULL;
        right = NULL;// .txt file will be made here
        cout << "inserted" << endl;

    }
    void print() {
        cout << "height  " << height << "fff  " << key << endl;
    }
};

template <typename T>
class AVL {
public:

    node<T>* root = NULL;
    int n;
    void insert(int x, T v) {
        root = insertUtil(root, x, v);
    }
    void remove(int x) {
        root = removeUtil(root, x);
    }
    node<T>* search(int x) {
        return searchUtil(root, x);
    }
    void inorder() {
        inorderUtil(root);
        cout << endl;
    }
private:
    int height(node<T>* head) {
        if (head == NULL) return 0;
        return head->height;
    }
    node<T>* rightRotation(node<T>* head) {
        node<T>* newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    node<T>* leftRotation(node<T>* head) {
        node<T>* newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    void inorderUtil(node<T>* head) {
        if (head == NULL) return;
        inorderUtil(head->left);
        cout << head->key << " " << head->value1 << " ->";
        inorderUtil(head->right);
    }

    node<T>* insertUtil(node<T>* head, int x, T v) {
        if (head == NULL) {
            //  cout << "yes";
            n += 1;
            node<T>* temp = new node<T>(x, v);
            return temp;
        }
        //cout << "ghty";
        if (x < head->key) head->left = insertUtil(head->left, x, v);
        else if (x > head->key) head->right = insertUtil(head->right, x, v);
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1) {
            if (x < head->left->key) {
                return rightRotation(head);
            }
            else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1) {
            if (x > head->right->key) {
                return leftRotation(head);
            }
            else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node<T>* removeUtil(node<T>* head, int x) {
        if (head == NULL) return NULL;
        if (x < head->key) {
            head->left = removeUtil(head->left, x);
        }
        else if (x > head->key) {
            head->right = removeUtil(head->right, x);
        }
        else {
            node<T>* r = head->right;
            if (head->right == NULL) {
                node<T>* l = head->left;
                delete(head);
                head = l;
            }
            else if (head->left == NULL) {
                delete(head);
                head = r;
            }
            else {
                while (r->left != NULL) r = r->left;
                head->key = r->key;
                head->right = removeUtil(head->right, r->key);
            }
        }
        if (head == NULL) return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1) {
            if (x > head->left->key) {
                return rightRotation(head);
            }
            else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1) {
            if (x < head->right->key) {
                return leftRotation(head);
            }
            else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node<T>* searchUtil(node<T>* head, int x) {
        if (head == NULL) return NULL;
        int k = head->key;
        if (k == x) return head;
        if (k > x) return searchUtil(head->left, x);
        if (k < x) return searchUtil(head->right, x);
    }
};