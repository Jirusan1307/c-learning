#include <stdio.h>

int main() 
{
    int age;
    float gpa;
    char grade;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    printf("Enter your grade: ");
    scanf(" %c", &grade); // ต้องมี space ก่อน %c

    printf("\nYou entered:\nAge: %d\nGPA: %.2f\nGrade: %c\n", age, gpa, grade);

    return 0;
}
