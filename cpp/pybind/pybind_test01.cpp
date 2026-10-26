// pybind test - attempting to compile a c++ program to a shared library to be accessed by python scripts
// 12-6-26

#include <pybind11/pybind11.h>

namespace py = pybind11;

// will test with a square sum function (will test python speed vs this one in .py)
long long squares_sum(long long a){

    long long total = 0;

    for (long long i =0; i <= a; i++){
        total = total + (i * i);
    }

    return total;
}


// this acts as a normal cpp main() but for pybind
// m.def forms the 'python facing name' so when you do module.function this is the function name (and address to cpp function with &)
PYBIND11_MODULE(pybind_test01, m, py::mod_gil_not_used()) {
    m.doc() = "pybind11 example plugin";                                                                      // optional module docstring
    m.def("cpp_square_sum", &squares_sum, "A function that calculates the sum of squares up to a given number");
}


// TO COMPILE
// Run from this directory with the same Python environment used to import the module.
// Linux:
// g++ -O3 -Wall -shared -std=c++17 -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)
// macOS:
// clang++ -O3 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)

// also testing different optimisations:
//clang++ -O0 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)
//clang++ -O1 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)
//clang++ -O2 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)
//clang++ -O3 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)
