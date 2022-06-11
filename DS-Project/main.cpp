#include<iostream>
#include<functional>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
#include<string>
#include<fstream>
#include "../DS-Project/machine.h"
using namespace std;

int hashq(string ar[], int size, int indsize, string mkey) {
    srand(time(0));

    //checking if value exists
    for (int i = 0; i < size; i++)
    {
        if (ar[i] == mkey) {
            return i;
        }
    }

    //generating
    int v1 = rand() % int(pow(2, indsize));
    //checking if value exist on ar[v1]
    if (ar[v1] == "") {
        ar[v1] = mkey;
        return v1;
    }
    else {
        v1 = rand() % int(pow(2, indsize));
        if (ar[v1] == "") {
            ar[v1] = mkey;
            return v1;
        }
        else {
            v1 = rand() % int(pow(2, indsize));
            ar[v1] = mkey;
            //cout << "Manhoosiyat";
            return v1;
        }
    }
}

int main() {

    string array1[50];
    int asiz = 50;
    for (int i = 0; i < 50; i++)
    {
        array1[i] = "";
    }
    //int c;
    //cout << "Please specify the size of identifier space in bits, i.e., 160 bits, 4 bits" << endl;


   // Machinelist<int> ars;
    //ars.create(2);
    //ars.print();

/*    AVL<float> t;
    t.insert(0, 1.3);
    t.insert(1, 2.4);
    t.insert(2, 3.5);
    t.insert(3, 4.6);
    t.insert(4, 5.7);
    t.insert(5, 6.8);
    t.insert(6, 7.9);
    t.inorder();
    t.remove(1);
    t.remove(3);
    t.remove(5);
    t.inorder();
   // node<float> *k;
   // k = t.search(2.4);
   // k->print();
    //option for to specify no. of machine and and identifer space bits
    */
    cout << "Please enter the number of machines" << endl;
    int n, c, d;
    cin >> n;
    cout << "Please specify the size of identifier space in bits, i.e., 160 bits, 4 bits" << endl;
    cin >> c;
    cout << "Do you want assign ids manually(press 0) or automaticaly(press 1) and press enter" << endl;
    cin >> d;
    int fu=10;
    int total_space = pow(2, c);

    int cd = 0;
    Machinelist<string> ars;
    ars.create(n,d,c);
    //done
    //ars.givemid(5);

    while (1) {
        cout <<endl<<"For inserting data press 0" << endl;
        cout << "Option for printing avl tree press 1" << endl;
        cout << "Remove data by you entering key press 2" << endl;
        cout << "Print routing table press 3--work in progress" << endl;//not done
        cout << "ADD machine press 4" << endl;
        cout << "Remove machine press 5----" << endl;
        cout << "Exit press 6" << endl;
        cout << "Path of machines press 7" << endl;
        cin >> fu;

        if (fu == 6) {
            break;
        }
        if (fu == 0) {
            int q;
            string e1,e2;
            cout << "which machine" << endl;
            cin >> q;
            q = ars.givemid(q);
            cout << "Insert key, press ENTER than insert value, press ENTER" << endl;
            cin >> e1;
            cin >> e2;
            //hash<string> hashing; //making object of class;
            //int key1 = (unsigned int)hashing(e1) % total_space; // unsigned int so we don't get a negative value
            int key1 = hashq(array1, asiz, c, e1);
            //Total is the total number of space eg 2^n
            //cout << key1 <<endl<< e1;
            ars.addvalue(key1, e2, q);
            //call function
        }

        if (fu == 1) {
            int af;
            cout << "Enter Machine id for which you want to print" << endl;
            cin >> af;
            af = ars.givemid(af);
            ars.printavl(af);//done
            }

             //removing done
        if (fu == 2) {
            string k;
            int md;
            cout << "enter key and mid" << endl;
            cin >> k;
            cin >> md;
            md = ars.givemid(md);
            //hash<string> hashing; //making object of class;
            //int key1 = (unsigned int)hashing(k) % total_space; // unsigned int so we don't get a negative value
            int key1 = hashq(array1, asiz, c, k);
            //give exact hash key
            ars.removen(key1, md);
        }

        if (fu == 3) {
            int aq;
            cout << "Enter M_id" << endl;
            cin >> aq;
            aq = ars.givemid(aq);
            ars.printrout(aq);
        }

        if (fu == 4) {
            int ml;
            cout << "Which machine to add, Enter M_id" << endl;
            cin >> ml;
            ars.AddMachine(ml);
        }
        // done
        if (fu == 5) {
            int ml;
            cout << "Which machine to remove, Enter M_id" << endl;
            cin >> ml;
            ml = ars.givemid(ml);
            ars.RemMachine(ml);
        }
        
        if (fu == 7) {
            ars.print();
        }
    }
    
    //make circle
    /*string e1;
    int n;
    cin >> e1;
    cin >> n;
    hash<string> hashing; //making object of class;
    int key1 = (unsigned int)hashing(e1) % n; // unsigned int so we don't get a negative value
    //Total is the total number of space eg 2^n
    cout << key1 << endl << e1;
    */

}

