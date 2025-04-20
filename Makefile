CC   := gcc
CXX  := g++

ARCH     := -m32
CFLAGS   := $(ARCH) -std=c99   -Wall -Wextra -pedantic -O0
CXXFLAGS := $(ARCH) -std=c++17 -Wall -Wextra -pedantic -O0

all: test_cpp test_c

#C++
Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test_cpp.o: test_cpp.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test_cpp: Matrix.o test_cpp.o
	$(CXX) $(CXXFLAGS) $^ -o $@

#C
matrix_c.o: matrix_c.c matrix_c.h
	$(CC) $(CFLAGS) -c $< -o $@

test_c.o: test_c.c matrix_c.h
	$(CC) $(CFLAGS) -c $< -o $@

test_c: matrix_c.o test_c.o
	$(CC) $(CFLAGS) $^ -o $@

run_cpp: test_cpp
	./test_cpp

run_c: test_c
	./test_c

clean:
	rm -f *.o test_cpp test_c

.PHONY: all clean run_cpp run_c
