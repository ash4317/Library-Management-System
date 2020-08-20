#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<fstream>
using namespace std;

class book {
    string bookName;
    int bookId;
    string issueDate;
public:
    book() {
        bookName = "none";
        bookId = 0;
        issueDate = "none";
    }
    void setBookData(string a, int b, string c) {
        bookName = a;
        bookId = b;
        issueDate = c;
    }
    string getBookName() {
        return bookName;
    }
    int getBookId() {
        return bookId;
    }
    string getIssueDate() {
        return issueDate;
    }
    void setDate(string x) {
        issueDate = x;
    }
    ~book() {}
};

int calcFine(string x) {
    int mm, yy, dd, MM, YY, DD, flag = 0;
    dd = (x[0] - '0')*10 + (x[1] - '0');
    mm = (x[3] - '0')*10 + (x[4] - '0');
    yy = (x[6] - '0')*1000 + (x[7] - '0')*100 + (x[8] - '0')*10 + (x[9] - '0');
    time_t a = time(0);
    tm *b = localtime(&a);
    YY = 1900 + b->tm_year;
    MM = 1 + b->tm_mon;
    DD = b->tm_mday;
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
    }
    else {
        return 0;
    }
}

class user {
    string userName;
    int userId;
    book b;
    int fine;
    int hasBook;
    int overdue;
public:
    void getUserData(unsigned int n) {
        book a;
        cout << "Enter full name: ";
        getline(cin, userName);
        userId = int(n) + 1;
        b = a;
        hasBook = fine = overdue = 0;
        cout << "Welcome " << userName << ".\nYour user ID is : " << userId << endl;
    }
    void setUserData(string a, int x, int c, book d, int e, int f) {
        userName = a;
        userId = x;
        hasBook = c;
        b = d;
        overdue = e;
        fine = f;
    }
    string getUserName() {
        return userName;
    }
    int getUserId() {
        return userId;
    }
    book getBook() {
        return b;
    }
    int getFine() {
        return fine;
    }
    int getHasBook() {
        return hasBook;
    }
    int getOverdue() {
        return overdue;
    }
    void bookIssue(vector<book> &u) {
        if(hasBook == 0) {
            int n;
            cout << "Book ID : Book Name\n";
            for(unsigned int i = 0; i < u.size(); i++) {
                cout << u[i].getBookId() << " : " << u[i].getBookName() << endl;
            }
            cout << "Enter book ID of the book you want to issue: ";
            cin >> n;
            hasBook = 1;
            for(auto i = u.begin(); i != u.end(); i++) {
                if(i->getBookId() == n) {
                    b.setBookData(i->getBookName(), i->getBookId(), "None");
                    cout << "Book Issued. Book details -\n";
                    cout << "Book name - " << i->getBookName() << "\nBook ID - " << i->getBookId() << endl;
                    u.erase(i);
                    break;
                }
            }
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
            cout << "Date of issue - " << w << endl;
            cout << "Return the book exactly 1 month from today.\nThank you.\n";
            b.setDate(w);
        }
        else {
            cout << "You already have issued a book. Return it to issue a new book.\n";
        }
    }
    void bookReturn(vector<book> &u) {
        if(hasBook == 1) {
            fine = calcFine(b.getIssueDate());
            if(fine != 0) {
                overdue = 1;
                cout << "You are returning your book after the scheduled date of return. Please pay the fine and return the book.\n";
                cout << "Fine: " << fine << endl;
            }
            hasBook = 0;
            overdue = 0;
            fine = 0;
            b.setDate("None");
            u.push_back(b);
            b.setBookData("None", 0, "None");
            cout << "Thank You for returning.\n";
            }
        else {
            cout << "You have not issued any book to return.\n";
        }
    }
};

void createUser(vector<user> &v) {
    user x;
    x.getUserData(v.size());
    v.push_back(x);
}

void login(vector<user> &v, vector<book> &u) {
    string input;
    int flag = 0, k = 0;
    cout << "Enter your registered name: ";
    getline(cin, input);
    int index;
    for(unsigned int i = 0; i < v.size(); i++) {
        if(v[i].getUserName() == input) {
            flag++;
            index = i;
            break;
        }
    }
    if(flag == 1) {
        cout << "Welcome back " << v[index].getUserName() << ".\n";
        cout << "User ID: " << v[index].getUserId() << endl;
        if(v[index].getOverdue() == 1) {
            cout << "You have not returned your book till the return date. Please return it asap to avoid increase in your fine !\n";
        }
        cout << "1 for issuing a book\n2 for returning a book\n0 for exit: ";
        cin >> k;
        while(k) {
            switch(k) {
            case 1:
                v[index].bookIssue(u);
                break;
            case 2:
                v[index].bookReturn(u);
            }
            cout << "1 for issuing a book\n2 for returning a book\n0 for exit: ";
            cin >> k;
        }
    }
    else {
        cout << "User not registered.\n";
    }
}

void init(vector<user> &v, vector<book> &u) {
    ifstream finu, finb;
    finu.open("users.txt", ios::in);
    book b;
    user x;
    string uname;
    getline(finu, uname);
    while(uname != "") {
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
    while(name != "") {
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

int main() {
    vector<user> userInfo;
    vector<book> bookInfo;
    init(userInfo, bookInfo);
    int k;
    cout << "0 for exit\n1 for login\n2 for creating new user: ";
    cin >> k;
    while(k) {
        switch(k) {
        case 1:
            getchar();
            login(userInfo, bookInfo);
            break;
        case 2:
            getchar();
            createUser(userInfo);
            break;
        default:
            cout << "Invalid operation.";
        }
        cout << "0 for exit\n1 for login\n2 for creating new user: ";
        cin >> k;
    }
    update(userInfo, bookInfo);
    cout << "THANK YOU!\n";
    return 0;
}
