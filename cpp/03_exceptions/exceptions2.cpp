// catching errors with exceptions part II  
// catching an exception after throwing
// page 46 

/*
script:
1. defines get_number() - this takes in input stream, 
                        parses this to a double if possible, 
                        if not it clears stream and throws exception

2. main() then calls get_number() - this tries to assign output_num to the input stream values via get_number  
                                    if get_number fails and throws exception, the catch block runs to show error
*/

#include <istream>
#include <iostream>
#include <sstream>
#include <print>


// get number function, now returning number itself
double get_number(std::istream &input_stream){

    double number{};
    input_stream >> number; // confused me: this >>operator tried to 'parse' a double out of input_stream
                            // once done, input_stream is the same object but based on the success/faiulure of this parse
                            // internal flags are changed (possible as istream is a class!). 
                            // hence if(input_stream) ONLY true if this parse has worked i.e. input is a double here

    // testing how it deals with "1a" etc.
    std::println("number parsed from input stream = {}, fail = {}", number, input_stream.fail());

    // CONTINUE PAGE 46
    if(input_stream){
        return number;
    }
    else{ // error - not a double

        // clear stream as in functions.cpp - 
        std::cin.clear(); // clears stream error
        std::cin.ignore(    // ignore lefover characters in stream  
            std::numeric_limits<std::streamsize>::max(),  // ignore up to the stream's maximum possible size (guaranteed FULL ignore/reset)  
            '\n' // or until reaches newline
        );

        throw std::exception{}; // throws an exception - caught by catch block in main() so this then executes
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
    }
    // // catches the throw exception if it runs! executes this block if so
    catch(const std::exception &e) // const and reference (can't change exception 'e', and doesn't copy it either)
    {
        // handling code scope
        std::cout << "Something went wrong!\n"; 
        std::cerr << e.what() << '\n'; // (default with vscode block)
    }

    // will print 
    std::println("\nGot {}, thanks!", output_num);

}
