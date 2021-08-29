/*
 * Task2, task2.c
 * Purpose: implement Unit Test suite for the function from "C language part 3" home task 1.
 * "Write a function that copies a string to a new one dynamically allocated. 
 * The function should return the new string address or NULL in case of an error.
 * <strike>Avoid using the standard functions from string.h"</strike>.
 * All the external function, such as malloc(), memcpy(), must be mocked. 
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 28/08/2021
 */

#include "string_copy.h"
#include "utests.h"

/*
 * The main function of the program.
 * Unit testing of the copy_string() function.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        run_test_suite_for_copy_string_function();

        return 0;
}
