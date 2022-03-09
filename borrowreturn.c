#include "library.h"
void borrow()
{
    headMessage("New Borrowal");
    int found = 0;
    int BookId = 0;
    s_BooksInfo BorrowedBook = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    int status = 0;
    int dateCmpStatus=0;

    fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    tmpFp = fopen("tmp.bin", "wb");
    if (tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }

    printf("\n\t\t\tEnter Book ID NO. :");
    scanf("%d", &BookId);

    while (fread(&BorrowedBook, sizeof(BorrowedBook), 1, fp))
    {
        if (BorrowedBook.books_id != BookId)
        {
            fwrite(&BorrowedBook, sizeof(BorrowedBook), 1, tmpFp);
        }
        else
        {
            if (BorrowedBook.availability)
            {
                do
                {
                    printf("\n\t\t\tBorrower Name  = ");
                    fflush(stdin);
                    fgets(BorrowedBook.studentName, MAX_AUTHOR_NAME, stdin);
                    status = isNameValid(BorrowedBook.studentName);
                    if (!status)
                    {
                        printf("\n\t\t\tName contain invalid character. Please enter again.");
                    }
                } while (!status);

                do
                {
                    printf("\n\t\t\tBorrower mobile Contact number = ");
                    fflush(stdin);
                    scanf("%d", &BorrowedBook.studentContact);
                    status = isNumberValid(BorrowedBook.studentContact);
                    if (!status)
                    {
                        printf("\n\t\t\tInvalid Phone number. Please enter again.");
                    }
                } while (!status);

                do
                {
                    do
                    {
                        //get date year,month and day from user
                        printf("\n\t\t\tEnter book issue date in format (day/month/year): ");
                        scanf("%d/%d/%d", &BorrowedBook.bookIssueDate.dd, &BorrowedBook.bookIssueDate.mm, &BorrowedBook.bookIssueDate.yyyy);
                        //check date validity
                        status = isValidDate(&BorrowedBook.bookIssueDate);
                        if (!status)
                        {
                            printf("\n\t\t\tPlease enter a valid date.\n");
                        }
                    } while (!status);

                    do
                    {
                        //get date year,month and day from user
                        printf("\n\t\t\tEnter book due date in format (day/month/year): ");
                        scanf("%d/%d/%d", &BorrowedBook.bookDueDate.dd, &BorrowedBook.bookDueDate.mm, &BorrowedBook.bookDueDate.yyyy);
                        //check date validity
                        status = isValidDate(&BorrowedBook.bookDueDate);
                        if (!status)
                        {
                            printf("\n\t\t\tPlease enter a valid date.\n");
                        }
                    } while (!status);
                    if (datecomp(BorrowedBook.bookIssueDate,BorrowedBook.bookDueDate)<=0)
                    {
                        printf("\n\t\t\tEntered Due date is on or before issue date");
                        printf("\n\t\t\tPlease enter dates again");
                        dateCmpStatus=0;
                    }
                    else dateCmpStatus=1;
                }
                while(!dateCmpStatus);

                BorrowedBook.availability = 0;
                printf("\n\t\t\tBorrowal Logged");
            }
            else
            {
                printf("\t\t\tRequested Book is currently unavailable.\n");
                printf("\t\t\tBook should be available again on %d-%d-%d", BorrowedBook.bookDueDate.dd, BorrowedBook.bookDueDate.mm, BorrowedBook.bookDueDate.yyyy);
            }
            fwrite(&BorrowedBook, sizeof(BorrowedBook), 1, tmpFp);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("\n\t\t\tBook not found in library");
    }
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin", FILE_NAME);
    printf("\n\t\t\tPress any key to go to main menu...");
    fflush(stdin);
    getchar();
    return;
}

void returnal()
{
    headMessage("Return Book");
    int found = 0;
    int BookId = 0;
    s_BooksInfo BorrowedBook = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    int status = 0;

    fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    tmpFp = fopen("tmp.bin", "wb");
    if (tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }

    printf("\n\t\t\tEnter Book ID NO. :");
    scanf("%d", &BookId);

    while (fread(&BorrowedBook, sizeof(BorrowedBook), 1, fp))
    {
        if (BorrowedBook.books_id != BookId)
        {
            fwrite(&BorrowedBook, sizeof(BorrowedBook), 1, tmpFp);
        }
        else
        {
            if (BorrowedBook.availability)
            {
                printf("\n\t\t\tBook is not currently borrowed");
            }
            else
            {
                fine(BorrowedBook.bookDueDate);
                strcpy(BorrowedBook.studentName, "NULL");
                BorrowedBook.studentContact=0;
                BorrowedBook.bookIssueDate.dd = 0;
                BorrowedBook.bookIssueDate.mm = 0;
                BorrowedBook.bookIssueDate.yyyy = 0;
                BorrowedBook.bookDueDate.dd = 0;
                BorrowedBook.bookDueDate.mm = 0;
                BorrowedBook.bookDueDate.yyyy = 0;
                BorrowedBook.availability=1;
                printf("\n\t\t\tBorrowed Book was successfully returned");
            }
            fwrite(&BorrowedBook, sizeof(BorrowedBook), 1, tmpFp);
            found = 1;
        }
    }
    if(!found) printf("\n\t\t\tRequested book is not in library");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin", FILE_NAME);
    printf("\n\t\t\tPress any key to go to main menu...");
    fflush(stdin);
    getchar();
}
