#include <stdlib.h>
#include <stdio.h>
int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int* scores = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Score %d: ", i+1);
        scanf("%d", &scores[i]);
    }

    free(scores);  // ปิดท้ายทุกครั้ง!
}