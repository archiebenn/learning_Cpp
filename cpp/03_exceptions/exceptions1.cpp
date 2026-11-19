// catching errors with exceptions and try etc.  
// page 46 +

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

    // CONTINUE PAGE 46
    if(input_stream){
        return number;
    }

    // NEW PART
    throw std::exception{}; // throws an exceptions - default initialised with {}
}


int main(){

    // testing with stringstream 
    // std::stringstream test{"abc"};

    std::println("Enter a double");
    double output_num{};
    output_num = get_number(std::cin);

    std::println("Got {}, thanks!", output_num);

}


/*
Fine
03_exceptions git:(main) ✗ ./exceptions1 
343

Exception error
➜  03_exceptions git:(main) ✗ ./exceptions1
abc
libc++abi: terminating due to uncaught exception of type std::exception: std::exception
[1]    43965 abort      ./exceptions1
*/