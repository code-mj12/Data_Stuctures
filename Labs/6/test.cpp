#include "pch.h"
#include <iostream>
using namespace std;
#include "../Project4/Stack.h"
#include "../Project4/queue.h"
#include "../Project4/Palin.h"
TEST(Q1, alpha) {
	//string str = "alpha";
	string re = "ahpla";
	Stack<string>fr(5);
	fr.push("a");
	fr.push("l");
	fr.push("p");
	fr.push("h");
	fr.push("a");
	EXPECT_EQ(fr.reverse(), re);
	EXPECT_TRUE(true);
}

TEST(Q1, right) {
	//string str = "right";
	string re = "thgir";
	Stack<string>fr(5);
	fr.push("r");
	fr.push("i");
	fr.push("g");
	fr.push("h");
	fr.push("t");
	EXPECT_EQ(fr.reverse(), re);
	EXPECT_TRUE(true);
}

TEST(Q2, tr) {
	Stack<char>sr(4);

	EXPECT_EQ(sr.isBalance("[[(]"), 1);
	EXPECT_TRUE(true);
}

TEST(Q2, tr1) {
	Stack<char>sr(4);

	EXPECT_EQ(sr.isBalance("{[(){}]}"), 1);
	EXPECT_TRUE(true);
}

TEST(Q2, fl) {
	Stack<char>sr(2);

	EXPECT_EQ(sr.isBalance("[[}]"), 0);
	EXPECT_TRUE(true);
}

TEST(Q3, palintrue) {
	string b = "daad";
	Palin a(b);
	EXPECT_EQ(a.check(), 1);
	EXPECT_TRUE(true);
}
TEST(Q3, palintrue2) {
	string b = "racecar";
	Palin a(b);
	EXPECT_EQ(a.check(), 1);
	EXPECT_TRUE(true);
}
TEST(Q3, palinlfalse) {
	string b = "biol";
	Palin a(b);
	EXPECT_EQ(a.check(), 0);
	EXPECT_TRUE(true);
}