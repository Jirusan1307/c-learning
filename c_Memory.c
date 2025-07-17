#include <stdlib.h>
#include <stdio.h>

int main() {
    int* arr = (int*)malloc(3 * sizeof(int));  // จอง array 3 ตัว

    if (arr == NULL) {
        printf("ไม่สามารถจอง memory ได้\n");
        return 1;
    }

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    for (int i = 0; i < 3; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr); // ต้องคืนหน่วยความจำทุกครั้ง
    return 0;
}
