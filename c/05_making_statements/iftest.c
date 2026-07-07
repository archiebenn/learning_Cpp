// iftest.c - just like python
// just asseses BOOL true (1) or false (0)

// syntax in C: if ( test expression ) { code to be exetcuted if true }

#include <stdio.h>

int main() {

    if (5 > 1){     // true

        printf("This is printed because 5 is indeed greater than 1\n");
        printf("Thanks for asking");
    }

    return 0;
}