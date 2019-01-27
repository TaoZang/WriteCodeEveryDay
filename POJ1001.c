#include <stdio.h>
#include <string.h>

const static int MAX_LENGTH = 126;

typedef struct {
    char base[126];
    int n;
} BigNum;

BigNum *real2Big(char *n, BigNum *b) {
    int num_start = 0, pow_start = 0;
    int power = 0;
    char *digit = n;
    char *base = b->base;
    while (*digit != '\0') {
        if (*digit == '.') {
            pow_start = 1;
            digit++;
            continue;
        } else if (*digit >= '1' && *digit <= '9') {
            num_start = 1;
        }
        if (pow_start) {
            power--;
        }
        if (num_start) {
            *base = *digit;
            base++;
        }
        digit++;
    }
    b->n = power;
    return b;
}

char *format(BigNum *num, char *output) {
    int n = num->n;
    char *base = num->base;
    
    int m = 0;
    int valid = 0;
    while (base[m] != '\0') {
        if (base[m] > '0' && base[m] <= '9') {
            valid = 1;
        }
        m++;
    }
    if (!valid) {
        output[0] = '0';
        return output;
    }
    if (n >= 0) {
        for (int i = 0; i < m + n; i++) {
            if (i < m) {
                output[i] = base[i];
            } else {
                output[i] = '0';
            }
        }
    } else {
        while (1) {
            if (base[m - 1] != '0' || n >= 0) {
                break;
            }
            base[m - 1] = '\0';
            n++;
            m--;
        }
        if (n == 0) {
            for (int i = 0; i < m; i++) {
                output[i] = base[i];
            }
        } else if (n < 0) {
            n = -n;
            if (n >= m) {
                output[0] = '.';
                int j = 1;
                for (int i = 0; i < n - m; i++, j++) {
                    output[j] = '0';
                }
                for (int i = 0; i < m; i++, j++) {
                    output[j] = base[i];
                }
            } else {
                int point = m - n;
                for (int i = 0; i < m + 1; i++) {
                    if (i < point) {
                        output[i] = base[i];
                    } else if (i == point) {
                        output[i] = '.';
                    } else {
                        output[i] = base[i - 1];
                    }
                }
            }
        }
    }
    return output;
}

void reverse_add(char *base, char *add) {
    int i = 0;
    int temp = 0, carry = 0;
    while (add[i] != '\0') {
        if (base[i] >= '0' && base[i] <= '9') {
            temp = (int)(base[i] - '0');
        } else {
            temp = 0;
        }
        temp += carry + (int)(add[i] - '0');
        if (temp > 9) {
            carry = 1;
            base[i] = '0' + (temp % 10);
        } else {
            carry = 0;
            base[i] = '0' + temp;
        }
        i++;
    }
    while (carry > 0) {
        if (base[i] >= '0' && base[i] <= '9') {
            temp = (int)(base[i] - '0');
        } else {
            temp = 0;
        }
        temp += carry;
        if (temp > 9) {
            carry = 1;
            base[i] = '0' + (temp % 9);
        } else {
            carry = 0;
            base[i] = '0' + temp;
        }
        i++;
    }
}

void int_multi(char *base, char *multi) {
    int m = 0, n = 0;
    while (base[m] != '\0') {
        m++;
    }
    while (multi[n] != '\0') {
        n++;
    }
    char add_base[MAX_LENGTH];
    memset(add_base, 0, MAX_LENGTH * sizeof(char));
    for (int i = n - 1; i >= 0; i--) {
        int index = 0;
        char integer[MAX_LENGTH];
        memset(integer, 0, MAX_LENGTH * sizeof(char));
        
        int zero = n - 1 - i;
        int multipler = (int)(multi[i] - '0');
        for (int z = 0; z < zero; z++) {
            integer[z] = '0';
            index++;
        }
        
        int carry = 0;
        for (int j = m - 1; j >= 0; j--) {
            int tmp = ((int)(base[j] - '0')) * multipler + carry;
            carry = tmp / 10;
            integer[index++] = tmp % 10 + '0';
        }
        if (carry > 0) {
            integer[index++] = carry + '0';
        }
        
        reverse_add(add_base, integer);
    }
    int length = 0;
    while (add_base[length] != '\0') {
        length++;
    }
    for (int j = length - 1; j >= 0; j--) {
        base[length - j - 1] = add_base[j];
    }
}

void big_multi(BigNum *base, BigNum *multi) {
    base->n += multi->n;
    int_multi(base->base, multi->base);
}

void big_exp(BigNum *num, BigNum *base, int power) {
    for (int i = 0; i < power; i++) {
        big_multi(num, base);
    }
}

int main(void) {
    int n = 0;
    char input[7] = {0};
    char output[MAX_LENGTH];
    while (scanf("%s%d", input, &n) == 2) {
        memset(output, 0, MAX_LENGTH * sizeof(char));
        BigNum num = {{'1'}, 0};
        BigNum base = {{'0'}, 0};
        big_exp(&num, real2Big(input, &base), n);
        printf("%s\n", format(&num, output));
    }
    return 0;
}
