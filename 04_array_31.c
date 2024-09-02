#include <stdio.h>
#include <string.h>

char *basic_number_mapping[20] = {
    "zero",    "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
};

char *tenth_number_mapping[10] = {"zero",   "ten",   "twenty", "thirty",
                                  "forty",  "fifty", "sixty",  "seventy",
                                  "eighty", "ninety"};

char *big_number_mapping[5] = {"", "thousand", "million", "billion",
                               "trillion"};

int choose_big_number_mapping(int position) {
  if (position == 0)
    return 0;
  if (position % 12 == 0)
    return 4;
  if (position % 9 == 0)
    return 3;
  if (position % 6 == 0)
    return 2;
  if (position % 3 == 0)
    return 1;

  return 0;
}

void to_writing(char *number) {
  int len = strlen(number);

  if (len == 1) {
    printf("%s ", basic_number_mapping[number[0] - '0']);
    return;
  }

  for (int i = 0; i < len; i++) {
    int remaining_digits = len - i;

    if (remaining_digits % 3 == 1)
      printf(
          "%s %s ", basic_number_mapping[number[i] - '0'],
          big_number_mapping[choose_big_number_mapping(remaining_digits - 1)]);

    else if (remaining_digits % 3 == 2) {
      int num = (number[i] - '0') * 10 + number[i + 1] - '0';

      if (number == 0)
        printf("%s ", big_number_mapping[choose_big_number_mapping(
                          remaining_digits - 2)]);
        

      else if (num < 20)
        printf("%s %s ", basic_number_mapping[num],
               big_number_mapping[choose_big_number_mapping(remaining_digits -
                                                            1 - (num < 10))]);

      else {
        printf("%s ", tenth_number_mapping[number[i] - '0']);
        if (number[i + 1] != '0')
          printf("%s ", basic_number_mapping[number[i + 1] - '0']);
        printf("%s ", big_number_mapping[choose_big_number_mapping(
                          remaining_digits - 2)]);
      }
      ++i;
    }

    else if (remaining_digits % 3 == 0) {
      if (number[i] != '0')
        printf("%s hundred ", basic_number_mapping[number[i] - '0']);
    }
  }
}

int main(void) {
  char number[1000];
  scanf(" %s", number);
  to_writing(number);
}
