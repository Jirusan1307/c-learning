#include <stdio.h>

void inputScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter score for student %d: ", i+1);
        scanf("%d", &scores[i]);
    }
}


float calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return (float)sum / size;
}

char getGrade(int score) {
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

void printGrades(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        char grade = getGrade(scores[i]);
        printf("Student %d: Score = %d, Grade = %c\n", i+1, scores[i], grade);
    }
}

int findHighestScore(int scores[], int size) {
    int max = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}


int main() {
    int scores[5];
    inputScores(scores, 5);
    
    float avg = calculateAverage(scores, 5);
    printf("Average score: %.2f\n", avg);

    printGrades(scores, 5);

    int highest = findHighestScore(scores, 5);
    printf("Highest score: %d\n", highest);

    return 0;
}
