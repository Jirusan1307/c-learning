#include <stdio.h>
#include <stdlib.h>

// ฟังก์ชันรับคะแนนนักเรียนจำนวน size ตัวผ่าน pointer scores
void inputScores(int *scores, int size) {
    for (int i = 0; i < size; i++) {
        // แสดงข้อความให้ผู้ใช้กรอกคะแนนนักเรียนคนที่ i+1
        printf("Enter score for student %d: ", i + 1);
        // รับคะแนนและเก็บไว้ในตำแหน่งที่ i ของ array scores
        scanf("%d", &scores[i]);
    }
}

// ฟังก์ชันคำนวณค่าเฉลี่ยคะแนน โดยรับ pointer ไปยัง array คะแนน และจำนวน size
float calculateAverage(int *scores, int size) {
    int sum = 0;  // ตัวแปรเก็บผลรวมคะแนนทั้งหมด
    for (int i = 0; i < size; i++) {
        sum += scores[i];  // บวกคะแนนแต่ละตัวเข้า sum
    }
    return (float)sum / size;  // แปลงเป็น float แล้วหารด้วยจำนวนคน (size) เพื่อหาค่าเฉลี่ย
}

// ฟังก์ชันรับคะแนน และคืนเกรดตัวอักษรตามเกณฑ์ที่กำหนด
char getGrade(int score) {
    if (score >= 80) return 'A';    // คะแนนตั้งแต่ 80 ขึ้นไปได้ A
    else if (score >= 70) return 'B'; // 70-79 ได้ B
    else if (score >= 60) return 'C'; // 60-69 ได้ C
    else if (score >= 50) return 'D'; // 50-59 ได้ D
    else return 'F';                  // ต่ำกว่า 50 ได้ F
}

// ฟังก์ชันแสดงคะแนนและเกรดของนักเรียนแต่ละคน
void printGrades(int *scores, int size) {
    for (int i = 0; i < size; i++) {
        char grade = getGrade(scores[i]);  // เรียกฟังก์ชัน getGrade เพื่อหาคะแนนเกรด
        printf("Student %d: Score = %d, Grade = %c\n", i + 1, scores[i], grade);  // แสดงผล
    }
}

// ฟังก์ชันหาคะแนนสูงสุดใน array scores
int findHighestScore(int *scores, int size) {
    int max = scores[0];  // กำหนดคะแนนตัวแรกเป็นค่ามากที่สุดเริ่มต้น
    for (int i = 1; i < size; i++) {
        if (scores[i] > max) {  // ถ้าพบคะแนนที่มากกว่า max
            max = scores[i];    // เปลี่ยน max เป็นค่านั้น
        }
    }
    return max;  // คืนค่าคะแนนสูงสุด
}

int main() {
    int n;  // ตัวแปรเก็บจำนวนคน

    // รับจำนวนคนจากผู้ใช้
    printf("Enter number of students: ");
    scanf("%d", &n);

    // จองหน่วยความจำแบบไดนามิกสำหรับเก็บคะแนนนักเรียน n คน
    int *scores = (int*)malloc(n * sizeof(int));

    // ตรวจสอบว่าการจองหน่วยความจำสำเร็จไหม
    if (scores == NULL) {
        printf("Memory allocation failed!\n");  // แสดง error หากจองไม่สำเร็จ
        return 1;  // ออกจากโปรแกรม
    }

    // เรียกฟังก์ชันเพื่อรับคะแนนจากผู้ใช้
    inputScores(scores, n);

    // คำนวณค่าเฉลี่ยคะแนนโดยใช้ฟังก์ชัน calculateAverage
    float avg = calculateAverage(scores, n);
    printf("\nAverage score: %.2f\n", avg);  // แสดงค่าเฉลี่ย (ทศนิยม 2 ตำแหน่ง)

    // แสดงคะแนนและเกรดของนักเรียนทุกคน
    printGrades(scores, n);

    // หาคะแนนสูงสุดในกลุ่ม และแสดงผล
    int highest = findHighestScore(scores, n);
    printf("Highest score: %d\n", highest);

    // คืนหน่วยความจำที่จองไว้ (สำคัญต้องทำทุกครั้งหลัง malloc)
    free(scores);

    return 0;  // จบโปรแกรมโดยปกติ
}
