// calling functions outside main() - starting all in one source file

#include <cassert>
#include <iostream>
#include <print>
#include <sstream>


// test function
void test_code(){

    int x = 1;

    // assert checks conditionals and aborts if false
    assert(x == 1);

}

// functions whcih accept parameters (parameters are a stream type, like user input, but doesn't need to wait for user input)
// function which passes by value (x is copied, and this copy is changed. x remains the same)
int pass_by_value(int x){
    x = x*2;
    return x;
}

// function which passes by refreence (x is passed directly and can be changed)
int pass_by_reference(int &x){
    x = x*2;
    return x;
}

// will now make a get_number function - extracts numbers from stream
// this can use a different stream rather than waiting for user input with std::cin  
// therefore the function needs at least one parameter taking in a stream so it can extract numbers from stream

// std::istream accepts std::cin or std::stringstream (as in test_code)  
// need to pass BY REFERENCE as we will be changing the stream directly and changing number 
bool get_number(std::istream &input_stream, double &number){

    input_stream >> number; // input stream into (>>) number (so this essentially converts input stream chars to a double type)

    if (input_stream) // true means a number has passed into input_stream
    {
        return true;
    }
    else 
    {
        return false;
    }
}


void test_get_num(){

        double value{};
         
        // remember, stream is something that moves things into/out of an internal buffer
        // and a buffer is what is read/written to with >> and << etc. 
        // and is basically a single contiguous character sequence to be processed  
        // std::stringstream type allows us to pass in a stream without needing user input like iostream stuff 
        std::stringstream some_input{"1"}; // needs {} as explicit 
        const bool ok = get_number(some_input, value);

        assert(ok);
        assert(value == 1);

        // new - pg. 29
        double unused{};
        std::stringstream bad_input{"q"}; // something non-numeric into stream
        const bool not_ok = get_number(bad_input, unused); // (fails)
        assert(!not_ok); // should be assert !false as not_ok should be 'false' from get_number  

}


int main(){

    // calls the test_code function above
    test_code();

    // initialise an int to assess passing by value and passing by reference
    int number1 = 25;
    std::println(" ");
    std::println("------------Passing by value and reference-------------");
    std::println("Number 'number1' declared and initialised as: {}", number1);

    pass_by_value(number1);
    std::println("pass_by_value() - doubles *a copy* of an int inside function with (int x), so `number1` stays as: {}", number1);

    pass_by_reference(number1);
    std::println("pass_by_reference() - actually doubles the int inside function with (& int x), so `number1` is now: {}", number1);
    std::println(" ");
    std::println("------------Testing get_number() function-------------");

    // test_get_num() - pages 28-32ish
    test_get_num();

    // now running get_number directly in main too  
    double number{};
    std::println("Please enter a number"); // works as std::istream &input_stream in get_number() accepts std::cin as input

    // output if get_number worked - std::cin as input
    if(get_number(std::cin, number)) 
    {
        std::println("Got number: {}, thanks!", number);  
        // this above confused me a lot - turns out when passing by reference with &number, the 'number'
        // variable in get_number() is literally the same object, so not in the local scope of the function  
        // hence it doesn't need to be returned out of get_number() but can still be accessed here  
        // this change is essentially written straight back to 'number' in main() without returning number 

    }
    else
    {
        // re-trying but need to clear and empty stream first as non-doubles will be left over in stream if above failed  
        // CARRY ON PAGE 35
        std::println("Something went wrong!");
        std::println("Please enter a number"); 
        if(get_number(std::cin, number)) 
        {
            std::println("Got number: {}, thanks!", number); 
        }
}