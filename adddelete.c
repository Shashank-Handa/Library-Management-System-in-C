#include "library.h"
void addBookInDataBase()
{
    headMessage("Add New Book");
    int days;
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME, "ab+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    printf("\n\n\t\t\tADD NEW BOOKS\n");
    printf("\n\n\t\t\tENTER DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tBook ID NO  = ");
    fflush(stdin);
    scanf("%u", &addBookInfoInDataBase.books_id);
    do
    {
        printf("\n\t\t\tBook Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.bookName, MAX_BOOK_NAME, stdin);
        status = isNameValid(addBookInfoInDataBase.bookName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    } while (!status);
    do
    {
        printf("\n\t\t\tAuthor Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.authorName, MAX_AUTHOR_NAME, stdin);
        status = isNameValid(addBookInfoInDataBase.authorName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    } while (!status);
    addBookInfoInDataBase.availability=1;
    fwrite(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
    printf("\n\n\n\t\t\tEntry Successful\n\n\n");
    printf("\n\t\t\tPress any key to got to Main Menu...");
    getchar();
}
void deleteBooks()
{
    headMessage("Delete Book");
    int found = 0;
    int bookDelete = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    int status = 0;

    fp = fopen(FILE_NAME, "rb");
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
    scanf("%d", &bookDelete);
    while (fread(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if (addBookInfoInDataBase.books_id != bookDelete)
        {
            fwrite(&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found) ? printf("\n\t\t\tBook Removed successfully.....") : printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin", FILE_NAME);
    printf("\n\t\t\tPress any key to got to Main Menu...");
    getchar();
}
