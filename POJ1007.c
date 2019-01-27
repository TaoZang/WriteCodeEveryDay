#include <stdio.h>
#include <stdlib.h>

struct DNA {
  char *seq;
  int order;
};

int calculate(char *str, int size) {
  int order = 0;
  for (int i = 0; i < size; i++) {
    if (str[i] == 'A') {
      continue;
    }
    int step = 0;
    for (int j = i + 1; j < size; j++) {
      if (str[i] > str[j]) {
        step++;
      }
    }
    order += step;
  }
  return order;
}

int cmpfunc(const void *a, const void *b) {
  return ((struct DNA *)a)->order - ((struct DNA *)b)->order;
}

int main(void) {
  int size, count;
  scanf("%d %d", &size, &count);

  char input[count][size + 1];
  struct DNA dna[count];
  for (int i = 0; i < count; i++) {
    scanf("%s", input[i]);
    dna[i].seq = input[i];
    dna[i].order = calculate(dna[i].seq, size);
  }
  qsort(dna, count, sizeof(struct DNA), cmpfunc);
  for (int i = 0; i < count; i++) {
    printf("%s\n", dna[i].seq);
  }

  return 0;
}
