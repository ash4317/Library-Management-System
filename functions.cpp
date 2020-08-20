/*
 * This file contains all the function definitions which are mentioned in the header file "functions.h"
*/

#include<bits/stdc++.h>
#include "myUser.h"
#include "myBook.h"
#include "functions.h"
using namespace std;

int calcFine(string x) {
    // This function calculates fine that the user has to pay (if any)
    int mm, yy, dd, MM, YY, DD, flag = 0;
    // dd, mm, yy is the date, month and year of the date of issue
    dd = (x[0] - '0')*10 + (x[1] - '0');
    mm = (x[3] - '0')*10 + (x[4] - '0');
    yy = (x[6] - '0')*1000 + (x[7] - '0')*100 + (x[8] - '0')*10 + (x[9] - '0');
    /* the following is used to get the current date using time_t variables.
     * YY - current year, MM - current month, DD - current day
    */
    time_t a = time(0);
    tm *b = localtime(&a);
    YY = 1900 + b->tm_year;
    MM = 1 + b->tm_mon;
    DD = b->tm_mday;
    // flag is set if the date of return has passed and fine is applicable
    if(mm == 12) {
        yy++;
        mm = 01;
    }
    else {
        mm++;
    }
    if(yy < YY) {
        flag = 1;
    }
    else {
        if(mm < MM) {
            flag = 1;
        }
        else {
            if(dd < DD) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        }
    }
    // the following calculates the fine. To see the charges, please read the "ABOUT PROJECT" file
    if(flag == 1) {
        if(yy == YY) {
            if(mm == MM) {
                return (DD - dd)*5;
            }
            else {
                if(dd == DD) {
                    return (MM - mm)*150;
                }
                else if(dd > DD) {
                    return ((MM - mm)*150  + (DD - dd)*5);
                }
                else {
                    return ((MM - mm)*150 + (DD - dd)*5);
                }
            }
        }
        else {
            return 3000;
        }
    }
    else {
        return 0;
    }
}

void createUser(vector<user> &v) {
    // function to create a user
    user x;
    x.getUserData(v.size());
    v.push_back(x);
}

void login(vector<user> &v, vector<book> &u) {
    // login function of a registered user
    string input;
    int flag = 0, k = 0;
    cout << "\nEnter your registered name: ";
    getline(cin, input);
    int index;
    for(unsigned int i = 0; i < v.size(); i++) {
            // for loop to find whether entered name is registered or not
        if(v[i].getUserName() == input) {
            flag++;
            index = i;
            break;
        }
    }
    if(flag == 1) {
        cout << "\nWelcome back " << v[index].getUserName() << ".\n";
        cout << "User ID: " << v[index].getUserId() << endl;
        if(v[index].getOverdue() == 1) {
            // this message will be displayed if fine is applicable
            cout << "\nYou have not returned your book till the return date. Please return it asap to avoid increase in your fine !\n";
        }
        cout << "1 for issuing a book\n2 for returning a book\n0 for logout: ";
        cin >> k;
        while(k) {
            switch(k) {
            case 1:
                v[index].bookIssue(u);  // function for book issue
                break;
            case 2:
                v[index].bookReturn(u); // function for returning the current book (if any)
            }
            cout << "1 for issuing a book\n2 for returning a book\n0 for logout: ";
            cin >> k;
        }
    }
    else {
        cout << "User not registered.\n";
    }
}

void init(vector<user> &v, vector<book> &u) {
    // initialization function which will read the files "users.txt" and "books.txt" to get the users and books list
    cout << "Initializing ...\n\n";
    ifstream finu, finb;
    finu.open("users.txt", ios::in);
    book b;
    user x;
    string uname;
    getline(finu, uname);
    while(uname != "") {
            // following code is such because of the format in which the user data is written in the file "users.txt"
        string bname, c, date;
        int uid, bid, bflag, overdue, fine;
        finu >> uid;
        getline(finu, c);
        finu >> bflag;
        getline(finu, c);
        getline(finu, bname);
        finu >> bid;
        getline(finu, c);
        getline(finu, date);
        finu >> overdue;
        getline(finu, c);
        finu >> fine;
        getline(finu, c);
        b.setBookData(bname, bid, date);
        x.setUserData(uname, uid, bflag, b, overdue, fine);
        v.push_back(x);
        getline(finu, uname);
    }
    finu.close();
    finb.open("books.txt", ios::in);
    string name;
    getline(finb, name);
    while((name != "") && (finb)) {
        // following code is such because of the format in which the user data is written in the file "books.txt"
        string c, date;
        int id;
        finb >> id;
        getline(finb, c);
        getline(finb, date);
        b.setBookData(name, id, date);
        u.push_back(b);
        getline(finb, name);
    }
    finb.close();
}

void update(vector<user> &v, vector<book> &u) {
    // function that will write the updated vectors values into "users.txt" and "books.txt" for future reference
    cout << "Updating ...\n\n";
    ofstream foutb, foutu;
    foutu.open("users.txt", ios::out);
    for(unsigned int i = 0; i < v.size(); i++) {
        foutu << v[i].getUserName() << endl;
        foutu << v[i].getUserId() << endl;
        foutu << v[i].getHasBook() << endl;
        book b;
        b = v[i].getBook();
        foutu << b.getBookName() << endl;
        foutu << b.getBookId() << endl;
        foutu << b.getIssueDate() << endl;
        foutu << v[i].getOverdue() << endl;
        foutu << v[i].getFine() << endl;
    }
    foutu.close();
    foutb.open("books.txt", ios::out);
    for(unsigned int i = 0; i < u.size(); i++) {
        foutb << u[i].getBookName() << endl;
        foutb << u[i].getBookId() << endl;
        foutb << u[i].getIssueDate() << endl;
    }
    foutb.close();
}
