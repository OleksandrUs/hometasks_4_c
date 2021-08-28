/*
 * Task2, string_copy.h
 * Purpose: The header file that contains prototype of a function that copies a string to a new one
 * dynamically allocated.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 28/08/2021
 */

#ifndef _STRING_COPY_H_
#define _STRING_COPY_H_

#include <stddef.h>

/*
 * This identifier is used as a code to identify whether a function call was successfull
 * or an error occured.
 */
#define STR_ERR -1

/*
 * The prototype of the function that copies a string to a new one
 * dynamically allocated.
 */
char * copy_string(const char *src_string);

/*
 * The prototype of the function that gets string length.
 */
static size_t get_str_length(const char *src_string);

#endif