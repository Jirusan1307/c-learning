#include <stdio.h>

void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

int add(int a, int b) {
    return a + b;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    greet("Kai");
    
    int sum = add(5, 6);
    printf("Sum = %d\n", sum);

    int x = 10, y = 20;
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}
