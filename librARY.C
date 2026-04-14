#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCTURES 

struct User
{
int id;
char name[50];
char password[20];
};

struct Book
{
 int id;
char title[50];
char author[50];
int quantity;
};

//USER FUNCTIONS 

void registerUser()
{
    struct User u;
    FILE *fp = fopen("users.txt","a");

    printf("Enter User ID: ");
    scanf("%d",&u.id);

    printf("Enter Name: ");
    scanf("%s",u.name);

    printf("Enter Password: ");
    scanf("%s",u.password);

    fprintf(fp,"%d %s %s\n",u.id,u.name,u.password);

    fclose(fp);
    printf("User Registered Successfully!\n");
}

void updateUser()
{
    struct User u;
    int id , found =0;

    FILE *fp = fopen("users.txt","r");
    FILE *temp = fopen("temp.txt","w");
    if (fp == NULL){
        printf("No users found\n");
        return ;
    }

    printf("Enter User ID to update: ");
    scanf("%d",&id);

    while

  (fscanf(fp,"%d %s %s",&u.id,u.name,u.password)!=EOF) {
    
    if(u.id==id)
        {
            found = 1;
        
            printf("Enter New Name: ");
            scanf("%s",u.name);

            printf("Enter New Password: ");
            scanf("%s",u.password);

            printf("User Updated!\n");
        }
  }
        fprintf(temp,"%d %s %s\n",u.id,u.name,u.password);
    fclose(fp);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt","users.txt");
    if(!found)
    printf("User ID not found\n");
}

void deleteUser()
{
    struct User u;
    int id , found =0;

    FILE *fp = fopen("users.txt","r");
    FILE *temp = fopen("temp.txt","w");
    if(fp == NULL){
        printf("No users found \n");
        return ;
    }

    printf("Enter User ID to delete: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s",&u.id,u.name,u.password)!=EOF) {
    
        if(u.id!=id)
        {
           fprintf(temp,"%d %s %s /n",u.id,u.name,u.password);
                }
        else 
        {
            found=1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt","users.txt");


    if(found)
    printf("User Deleted Successfully\n");
    else 
    printf("User ID not found\n");
}

int loginUser()
{
    struct User u;
    int id;
    char pass[20];

    FILE *fp = fopen("users.txt","r");

    printf("Enter User ID: ");
    scanf("%d",&id);

    printf("Enter Password: ");
    scanf("%s",pass);

    while(fscanf(fp,"%d %s %s",&u.id,u.name,u.password)!=EOF)
    {
        if((u.id==id && strcmp(u.password,pass))==0)
        {
            fclose(fp);
            printf("Login Successful!\n");
            return id;
        }
    }

    fclose(fp);
    printf("Invalid ID or Password\n");
    return -1;
}

//BOOK FUNCTIONS 

void addBook()
{
    struct Book b;
    FILE *fp = fopen("books.txt","a");

    printf("Enter Book ID: ");
    scanf("%d",&b.id);

    printf("Enter Title: ");
    scanf("%s",b.title);

    printf("Enter Author: ");
    scanf("%s",b.author);

    printf("Enter Quantity: ");
    scanf("%d",&b.quantity);

    fprintf(fp,"%d %s %s %d\n",b.id,b.title,b.author,b.quantity);

    fclose(fp);
    printf("Book Added Successfully!\n");
}

void viewBooks()
{
    struct Book b;
    FILE *fp = fopen("books.txt","r");

    printf("\n---- Book List ----\n");

    while(fscanf(fp,"%d %s %s %d",&b.id,b.title,b.author,&b.quantity)!=EOF)
    {
        printf("ID:%d  Title:%s  Author:%s  Qty:%d\n",
        b.id,b.title,b.author,b.quantity);
    }

    fclose(fp);
}

void deleteBook()
{
    struct Book b;
    int id , found =0;

    FILE *fp = fopen("books.txt","r");
    FILE *temp = fopen("temp.txt","w");
    
    if (fp == NULL)
    {
        printf("NO books available\n");
        return;
    }

    printf("Enter Book ID to delete: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s %d",&b.id,b.title,b.author,&b.quantity)!=EOF) 
   {
        if(b.id!=id)
        {
            fprintf(temp,"%d %s %s %d\n",b.id,b.title,b.author,b.quantity);
        }
        else{
            found=1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt","books.txt");
    
    if(found)
    printf("Book Deleted Successfully\n");
    else
    printf("Book ID not found\n");
}

// BORROW & RETURN 

void borrowBook(int userId)
{
    struct Book b;
    int id, found=0;

    FILE *fp = fopen("books.txt","r");
    FILE *temp = fopen("temp.txt","w");

    printf("Enter Book ID to Borrow: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s %d",&b.id,b.title,b.author,&b.quantity)!=EOF)
    {
        if(b.id==id && b.quantity>0)
        {
            b.quantity--;
            found=1;
            printf("Book Borrowed Successfully!\n");
        }

        fprintf(temp,"%d %s %s %d\n",b.id,b.title,b.author,b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt","books.txt");

    if(!found)
        printf("Book not available\n");
}

void returnBook()
{
    struct Book b;
    int id;

    FILE *fp = fopen("books.txt","r");
    FILE *temp = fopen("temp.txt","w");

    printf("Enter Book ID to Return: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s %d",&b.id,b.title,b.author,&b.quantity)!=EOF)
    {
        if(b.id==id)
        {
            b.quantity++;
            printf("Book Returned Successfully!\n");
        }

        fprintf(temp,"%d %s %s %d\n",b.id,b.title,b.author,b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt","books.txt");
}

//ADMIN LOGIN 

int adminLogin()
{
    char u[20], p[20];

    printf("Enter Admin Username: ");
    scanf("%s",u);

    printf("Enter Admin Password: ");
    scanf("%s",p);

    if(strcmp(u,"admin")==0 && strcmp(p,"admin123")==0)
        return 1;

    return 0;
}

// MAIN 

int main()
{
    int choice, userId=-1;

    while(1)
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Register User\n");
        printf("2. Login User\n");
       
        printf("5. Admin Login\n");
        
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: registerUser(); break;
            case 2: 
            if (userId = loginUser())
            { 
                int ch;
                do {
                    printf("\n 1.Uapdate User \n 2.Delete User \n 3.View Books\n 4.Borrow Books\n 5.Return Book\n 6.Logout \n");
                    scanf("%d",&ch);
                    if(ch==1) updateUser();
                    else if(ch==2) deleteUser();
                    else if(ch==3) viewBooks();
                    else if(ch==4) borrowBook(userId);
                    else if (ch==5) returnBook();
                } while (ch!=6);
                }
                else 
                printf("Invalid User Login \n");
                 break;
            
            
            case 5:
                if(adminLogin())
                {
                    int ch;
                    do {
                        printf("\n1.Add Book\n2.Delete Book\n3.Logout\n");
                        scanf("%d",&ch);

                        if(ch==1) addBook();
                        else if(ch==2) deleteBook();

                    } while(ch!=3);
                }
                else
                    printf("Invalid Admin Login\n");
                break;

            
            case 6: exit(0);

            default: printf("Invalid Choice\n");
        }
    }
}