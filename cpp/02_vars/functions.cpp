// calling functions outside main() - starting all in one source file

#include <cassert>
#include <iostream>
#include <print>


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
int pass_by_reference(int & x){
    x = x*2;
    return x;
}

// will now make a get_number function
// this can use a different stream rather than waiting for user input with std::cin  
// therefore the function needs at least one parameter taking in a stream so it can extract numbers  
// can pass by reference here with &  
// CONTINUE FROM HERE PAGE 27


int main(){

    // calls the test_code function above
    test_code();

    // initialise an int to assess passing by value and passing by reference
    int number1 = 25;
    std::println("Number 'number1' declared and initialised as: {}", number1);

    pass_by_value(number1);
    std::println("pass_by_value() - doubles *a copy* of an int inside function with (int x), so `number1` stays as: {}", number1);
    pass_by_reference(number1);
    std::println("pass_by_reference() - actually doubles the int inside function with (& int x), so `number1` is now: {}", number1);

}