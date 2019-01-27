#include <stdio.h>

int main(void) {
    float number;
    while (1) {
        scanf("%f", &number);
        if (number < 0.01) {
            break;
        }

        float sum = 0.0;
        int count = 0;
        for (int i = 1; ; i++) {
            sum += 1.0 / (i + 1);
            if (sum >= number) {
                count = i;
                break;
            }}
        
        printf("%d card(s)\n", count);
    }
    return 0;
}