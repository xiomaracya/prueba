#include "types.h"

/**
 * @brief: Invert a string using a stack, returning a newly allocated string
 *
 * @example: "Hello World" => "olleH dlroW"
 *
 * @param str Input string
 * @return A newly allocated string with the input string in reverse order.
 **/
char *string_invert(char *str);

/**
 * @brief: Reverse each of the words of an input string and return the result in
 *a previously allocated string passed as argument.
 *
 * @example: "Hello World" => "olleH dlroW"
 * The words in the input string are separated by a space character.
 * The strings may not overlap, and the destination string strout
 * must be large enough for the resulting string.
 *
 * @param strout, Pointer to the output buffer
 * @param strin, Pointer to the input expression
 * @return The function returns OK or ERROR
 **/
Status reverseWords(char *strout, char *strin);
