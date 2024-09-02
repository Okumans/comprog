#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

const char *UNDER_TWENTY_NUMBERS[20] = {
    "zero",    "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
};

const char *TENTH_NUMBERS[10] = {"zero",   "ten",   "twenty", "thirty",
                                 "forty",  "fifty", "sixty",  "seventy",
                                 "eighty", "ninety"};

const char *BIG_PRESISION_NUMBERS[5] = {"", "thousand", "million", "billion",
                                        "trillion"};
const char *SMALL_PRESISION_NUMBERS[3] = {"", "ten", "hundred"};
// 010,010,017
// ten million, 10 thousand seven teen

/* this function will return true if buffer is writed, false if not*/
static bool _write_under_hundred(char *original, char *buffer, bool allow_zero,
                                 bool fixed_length) {

  int original_number_size = strlen(original);
  int temp_original_number_size = original_number_size;

  char replaced_null_terminator;
  if (fixed_length && original_number_size >= 3) {
    original_number_size = 3;
    replaced_null_terminator = original[3];
    original[3] = '\0';
  }

  // assert(original_number_size && original_number_size <= 3);

  if (!atoi(original)) {
    if (fixed_length && original_number_size >= 3)
      original[3] = replaced_null_terminator;

    if (allow_zero) {
      strcat(buffer, "zero");
      return true;
    }
    return false;
  }

  if (original_number_size == 3 && original[0] != '0') {
    strcat(buffer, UNDER_TWENTY_NUMBERS[original[0] - '0']);
    strcat(buffer, " hundred ");
  }

  int two_digits_number = atoi(original + max(0, original_number_size - 2));

  if (!two_digits_number) {
    if (fixed_length && original_number_size >= 3)
      original[3] = replaced_null_terminator;

    return true;
  }

  if (two_digits_number < 20) {
    strcat(buffer, UNDER_TWENTY_NUMBERS[two_digits_number]);
    strcat(buffer, " ");
  } else {
    strcat(buffer, TENTH_NUMBERS[two_digits_number / 10]);
    strcat(buffer, " ");
    if (two_digits_number % 10) {
      strcat(buffer, UNDER_TWENTY_NUMBERS[two_digits_number % 10]);
      strcat(buffer, " ");
    }
  }

  if (fixed_length && temp_original_number_size >= 3) {
    original[3] = replaced_null_terminator;
  }

  buffer[strlen(buffer) - 1] = '\0';
  return true;
}

static void _prepare_number(char **original) {
  unsigned int original_number_size = strlen(*original);

  if (original_number_size % 3 == 0)
    return;

  unsigned int padding_size = 3 - (original_number_size % 3);
  unsigned int target_size = original_number_size + padding_size;

  char *original_buffer = (char *)malloc(sizeof(char) * (target_size + 1));

  memset(original_buffer, '0', sizeof(char) * padding_size);
  memcpy(original_buffer + padding_size, *original,
         sizeof(char) * original_number_size);

  original_buffer[target_size] = '\0';
  *original = original_buffer;
}

void write_as_number(char *original, char *buffer) {
  _prepare_number(&original);

  if (!atoi(original)) {
    strcat(buffer, "zero");
    return;
  }

  unsigned int original_number_size = strlen(original);
  assert(original_number_size % 3 == 0);

  for (unsigned int i = 0; i < original_number_size - 1; i += 3) {
    const char *seperator_numbers =
        BIG_PRESISION_NUMBERS[(original_number_size - i) / 3 - 1];

    if (_write_under_hundred(original + i, buffer, false, true)) {
      if ((original_number_size - i) / 3 - 1)
        strcat(buffer, " ");

      strcat(buffer, seperator_numbers);
      strcat(buffer, " ");
    }
  }

  buffer[strlen(buffer) - 1] = '\0';
}

int main(void) {
  char buffer[2000] = "";
  char number[50];

  scanf("%s", number);
  write_as_number(number, buffer);
  printf("%s", buffer);
}
