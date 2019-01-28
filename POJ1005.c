#include <stdio.h>
#include <math.h>

#define PI 31.831

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    float x, y;
    scanf("%f%f", &x, &y);
    float limit = sqrt(x * x + y * y);
    int year = 1;
    float r = 0.0;
    while (1) {
      r = sqrt(PI + r * r);
      if (r > limit) {
        printf("Property %d: This property will begin eroding in year %d.\n", i + 1, year);
        break;
      }
      year++;
    }
  }
  printf("END OF OUTPUT.\n");
}
