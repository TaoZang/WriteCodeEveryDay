#include <stdio.h>
#include <math.h>

int main(void) {
  int n;
  int vi, ti;
  while (scanf("%d", &n), n) {
    int min = 0x7FFFFFFF;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &vi, &ti);
      if (ti < 0) {
        continue;
      }
      int duration = ceil(16200.0 / (float)vi) + ti;
      if (duration < min) {
        min = duration;
      }
    }
    printf("%d\n", min);
  }

  return 0;
}
