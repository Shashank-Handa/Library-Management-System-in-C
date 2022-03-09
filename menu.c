#include "library.h"

void initialize()
{
    char choice;
    printf("\n\t\t\tDatabase file does not exist. Create new database file? (Y/N)");
    scanf("%c",&choice);
    if (choice=='Y')
    {
        fclose(fopen(FILE_NAME,"w"));
    }
    else
    {
        printf("\n\t\t\tPlace database file in program folder and relaunch program");
        exit(1);
    }
}

void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t%s",message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void menu()
{
    int choice = 0;
    do
    {
        headMessage("Main Menu");
        printf("\n\n\n\t\t\t1.Add Book");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.New Borrowal");
        printf("\n\t\t\t5.Delete Book");
        printf("\n\t\t\t6.Book return");
        printf("\n\t\t\t7.View Borrowed Books");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBookInDataBase();
            break;
        case 2:
            searchBooks();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            borrow();
            break;
        case 5:
            deleteBooks();
            break;
        case 6:
            returnal();
            break;
        case 7:
            viewBorrowedBooks();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
    } while (choice != 0);
}