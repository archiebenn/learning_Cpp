// input_experiment pg. 20 of book  
// testing left over stream buffer values when declaring numbers too big for certain types

#include <iostream>
#include <print>
#include <limits>

int main(){

    const double largest = std::numeric_limits<double>::max();

    // set variable double to 0 ({} = 0)
    double number{};

    std::println("Enter a number smaller than {}", largest);
    std::cin >> number;
    std::println("You entered: {}", number);

    // input streams like std::cin have an eof() function
    // eof() tells you if there are more characters left in the stream asfter an attempt to read
    // however, .eof() on its own will be true regardless if you hit any number + Enter key, as the Enter sends a \n to cin, so std::cin stops at the non numeric \n, so !.eof() alone evalues to True!
    // to fix this, will also add .peek() which looks at the next character in the stream and set this to check if it is a \n or not (\n is one character)
    if(!std::cin.eof() && std::cin.peek() != '\n'){

        // only prints if there is leftover in the stream not caught by number (int) and not a newline character
        std::println("Unused input");

    }

    /*
    ./input_experiment 
    Enter a number smaller than 1.7976931348623157e+308
    a
    You entered: 0
    Unused input

    ./input_experiment 
    Enter a number smaller than 1.7976931348623157e+308
    1a
    You entered: 1
    Unused input
    */

    // as above, a letter entered into the cin stream will lead to Unused input as it is non-numeric
    // alongside eof, stream has a fail function which tells you if input has gone wrong
    //if(std::cin.fail()){
   //     std::cout << "Something went wrong!\n";
   // }

    // but in general, if something has gone wrong there are lots of ways it might have happened. 
    // rather than checking stream functions like 'bad', 'eof', and 'fail' directly, the neater way is simply this
    // (this is a bit of 'syntactic sugar')
    if(std::cin){                                
        std::cout << "And for the second if(stream) example, you entered: " << number << '\n';
    }
    else{
        std::cout << "Bother! It failed\n";
    }

    // if(stream) = shothand for if(stream.operator bool())
    // the stream operator has a bool function which returns 0 or 1 is the stream passes/fails/is good/bad etc. 
    // essentially, the if(stream) checks that the stream is good and would then evaluate to 1/TRue if so
    // but the stream cannot be assigned to a bool data-type
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

./input_experiment 
Enter a number smaller than 2147483647
1
You entered: 1

./input_experiment 
Enter a number smaller than 2147483647
1a
You entered: 1
Unused input

./input_experiment 
Enter a number smaller than 2147483647
a
You entered: 0
Unused input

*/