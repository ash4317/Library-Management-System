/* Please read the "ABOUT PROJECT" text file to gain some insight on the project. THANK YOU. */

#include<bits/stdc++.h>
/* 3 user defined header and source files are created which include all the class and function definitions required for this project. */
#include "functions.h"
#include "myUser.h"
#include "myBook.h"
using namespace std;

int main() {
    vector<user> userInfo;  // a vector that will store the information about all the registered users
    vector<book> bookInfo;  // a vector that will store the information about all the books that have not been issued yet
    /*
    *  This is an initialization function. During the start of the program, this function will read the files "users.txt" and "books.txt".
    *  It will store the contents in the two vectors. Throughout the project, these vectors will be manipulated.
    */
    init(userInfo, bookInfo);
    int k;
    cout << "0 for exit\n1 for login\n2 for creating new user: ";
    cin >> k;
    while(k) {
        switch(k) {
        case 1:
            getchar();
            login(userInfo, bookInfo);      // for login of registered user
            break;
        case 2:
            getchar();
            createUser(userInfo);           // for creating a user
            break;
        default:
            cout << "\nInvalid operation.\n";
        }
        cout << "\n0 for exit\n1 for login\n2 for creating new user: ";
        cin >> k;
    }
    update(userInfo, bookInfo);             // the manipulated vector data is written back to the files "users.txt" and "books.txt" for future reference
    cout << "\nTHANK YOU!\n";
    return 0;
}
