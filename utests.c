/*
 * Task2, utests.c
 * Purpose: The implementation of the functions for unit testing
 * of the copy_string() function and implementation of a group 
 * of additional assert-functions used for unit testing.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 28/08/2021
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utests.h"
#include "string_copy.h"

/*
 * This function implements Unit Test suite for the function copy_string().
 * Sequentially, one by one, the functions for each test case are called.
 */
void run_test_suite_for_copy_string_function(void)
{
        printf("\n=============UNIT TESTS for copy_string() function=============\n");
        test_str_lengths_are_equal();
        test_the_length_of_the_str_copy();
        test_if_pointers_to_strings_are_different();
        test_the_content_of_the_str_copy();
        test_if_the_source_str_is_null();
        test_if_src_string_is_empty();
        test_if_pointers_to_empty_strings_are_different();
        test_if_copy_of_empty_str_contains_null_terminator();
        printf("===============================================================\n");
}

/*
 * The function tests if the lengths of the original string and the copy
 * of the string are equal.
 */
static void test_str_lengths_are_equal(void)
{
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        assert_equal(strlen(src), strlen(dest), "String lengths are equal.");
        free(dest);
}

/*
 * The function tests if the length of the copy of the string is equal
 * to the number of characters in the original string.
 */
static void test_the_length_of_the_str_copy(void)
{
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        size_t length = strlen(src);
        assert_equal(length, strlen(dest), "The length of the copy of the string is 12.");
        free(dest);
}

/*
 * The function tests if the pointers to the original string and its copy
 * are different and points to different memory blocks in RAM (i.e. that the
 * original string was really copied into a new one for which memory was 
 * dynamically allocated).
 */
static void test_if_pointers_to_strings_are_different(void)
{
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        assert_true(src != dest, "Pointers to src and dest strings are different.");
        free(dest);
}

/*
 * The function tests if the contents of the copy of the string 
 * are the same as the original.
 */
static void test_the_content_of_the_str_copy(void)
{
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        assert_equal(0, strcmp(src, dest), "The copy of the string contains the same symbols.");
        free(dest);
}

/*
 * The function tests whether NULL is returned in case if the pointer to
 * the original string, passed in the copy_string() function as a parameter, is NULL.
 */
static void test_if_the_source_str_is_null(void)
{
        char *dest = NULL;
        dest = copy_string(NULL);
        assert_true(dest == NULL, "The src and dest strings are NULL.");
        free(dest);
}

/*
 * The function tests if the length of the copy of empty string is 0.
 */
static void test_if_src_string_is_empty(void)
{
        char *dest = NULL;
        char src[] = "";
        dest = copy_string(src);
        assert_equal(strlen(src), strlen(dest), "String lengths are equal 0.");
        free(dest);
}

/*
 * The function tests if the pointers to the original string and its copy
 * are different and points to different memory blocks in RAM (i.e. that the
 * original string was really copied into a new one for which memory was 
 * dynamically allocated even if the original string is empty and contains
 * null terminator).
 */
static void test_if_pointers_to_empty_strings_are_different(void)
{
        char *dest = NULL;
        char src[] = "";
        dest = copy_string(src);
        assert_true(src != dest, "Pointers to empty src and dest strings are different.");
        free(dest);
}

/*
 * The function tests if the copy of the empty string contains null terminator.
 */
static void test_if_copy_of_empty_str_contains_null_terminator(void)
{
        char *dest = NULL;
        char src[] = "";
        dest = copy_string(src);
        assert_equal('\0', dest[0], "The copy of empty string contains null terminator.");
        free(dest);
}

/*
 * The function checks if the value is TRUE and prints the formated message
 * in the console.
 * 
 * @param value is the value to be checked if it is TRUE
 * @param name is a string to be printed in the formatted message in the console
 */
static void assert_true(int value, const char *name)
{
        if(value == TRUE) {
                printf("[PASSED] %s\n", name);
        } else {
                printf("[FAILED] %s\n", name);
                printf("\t expected: TRUE, actual %s\n", (value == TRUE) ? "TRUE" : "FALSE");
        }
}

/*
 * The function checks if the value is FALSE and prints the formated message
 * in the console.
 * 
 * @param value is the value to be checked if it is FALSE
 * @param name is a string to be printed in the formatted message in the console
 */
static void assert_false(int value, const char *name)
{
        if(value == FALSE) {
                printf("[PASSED] %s\n", name);
        } else {
                printf("[FAILED] %s\n", name);
                printf("\t expected: FALSE, actual %s\n", (value == FALSE) ? "FALSE" : "TRUE");
        }
}

/*
 * The function checks if the values passed in this functions as parameters
 * are equall and prints the formatted message in the console.
 * 
 * @param expected is the value to compare with the actual value
 * @param actual is the value to compare with the expected value
 * @param name is a string to be printed in the formatted message in the console
 */
static void assert_equal(int expected, int actual, const char *name)
{
        if(expected == actual) {
                printf("[PASSED] %s\n", name);
        } else {
                printf("[FAILED] %s\n", name);
                printf("\t expected: %d, actual %d\n", expected, actual);
        }
}
