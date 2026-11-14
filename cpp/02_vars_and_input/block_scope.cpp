// block_scope.cpp - starts on page 37  
// looks at what block scope means simply  
// date: 14-11-26  

#include <iostream>
#include <print>

// example function - void as no return
void quadruple_int(int &x){
    x = x*4;
    // no return as passing x by reference
    // in general, using return might be slightly slower BUT improves readability  
    // and could be considered more 'pure function-like'  
}

int main(){

    // BLOCK 1: 'some_number' is initialised and declared
    {
        std::println("Please enter an integer number to quadruple:");
        int some_number{}; // start as 0
        std::cin >> some_number; 
        quadruple_int(some_number); // quadruples 'some_number'  
        std::println("Output: {}", some_number);
    }

    // BLOCK 2: 'some_number' is again initialised and declared
    // this is only possible as they are in their own 'blocks' scopes'  
    // if no blocks, this would not compile
    {
       std::println("Please enter an integer number to quadruple:");
        int some_number{}; // start as 0
        std::cin >> some_number; 
        quadruple_int(some_number); // quadruples 'some_number'  
        std::println("Output: {}", some_number); 
    }
}

// example of attempting compilation WITHOUT block scope:

/*
clang++ -Wall -std=c++23 block_scope.cpp -o block_scope
block_scope.cpp:31:13: error: redefinition of 'some_number'
   31 |         int some_number{}; // start as 0
      |             ^
block_scope.cpp:20:13: note: previous definition is here
   20 |         int some_number{}; // start as 0
      |             ^
1 error generated.
*/