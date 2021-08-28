/*
 * Task2, string_copy.c
 * Purpose: write a function that copies a string to a new one
 * dynamically allocated. The function should return the new string address
 * or NULL in case of error. Avoid using the standard functions from string.h.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 28/08/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "string_copy.h"

/*
 * The function copies a string to a new one dynamically allocated.
 *
 * @param src_string a pointer to an array of char that contains a string to copy to a new one
 * @return a pointer to an array of char allocated dynamically that contains the copy of a source string
 * (i.e. the new string address), or NULL in case of error
 */
char * copy_string(const char *src_string)
{
        if(src_string == NULL){
                return NULL;
        }

        size_t length = get_str_length(src_string);
        if(length == STR_ERR){
                return NULL;
        }

        char *dest_string = NULL;
        dest_string = malloc(length + 1);

        if(dest_string != NULL){
                for(int i = 0; i < length; i++){
                        dest_string[i] = src_string[i];
                }
                dest_string[length] = '\0';
        }

        return dest_string;
}

/*
 * The function gets the length of a C string.
 *
 * @param src_string a pointer to an array of char that contains a string the length of which to find
 * @return the length of a C string or STR_ERR if the function argument is not valid
 */
static size_t get_str_length(const char *src_string)
{
        if(src_string == NULL){
                return STR_ERR;
        }

        unsigned int length = 0;

        while(src_string[length] != '\0'){
                length++;
        }

        return length;
}
