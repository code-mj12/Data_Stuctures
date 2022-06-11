#pragma once
#include<iostream>
#include<functional>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
#include<string>
#include<fstream>
#include "../DS-Project/avl.h"
using namespace std;



template <typename T>
class rTable {
    //    Machinenode<T> val;
    rTable<T>* next;
    rTable<T>* previous;
};


template <typename T>
class Machinenode {
public:
    int id;
    AVL<T> avl;
    rTable<T> rt;
    Machinenode<T>* next;

};

//mn->avl.insert()
template <typename T>
class Machinelist {
    Machinenode<T>* head;
public:
    Machinelist() {
        head = NULL;
    }

    bool chkIs(int is, int val) {
        if (val < pow(2, is))
            return true;
        else
            return false;
    }

    void selectionSort(int a[], int n) {
        int i, j, min, temp;
        for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++)
                if (a[j] < a[min])
                    min = j;
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    void create(int x, int am, int is) {
        ofstream file;
        int a;
        int index = 0;
        Machinenode<T>* curr;
        srand(time(0));
        int arr[10];
        for (int i = 0; i < x; i++)
        {
            Machinenode<T>* newNode = new Machinenode<T>();
            if (am == 0) {
                //manualy assigning it(temp for singly)
                string filename = "";
                cout << "id of machine: ";
                cin >> a;
                if (!(chkIs(is, a))) {
                    i--;
                    cout << "value not stored please enter again" << endl;
                    continue;
                }
                newNode->id = a;
                string x = to_string(a);
                filename = x + "machine.txt";
                file.open(filename);
                file.close();
                if (i == 0) {
                    head = newNode;
                    newNode->next = head;

                }
                else {
                    curr = head;
                    while (curr->next != head) {            //here
                        curr = curr->next;
                    }
                    curr->next = newNode;
                    newNode->next = head;
                    //cout << head->next->id <<"ffffff"<< endl;
                }
            }
            else {
                int v1 = rand() % int(pow(2, is));
                for (int j = 0; j < i; j++)
                {
                    if (arr[j] == v1)
                        v1 = rand() % int(pow(2, is));
                }
                arr[i] = v1;
                cout << "automaticaly assigning it" << v1 << endl;
            }

        }

        if (am != 0) {
            //sort array
            //cout << "dfff" << endl;
            selectionSort(arr, x);
            for (int i = 0; i < x; i++)
            {
                cout << arr[i] << "->";
            }
            for (int i = 0; i < x; i++)
            {
                Machinenode<T>* newNode = new Machinenode<T>();
                newNode->id = arr[i];
                ofstream file;
                string filename = "";
                string x = to_string(arr[i]);
                filename = x + "machine.txt";
                file.open(filename);
                file.close();
                if (i == 0) {

                    head = newNode;
                    newNode->next = head;
                }
                else {
                    curr = head;
                    while (curr->next != head) {//here
                        curr = curr->next;
                    }
                    curr->next = newNode;
                    newNode->next = head;
                    //cout << head->next->id <<"ffffff"<< endl;
                }
            }
        }
    }

    int givemid(int mid) {
        Machinenode<T>* curr1 = head;
        int arr[10];
        int i = 0;
        while (curr1->next != head) {
            arr[i] = curr1->id;
            i++;
            curr1 = curr1->next;
        }
        arr[i] = curr1->id;

        for (int j = 0; j <= i; j++)
        {
            if (arr[j] == mid) {
                return mid;
            }
        }
        while (1) {
            int gh;
            cout << "Pleae enter valid mid" << endl;
            cin >> gh;
            for (int j = 0; j <= i; j++)
            {
                if (arr[j] == gh) {
                    return gh;
                }
            }
        }

    }

    void print() {
        Machinenode<T>* curr = head;
        // cout << "fff" << head->id << endl;
        while (curr->next != head) {
            cout << "ID: " << curr->id << endl;
            curr = curr->next;
        }
        cout << "ID: " << curr->id << endl;
    }

