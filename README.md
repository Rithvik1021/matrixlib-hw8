HW #8

a. AUTHORING
Rithvik Srinivasan  
UMBC CMSC 313 
Mon/Wed 8:30 AM – 9:45 AM

b. PURPOSE OF SOFTWARE
Provide two matrix libraries, one in C++ and one in C, each being able to do:
- matrix addition  
- scalar × matrix multiplication  
- matrix transposition  
- matrix × matrix multiplication  

c. FILES
- Matrix.h
- Matrix.cpp
- test_cpp.cpp
- matrix_c.h
- matrix_c.c
- test_c.c
- makefile
- README

d. BUILD INSTRUCTIONS:
- C++
g++ -std=c++17 -Wall -Wextra -pedantic Matrix.cpp test_cpp.cpp -o test_cpp
./test_cpp
- C
gcc -std=c99 -Wall -Wextra -pedantic matrix_c.c test_c.c -o test_c
./test_c


e. TESTING METHODOLOGY
- Choosing (6 and 4) for A, (1,2,3) for B, and (2,4,6) for C
- Using the formula D = A+(3*B) * C^T
- Should get D = [ 90 70 ] [200 150]

f. ADDITIONAL INFORMATION
- tested on powershell
- includes error handling
- uses vector to allocate and deallocate
