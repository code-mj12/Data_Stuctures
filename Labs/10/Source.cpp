#include<iostream>
using namespace std;
int f = 0;
class BST {

    struct node {
        int rec;
        int accid;
        string name;
        float bal;
        node* left;
        node* right;
    };

    node* root;
    int h = 1;
    
    node* insert(int x, node* t,string n, float b)
    {
        if (t == NULL)
        {

            t = new node;
            t->accid = x;
            t->rec = f++;
            t->bal = b;
            t->name = n;
            t->left = t->right = NULL;
        }
        else if (x < t->accid) {
            t->left = insert(x, t->left,n,b);
            h++;

        }
        else if (x > t->accid)
            t->right = insert(x, t->right,n,b);
        return t;
    }

    void inorder(node* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout <<t->rec<<"  "<< t->accid << " " << t->name << " " << t->bal << endl;
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if (t == NULL)
            return NULL;
        else if (x < t->accid)
            return find(t->left, x);
        else if (x > t->accid)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {    }

    void insert(int x, string n, float b) {
        root = insert(x, root, n , b);
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
    t.insert(6274,"James",415.56);
    t.insert(2834,"Marcus",9217.23);
    t.insert(4892,"Debra",27.26);
    t.insert(1892,"Mary",918.26);
    t.insert(8837,"Simon",386.85);
    t.display();
    cout << "25 val is there " << t.retrive(25) << " hieght " << t.reth();
    return 0;
}