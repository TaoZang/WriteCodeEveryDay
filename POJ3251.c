#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

void calcu(Point m, Point n, Point *a, Point *b, int direction) {
    Point vector = {.x = (n.x - m.x), .y = (n.y - m.y)};
    Point delta = {.x = -vector.y * direction, .y = vector.x * direction};
    a->x = delta.x + m.x;
    a->y = delta.y + m.y;
    b->x = a->x + vector.x;
    b->y = a->y + vector.y;
}

int area(Point m, Point n) {
    int x = abs(m.x - n.x);
    int y = abs(m.y - n.y);
    return (x + y) * (x + y) - (x * y * 2);
}

int is_valid(Point m, int limit) {
    if (m.x < 0 || m.y < 0 || m.x >= limit || m.y >= limit) {
        return 0;
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    char c;
    char input[10000];
    int count = 0;
    Point occupied[10000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &c);
            input[i * n + j] = c;
            if (c == 'J') {
                Point p = {.x = i, .y = j};
                occupied[count++] = p;
            }
        }
    }

    Point a1, b1, a2, b2;
    int max = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            calcu(occupied[i], occupied[i + 1], &a1, &b1, 1);
            calcu(occupied[i], occupied[i + 1], &a2, &b2, -1);
            if (is_valid(a1, n) && is_valid(b1, n)) {
                int ia = a1.x * n + a1.y;
                int ib = b1.x * n + b1.y;
                if ((input[ia] == '*' && input[ib] == 'J') ||
                    (input[ia] == 'J' && input[ib] == '*')) {
                    int current = area(a1, b1);
                    if (max < current) {
                        max = current;
                        continue;
                    }
                }
            }
            if (is_valid(a2, n) && is_valid(b2, n)) {
                int ic = a2.x * n + a2.y;
                int id = b2.x * n + b2.y;
                if ((input[ic] == '*' && input[id] == 'J') ||
                    (input[ic] == 'J' && input[id] == '*')) {
                    int current = area(a2, b2);
                    if (max < current) {
                        max = current;
                    }
                }
            }
        }
    }

    printf("%d", max);

    return 0;
}
