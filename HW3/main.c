#include <stdio.h>

int main() {
    task1();
    task2();
    task3();
    task4();
    
    return 0;
}

void task1(){
     int a, b, c, d, e;
    printf("Enter 5 numbers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    if (e > max) max = e;
    
    printf("output: %d\n", max);
}

void task2(){
    int a, b, c, d, e;
    printf("Enter 5 numbers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;
    
    printf("output: %d\n", min);
}

void task3(){
    int a, b, c;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a < b && b < c)
        printf("output: YES\n");
    else
        printf("output: NO\n");
}

void task4(){
    int month;
    printf("Enter number of month: ");
    scanf("%d", &month);
    
    char* season;
    switch (month) {
        case 12:
        case 1:
        case 2:
            season = "winter";
            break;
        case 3:
        case 4:
        case 5:
            season = "spring";
            break;
        case 6:
        case 7:
        case 8:
            season = "summer";
            break;
        case 9:
        case 10:
        case 11:
            season = "autumn";
            break;
        default:
            season = "invalid";
            break;
    }
}