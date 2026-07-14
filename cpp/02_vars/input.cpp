// input.cpp - accepting input in C++. pg. 15 in book  
// compile with: g++-14 -std=c++23 input.cpp -o input

// one option for input in c++23: still std::cin

// types - e.g with int number = 0;
// brace initialisation = more general approach, such as: int number{}; - this sets it as 0 initially

#include <iostream>
#include <print>

int main(){

    // output text
    std::println("Please enter a number");

    // declares number and uses {} to initialise it to 0
    int number{};

    // takes input and stores in variable number
    std::cin >> number;

    // output number. in C++, {} are placeholders within the string literal and equivalent to %d etc. in C but for ANY type
    std::println("Number entered: {}", number);

}

