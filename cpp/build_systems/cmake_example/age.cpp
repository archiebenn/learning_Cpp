// defines how process_age() actually works
#include <iostream>
#include <print>


void process_age(){
    
    int age;
    // no line on purpose (std::print)
    std::print("Please enter your age in years: ");
    std::cin >> age;
    std::println("You are {} years old!", age);

}