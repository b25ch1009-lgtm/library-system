Library Management System (C Project)
 About Project
This is a simple Library Management System made using C language.
It is a menu-driven program which helps to manage users and books.
=> Features
# User Part
* Register user
* Login user
* Update user
* Delete user
# Book Part (Admin)
* Add book
* Delete book
* View books
# Other Functions
* Borrow book
* Return book
# Admin Login
Username: admin
Password: admin123
# Files Used
* users.txt (stores user data)
* books.txt (stores book data)
* temp.txt (used for update/delete)
# How to Run
1. Compile the code:
gcc filename.c -o library
2. Run the program:
./library
# What I Learned
* Use of structures in C
* File handling (read/write)
* Menu-driven programs
* Basic project making
# out put format of this code :
===== LIBRARY MANAGEMENT SYSTEM =====
1. Register User
2. Login User
3. Update User
4. Delete User
5. Admin Login
6. View Books
7. Borrow Book
8. Return Book
9. Exit

Enter Choice: 1

Enter User ID: 101
Enter Name: Divya
Enter Password: 1234
User Registered Successfully!
### Admin Login
Enter Choice: 5

Enter Admin Username: admin
Enter Admin Password: admin123

1. Add Book
2. Delete Book
3. Logout

Enter Choice: 1

Enter Book ID: 1
Enter Title: CProgramming
Enter Author: Dennis
Enter Quantity: 5

Book Added Successfully!

# View Books
Enter Choice: 6

---- Book List ----
ID:1  Title:CProgramming  Author:Dennis  Qty:5
#Borrow Book
Enter Choice: 7

Enter Book ID to Borrow: 1
Book Borrowed Successfully!
# Return Book
Enter Choice: 8

Enter Book ID to Return: 1
Book Returned Successfully!
# CONTRIBUTION PART :
This project was developed as a team work. Each member worked on different modules:
1. User Management ( divya b25ph1004)
   * Register User
   * Login User
   * Update User
   * Delete User
2. Book Management(navya b25cs1042)
   * Add Book
   * Delete Book
   * View Books
3. Admin Module( avani b25ch1009)
   * Admin Login
   * Manage Book Operations
4. Borrow and Return System (sahana b25ph1013)
   * Borrow Book
   * Return Book
All modules were combined together to form the complete Library Management System.

