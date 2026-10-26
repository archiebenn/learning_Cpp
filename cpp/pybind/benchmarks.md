# Different optimisation levels and impacts on C++ time

- comparison of using binary function compiled using different -O optimisation levels on C++ with clang++

## -O0

```
clang++ -O0 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)

Python loop time on 500000000 iterations: 10.3439197920s
C++ loop time on 500000000 iterations: 0.2562426250s
NumPy loop time on 500000000 iterations: 1.1260112910s
Closed form time on 500000000 iterations: 0.0000020420s
```

## -O1

```
clang++ -O1 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)

Python loop time on 500000000 iterations: 10.0082847090s
C++ loop time on 500000000 iterations: 0.0000054580s
NumPy loop time on 500000000 iterations: 1.1242252910s
Closed form time on 500000000 iterations: 0.0000019170s
```

- so even with level 1 optimisation it was down to 0.000005s

## -O2

```
clang++ -O2 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)

Python loop time on 500000000 iterations: 10.3270091660s
C++ loop time on 500000000 iterations: 0.0000075000s
NumPy loop time on 500000000 iterations: 0.4439688330s
Closed form time on 500000000 iterations: 0.0000018750s
```

- strangely went up a tiny bit for this -O2  

## -O3

```
clang++ -O3 -Wall -shared -std=c++17 -undefined dynamic_lookup -fPIC $(python3 -m pybind11 --includes) pybind_test01.cpp -o pybind_test01$(python3 -m pybind11 --extension-suffix)

Python loop time on 500000000 iterations: 10.4950253750s
C++ loop time on 500000000 iterations: 0.0000057090s
NumPy loop time on 500000000 iterations: 0.8153498750s
Closed form time on 500000000 iterations: 0.0000022910s
```

- still pretty similar to -O1 and -O2, with all three of these much faster than -O0  
