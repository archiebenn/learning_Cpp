# pybind test 1 - comparing native python vs c++ speeds for sum of squares function (and np too for comparison)
# will import the C++ function using include
# this has already been compiled (see bottom of .cpp file)

import cpp.pybind.pybind_test01 as pybind_test01      # imports pybind module (compiled from c++ program and containing squares_sum)
import time
import numpy as np


# create equivalent loop function in python for squares sum
def py_squares_sum(a):

    i = 0
    total = 0

    for i in range(a +1):             # eqvn to cpp's i <= a; (+1 to capture a itself as range is to -1)

        total += i*i
    
    return total


# and then the actual 0(n) function bc why not as it exists as a solved/closed form shortcut
# # this will be by far the fastest and not really a comparison but still
def fast_py_squares_sum(n):
    return n * (n + 1) * (2 * n + 1) // 6


# run both and compare times
n = 100000000                 # sum squares up to n
print()

# PYTHON 
start = time.time()
py_squares_sum(n)
end = time.time()
py_time = end - start
print(f"Python loop time on {n} iterations: {py_time:.3f}s")

# C++ pybind 
start = time.time()
pybind_test01.cpp_square_sum(n)
end = time.time()
cpp_time = end - start
print(f"C++ loop time on {n} iterations: {cpp_time:.3f}s")

# numpy .
start = time.time()
(np.arange(n + 1, dtype=np.int64) ** 2).sum()
end = time.time()
print(f"NumPy time on {n} iterations: {end - start:.3f}s")

# PYTHON/mathematical closed form speed
start = time.time()
fast_py_squares_sum(n)
end = time.time()
py_fast_time = end - start
print(f"Closed form time: {py_fast_time:.3f}s")


# example output!
# Python loop time on 1000000000 iterations: 61.283s
# C++ loop time on 1000000000 iterations: 0.645s
# NumPy time on 1000000000 iterations: 4.024s
# Closed form time: 0.000s

