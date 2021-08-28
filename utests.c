#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utests.h"
#include "string_copy.h"

void run_test_suite_for_copy_string_function(void)
{
        test_str_lengths_are_equal();
        test_the_length_of_the_str_copy();
        test_if_pointers_to_strings_are_different();
        test_the_content_of_the_str_copy();
        test_if_the_source_str_is_null();
        test_if_src_string_is_empty();
        test_if_pointers_to_empty_strings_are_different();
        test_if_copy_of_empty_str_contains_null_terminator();
}

static void test_str_lengths_are_equal(void)
{
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        assert_equal(strlen(src), strlen(dest), "String lengths are equal.");
        free(dest);
}

static void test_the_length_of_the_str_copy(void)
{
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        size_t length = strlen(src);
        assert_equal(length, strlen(dest), "The length of the string copy is 12.");
        free(dest);
}

static void test_if_pointers_to_strings_are_different(void)
{
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        assert_true(src != dest, "Pointers to src and dest strings are different.");
        free(dest);
}

 static void test_the_content_of_the_str_copy(void)
 {
        char *dest = NULL;
        char src[] = "Test string.";
        dest = copy_string(src);
        assert_equal(0, strcmp(src, dest), "The copy of the string contains the same symbols.");
        free(dest);
 }

 static void test_if_the_source_str_is_null(void)
 {
        char *dest = NULL;
        dest = copy_string(NULL);
        assert_true(dest == NULL, "The src and dest strings are NULL.");
        free(dest);
 }

 static void test_if_src_string_is_empty(void)
 {
        char *dest = NULL;
        char src[] = "";
        dest = copy_string(src);
        assert_equal(strlen(src), strlen(dest), "String lengths are equal 0.");
        free(dest);
 }

static void test_if_pointers_to_empty_strings_are_different(void)
{
        char *dest = NULL;
        char src[] = "";
        dest = copy_string(src);
        assert_true(src != dest, "Pointers to empty src and dest strings are different.");
        free(dest);
}

static void test_if_copy_of_empty_str_contains_null_terminator(void)
{
        char *dest = NULL;
        char src[] = "";
        dest = copy_string(src);
        assert_equal('\0', dest[0], "The copy of empty string contains null terminator.");
        free(dest);
}

static void assert_true(int value, const char *name)
{
        if(value == TRUE) {
                printf("PASSED %s\n", name);
        } else {
                printf("FAILED %s\n", name);
                printf("\t expected: TRUE, actual %s\n", (value == TRUE) ? "TRUE" : "FALSE");
        }
}

static void assert_false(int value, const char *name)
{
        if(value == FALSE) {
                printf("PASSED %s\n", name);
        } else {
                printf("FAILED %s\n", name);
                printf("\t expected: FALSE, actual %s\n", (value == FALSE) ? "FALSE" : "TRUE");
        }
}

static void assert_equal(int expected, int actual, const char *name)
{
        if(expected == actual) {
                printf("PASSED %s\n", name);
        } else {
                printf("FAILED %s\n", name);
                printf("\t expected: %d, actual %d\n", expected, actual);
        }
}
