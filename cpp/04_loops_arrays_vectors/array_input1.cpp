// working with arrays in C++ - page 62

/*
NOTE ON CONTAINERS and CLASS TEMPLATES

C++ containers are class templates for common data structures which store elements.
Several different types of containers, such as sequenced containers (arrays, vectors) and associative containers (like look up tables). 

Class templates have been mentioned a few times before in the book. They are essentially blueprints/templates for a class.
For example, with std::expected -> 'template< class T, class E >class expected;' is the class template
This means that T or E (class/typename just means type) will be replaces by the type which is put in each place, depending on True of Error 
e.g std::expected<double, std::string> expectes a double type, and if not the error will be a string
here, <double, std::string> are the 'template parameters' and these can be types (as here) or non-type template parameters (like numbers)

std::array is a class template 
Template from https://en.cppreference.com/cpp/container/array:
template<class T, std::size_t N> struct array;
so this makes a class when filled with parameters - std::array<int, N> is a separate class to std::array<double, N>

Here, T is class/typename which just means the type, and N is the size of the array, known at compile time
*/

#include <array>
#include <iostream>
#include <expected>
#include <limits>

void array_experiment(){

    // array for 5 doubles - initialised as 0.0, 0.0, 0.0, 0.0, 0.0
    // following std::array<class T, std::size_t N> as described above:
    std::array<double, 5> numbers_array{}; 

    // can access array elements using [] and indexed to 0 
    std::cout << numbers_array[0] << '\n'; 

    // change element
    numbers_array[0] = 263.2;

    std::cout << numbers_array[0] << '\n'; 
}

// re-doing get_number() again here
std::expected<double, std::string> get_number(std::istream &user_input){

    // initialise and parse stream to number
    double number{};
    user_input >> number;

    // parse successful - user_input flags change to show this
    if(user_input){
        return number;
        // exits
    }
    // clear up stream errors + mop up unused input if non-numeric (as now calling this function in a loop)
    user_input.clear();
    user_input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // unexpected string if fails
    return std::unexpected{"That's not a number dude\n"};
}

// function to loop over an array and print out the values using range-based for loop
// pass array by referece as a const as this is reading array only, not changing the array (but still saves copying whole thing)
void print_numbers(const std::array<double, 5u> &array){

    std::cout << "ARRAY: ";

    for (const auto i:array){ // declares range-based for loop over all numbers in the array
        std::cout << i << ", "; // , added for printing clarity
    }
    std::cout << '\n';

}

int main(){

    // initialise array to popuulate 
    std::array<double, 5> numbers_array{}; // (starts as N x 0.0)
    std::cout << "Enter " << numbers_array.size() << " numbers to store:\n";

    /* wrote this block below myself without book but will comment out and do what book suggests (pretty similar overall)
    int n = 5;
    int s = 0;

    while (s < n){
        auto num = get_number(std::cin); 
        if (num.has_value()){
            numbers_array[s] = num.value(); // use .value to extract the double to the array
            s++;
        }
    }
    */

    // book's version
    int count = 0u; // u means unsigned whole number (literally, 'no sign' so only >= 0) - declaring u stops unexpected behaviours  

    // while loop and using .size() function
    while (count < numbers_array.size()){

        auto num = get_number(std::cin);
        if (num.has_value()){
            numbers_array[count] = num.value();
            std::cout << "Placed " << num.value() << " into the array, cheers!\n";
            count++;  // book puts this after this block but i think it should be in it...
        }
        else {
            std::cout << num.error();
        }
    }   
    std::cout << "\nAll " << numbers_array.size() << " numbers stored and will be output below, thanks for using this service:\n";

    // and now use the print_numbers() function
    print_numbers(numbers_array);

    // CONTINUE PAGE 70
}