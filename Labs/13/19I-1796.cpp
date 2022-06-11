#include<iostream>
using namespace std;

class BST {

    struct node {
        int data;
        int height;
        node* left;
        node* right;
    };

    node* root;
    int h = 1;
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
        else {
            return t;
        }
        
        t->height = 1 + max(height(t->left),
            height(t->right));

        int balance = getBalance(t);



        // Left Left Case  
        if (balance > 1 && x < t->left->data)
            return rr(t);

        // Right Right Case  
        if (balance < -1 && x > t->right->data)
            return lr(t);

        // Left Right Case  
        if (balance > 1 && x > t->left->data)
        {
            t->left = lr(t->left);
            return rr(t);
        }

        // Right Left Case  
        if (balance < -1 && x < t->right->data)
        {
            t->right = rr(t->right);
            return lr(t);
        }

        /* return the (unchanged) node pointer */
        return t;

    }

 /*   void inorder(node* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }*/
    void preorder(node* t) {
        if (t == NULL) {
            return;
        }
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
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

    node* minValueNode(node* node1)
    {
        node* current = node1;

        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
            current = current->left;

        return current;
    }
    node* deleteNode(node* root, int key)
    {

        // STEP 1: PERFORM STANDARD BST DELETE  
        if (root == NULL)
            return root;
 
        if (key < root->data)
            root->left = deleteNode(root->left, key);

       // in right subtree  
        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        // This is the node to be deleted  
        else
        {
            // node with only one child or no child  
            if ((root->left == NULL) ||
                (root->right == NULL))
            {
                node* temp = root->left ?
                    root->left :
                    root->right;

                // No child case  
                if (temp == NULL)
                {
                    //cout << "A";

                    temp = root;
                    root = NULL;
                }
                else // One child case  
                    *root = *temp; 
                free(temp);
            }
            else
            {

                node* temp = minValueNode(root->right);

                root->data = temp->data;

                // Delete the inorder successor  
                root->right = deleteNode(root->right,
                    temp->data);
            }
        }


        if (!(root == NULL)){}
        else{
            return root;
        }
        root->height = 1 + max(height(root->left),
            height(root->right));

        int balance = getBalance(root);
 

        // Left Left Case  
        if (balance > 1 &&
            getBalance(root->left) >= 0)
            return rr(root);

        // Left Right Case  
        if (balance > 1 &&
            getBalance(root->left) < 0)
        {
            root->left = lr(root->left);
            return rr(root);
        }

        // Right Right Case  
        if (!(balance < -1 && getBalance(root->right) <= 0)){}
        else{
            return lr(root);
        }
        // Right Left Case  
        if (!(balance < -1 && getBalance(root->right) > 0)){}
        else{
            root->right = rr(root->right);
            return lr(root);
        }

        return root;
    }


public:
    BST() {
        root = NULL;
    }

    ~BST() {    }

 
    void deletenode(int x) {
        deleteNode(root, x);
    }


    void insert(int x) {
        root = insert(x, root);
    }

    int reth() {
        return h;
    }
    void display() {
        preorder(root);
        cout << endl;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int height(node* N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

    node* rr(node* y)
    {
        node* x = y->left;
        node* T2 = x->right;

        // Perform rotation  
        x->right = y;
        y->left = T2;

        // Update heights  
        y->height = max(height(y->left),height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root  
        return x;
    }
    node* lr(node* x)
    {
        node* y = x->right;
        node* T2 = y->left;

        // Perform rotation  
        y->left = x;
        x->right = T2;

        // Update heights  
        x->height = max(height(x->left),
            height(x->right)) + 1;
        y->height = max(height(y->left),
            height(y->right)) + 1;

        // Return new root  
        return y;
    }
    int getBalance(node* N)
    {
        if (!(N == NULL)){}
        else{
            return 0;
        }
        return height(N->left) - height(N->right);
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
    cout << "Pre-order display" << endl;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.display();

    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(10);
    t.display();

    t.insert(8);
    t.insert(7);
    t.insert(9);
    t.display();


    t.deletenode(11);
    t.deletenode(10);
    t.deletenode(9);
    t.deletenode(6);
    t.display();

    t.deletenode(8);
    t.deletenode(7);
    t.display();

    t.deletenode(2);
    t.deletenode(3);
    t.deletenode(4);
    t.deletenode(5);
    t.display();

    t.deletenode(1);
    cout << "Last node deleted";
    //cout << "25 val is there" << t.retrive(25) << " hieght " << t.reth();
    return 0;
}