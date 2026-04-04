#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
struct Book {
    int id;
    char name[50];
    char author[50];
};

// ---------------- ADMIN LOGIN ----------------
int adminLogin() {
    char username[20], password[20];

    printf("Enter Admin Username: ");
    scanf("%s", username);

    printf("Enter Admin Password: ");
    scanf("%s", password);

    if(strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
        printf("Admin Login Successful!\n");
        return 1;
    } else {
        printf("Invalid Admin Login!\n");
        return 0;
    }
}

// ---------------- ADD BOOK ----------------
void addBook() {
    struct Book b;
    FILE *fp = fopen("books.txt", "a");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    scanf("%s", b.name);

    printf("Enter Author Name: ");
    scanf("%s", b.author);

    fprintf(fp, "%d %s %s\n", b.id, b.name, b.author);

    fclose(fp);
    printf("Book Added Successfully!\n");
}

#include <stdio.h>
#include <string.h
#include "addnewbook.h"
void addnewbook(add_book*b,char*title,char*author,int quantity,float price,int publication_year){
strcpy(b->title,title);
strcpy(b->author,auther);
b->quantity=quantity;
b->price=price;
b->publication_year=publication_year;
printf("Book added successfully!\n");
}
// ---------------- DISPLAY BOOKS ----------------
void displayBooks() {
    struct Book b;
    FILE *fp = fopen("books.txt", "r");

    while(fscanf(fp, "%d %s %s", &b.id, b.name, b.author) != EOF) {
        printf("ID:%d Name:%s Author:%s\n", b.id, b.name, b.author);
    }

    fclose(fp);
}

// ---------------- SEARCH BOOK ----------------
void searchBook() {
    struct Book b;
    int id, found = 0;
    FILE *fp = fopen("books.txt", "r");

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %s %s", &b.id, b.name, b.author) != EOF) {
        if(b.id == id) {
            printf("Found: %d %s %s\n", b.id, b.name, b.author);
            found = 1;
        }
    }

    if(!found)
        printf("Book not found!\n");

    fclose(fp);
}

// ---------------- UPDATE BOOK ----------------
void updateBook() {
    struct Book b;
    int id;
    FILE *fp = fopen("books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %s %s", &b.id, b.name, b.author) != EOF) {
        if(b.id == id) {
            printf("Enter New Name: ");
            scanf("%s", b.name);
            printf("Enter New Author: ");
            scanf("%s", b.author);
        }
        fprintf(temp, "%d %s %s\n", b.id, b.name, b.author);
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    printf("Book Updated!\n");
}

// ---------------- DELETE BOOK ----------------
void deleteBook() {
    struct Book b;
    int id;
    FILE *fp = fopen("books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %s %s", &b.id, b.name, b.author) != EOF) {
        if(b.id != id) {
            fprintf(temp, "%d %s %s\n", b.id, b.name, b.author);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    printf("Book Deleted!\n");
}

#ifndef ADDNEWBOOK_H
#define ADDNEWBOOK_H
struct addnewbook {
    int book_id;
    char title[100];
    char author[100];
    int quantity;
    float price;
    int publication_year;
 };
 void addnewbook(add_book*b,char*title,char*author,int quantity,float price,int publication_year);
 #endif
 #ifndef DIAPLAYBOOK_H
#define DISPLAYBOOK_H
#include <iostream>
#include<string.h>
#include "bookquantityfile.h"
using namespace std;
struct displaybook
{
    char title[100];
    char author[20];
    int book_id;
};
void displayAvailableBooks(const vector<book>& books) {
    cout << "Available Books:" << endl;
    bool found = false;
    for (const auto& b : books) {
        cout << "Book ID: " << b.book_id << endl;
        cout << "Title: " << b.title << endl;
        cout << "Author: " << b.author << endl;
        cout << "Quantity: " << b.quantity << endl;
        cout << "-------------------------" << endl;
        found = true;
    }
}
    if (!found) {
        cout << "No books available." << endl;
    }
}
#endif
#include <stdio.h>  
#include <string>
struct searchforbook
{
    char title[100];
    char author[20];
    int book_id;
};
int main(){
    struct searchforbook searchbook
    printf("enter the book title");
    scanf("%s",searchbook.title);
    printf("enter the book author");
    scanf("%s",searchbook.author);
    printf("enter the book id");
    scanf("%d",&searchbook.book_id);
    return 0;
}
#include <stdio.h>
#include <string.h
#include "addnewbook.h"
void addnewbook(add_book*b,char*title,char*author,int quantity,float price,int publication_year){
strcpy(b->title,title);
strcpy(b->author,auther);
b->quantity=quantity;
b->price=price;
b->publication_year=publication_year;
printf("Book added successfully!\n");
}