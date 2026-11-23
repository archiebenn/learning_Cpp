// expectations2 - building on excpectations
// 23-11-26

#include <expected>
#include <string>
#include <iostream>
#include <print>
#include <limits>

/*
From stack overflow on exceptions vs expected:

Use exceptions for exceptional, rare, unexpected cases. When possibility that the throw-instruction is really called is low.

Use std::expected for errors that are expected.
*/

/* 
new get_number() which returns a std::expected type
std::expected takes two types - expected and unexpected values
we 'expect' to get a souble out of get_number...
for the unexpected type, we will put a message in a string

this also introduces us to *class templates* 
when a type is in <>, then it's from a class template (i.e from a header)
*/

// want to be able to return an expected (double) and an unexpected (string):
std::expected<double, std::string> get_number(std::istream &user_input){

    // initialise and parse stream to number
    double number{};
    user_input >> number;

    // parse successful - user_input flags change to show this
    if(user_input){
        return number;
    }

    // unexpected string if fails
    return std::unexpected{"That's not a number\n"};
}

int main(){

    std::cout << "Enter a number into the stream\n";

    // can define num as auto so compiler will fill in the type (rather than typing out std::expected<double, std::string> num)
    auto num = get_number(std::cin);
    
    // removes the has_value check in expectations1 to test what error is thrown if non-numeric input
    std::cout << "Retrieved " << num.value() << " from the stream, thanks!\n";

    /*
    Spits out a load of type details ('< >'s) for the std::bad_expected_access type (itself an exception, not expectation)
    essentially this is C++ letting you to let the exception be thrown instead of forcing having to check the expected typn, thanks C++  

    Enter a number into the stream
    lol  
    libc++abi: terminating due to uncaught exception of type std::__1::bad_expected_access<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>: bad access to std::expected
    Retrieved [1]    19283 abort      ./expectations2
    */


}