    void addvalue(int key, T val, int m_id) {
        Machinenode<T>* curr = head;

        cout << "YOUR hashed key is: " << key << endl;

        while (curr->next != head) {//here
            //cout << "MKKKKK" << endl;
            if (curr->id == m_id) {
                cout << "Using Machine id_" << curr->id << " reached" << endl;
                break;
            }
            curr = curr->next;
            if (curr->next == head) {
                cout << "Using Machine id_" << head->id << " reached" << endl;
            }
        }
        int u_id = curr->id;
        //here
        int amu = 0;
        // cout << "currid" << curr->id<< " headid" << head->id <<" mid"<< m_id <<" key"<< key << endl;

        if (key < m_id && key >= head->id) {
            cout << "first";
            while (curr->next->id != u_id) {
                cout << curr->id << " ->";
                if (curr->next->id == head->id) {
                    amu = 1;
                    //cout << "amu is 1" << endl;
                }
                if (amu == 1) {
                    if (key <= curr->next->id) {
                        //cout << "some errror big mistake";
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.insert(key, val);
                        curr = curr->next;
                        break;
                    }
                }
                curr = curr->next;
                if (amu == 1) {
                    if (key <= curr->next->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        //cout << "some errror big mistake2";
                        curr->next->avl.insert(key, val);
                        curr = curr->next;
                        break;
                    }
                }
            }
        }

        else if (key > m_id) {
            cout << "second";
            //if this is head??
            if (curr != head) {
                while (curr->id != head->id) {
                    //cout << "key > m_id";
                    cout << curr->id << " ->";
                    if (curr->next->id == head->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.insert(key, val);
                        curr = curr->next;
                        break;
                    }
                    curr = curr->next;
                    if (key <= curr->id) {
                        cout << curr->id << " ->";
                        curr->avl.insert(key, val);
                        break;
                    }
                    if (curr->next->id == head->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.insert(key, val);
                        curr = curr->next;
                        break;
                    }
                }
            }
            else if (curr == head) {
                cout << "it is head";
                while (curr->next != head) {
                    cout << curr->id << " ->";
                    curr = curr->next;
                    if (key <= curr->id) {
                        //    cout << "comin";
                        cout << curr->id << " ->";
                        curr->avl.insert(key, val);
                        break;
                    }
                    if (curr->id == head->id) {
                        //  cout << "it is being inserted";
                        cout << curr->id << " ->";
                        head->avl.insert(key, val);
                        break;
                    }
                    if (curr->next->id == head->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.insert(key, val);
                        curr = curr->next;
                        break;
                    }
                }
            }
        }

        else if (key == m_id) {
            cout << "third";
            cout << curr->id << " ->";
            curr->avl.insert(key, val);
        }

        else if (key < head->id) {
            cout << "fourth";
            while (curr->id != head->id) {
                cout << curr->id << " ->";
                curr = curr->next;
            }
            cout << curr->id << " ->";
            curr->avl.insert(key, val);
        }

        else {
            cout << "Something Wrong" << endl;
        }
        //curr = curr->next;        made change here

        cout << "CURRRR_ID  " << curr->id << endl;


        ofstream file;
        string filename;
        //int file_no;
        filename = to_string(curr->id) + "machine.txt";
        file.open(filename, ios::app);			//copy
        file << key << "," << val << endl;
        file.close();

    }

    void search(int key, int m_id) {
        Machinenode<T>* curr = head;
        while (curr->next != head) {//here
            if (curr->id == m_id)
                break;
            curr = curr->next;
        }

    }

    void printavl(int m_id) {
        Machinenode<T>* curr = head;
        while (curr->next != head) {//here
            if (curr->id == m_id)
                break;
            curr = curr->next;
        }

        curr->avl.inorder();
    }

