#include <stdio.h>
#include <math.h>

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    float R, r;
    int N;
    scanf("%f%d", &R, &N);
    r = sin(3.1415926 / (float)N);
    r = (r * R) / (1.0 + r);
    printf("Scenario #%d:\n%.3f\n\n", i + 1, r);
  }
}
