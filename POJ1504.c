#include <stdio.h>

int OCT_POW[] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

void convert(char *digits, int number) {
  int division;
  int start = 0;
  for (int i = 0; i < 10; i++) {
    division = number / OCT_POW[i];
    if (start || division > 0) {
      start = 1;
      *digits = division;
      digits++;
      number %= OCT_POW[i];
    }
  }
}

int main(void) {
  int count;
  scanf("%d", &count);
  int a, b;
  for (int i = 0; i < count; i++) {
    scanf("%d %d", &a, &b);
    char x[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    char y[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    convert(x, a);
    convert(y, b);

    int l, r;
    int sum = 0, carry = 0, number = 0;
    for (int j = 0; j < 10; j++) {
      l = x[j];
      r = y[j];
      if (l > 9 && r > 9 && carry == 0) {
        break;
      }
      if (l > 9) {
        l = 0;
      }
      if (r > 9) {
        r = 0;
      }
      number = l + r + carry;
      if (number > 9) {
        carry = 1;
        number = number % 10;
      } else {
        carry = 0;
      }
      sum = sum * 10 + number;
    }
    printf("%d\n", sum);
  }
  return 0;
}
