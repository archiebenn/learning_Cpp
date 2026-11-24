// working with while loops in C++ - page 60  

#include <expected>
#include <iostream>
#include <string>

// std::expected<T, E> class template design -> True or Error
// get_number function with expectations (see 03/expectations1.cpp)
std::expected<double, std::string> get_number(std::istream &user_input){

    // initialise and parse stream to number
    double number{};
    user_input >> number;

    // parse successful - user_input flags change to show this
    if(user_input){
        return number;
    }

    // unexpected string if fails
    return std::unexpected{"That's not a number. Exiting...\n"};
}

int main(){

    std::cout << "Please Enter a Number:\n";

    // NEW - while loop
    while (true){

        auto num = get_number(std::cin);
        if (num.has_value()){
        std::cout << "Retrieved " << num.value() << " from the stream, thanks!\n\n" <<
        "Please enter another number:\n";

    } 
    else{
        // print Error string
        std::cout << num.error() << '\n';
        // while (true) so need to explicitly leave
        break; 
    }

    }

}