/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_lib
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

#include <my_string.h>

#define MY_ABS(x) (((x) < 0) ? (-x) : (x))
#define MY_MAX(x, y) ((x < y) ? (y) : (x))
#define MY_SIGN(x) (((x) < 0) ? (-1) : (1))

extern const char **environ;

/////////////////////////////////////////////////////////////////////////////
/// @brief Changes the size of the memory block pointed by ptr to size bytes
/// @param ptr Poiter to reallocate
/// @param size New size to allocate
/// @return Address of the newly allocated block
/////////////////////////////////////////////////////////////////////////////
void *my_realloc(void *ptr, size_t size);

/////////////////////////////////////////////////////////////////////////
/// @brief Searches the environment list to find an environment variable
/// @param name The name of the environment variable to search for
/// @return A pointer to the corresponding value string
/////////////////////////////////////////////////////////////////////////
char *my_getenv(const char *name);

/// @brief Prints a string on standard error output
/// @param str String to print
/// @return The number of bytes wrote
int my_puterr(const char *str);

/// @brief Prints a string on standard output
/// @param str String to print
/// @return The number of bytes wrote
int my_putstr(const char *str);

/// @brief Prints a character on standard output
/// @param c Character to print
/// @return 1 on success
int my_putchar(char c);

/// @brief Reads an entire line from standard input,
/// storing the adress of the buffer containing the text into *lineptr.
/// The buffer is null terminated and does NOT include the newline character.
/// @param lineptr The adress of the buffer containing the text
/// @return The number of bytes read on success
/// not including the newline character,
/// -1 on failure to read a line (including end-of-file condition).
int my_readline(char **lineptr);

/// @brief Convert an integer to a string
/// @param nb The number to convert
/// @return The newly allocated string containing the number
char *my_itostr(int nb);

/// @brief Print a number on the standard output
/// @param nb Number to print
/// @return The number of bytes printed
int my_putnbr(int nb);

/// @brief Free an array of pointers
/// @param ptr Pointer on the array to free
void my_freearray(void *ptr);

/// @brief Compute the length of an array of pointers
/// @param ptr Pointer on the array
/// @return The length of the array
size_t my_arrlen(void *ptr);

/// @brief Copy pointers from an array to another
/// @param dest Destination receving the pointers
/// @param src Source providing the pointers to copy
/// @return Address of dest
void *my_arrcpy(void *dest, void *src);

/// @brief Append a pointer to an array of pointers
/// @param ptr Pointer on the array
/// @param elem Element to append
/// @return Adress of the newly allocated array
void *my_arrappend(void *ptr, void *elem);

/// @brief Allocates an array of pointers
/// @param size Size of the array to allocate
/// @return Adress of the array
void *my_allocarray(size_t size);