    void AddMachine(int m_id) {
        if (m_id < 0) return;
        int currIndex = 1;
        Machinenode<T>* currNode = head;
        while (currNode->next != head && m_id > currNode->id) {     //here
            currNode = currNode->next;
            currIndex++;
        }
        //if (m_id > 0 && currNode == NULL) { 
          //  cout << "ffdss";
            //return; }
        Machinenode<T>* newNode = new Machinenode<T>();
        newNode->id = m_id;
        ofstream file;
        string filename = "";
        string x = to_string(m_id);
        filename = x + "machine.txt";
        file.open(filename);
        file.close();
        //add and remove ids

        Machinenode<T>* curr1 = head;
        while (curr1->next != head) {
            curr1 = curr1->next;
        }


        if (currNode == head) {
            int a = 0;
            int b = m_id;
            for (int i = a; i <= b; i++)
            {
                if (currNode->avl.search(i)) {
                    node<T>* temp = currNode->avl.search(i);
                    newNode->avl.insert(temp->key, temp->value1);
                    currNode->avl.remove(temp->key);
                }
                else {
                    cout << "NULL1";
                }
            }
            newNode->next = head;
            head = newNode;
            curr1->next = head;
        }

        else {
            int a = currNode->id;
            int b = m_id;
            for (int i = a; i <= b; i++)
            {
                if (currNode->next->avl.search(i)) {
                    node<T>* temp = currNode->next->avl.search(i);
                    newNode->avl.insert(temp->key, temp->value1);
                    currNode->next->avl.remove(temp->key);
                }
                else {
                    cout << "NULL2";
                }
            }
            newNode->next = currNode->next;
            currNode->next = newNode;

        }

    }

    void RemMachine(int m_id) {
        Machinenode<T>* prevNode = NULL;
        Machinenode<T>* currNode = head;
        int currIndex = 1;
        while (currNode->next != head && currNode->id != m_id) {  //here

            prevNode = currNode;
            currNode = currNode->next;
            currIndex++;

        }

        Machinenode<T>* curr1 = head;
        while (curr1->next != head) {
            curr1 = curr1->next;
        }

        if (currNode->next == head) {
            if (prevNode) {
                //cout << "doneboss";
                int a = prevNode->id;
                int b = currNode->id;
                a++;
                for (int i = a; i <= b; i++)
                {
                    if (currNode->avl.search(i)) {
                        node<T>* temp = currNode->avl.search(i);
                        currNode->next->avl.insert(temp->key, temp->value1);
                        currNode->avl.remove(temp->key);
                    }
                }
                prevNode->next = currNode->next;
                string filename = to_string(currNode->id) + "machine.txt";
                remove(filename.c_str());
                delete currNode;
            }
        }
        else if (currNode->next != head) {//here
            if (prevNode) {
                cout << "fff";
                int a = prevNode->id;
                int b = currNode->id;
                a++;
                for (int i = a; i <= b; i++)
                {
                    if (currNode->avl.search(i)) {
                        node<T>* temp = currNode->avl.search(i);
                        currNode->next->avl.insert(temp->key, temp->value1);
                        currNode->avl.remove(temp->key);
                    }
                }
                prevNode->next = currNode->next;
                string filename = to_string(currNode->id) + "machine.txt";
                remove(filename.c_str());
                delete currNode;
            }
            else {
                cout << "jjj";
                int a = 0;
                int b = currNode->id;
                for (int i = 0; i < b; i++)
                {
                    if (currNode->avl.search(i)) {
                        node<T>* temp = currNode->avl.search(i);
                        currNode->next->avl.insert(temp->key, temp->value1);
                        currNode->avl.remove(temp->key);
                    }
                }
                head = currNode->next;
                curr1->next = head;
                string filename = to_string(currNode->id) + "machine.txt";
                remove(filename.c_str());
                delete currNode;

            }

        }

        //return 0;
        //remove(filename)
    }

