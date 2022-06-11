#include<iostream>
#include<string>
using namespace std;
int f = 0;


class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;
    int h = 1;


    void makeDeletion(node*& nodePtr) {
        node* tempNodePtr; 
        if (nodePtr->right == NULL) { // case for leaf and one (left) child
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left; // Reattach the left child
            delete tempNodePtr;
        }
        else if (nodePtr->left == NULL) { // case for one (right) child
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right; // Reattach the right child
            delete tempNodePtr;
        }
        else { // case for two children.
            tempNodePtr = nodePtr->right; // Move one node to the right
            while (tempNodePtr->left) { // Go to the extreme left node
                tempNodePtr = tempNodePtr->left;
            }
            tempNodePtr->left = nodePtr->left; // Reattach the left subtree
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right; // Reattach the right subtree
            delete tempNodePtr;
        }
    }

    node* insert(int x, node* t)
    {
        if (t == NULL)
        {

            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data) {
            t->left = insert(x, t->left);
            h++;

        }
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    void inorder(node* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << endl;
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }
    int findlvl(node* t, int val) {
        if (t == nullptr) {
            return NULL;
        }
        else if (val < t->data) {
            return 1 + findlvl(t->left, val);
        }
        else if (val > t->data) {
            return 1 + findlvl(t->right, val);
        }
        else {
            return 0;
        }
    }


    void printf(node* root, int sum, string path) {
        //cout << "GG" << root->data << endl;
        static int e = 0;
        if (root != NULL) {
            if (root->data > sum) { // if root is greater than Sum
                if(e != 1)
                    cout << "No path" << endl;
                return;
            }
            else {
                path += to_string(root->data) + ">-";
                sum = sum - root->data; 
                
                if (sum == 0) {
                    e++;
                    reverse(path.begin(), path.end());
                    cout<<"Path is  " << path << endl;
                }
                //cout << "GG" << path << "ff"<<root->data << endl;
                printf(root->left, sum, path);
                printf(root->right, sum, path);
            }
        }
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {    }

    int flvl(int v) { return findlvl(root, v); }

    void fpr(int v) { printf(root, v, ""); }


    void deleteNode(int num, node*& nodePtr) {
        if (nodePtr == nullptr) 
            cout << num <<" not found "<<endl;
        else if (num < nodePtr->data)
            deleteNode(num, nodePtr->left); 
        else if (num > nodePtr->data)
            deleteNode(num, nodePtr->right); 
        else 
            makeDeletion(nodePtr); 

    }

    void remove(int num) { deleteNode(num, root); }

    void insert(int x) {
        root = insert(x, root);
    }

    int reth() {
        return h;
    }
    void display() {
        inorder(root);
        cout << endl;
    }

    bool retrive(int x) {
        root = find(root, x);
        if (root)
            return true;
        else
            return false;
    }
};

int main() {
    BST t;
    t.insert(3);
    t.insert(2);
    t.insert(1);
    t.insert(8);
    t.insert(6);
    t.display();
    cout << "Deleting 8"<<endl;
    t.remove(8);
    t.display();
    cout << "for 7 path is: ";
    t.fpr(7);

    cout << "for 6 path is: ";
    t.fpr(6);
    cout <<"14 is at level "<< t.flvl(14)<<endl;
    return 0;
}