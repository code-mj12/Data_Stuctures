#include <iostream>
#include <sstream>
#include<fstream>
#include<string>
#include "task.h"
#include "task2.h"
using namespace std;

int main() {
	std::stringstream s("Data Structure and Algo");
	std::string word;
	DynIntQueue que[4];
	DynIntQueue fin2;
	for (int i = 0; i < 4; i++)
	{
		s >> word;
		que[i].broke(word);
		cout << "Q" << i << "=";
		que[i].print();
		cout << endl;
	}
	string ans="";
	for (int i = 0; i<4; i++) {
		for (int j = 0; !(que[i].isEmpty()); j++)
		{
			ans += que[i].dequeue();

		}
		fin2.enqueue(ans);
		//cout << ans;
		ans = "";
	}
	//fin.concat(que, 4);
	fin2.print();

    Stack<char> s1;
    ifstream fil;
    char my_character;
    fil.open("Text1.txt", ios::in);
    while (fil.get(my_character))
    {
        if (my_character == '{')
        {
            s1.push('{');
        }
        if (my_character == '}')
        {
            s1.pop();
        }
    }
    fil.close();
    cout << endl;
    if (s1.isEmpty())
    {
        cout << "Text1 is  Valid" << endl;
    }
    else
    {
        cout << "Text1 is Invalid" << endl;
    }

    Stack<char> s2;
    fil.open("Text2.txt", ios::in);
    while (fil.get(my_character))
    {
        if (my_character == '{')
        {
            s2.push('{');
        }
        if (my_character == '}')
        {
            s2.pop();
        }
    }
    fil.close();

    if (s2.isEmpty())
    {
        cout << "Text2 is in Valid" << endl;
    }
    else
    {
        cout << "Text2 is in Invalid" << endl;
    }

    Stack<char> s3;
    fil.open("Text3.txt", ios::in);
    while (fil.get(my_character))
    {
        if (my_character == '{')
        {
            s3.push('{');
        }
        if (my_character == '}')
        {
            s3.pop();
        }
    }
    fil.close();

    if (s3.isEmpty())
    {
        cout << "Text3 is in  Valid" << endl;
    }
    else
    {
        cout << "Text3 is in Invalid" << endl;
    }



}