    void removen(int key, int m_id) {
        Machinenode<T>* curr = head;
        while (curr->next != head) {
            if (curr->id == m_id) {
                cout << "Machine " << curr->id << " reached" << endl;
                break;
            }
            curr = curr->next;
        }
        if (curr->id == head->id)
            cout << "Machine " << curr->id << " reached" << endl;

        int u_id = curr->id;
        //here
        cout << "YOUR hashed key is: " << key << endl;

        int amu = 0;
        //cout << "currid" << curr->id << " headid" << head->id << " mid" << m_id << " key" << key << endl;

        if (key < m_id && key >= head->id) {
            //cout << "first";
            while (curr->next->id != u_id) {
                cout << curr->id << " ->";
                if (curr->next->id == head->id) {
                    amu = 1;
                    //cout << "amu is 1" << endl;
                }
                if (amu == 1) {
                    if (key <= curr->next->id) {
                        //cout << "some errror big mistake";
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.remove(key);
                        curr = curr->next;
                        break;
                    }
                }
                curr = curr->next;
                if (amu == 1) {
                    if (key <= curr->next->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        //cout << "some errror big mistake2";
                        curr->next->avl.remove(key);
                        curr = curr->next;
                        break;
                    }
                }
            }
        }

        else if (key > m_id) {
            cout << "second";
            //if this is head??
            if (curr != head) {
                while (curr->id != head->id) {
                    //cout << "key > m_id";
                    cout << curr->id << " ->";
                    if (curr->next->id == head->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.remove(key);
                        curr = curr->next;
                        break;
                    }
                    curr = curr->next;
                    if (key <= curr->id) {
                        cout << curr->id << " ->";
                        curr->avl.remove(key);
                        break;
                    }
                    if (curr->next->id == head->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.remove(key);
                        curr = curr->next;
                        break;
                    }
                }
            }
            else if (curr == head) {
                //cout << "it is head";
                while (curr->next != head) {
                    cout << curr->id << " ->";
                    curr = curr->next;
                    if (key <= curr->id) {
                        //    cout << "comin";
                        cout << curr->id << " ->";
                        curr->avl.remove(key);
                        break;
                    }
                    if (curr->id == head->id) {
                        //  cout << "it is being inserted";
                        cout << curr->id << " ->";
                        head->avl.remove(key);
                        break;
                    }
                    if (curr->next->id == head->id) {
                        cout << curr->id << " ->";
                        cout << curr->next->id << " ->";
                        curr->next->avl.remove(key);
                        curr = curr->next;
                        break;
                    }
                }
            }
        }

        else if (key == m_id) {
            cout << "third";
            cout << curr->id << " ->";
            curr->avl.remove(key);
        }

        else if (key < head->id) {
            cout << "fourth";
            while (curr->id != head->id) {
                cout << curr->id << " ->";
                curr = curr->next;
            }
            cout << curr->id << " ->";
            curr->avl.remove(key);
        }

        else {
            cout << "Something Wrong" << endl;
        }
        //curr = curr->next;


        del_file(curr->id, key);

        /*int hj = 0;
        //if (key >= m_id) {
            while (curr->next != head) {
                if (key < curr->next->id && key > m_id) {
                    curr->next->avl.remove(key);
                    hj = 1;
                    break;
                }           //greater m_id an above
                curr = curr->next;
            }

        //}
        if (key < m_id) {
            while (curr->id != m_id) {
                if (key <= curr->id) {
                    break;
                    hj = 1;
                }
                curr = curr->next;
            }
            curr->avl.remove(key);
        }
        if (hj == 0) {

        }*/
    }

    void del_file(int q, int key1)  //int q is m_id
    {
        ifstream file;
        string key = to_string(key1);
        string val;
        ofstream tmp;
        string search;
        string filename;
        int i = 0;
        string x = to_string(q);
        filename = x + "machine.txt";
        file.open(filename);
        tmp.open("temp.txt", ios::app);
        while (getline(file, val))
        {
            while (val[i] != ',')
            {
                search = search + val[i];
                i++;
            }
            //cout << search << endl;
            i = 0;
            if (!(key.compare(search) != 0)) {}
            else
            {
                tmp << val << endl;
            }
            search = "";
        }
        file.close();
        tmp.close();
        const char* c = filename.c_str();
        remove(c);
        cout << rename("temp.txt", c);
    }

    void printrout(int mid) {

        Machinenode<T>* curr = head;
        while (curr->id != mid) {
            curr = curr->next;
        }
        string h = "mid";
        int amu = 1;
        int p = 31;
        int m = 5 + 9;
        int value = 0;
        int p_pow = 1;
        for (char c : h) {
            value = (value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        cout << "ROUTING TABLE PRINTING FOR MACHINE NO." << mid << endl;
        while (curr != head) {
            if (amu == 1) {
                cout << curr->id << "->";
                amu = 0;
            }
            else {
                amu = 1;
            }
            curr = curr->next;
        }

    }
};

