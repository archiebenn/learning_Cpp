// expectations1 - using std::expected - new to c++23  
// also meet class templates and 'auto' type
// 22-11-26

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
    
    // as get_number will return non-values (string) if it fails to parse, need to check if it has a value/has worked
    if (num.has_value()){
        std::cout << "Retrieved " << num.value() << " from the stream, thanks!\n";
    } 
    else{
        std::cout << num.error();
    }

    // checking number sizes
    std::cout << "\n" << "Ints\t" << std::numeric_limits<int>::min() << "\t"
    << std::numeric_limits<int>::max() << "\n"
    << "Long\t" << std::numeric_limits<long>::min() << "\t"
    << std::numeric_limits<long>::max() << "\n"
    << "Long long\t" << std::numeric_limits<long long>::min() << "\t"
    << std::numeric_limits<long long>::max() << "\n"
    << "Floats\t" << std::numeric_limits<float>::min() << "\t"
    << std::numeric_limits<float>::max() << "\n"
    << "Doubles\t" << std::numeric_limits<double>::min() << "\t" 
    << std::numeric_limits<double>::max() << "\n"
    << "Long doubles\t" << std::numeric_limits<long double>::min() << "\t" 
    << std::numeric_limits<long double>::max() << "\n";

}