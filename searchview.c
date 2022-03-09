#include "library.h"
void viewBooks()
{
    headMessage("View All Books");
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tBook Count = %d.\n\n",countBook);
        printf("\t\t\tBook id = %u",addBookInfoInDataBase.books_id);
        printf("\n\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        addBookInfoInDataBase.availability?printf("\t\t\tStatus: Available\n"):printf("\t\t\tStatus: Borrowed\n");
        if(!addBookInfoInDataBase.availability)
        {
            printf("\n\t\t\t\tBorrowed by = %s",addBookInfoInDataBase.studentName);
            printf("\n\t\t\t\tBorrower contact number: %d",addBookInfoInDataBase.studentContact);
            printf("\n\t\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookIssueDate.dd,
                    addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
            printf("\n\t\t\t\tBook Due date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookDueDate.dd,
                    addBookInfoInDataBase.bookDueDate.mm, addBookInfoInDataBase.bookDueDate.yyyy);
        }
        found = 1;
        ++countBook;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}

void viewBorrowedBooks()
{    
    headMessage("View Borrowed Books");
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(!addBookInfoInDataBase.availability)
        {
            printf("\n\t\t\tBook Count = %d.\n\n",countBook);
            printf("\t\t\tBook id = %u",addBookInfoInDataBase.books_id);
            printf("\n\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
            printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
            printf("\n\t\t\tBorrowed by = %s",addBookInfoInDataBase.studentName);
            printf("\n\t\t\tBorrower contact number: %d",addBookInfoInDataBase.studentContact);
            printf("\n\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookIssueDate.dd,
                    addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
            printf("\n\t\t\tBook Due date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookDueDate.dd,
                    addBookInfoInDataBase.bookDueDate.mm, addBookInfoInDataBase.bookDueDate.yyyy);
            
            found = 1;
            ++countBook;
        }
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}

void searchBooks(void)
{
    headMessage("Search Books");
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Book Name to search:");
    fflush(stdin);
    fgets(bookName, MAX_BOOK_NAME, stdin);
    while (fread(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if (!strcmp(addBookInfoInDataBase.bookName, bookName))
        {
            found = 1;
            break;
        }
    }
    if (found)
    {
        printf("\t\t\tBook id = %u",addBookInfoInDataBase.books_id);
        printf("\n\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        addBookInfoInDataBase.availability?printf("\t\t\tStatus: Available"):printf("\t\t\tStatus: Borrowed");
        if(!addBookInfoInDataBase.availability)
        {
            printf("\n\t\t\t\tBorrowed by = %s",addBookInfoInDataBase.studentName);
            printf("\n\t\t\t\tBorrower contact number: %d",addBookInfoInDataBase.studentContact);
            printf("\n\t\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookIssueDate.dd,
                    addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
            printf("\n\t\t\t\tBook Due date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookDueDate.dd,
                    addBookInfoInDataBase.bookDueDate.mm, addBookInfoInDataBase.bookDueDate.yyyy);
        }
        printf("\t\t\t");
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}