#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

// header file which consists of all the functions apart from the class functions

#include<bits/stdc++.h>
#include "myBook.h"
#include "myUser.h"
using namespace std;

int calcFine(string x);
void createUser(vector<user> &v);
void login(vector<user> &v, vector<book> &u);
void init(vector<user> &v, vector<book> &u);
void update(vector<user> &v, vector<book> &u);

#endif // FUNCTIONS_H_INCLUDED
