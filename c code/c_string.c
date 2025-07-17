#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    int score;
    
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // ลบ '\n' ที่แถมมากับ fgets

    printf("Enter your score: ");
    scanf("%d", &score);

    char grade;
    if (score >= 80) grade = 'A';
    else if (score >= 70) grade = 'B';
    else if (score >= 60) grade = 'C';
    else if (score >= 50) grade = 'D';
    else grade = 'F';

    printf("%s got grade %c\n", name, grade);
    return 0;
}
