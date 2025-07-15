#include <stdio.h>
int studen1;
int studen2;
int studen3;
int studen4;
int x;
int score;

int main() 
{
printf("score1 ");
scanf("%d", &studen1);

printf("score2 ");
scanf("%d", &studen2);

printf("score3 ");
scanf("%d", &studen3);

printf("score4 ");
scanf("%d", &studen4);

printf("number this u want 1 2 3 or 4 ");
scanf("%d", &x);
switch (x)
{
case 1:
    printf("\nscore1: %d\nscore2: %d\nscore3: %d\nscore4: %d\n",studen1,studen2,studen3,studen4);
    score = studen1 + studen2+ studen3 +studen4;
    printf("Total score: %d\n", score );
    break;
case 2:
    printf("\nscore1: %d\nscore2: %d\nscore3: %d\nscore4: %d\n",studen1,studen2,studen3,studen4);
    score = studen1 - studen2 - studen3 - studen4;
    printf("Total score: %d\n", score );
    break;
case 3:
    printf("\nscore1: %d\nscore2: %d\nscore3: %d\nscore4: %d\n",studen1,studen2,studen3,studen4);
    score = studen1 * studen2* studen3 *studen4;
    printf("Total score: %d\n", score );
    break;
case 4:
    printf("\nscore1: %d\nscore2: %d\nscore3: %d\nscore4: %d\n",studen1,studen2,studen3,studen4);
    score = studen1 / studen2 / studen3 /studen4;
    printf("Total score: %d\n", score );
    break;
default:
    break;
}
}