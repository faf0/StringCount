/*
 * Converts integers which are greater than zero to strings
 * over the alphabet A-Z such that A = 1, B = 2, ..., Z = 26,
 * AA = 27, and so on.
 *
 * Author: Fabian Foerg
 */

#include <stdio.h>
#include <stdlib.h>

#include "string_count.h"

/*
 * Prints how to use this program.
 *
 * @prog_name the command-line name of this program.
 */
static void usage(const char *prog_name)
{
  printf("Syntax: %s w\n\nw is either a positive integer "
         "or a string over the alphabet A-Z that is lexicographically "
         "smaller than or equal to %s\n", prog_name, MAX_STRING);
}

/*
 * Converts the given argument to an integer value or a string,
 * depending on the format of the argument.
 *
 * @arg may be an ASCII string representing an integer or the
 *      ASCII representation of an integer.
 * @return the exit status of the conversion.
 */
static int convert(const char *arg)
{
  if (isInCorrectFormat(arg)) {
    uint32_t i = stringToInt(arg);
    printf("%u\n", i);
  } else {
    uint32_t i = (uint32_t) atol(arg);

    if (i < 1) {
      printf("The first argument must be a positive integer or "
             "a string over the alphabet A-Z that is lexicographically "
             "smaller than or equal to %s\n", MAX_STRING);
      return EXIT_FAILURE;
    } else {
      char *string = intToString(i);

      if (string) {
        printf("%s\n", string);
        free(string);
      } else {
        printf("Cannot allocate memory for string representation!\n");
        return EXIT_FAILURE;
      }
    }
  }

  return EXIT_SUCCESS;
}

/*
 * Converts the given command-line string or integer
 * to its integer representation or string representation,
 * respectively, and prints the result on standard output.
 */
int main(int argc, char *argv[])
{
  if (argc != 2) {
    usage(argv[0]);
    return EXIT_FAILURE;
  } else {
    return convert(argv[1]);
  }
}
