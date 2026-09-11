# makefile test example (separate to cmake example) for running main and age cpps
# order doesn't matter, but target/default is at the top so plain 'make' runs it

# variable names for compiling as easier than typing out
# names are just conventional
CXX = g++-14
CXXFLAGS = -std=c++23

.PHONY: clean

# hello_age is main target, and depends on the 'main.o' and 'age.o' objects
# note: this part is LINKING (links/stitches together two compiled .o files), and doesn't need -std=c++23
hello_age: main.o age.o
	$(CXX) main.o age.o -o hello_age

# compile main.cpp and age.cpp to .o intermediary files
# remember the -c flag: otherwise compiler will compile + link each individual one which we don't want here (link later in hello_age)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

age.o: age.cpp
	$(CXX) $(CXXFLAGS) -c age.cpp

# PHONY target - no real file called 'clean' ever exists
clean:
	rm *.o hello_age
