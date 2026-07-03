// sizeof.c - useing the sizeof() operator to find byte size
// sizeof() returns an integer value
// format specifier is: %zu

#include <stdio.h>

// haven't met structs yet but is list of different data type variables
// just shows that sizeof works on structs as a whole single thing
struct person {char name[50]; int age; float height;};

int main(){
    int num = 1234567890;
    float dec = 0.123456;
    double ext = 0.0123456789;
    char ltr ='A';
    char str[] = "something to write home about...";

    // initialise struct called boy
    struct person boy;

    printf("Size of num int is %zu bytes \n", sizeof(num));
    printf("Size of dec float is %zu bytes \n", sizeof(dec));
    printf("Size of ext double is %zu bytes \n", sizeof(ext));
    printf("Size of ltr char is %zu bytes \n", sizeof(ltr));
    printf("Size of str string is %zu bytes \n", sizeof(str));

    // this is 60 bytes (name[50] + int + float = 60 bytes)
    printf("Size of boy struct is %zu bytes \n", sizeof(boy));

    return 0;
}