// working with arrays in C++ - page 62

/*
NOTE ON CONTAINERS and CLASS TEMPLATES

C++ containers are class templates for common data structures which store elements.
Several different types of containers, such as sequenced containers (arrays, vectors) and associative containers (like look up tables). 

Class templates have been mentioned a few times before in the book. They are essentially blueprints/templates for a class.
For example, with std::expected -> template< class T, class E >class expected; is the class template
This means that T or E (class/typename just means type) will be replaces by the type which is put in each place, depending on True of Error 
e.g std::expected<double, std::string> expectes a double type, and if not the error will be a string
here, <double, std::string> are the 'template parameters' and these can be types (as here) or non-type template parameters (like numbers)

std::array is a class template 
Template from https://en.cppreference.com/cpp/container/array:
template<class T, std::size_t N> struct array;

Here, T is class/typename which just means the type, and N is the size of the array, known at compile time
*/

#include <array>
#include <iostream>

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

int main(){

    array_experiment();

}