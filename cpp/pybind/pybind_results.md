# example output!

- uses -03 flag for biggest optimisation. 

## thinkpad t14s
- compiled with: 
```
g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)
```

Python loop time on 1000000000 iterations: 61.283s
C++ loop time on 1000000000 iterations: 0.645s
NumPy time on 1000000000 iterations: 4.024s
Closed form time: 0.000s

## macbook pro m5 
- compiled with:
```
g++ -O3 -Wall -shared -undefined dynamic_lookup -std=c++17 -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)
```

Python loop time on 1000000000 iterations: 20.914s
C++ loop time on 1000000000 iterations: 0.000s
NumPy time on 1000000000 iterations: 2.790s
Closed form time: 0.000s

- these times faster likely just because of macbook vs thinkpad difefrences, but the C++ loop time may have been over-optimised by the compiler as it is solved, and hence showing 0.000s on macbook (different compilers used)  
- so could test on another thing which does not have a closed form solution  
