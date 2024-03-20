#include <stdio.h>
#include <locale.h>

int main() {
    task1();
    task2();
    task3();
    return 0;
}

void task1(){
    int a, b, c;
    printf("type 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int sum = a + b + c;
    printf("output: %d+%d+%d=%d\n", a, b, c, sum);
}

void task2(){
    int a, b, c;
    printf("type 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int sum = a + b + c;
    int product = a * b * c;
    printf("ouput: %d+%d+%d=%d\n", a, b, c, sum);
    printf("%d*%d*%d=%d\n", a, b, c, product);
}

void task3(){
    int a, b;
    printf("type 2 numbers: ");
    scanf("%d %d", &a, &b);
    int difference = a - b;
    printf("output: %d\n", difference);
}