#include <stdio.h>
#include <math.h>

// Задача 1: В прямом порядке
void print_num(int num) {
    if (num < 10) {
        printf("%d ", num);
        return;
    }
    print_num(num / 10);
    printf("%d ", num % 10);
}

// Задача 2: От A до B
void print_sequence(int a, int b) {
    if (a == b) {
        printf("%d ", a);
        return;
    }
    if (a < b) {
        printf("%d ", a);
        print_sequence(a + 1, b);
    } else {
        printf("%d ", a);
        print_sequence(a - 1, b);
    }
}

// Задача 3: Количество 1
int count_ones(int n) {
    if (n == 0)
        return 0;
    return (n & 1) + count_ones(n >> 1);
}

// Задача 4: Все нечетные
void print_odd_numbers(const int numbers[]) {
    for (int i = 0; numbers[i] != 0; i++) {
        if (numbers[i] % 2 != 0)
            printf("%d ", numbers[i]);
    }
    printf("\n");
}

// Задача 5: Сколько раз встречается символ a
int acounter(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '.'; i++) {
        if (str[i] == 'a')
            count++;
    }
    return count;
}

// Задача 6: Возвести в степень
int recurs_power(int n, int p) {
    if (p == 0)
        return 1;
    return n * recurs_power(n, p - 1);
}

int main() {
    // Примеры использования функций

    // Задача 1
    printf("Ex 1\n");
    printf("Input data: 15\n");
    printf("Output data: ");
    print_num(15);
    printf("\n");

    // Задача 2
    printf("\nEx 2\n");
    printf("Input data: 5 2\n");
    printf("Output data: ");
    print_sequence(5, 2);
    printf("\n");

    // Задача 3
    printf("\nEx 3\n");
    printf("Input data: 5\n");
    printf("Output data: %d\n", count_ones(5));

    // Задача 4
    printf("\nEx 4\n");
    printf("Input data: 12 13 173 28 19 0\n");
    int numbers1[] = {12, 13, 173, 28, 19, 0};
    printf("Output data: ");
    print_odd_numbers(numbers1);
    printf("\n");

    // Задача 5
    printf("\nEx 5\n");
    printf("Input data: abcd a.\n");
    const char *str1 = "abcd a.";
    printf("Output data: %d\n", acounter(str1));

    // Задача 6
    printf("\nEx 6\n");
    printf("Input data: 2 3\n");
    printf("Output data: %d\n", recurs_power(2, 3));

    return 0;
}