// input_experiment pg. 20 of book  
// testing left over stream buffer values when declaring numbers too big for certain types

#include <iostream>
#include <print>

int main(){

    int number{};

    std::println("Enter a number");
    std::cin >> number;

    // input streams like std::cin have an eof() function
    // eof() tells you if there are more characters left in the stream asfter an attempt to read
    // however, .eof() on its own will be true regardless if you hit any number + Enter key, as the Enter sends a \n to cin, so std::cin stops at the non numeric \n, so !.eof() alone evalues to True!
    // to fix this, will also add .peek() which looks at the next character in the stream and set this to check if it is a \n or not (\n is one character)
    if(!std::cin.eof() && std::cin.peek() != '\n'){

        // only prints if there is leftover in the stream not caught by number (int) and not a newline character
        std::println("Unused input");

    }
}


/*
EXAMPLE RUN

./input_experiment 
Enter a number
646464

./input_experiment 
Enter a number
99999999

./input_experiment 
Enter a number
9999999999
Unused input

./input_experiment 
Enter a number
747474.87733
Unused input

*/