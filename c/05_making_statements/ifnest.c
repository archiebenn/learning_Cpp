// ifnest.c - nesting if statements in C
// printf only executed as al 3 are true


#include <stdio.h>

int main(){

    if (5 > 1){

        if ('A' == 'A'){

            if (1 != 100){

                printf("All of these conditions evaluate to true\n");
                printf("5 is greater than 1, A is equal to A, and 1 does not equal 100!\n");
            }
        }
    }

    // another method for the same outcome:

    if ((5 > 1) && ('A' == 'A') && (1 != 100)) {

        printf("\nThe other method using && also works in this case\n");

    } 

    return 0;
}