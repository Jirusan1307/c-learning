#include <stdio.h>
#include <stdlib.h>

// ฟังก์ชันรับคะแนนนักเรียนจำนวน size ตัวผ่าน pointer scores
void inputScores(int *scores, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter score for student %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
}

// ฟังก์ชันคำนวณค่าเฉลี่ยคะแนน
float calculateAverage(int *scores, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return (float)sum / size;
}

// ฟังก์ชันรับคะแนนและคืนเกรดตัวอักษร
char getGrade(int score) {
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

// ฟังก์ชันแสดงคะแนนและเกรดของนักเรียนแต่ละคน
void printGrades(int *scores, int size) {
    for (int i = 0; i < size; i++) {
        char grade = getGrade(scores[i]);
        printf("Student %d: Score = %d, Grade = %c\n", i + 1, scores[i], grade);
    }
}

// ฟังก์ชันหาคะแนนสูงสุดใน array scores
int findHighestScore(int *scores, int size) {
    int max = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

int main() {
    int n = 0;
    int *scores = NULL;
    int choice;
    int scoresEntered = 0;  // ตัวแปรเช็คว่ากรอกคะแนนแล้วหรือยัง

    // รับจำนวนคนจากผู้ใช้ ต้องมากกว่า 0
    do {
        printf("Enter number of students (must be > 0): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid number. Please try again.\n");
        }
    } while (n <= 0);

    // จองหน่วยความจำ
    scores = (int*)malloc(n * sizeof(int));
    if (scores == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n==== Menu ====\n");
        printf("1: Input Scores\n");
        printf("2: Show Grades\n");
        printf("3: Show Average\n");
        printf("4: Show Highest Score\n");
        printf("0: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputScores(scores, n);
                scoresEntered = 1;
                break;
            case 2:
                if (scoresEntered)
                    printGrades(scores, n);
                else
                    printf("Please input scores first (choose option 1).\n");
                break;
            case 3:
                if (scoresEntered) {
                    float avg = calculateAverage(scores, n);
                    printf("\nAverage score: %.2f\n", avg);
                } else {
                    printf("Please input scores first (choose option 1).\n");
                }
                break;
            case 4:
                if (scoresEntered) {
                    int highest = findHighestScore(scores, n);
                    printf("Highest score: %d\n", highest);
                } else {
                    printf("Please input scores first (choose option 1).\n");
                }
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    free(scores);
    return 0;
}
