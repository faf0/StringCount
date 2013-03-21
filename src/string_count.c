#include <stdlib.h>
#include <string.h>

#include "string_count.h"

/*
 * Reverses the given string.
 *
 * @param s the string to reverse.
 * @param length the string length.
 */
static void strrev(char *s, int length)
{
  for (int i = 0; i < length / 2; i++) {
    /* Swap i'th element and (length -1 - i)'th element. */
    int tmp = s[i];
    s[i] = s[length - 1 - i];
    s[length - 1 - i] = tmp;
  }
}

/*
 * Converts the given integer to a string.
 *
 * @param a the integer to convert. Must be positive.
 * @return the string representation of the integer.
 *         Must be freed after usage.
 */
char *intToString(uint32_t a)
{
  char *result = (char *) malloc(sizeof(char) * (LENGTH + 1));
  uint32_t div = a;
  int position = 0;

  if (!result || (a < 1)) {
    return NULL;
  }

  while ((div > 0) && (position < LENGTH)) {
    int remainder = div % 26;

    if (remainder == 0) {
      result[position] = 'Z';
      div -= 26;
    } else {
      /* 1 <= remainder <= 25; */
      result[position] = 'A' - 1 + remainder;
    }

    div /= 26;
    position++;
  }

  result[position] = 0;
  strrev(result, position);
  return result;
}

/*
 * Converts the given string to its integer value.
 *
 * @param count the string to convert. Must fulfill
 *              the requirements by isInCorrectFormat.
 * @return the string's integer value or 0, if an
 *         error occurred.
 */
uint32_t stringToInt(const char *count)
{
  uint32_t result = 0;
  int position = 0;

  if (!isInCorrectFormat(count)) {
    return 0;
  }

  while (count[position] != 0) {
    result = (count[position] - 'A' + 1) + (result * 26);
    position++;
  }

  return result;
}

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
int isInCorrectFormat(const char *count)
{
  int length = strlen(count);

  if (length > LENGTH) {
    return 0;
  }

  for (int i = 0; i < length; i++) {
    if ((count[i] < 'A') || (count[i] > 'Z')) {
      return 0;
    }
  }

  /*
   * Make sure that the string is not lexicographically
   * greater than the largest string that is representable
   * by a signed 32-bit integer.
   */
  if ((length == LENGTH) && (strcmp(count, MAX_STRING) > 0)) {
    return 0;
  }

  return 1;
}
