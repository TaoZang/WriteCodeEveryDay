#include <stdio.h>
#include <math.h>

int main(void) {
    int input;
    scanf("%d", &input);
    int count = 1;
    int max = input / 2 + 1;
    int min = (int)((sqrt(input * 8 + 1) - 1.0) / 2.0);
    for (int i = max; i >= min; i--) {
        int total = 0;
        for (int j = i; j > 0; j--) {
            total += j;
            if (total == input) {
                count++;
                break;
            } else if (total > input) {
                break;
            }
        }
    }
    printf("%d\n", count);
}
