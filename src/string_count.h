#ifndef _STRING_COUNT_H
#define _STRING_COUNT_H 1

#include <stdint.h>

/*
 * The maximum 32-bit unsigned integer has the value 2^32 - 1.
 * The string representation requires therefore at most
 * log (25 * (2^32 - 1) + 1) / log 26 = 7.795... digits.
 * Hence 7 bytes suffice for any unsigned 32-bit integer
 * that is converted to a string.
 */
#define LENGTH 7

/*
 * The string representation of the maximum unsigned 32-bit
 * integer.
 */
#define MAX_STRING "MWLQKWU"

/*
 * Converts the given integer to a string.
 *
 * @param a the integer to convert. Must be positive.
 * @return the string representation of the integer.
 *         Must be freed after usage.
 */
char *intToString(uint32_t a);

/*
 * Converts the given string to its integer value.
 *
 * @param count the string to convert. Must fulfill
 *              the requirements by isInCorrectFormat.
 * @return the string's integer value or 0, if an
 *         error occurred.
 */
uint32_t stringToInt(const char *count);

/*
 * Returns whether the given string is in the correct
 * format. The string must not be longer than LENGTH
 * and must not be lexicographically greater than
 * MAX_STRING. Additionally, the string must only
 * consist of ASCII characters between A-Z, inclusively.
 *
 * @return 1 if the string is in the correct format.
 *         Otherwise, 0 is returned.
 */
int isInCorrectFormat(const char *count);

#endif
