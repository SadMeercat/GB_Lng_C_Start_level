#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Задача 1: Сколько зерен на доске?
long long grains_on_square(int n) {
    if (n < 1 || n > 64)
        return -1; // Неправильный ввод
    return 1LL << (n - 1);
}

// Задача 2: НОД
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Задача 3: Сумма цифр равна произведению
bool is_happy_number(int n) {
    int sum = 0, product = 1, digit;
    int num = n;
    while (num > 0) {
        digit = num % 10;
        sum += digit;
        product *= digit;
        num /= 10;
    }
    return sum == product;
}

// Задача 4: Сумма от 1 до N
int sum_up_to_n(int n) {
    return (n * (n + 1)) / 2;
}

// Задача 5*: Скобки
bool check_brackets(const char *str) {
    int balance = 0;
    for (int i = 0; str[i] != '.'; i++) {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')') {
            balance--;
            if (balance < 0)
                return false; // Неправильное распределение скобок
        }
    }
    return balance == 0;
}

int main() {
    // Примеры использования функций

    // Задача 1
    printf("Ex 1\n");
    printf("Input data: 3\n");
    printf("Output data: %lld\n", grains_on_square(3));

    // Задача 2
    printf("\nEx 2\n");
    printf("Input data: 14 21\n");
    printf("Output data: %d\n", gcd(14, 21));

    // Задача 3
    printf("\nEx 3\n");
    printf("Input data: 123\n");
    printf("Output data: %s\n", is_happy_number(123) ? "YES" : "NO");

    // Задача 4
    printf("\nEx 4\n");
    printf("Input data: 100\n");
    printf("Output data: %d\n", sum_up_to_n(100));

    // Задача 5*
    printf("\nEx 5\n");
    printf("Input data: (()()).\n");
    printf("Output data: %s\n", check_brackets("(()()).") ? "YES" : "NO");

    return 0;
}