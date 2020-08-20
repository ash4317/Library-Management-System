/*
 * This source file contains all the class function definitions of the class "book". Class book is present in the header file "myBook.h"
*/

#include<bits/stdc++.h>
#include "myBook.h"
using namespace std;

book ::book() {
    // constructor for a book object
    bookName = "none";
    bookId = 0;
    issueDate = "none";
}

void book ::setBookData(string a, int b, string c) {
    // sets book data
    bookName = a;
    bookId = b;
    issueDate = c;
}

string book ::getBookName() {
    return bookName;
}

int book ::getBookId() {
    return bookId;
}

string book ::getIssueDate() {
    return issueDate;
}

void book ::setDate(string x) {
    // sets issue date
    issueDate = x;
}

book ::~book() {}
