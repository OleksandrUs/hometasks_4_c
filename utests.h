#ifndef _UTESTS_H_
#define _UTESTS_H_

#define FALSE 0
#define TRUE 1

void run_test_suite_for_copy_string_function(void);

static void test_str_lengths_are_equal(void);
static void test_the_length_of_the_str_copy(void);
static void test_if_pointers_to_strings_are_different(void);
static void test_the_content_of_the_str_copy(void);
static void test_if_the_source_str_is_null(void);
static void test_if_src_string_is_empty(void);
static void test_if_pointers_to_empty_strings_are_different(void);
static void test_if_copy_of_empty_str_contains_null_terminator(void);

static void assert_true(int value, const char *name);
static void assert_false(int value, const char *name);
static void assert_equal(int expected, int actual, const char *name);

#endif