// conditional.c - ?: conditional operator
// works as follows:
// (test expression) ? if-true-do-this : if-false-do-this ;

// used to execute progra, statements according to result of the conditional test

#include <stdio.h>

int main(){

    // initialise (and declare)
    int num1 = 16165, num2 = 71712;
    char letter;

    // num1 divided by 2 remainder != 0 ? true = it's odd : false = it's even!
    ( num1 %2 != 0) ? printf("%d is odd! \n", num1) : printf("%d is even! \n", num1);

    // same again with num2
    ( num2 %2 != 0) ? printf("%d is odd! \n", num2) : printf("%d is even! \n", num2);

    // works for declaring too: letter assigned to Y or N based on the conditional statement (?True:False)
    letter = (num2 %2 != 0) ? 'Y' : 'N';
    printf("Is %d odd? %c \n", num1, letter);

    return 0;
}