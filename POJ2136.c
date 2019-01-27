#include <stdio.h>

int main(void) {
  int digits[26] = {0};

  char input;
  int max = 0;
  for (int i = 0; i < 4; i++) {
    while (1) {
      scanf("%c", &input);
      if (input == '\n') {
        break;
      }
      if (input < 'A' || input > 'Z') {
        continue;
      }
      digits[input - 'A']++;
      if (digits[input - 'A'] > max) {
        max = digits[input - 'A'];
      }
    }
  }
  for (int i = max; i > 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (digits[j] >= i) {
        printf("*");
      } else {
        printf(" ");
      }
      if (j < 25) {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");

  return 0;
}
