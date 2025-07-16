#include <stdio.h>


void loop()  
{
    int abb;
    int num1;
    int num2;
    float number;
    printf("please input num 1, 2, 3, 4  ");
    scanf("%d", &abb);

    if (abb == 1 || abb == 2 || abb == 3 || abb == 4) {
        printf("You entered: %d\n", abb); 
    } else {
        printf("Out of range\n"); 
        return; 
    }

    printf("Please input num1: ");
    scanf("%d", &num1);
    printf("Please input num2: ");
    scanf("%d", &num2);

    switch (abb)
    {
        case 1:
            number = num1 + num2;
            printf("num1 + num2 = %.2f\n", number);
            break;
        case 2:
            number = num1 - num2;
            printf("num1 - num2 = %.2f\n", number);
            break;
        case 3:
            number = num1 * num2;
            printf("num1 * num2 = %.2f\n", number);
            break;
        case 4:
            if (num2 == 0) {
                printf("Cannot divide by 0. Please try again.\n");
            } else {
                number = num1 / num2;
                printf("num1 / num2 = %.2f\n", number);
            }
            break;
        default:
            printf("Unknown error.\n");
            break;
    }
}

int main() {
    while (1) {
        loop();
    }
}
