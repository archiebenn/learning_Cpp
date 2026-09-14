// calling functions outside main() - starting all in one source file

#include <cassert>

// test function
void test_code(){

    int x = 1;

    // assert checks conditionals and aborts if false
    assert(x == 1);

}

// functions whcih accept parameters (parameters are a stream type, like user input, but doesn't need to wait for user input)
// function which passes by value (x is copied, and this copy is changed. x remains the same)
void a_function(int x){
}

// function which passes by refreence (x is passed directly and can be changed)
void a_function(int & x){
}

// function to get a value
void get_number(){

    

}

int main(){

    // calls the test_code function above
    test_code();
}