// defines how process_age() actually works
#include <iostream>
#include <print>


void process_age(){
    
    int age;
    std::println("Please enter your age in years: ");
    std::cin >> age;
    std::println("You are {} years old!", age);

}