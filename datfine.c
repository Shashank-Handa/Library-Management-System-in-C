#include "library.h"
int datecomp(Date dayx, Date dayy)//ACCOUNT FOR RETURNING BEFORE DUE DATE
{
    int day1 = dayx.dd, mon1 = dayx.mm, year1 = dayx.yyyy;
    int day2 = dayy.dd, mon2 = dayy.mm, year2 = dayy.yyyy;
    int fine,temp;
    int day_diff, mon_diff, year_diff, month_day, year_day, no_of_days;

    if (day2 < day1)
    {

        if (mon2 == 3)
        {

            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
            {
                day2 += 29;
            }

            else
            {
                day2 += 28;
            }
        }

        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)
        {
            day2 += 30;
        }

        else
        {
            day2 += 31;
        }

        mon2 = mon2 - 1;
    }

    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }

    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;


    month_day = mon_diff * 30;
    year_day = year_diff * 365;
    no_of_days = day_diff + month_day + year_day;

    return no_of_days;
}

void fine(Date DueDate)
{
    Date returnDate;
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    int status = 0;
    int fine=0;
    int no_of_days=0;
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter returning date in format (day/month/year): ");
        scanf("%d/%d/%d", &returnDate.dd, &returnDate.mm, &returnDate.yyyy);
        //check date validity
        status = isValidDate(&returnDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    } while (!status);

    no_of_days=datecomp(DueDate, returnDate);
    
    if (no_of_days <= 0 )
    {
        printf("\n\t\t\tThank you for returning on time");
    }
    else if (no_of_days > 0 && no_of_days <= 25)
    {
        printf("\t\t\tDifference: %d days.", no_of_days);
        fine = no_of_days * RATE_FINE;
        printf("\n\t\t\tPlease pay a fine of: %d", fine);
    }
    else if (no_of_days > 25)
    {
        printf("\t\t\tDifference: %d days.", no_of_days);
        printf("\n\t\t\tPlease pay a fine of: %d", MAX_FINE);
    }
    return;
}
