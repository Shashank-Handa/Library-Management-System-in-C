#include "library.h"
int main()
{
    FILE *fptest;
    fptest=fopen(FILE_NAME,"r");
    if(fptest==NULL) initialize();
    fclose(fptest);
    menu();
    return 0;
}