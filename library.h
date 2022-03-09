#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

//Macros
#define MAX_YR 9999
#define MIN_YR 1900
#define FILE_NAME "S.bin"
// Macro related to the books info
#define MAX_BOOK_NAME 50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_PNUMBER 20
//fine macros
#define MAX_FINE 500
#define RATE_FINE 10

#define FILE_HEADER_SIZE sizeof(sFileHeader)

typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;

typedef struct // to call in program
{
    unsigned int books_id;                   // declare the integer data type
    char bookName[MAX_BOOK_NAME];            // declare the character data type
    char authorName[MAX_AUTHOR_NAME];        // declare the charecter data type
    int availability;                        //1 for available, 0 for borrowed
    char studentName[MAX_STUDENT_NAME];      // declare the character data type
    int studentContact; // declare the character data type
    Date bookIssueDate;
    Date bookDueDate;
} s_BooksInfo;
//Prototypes

int datecomp(Date dayx, Date dayy);
int isNameValid(const char *name);
int isNumberValid(int number);
int IsLeapYear(int year);
int isValidDate(Date *validDate);
void addBookInDataBase();
void deleteBooks();
void borrow();
void searchBooks(void);
void fine(Date DueDate);
void returnal();
void viewBooks();
void viewBorrowedBooks();
void initialize();
void headMessage(const char *message);
void menu();
