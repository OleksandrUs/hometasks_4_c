**Description**

*Home tasks are:*

1. Create as many as possible test cases to cover memcpy () function. For the interface, you
may refer to https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm 
Note. The function is implemented for maximum performance, so keep in mind CPU core architecture (32 or 64 bit)

2. Implement Unit Test suite for the function from “C language part 3’ home task 1.
“Write a function that copies a string to a new one dynamically allocated. The function should return the new
string address or NULL in case of error. ~~Avoid using the standard functions from string.h~~
All the external functions, such as malloc(), memcpy (), must be mocked.

The test cases for home task 1 described in task1.xls file.

**Requirements**

*Linux (Ubuntu)*<br>
gcc 9.3.0

*Windows*<br>
gcc 8.1.0

**Build project**
- To build the program run the command in 'Terminal' from the root project directory:<br>
``gcc task2.c string_copy.c utests.c -o task2``<br>

**Run the program in Terminal**
- To run the program run the command in 'Terminal' from the root project directory:<br>
``./task2``<br>

