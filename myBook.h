#ifndef MYBOOK_H_INCLUDED
#define MYBOOK_H_INCLUDED

// header file which consists of all the class functions of the class "book"

#include<bits/stdc++.h>
using namespace std;
class book {
    string bookName;
    int bookId;
    string issueDate;
public:
    book();
    void setBookData(string a, int b, string c);
    string getBookName();
    int getBookId();
    string getIssueDate();
    void setDate(string x);
    ~book();
};

#endif // MYBOOK_H_INCLUDED
