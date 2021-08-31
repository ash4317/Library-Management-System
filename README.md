# Library-Management-System
Source codes for OOPD project - Library Management System

Project by -
Name: Ashwin Milind Kulkarni<br />
Branch: Electrical Engineering<br />
MIS: 111705010<br />

The project is about "Designing a basic Library Management System". It is a menu-driven program that will perform the following functions :
1) Create a user and store user info in a file for future references
2) Login facility for every registered user so that the user would be able to issue a book and return a book.
3) Can get current date automatically and set it to the date of issue.

Two files are made - "users.txt" and "books.txt" which are databases that store all the user info and book info.
All the manipulations of user info and book info is done into two vectors that read these two files at the start of the program. At the end of the program, the manipulated vector data is written back to these two files so that when this project is run after some time, it will restore the last session data.

Each user can issue ONLY ONE book. To issue another book, the first book has to be returned. The book can be kept for exactly ONE MONTH. If after one month book is not returned, a fine will be charged.

Fine details - Rs. 5 per day. If one year is passed, fine is Rs. 3000 and is fixed.

3 header and their respective source files are made.
1) for class user
2) for class book
3) for other functions
