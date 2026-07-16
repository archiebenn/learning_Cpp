# learning_C++
Learning C basics with the aim to move into C++. This is essentially out of interest for programming and to improve my understanding of higher level languages, but being able to read/write in these languages may also be helpful for come comp bio stuff in the future (I hope).

## C
Working through an old and short book on C I found (C programming by Mike Mcgrath, 2006)  
The main plan is just to get for this lower level programming vs my background in R/Python before moving onto and focusing on C++.  

## C++
Now working through a new C++ book (Introducing C++ by Frances Buontempo, 2026)


## Python bindings with `pybind11`
Learning about implementing C++ code into Python scripts with pybind which could be useful for offloading some computationally demanding aspects of Python scripts to C++ functions.  

So far, I have used for loops to get the sum of squares, with one written in C++ and one in Python and both run from a Python script (see `pybind/pybind_test01.cpp` and `.py`), to get this result to demonstrate binding usefulness: 

```
Python loop time on 1000000000 iterations: 61.283s
C++ loop time (in .py) on 1000000000 iterations: 0.645s
```
