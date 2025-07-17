#include <stdio.h>

// ตัวแปรธรรมดาเก็บค่า 10
int pm = 10;

// สร้าง pointer p ชี้ไปยังตัวแปร pm
int *p = &pm;

// สร้าง array ชื่อ num มีสมาชิก 3 ค่า: 10, 20, 30
int num[3] = {10,20,30};

// สร้าง pointer a ชี้ไปยังตำแหน่งแรกของ array num
int *a = num;

void swap(int* x, int* y,int*z) {
    int temp = *x;
    *x = *y;
    *y =*z;
    *z = temp;
}


int main()
{
    // แสดงค่าของตัวแปร pm (คือ 10)
    printf("%d\n", pm);

    // แสดง address ของ pm (ตำแหน่งในหน่วยความจำ)
    printf("%p\n", &pm);

    // แสดงค่าที่เก็บอยู่ใน pointer p (คือ address ของ pm)
    printf("%p\n", p);

    // แสดงค่าที่ pointer p ชี้ไป (คือค่าของ pm = 10)
    printf("%d\n", *p);

    // ❌ ผิด type: num คือ address แต่ใช้ %d → ค่าที่แสดงจะเพี้ยน
    // เหมือนนำ address ไปตีความเป็นจำนวนเต็มแบบผิดประเภท
    printf("%d\n", num);

    // แสดงค่าของ num[0] (10)
    printf("%d\n", num[0]);

    // แสดงค่าของ num[1] (20)
    printf("%d\n", num[1]);

    // แสดงค่าของ num[2] (30)
    printf("%d\n", num[2]);

    // แสดง address ของตำแหน่งแรกของ array num (เท่ากับ &num[0])
    printf("%p\n", num);

    // แสดง address ของ array ทั้งก้อน num (type คือ int (*)[3]) → ค่าเดียวกันกับ num
    printf("%p\n", &num);

    // แสดง address ที่ pointer a ชี้ไป (คือ address ของ num[0])
    printf("%p\n", a);

    // แสดงค่าที่ pointer a ชี้อยู่ (คือ num[0] = 10)
    printf("%d\n", *a);

    // แสดงค่าจากตำแหน่งถัดไปใน array (num[1] = 20)
    printf("%d\n", *(a+1));

    // แสดงค่าจากตำแหน่งถัดไปใน array (num[2] = 30)
    printf("%d\n", *(a+2));

    // เรียกใช้ฟังก์ชัน swap → ส่ง address ของ num[0], num[1], num[2]
    swap(&num[0], &num[1], &num[2]);

    // แสดงค่าหลังจาก swap (สลับ: num[0] ← num[1], num[1] ← num[2], num[2] ← num[0])
    printf("%d\n", *a);       // ควรได้ num[0] ใหม่
    printf("%d\n", *(a+1));   // ควรได้ num[1] ใหม่
    printf("%d\n", *(a+2));   // ควรได้ num[2] ใหม่

}
