#include <stdio.h>

int abs(int n) {
  return n < 0 ? -n : n;
}

int main(void) {
  int count = 0;
  scanf("%d", &count);
  int remain, slice;
  for (int i = 0; i < count; i++) {
    scanf("%d", &remain);
    printf("Scenario #%d:\n", i + 1);
    slice = remain * 2 + 1;
    for (int j = 0; j < slice; j++) {
      printf("slice #%d:\n", j + 1);
      int index = 0;
      char output[400] = {0};
      int s = slice / 2;
      int b = abs(j - s);
      int p = remain - b;
      for (int m = 0; m < slice; m++) {
        int v = abs(m - remain);
        for (int n = 0; n < slice; n++) {
          int h = abs(n - remain) + v;
          if (h <= p) {
            output[index++] = (char)(b + h + '0');
          } else {
            output[index++] = '.';
          }
        }
        output[index++] = '\n';
      }
      printf("%s", output);
    }
    printf("\n");
  }
    return 0;
}
