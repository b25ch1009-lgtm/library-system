#  Library Management System in C

##  Project Title

**Library Management System**

---

##  Objective

The objective of this project is to design and implement a **menu-driven Library Management System using C programming**.
This project helps in understanding and applying core C concepts such as:

* Structures
* File Handling
* Arrays
* Pointers
* Functions
* Control Statements

---

##  Project Description

This system simulates a real-world **library environment** where two types of users can interact:

1. **Administrator (Librarian)**
2. **Library User (Member)**

The system allows management of:

* Books
* Users
* Transactions (Borrow & Return)

It is a **menu-driven program**, making it user-friendly and interactive.

---

## ⚙️ Features / Functionalities

### 📖 1. Book Management

* Add new books (ID, Title, Author, Publication, Quantity, Category)
* Display all books
* Search books by:

  * Title
  * Author
  * ID
  * Category
* Update book details
* Delete books
* Auto-update quantity on borrow/return

---

###  2. User Management

* Register new users
* View all users
* Edit user details
* Delete users
* User login authentication

---

### 🔄 3. Borrowing & Returning System

* Borrow books (with limit per user)
* Store borrowing & return dates
* Return books and update stock
* View borrowing history

---

###  4. Administrator Features

* Admin login (predefined credentials)
* Manage books and users
* View transaction reports
* Backup system data

---

###  5. File Handling

Data is stored permanently using files:

* `books.txt`
* `users.txt`
* `transactions.txt`

---

##  Sample Output

```
==== Welcome to Library Management System ====
1. Login as User
2. Login as Admin
3. Register as New User
4. Exit
Enter choice: 2

--- Admin Login ---
Username: admin
Password: ****

===== Admin Menu =====
1. Add New Book
2. View All Books
3. Manage Users
4. View Borrow Records
5. Logout

Enter your choice: 1

Enter Book ID: 101
Enter Title: C Programming
Enter Author: Dennis Ritchie
Enter Publication: PHI
Enter Quantity: 5

Book added successfully!
```

---

##  Technologies Used

* **Programming Language:** C
* **Concepts Used:** File Handling, Structures, Functions, Arrays, Pointers

---

## How to Run the Project

1. Open the project in any C compiler (Turbo C / GCC / VS Code)
2. Compile the program:

   ```
   gcc library.c -o library
   ```
3. Run the program:

   ```
   ./library
   ```

---

##  Future Enhancements

* Add GUI (using C++ or Python)
* Online database integration
* Fine calculation for late returns
* Barcode-based book tracking

---

This project is for educational purposes only.
