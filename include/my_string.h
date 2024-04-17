/*
** EPITECH PROJECT, 2024
** my_string.h
** File description:
** Header file for C string manipulation
*/

#pragma once

#include <stddef.h>

#define __BOOL_TYPE__ unsigned char
#define TRUE 1
#define FALSE 0

typedef __BOOL_TYPE__ bool_t;

#define IS_NUM(c) ('0' <= c && c <= '9')
#define IS_ALPHA(c) (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))

#define LOW_ALPHA "abcdefghijklmnopqrstuvwxyz"
#define UP_ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"

/// @brief Compute the lenght of a string
/// @param str String whose lenght is to be computed
/// @return Lenght of the string str
size_t my_strlen(const char *str);

/// @brief Copie characters from a string to another
/// @param dest Destination receving the characters
/// @param src Source providing the characters to copy
/// @return Address of dest
char *my_strcpy(char *dest, const char *src);

/// @brief Copie no more than n characters from a string to another
/// @param dest Destination receving the characters
/// @param src Source providing the characters to copy
/// @param n The number of characters to copy
/// @return Address of dest
char *my_strncpy(char *dest, const char *src, size_t n);

/// @brief Compare two strings
/// @param s1 First string
/// @param s2 Second string
/// @return 0 if the strings are equal, a non-zero interger otherwise
int my_strcmp(const char *s1, const char *s2);

/// @brief Compares no more than n bytes from two strings
/// @param s1 First string
/// @param s2 Second string
/// @param n The number of bytes to compare
/// @return 0 if the n first bytes of the strings are equal,
/// a non-zero integer otherwise
int my_strncmp(const char *s1, const char *s2, size_t n);

/// @brief Concatenates characters from a string to another
/// @param dest Destination receving the characters
/// @param src Source providing the characters to concatenate
/// @return Address of dest
char *my_strcat(char *dest, const char *src);

/// @brief Allocate a new string with some content
/// @param str String whose content is to be copied
/// @return Address of the newly allocated string
char *my_strdup(const char *str);

/// @brief Convert a string to an int
/// @param str String to convert
/// @return A number in the from of an int
int my_strtoi(const char *str);

/// @brief Searches a character in a string
/// @param str String in which the search is done
/// @param c Character to search
/// @return Address of the first occurence of the character
/// in the string if it is found, NULL otherwise
const char *my_strchr(const char *str, char c);

/// @brief Searches a character in a string
/// @param str String in which the search is done
/// @param c Character to search
/// @return Address of the last occurence of the character
/// in the string if it is found, NULL otherwise
const char *my_strrchr(const char *str, char c);

/// @brief Check if a string contains only given characters
/// @param str String to check
/// @param only String containing the only characters allowed
/// @return A number in the from of an int
bool_t my_stronly(const char *str, const char *only);

/// @brief Split a string into an array of strings
/// @param str String to split
/// @param sep Separators
/// @return Address of the newly allocated array of strings
char **my_strsplit(const char *str, const char *sep);

/// @brief Create a string from two strings
/// @param s1 first part
/// @param s2 second part
/// @return The adress of the newly allocated string
char *my_stradd(char *s1, char *s2);

/// @brief Check if a string is alphabetical
/// @param str String to check
/// @return 1 if str is alphabetical, 0 otherwise
bool_t my_stralpha(char *str);

/// @brief Check if a string is numerical
/// @param str String to check
/// @return 1 if str is numerical, 0 otherwise
bool_t my_strnum(char *str);

/// @brief Check if a string is alphanumerical
/// @param str String to check
/// @return 1 if str is alphanumerical, 0 otherwise
bool_t my_stralphanum(char *str);
