// input.cpp - accepting input in C++. pg. 15 in book  
// compile with: g++-14 -std=c++23 input.cpp -o input

// one option for input in c++23: still std::cin

// types - e.g with int number = 0;
// brace initialisation = more general approach, such as: int number{}; - this sets it as 0 initially

#include <iostream>
#include <print>
#include <limits>

int main(){

    // output text
    std::println("Please enter a number with decimal places");

    // declares number and uses {} to initialise it to 0
    int number{};
    double leftover{};

    // takes input from stream and stores  
    // here, the int number will take input until a decimal point, then stop. any leftover decimal digits will stay in std::cin awaiting the next read (the next read is leftover and will be captured as leftover is not an int)
    std::cin >> number;
    std::cin >> leftover;

    // output number. in C++, {} are placeholders within the string literal and equivalent to %d etc. in C but for ANY type
    std::println("Number entered when stored as int: {}", number);
    std::println("Leftover of value in stream caught when stored as a double: {}", leftover);

    // pg. 19 testing C++ data type size limits with <limits> header for ints and doubles
    int largest_int = std::numeric_limits<int>::max();
    double largest_double = std::numeric_limits<double>::max();

}

