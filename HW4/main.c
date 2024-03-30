#include <stdio.h>
#include <stdbool.h>

// Задача 1: Сумма квадратов маленьких чисел
int sum_of_squares(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += i * i;
    }
    return sum;
}

// Задача 2: Ровно три цифры
char* exactly_three_digits(int num) {
    return (num >= 100 && num <= 999) ? "YES" : "NO";
}

// Задача 3: Все цифры четные
char* all_even_digits(int num) {
    while (num > 0) {
        if ((num % 10) % 2 != 0) {
            return "NO";
        }
        num /= 10;
    }
    return "YES";
}

// Задача 4: Перевернуть число
int reverse_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Задача 5: Все счастливые числа
bool is_happy(int num) {
    int sum = 0, product = 1;
    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        product *= digit;
        num /= 10;
    }
    return sum == product;
}

void happy_numbers(int n) {
    printf("Output: ");
    for (int i = 10; i <= n; i++) {
        if (is_happy(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    // Примеры использования функций
    // Задача 1
    printf("Ex 1\n");
    printf("Input data: 4 10\n");
    printf("Output data: %d\n", sum_of_squares(4, 10));

    // Задача 2
    printf("\nEx 2\n");
    printf("Input data: 1234\n");
    printf("Output data: %s\n", exactly_three_digits(1234));

    // Задача 3
    printf("\nEx 3\n");
    printf("Input data: 2994\n");
    printf("Output data: %s\n", all_even_digits(2994));

    // Задача 4
    printf("\nEx 4\n");
    printf("Input data: 782\n");
    printf("Output data: %d\n", reverse_number(782));

    // Задача 5
    printf("\nEx 5\n");
    printf("Input data: 1000\n");
    happy_numbers(1000);

    return 0;
}