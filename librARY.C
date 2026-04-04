
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#define MAX 100

// ------------------ STRUCTURES ------------------

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

struct User {
    int id;
    char name[50];
    char password[20];
};

// ------------------ BOOK FUNCTIONS ------------------

void addBook() {
    FILE *fp = fopen("books.txt", "a");

    struct Book b;

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", b.author);
    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fprintf(fp, "%d %s %s %d\n", b.id, b.title, b.author, b.quantity);

    fclose(fp);
    printf("Book added successfully!\n");
}

void viewBooks() {
    FILE *fp = fopen("books.txt", "r");

    struct Book b;

    printf("\n--- Book List ---\n");

    while (fscanf(fp, "%d %s %s %d", &b.id, b.title, b.author, &b.quantity) != EOF) {
        printf("ID:%d Title:%s Author:%s Qty:%d\n", b.id, b.title, b.author, b.quantity);
    }

    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("books.txt", "r");

    int id, found = 0;
    struct Book b;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.title, b.author, &b.quantity) != EOF) {
        if (b.id == id) {
            printf("Found: %s by %s\n", b.title, b.author);
            found = 1;
        }
    }

    if (!found) printf("Book not found!\n");

    fclose(fp);
}

// ------------------ USER FUNCTIONS ------------------

void registerUser() {
    FILE *fp = fopen("users.txt", "a");

    struct User u;

    printf("Enter User ID: ");
    scanf("%d", &u.id);
    printf("Enter Name: ");
    scanf("%s", u.name);
    printf("Enter Password: ");
    scanf("%s", u.password);

    fprintf(fp, "%d %s %s\n", u.id, u.name, u.password);

    fclose(fp);
    printf("User registered!\n");
}

int loginUser() {
    FILE *fp = fopen("users.txt", "r");

    char name[50], pass[20];
    struct User u;

    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Password: ");
    scanf("%s", pass);

    while (fscanf(fp, "%d %s %s", &u.id, u.name, u.password) != EOF) {
        if (strcmp(name, u.name) == 0 && strcmp(pass, u.password) == 0) {
            fclose(fp);
            return u.id;
        }
    }

    fclose(fp);
    return -1;
}

// ------------------ BORROW / RETURN ------------------

void borrowBook(int userId) {
    FILE *fp = fopen("books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int id;
    struct Book b;

    printf("Enter Book ID to borrow: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.title, b.author, &b.quantity) != EOF) {
        if (b.id == id && b.quantity > 0) {
            b.quantity--;

            FILE *tr = fopen("transactions.txt", "a");
            fprintf(tr, "User %d borrowed Book %d\n", userId, id);
            fclose(tr);

            printf("Book borrowed!\n");
        }
        fprintf(temp, "%d %s %s %d\n", b.id, b.title, b.author, b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");
}

void returnBook(int userId) {
    FILE *fp = fopen("books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int id;
    struct Book b;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.title, b.author, &b.quantity) != EOF) {
        if (b.id == id) {
            b.quantity++;

            FILE *tr = fopen("transactions.txt", "a");
            fprintf(tr, "User %d returned Book %d\n", userId, id);
            fclose(tr);

            printf("Book returned!\n");
        }
        fprintf(temp, "%d %s %s %d\n", b.id, b.title, b.author, b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");
}

// ------------------ MAIN MENU ------------------

int main() {
    int choice, userId;

    while (1) {
        printf("\n==== Library System ====\n");
        printf("1. Register\n2. Login\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser();
        }

        else if (choice == 2) {
            userId = loginUser();

            if (userId == -1) {
                printf("Login failed!\n");
            } else {
                int ch;

                while (1) {
                    printf("\n1. View Books\n2. Borrow\n3. Return\n4. Logout\n");
                    scanf("%d", &ch);

                    if (ch == 1) viewBooks();
                    else if (ch == 2) borrowBook(userId);
                    else if (ch == 3) returnBook(userId);
                    else break;
                }
            }
        }

        else {
            break;
        }
    }

    return 0;
}
