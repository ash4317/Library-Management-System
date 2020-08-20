#ifndef MYUSER_H_INCLUDED
#define MYUSER_H_INCLUDED

// header file which consists of all the class functions of the class "user"

#include<bits/stdc++.h>
#include "myBook.h"
using namespace std;

class user {
    string userName;
    int userId;
    book b;
    int fine;
    int hasBook;
    int overdue;
public:
    void getUserData(unsigned int n);
    void setUserData(string a, int x, int c, book d, int e, int f);
    string getUserName();
    int getUserId();
    book getBook();
    int getFine();
    int getHasBook();
    int getOverdue();
    void bookIssue(vector<book> &u);
    void bookReturn(vector<book> &u);
};

#endif // MYUSER_H_INCLUDED
