// exceptions 3
// page 52 - builds on exceptions2.cpp with new exception types

/*
script:
1. defines get_number() - this takes in input stream, 
                        parses this to a double if possible, 
                        if number is negative, throws exception 1
                        if non-numeric input, throws exception 2

2. main() then calls get_number() - this tries to assign output_num to the input stream values via get_number  
                                    exception block if errors above occut during main()  
*/

#include <istream>
#include <iostream>
#include <sstream>
#include <print>
#include <stdexcept>


// get number function, now only accepting non-negatives!
double get_number(std::istream &input_stream){

    double number{};
    input_stream >> number; 

    // testing how it deals with "1a" etc.
    std::println("\nNumber parsed from input stream = {}, fail = {}", number, input_stream.fail());

    // add in the non-negative condition after taking in a double
    if(input_stream){
        
        if (number >= 0.0){ // n.b could compare double >= 0 (an int), as c++ does *implicit conversion* of int to double, but it's often better to be explicit
            return number;
        }
        // NEW - new exception type from the <stdexcept> lib header
        // exception 1: thrown if number IS a double BUT non-negative
        // n.b std::invalid_argument is a type of std::exception so this will proceed to the std::exception catch block
        // UNLESS a std::invalid_argument catch block appears BEFORE the general std::exception block
        throw std::invalid_argument("Please provide a non-negative number");
    }
    else{
        // clear stream as in functions.cpp - 
        std::cin.clear(); // clears stream error
        std::cin.ignore(    // ignore lefover characters in stream  
            std::numeric_limits<std::streamsize>::max(),  // ignore up to the stream's maximum possible size (guaranteed FULL ignore/reset)  
            '\n' // or until reaches newline
        );

        // exception 2: thrown if non-double if entered i.e. non-numeric  
        throw std::exception{}; 
    }
}


int main(){

    // testing with stringstream 
    // std::stringstream test{"abc"};

    std::println("Enter a double");
    double output_num{65}; // initialise to non-0 here for testing

    // NEW PART - try catch block
    try
    {
        // try code scope
        output_num = get_number(std::cin);
        // will exit before get_number() completes if an exception is thrown

        // will print if no exceptions thrown
        std::cout << "\nGot " << output_num << ", thanks!\n";
    }
    // catches std::invalid_argument exception if thrown (tjis needs to come before the more generic std::exception catch block below)
    catch(const std::invalid_argument &ex)
    {
        // prints out the string error message we wrote (.what() accesses it)
        std::cout << "ERROR=non-negative: " << ex.what() << '\n'; 
    }
    // catches generic throw std::exception if it is thrown - executes this block if so
    catch(const std::exception &ex) // const and reference (can't change exception 'e', and doesn't copy it either)
    {
        // handling code scope
        std::cout << "ERROR=non-numeric: " << ex.what() << '\n'; // (default with vscode block)
    }

}
