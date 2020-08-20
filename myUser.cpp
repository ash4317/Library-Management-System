/*
 * This source file contains all the class definitions of the class "user".
 * Definition of class user is done in the header file "myUser.h"
*/

#include<bits/stdc++.h>
#include "myBook.h"
#include "myUser.h"
#include "functions.h"
using namespace std;

void user ::getUserData(unsigned int n) {
    /*
     * This will get the user data and will initialize the rest of the methods of the object.
     * This function also sets a user ID to every registered user
    */
    book a;
    cout << "Enter full name: ";
    getline(cin, userName);
    userId = int(n) + 1;
    b = a;
    hasBook = fine = overdue = 0;
    cout << "Welcome " << userName << ".\nYour user ID is : " << userId << endl;
}

void user ::setUserData(string a, int x, int c, book d, int e, int f) {
    // sets user data
    userName = a;
    userId = x;
    hasBook = c;
    b = d;
    overdue = e;
    fine = f;
}

string user ::getUserName() {
    return userName;
}

int user ::getUserId() {
    return userId;
}

int user ::getHasBook() {
    return hasBook;
}

book user ::getBook() {
    return b;
}

int user ::getFine() {
    return fine;
}

int user ::getOverdue() {
    return overdue;
}

void user ::bookIssue(vector<book> &u) {
    // function for issuing a book
    if(hasBook == 0) {
            // this function will work only if the user does not have any book already issued
        int n, flag = 0;
        cout << "\nBook ID : Book Name\n";
        for(unsigned int i = 0; i < u.size(); i++) {
            cout << u[i].getBookId() << " : " << u[i].getBookName() << endl;
        }
        cout << "\nEnter book ID of the book you want to issue: ";
        cin >> n;
        for(auto i = u.begin(); i != u.end(); i++) {
            if(i->getBookId() == n) {
                b.setBookData(i->getBookName(), i->getBookId(), "None");
                cout << "\nBook Issued. Book details :\n";
                cout << "Book name : " << i->getBookName() << "\nBook ID : " << i->getBookId() << endl;
                flag = 1;
                u.erase(i);
                break;
            }
        }
        if(flag == 1) {
            // if the book is available for issuing, then the function will proceed
            hasBook = 1;
            // YY, MM, DD are used to get the current date which is the date of issuing
            int YY, MM, DD;
            time_t a = time(0);
            tm *c = localtime(&a);
            YY = 1900 + c->tm_year;
            MM = 1 + c->tm_mon;
            DD = c->tm_mday;
            string x, y, z, w;
            x = to_string(YY);
            y = to_string(MM);
            z = to_string(DD);
            if(DD < 10) {
                z = "0" + z;
            }
            if(MM < 10) {
                y = "0" + y;
            }
            w = z + "-" + y + "-" + x;
            cout << "Date of issue : " << w << endl;
            cout << "Return the book exactly 1 month from today.\nThank you.\n\n";
            b.setDate(w);
        }
        else {
            // if book is not available for issuing, it means another user has already issued this book.
            cout << "Looks like the book has already been issued by another user.\n\n";
        }
    }
    else {
        // if book is already issued, the user cannot issue another book
        cout << "You already have issued a book. Return it to issue a new book.\n\n";
    }
}

void user ::bookReturn(vector<book> &u) {
    // function to return a book
    if(hasBook == 1) {
    // if the user has indeed issued a book
    fine = calcFine(b.getIssueDate());  // function to calculate fine (if any)
    if(fine != 0) {
        overdue = 1;
        cout << "You are returning your book after the scheduled date of return. Please pay the fine and return the book.\n";
        cout << "Fine: " << fine << endl;
    }
    hasBook = 0;
    overdue = 0;
    fine = 0;
    b.setDate("None");
    u.push_back(b); // the book is now available for issuing. Hence, it will be pushed to the book info vector
    b.setBookData("None", 0, "None");
    cout << "Thank You for returning.\n\n";
    }
    else {
        cout << "\nYou have not issued any book to return.\n\n";
    }
}
