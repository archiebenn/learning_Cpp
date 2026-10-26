# pybind test 1 - comparing native python vs c++ speeds for sum of squares function (and np too for comparison)
# and added a macbook version of the same test for comparison (see pybind_test01_mac.py)
# will import the C++ function using include
# this has already been compiled (see bottom of .cpp file)

import pybind_test01 as pybind_test01      # imports pybind module (compiled from c++ program and containing squares_sum)
import timeit
import numpy as np
# import pybind_test01 as pybind_test01  # imports pybind module (compiled from c++ program and containing squares_sum)  # noqa: PLC0414
import pybind_test01 as pybind_test01  


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
n = 500000000                 # sum squares up to n
print()

# PYTHON 
py_time = timeit.timeit(lambda: py_squares_sum(n), number=1)
print(f"Python loop time on {n} iterations: {py_time:.10f}s")

# C++
cpp_time = timeit.timeit(lambda: pybind_test01.cpp_square_sum(n), number=1)
print(f"C++ loop time on {n} iterations: {cpp_time:.10f}s")

# numpy .
numpy_time = timeit.timeit(lambda: (np.arange(n + 1, dtype=np.int64) ** 2).sum()
, number=1)
print(f"NumPy loop time on {n} iterations: {numpy_time:.10f}s")

# PYTHON/mathematical closed form speed
solved_time = timeit.timeit(lambda: fast_py_squares_sum(n), number=1)
print(f"Closed form time on {n} iterations: {solved_time:.10f}s")




# example output!
# Python loop time on 1000000000 iterations: 61.283s
# C++ loop time on 1000000000 iterations: 0.645s
# NumPy time on 1000000000 iterations: 4.024s
# Closed form time: 0.000s

