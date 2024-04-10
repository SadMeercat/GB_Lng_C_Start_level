#include <stdio.h>

// Задача 1: Среднее арифметическое чисел
float average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return (float) sum / size;
}

// Задача 2: Найти минимум
int find_minimum(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Задача 3: Циклический сдвиг массива вправо на 4
void shift_array(int arr[], int size, int shift) {
    int temp[shift];
    for (int i = size - shift; i < size; ++i) {
        temp[i - size + shift] = arr[i];
    }
    for (int i = size - shift - 1; i >= 0; --i) {
        arr[i + shift] = arr[i];
    }
    for (int i = 0; i < shift; ++i) {
        arr[i] = temp[i];
    }
}

// Задача 4: Отсортировать по последней цифре
void bubble_sort_by_last_digit(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] % 10 > arr[j + 1] % 10) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Задача 5: Вторая с конца ноль
void select_second_from_end_zero(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        int num = arr[i];
        int second_from_end = (num / 10) % 10;
        if (second_from_end == 0) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Задача 6: Чаще других
int find_most_common(int arr[], int size) {
    int count[100] = {0}; // Предполагаем, что числа в массиве не превышают 100
    for (int i = 0; i < size; ++i) {
        count[arr[i]]++;
    }
    int max_count = 0, most_common = 0;
    for (int i = 0; i < 100; ++i) {
        if (count[i] > max_count) {
            max_count = count[i];
            most_common = i;
        }
    }
    return most_common;
}

int main() {
    // Примеры использования функций

    // Задача 1
    int arr1[] = {4, 15, 3, 10, 14};
    printf("Ex 1\n");
    printf("Output: %.3f\n", average(arr1, 5));

    // Задача 2
    int arr2[] = {4, 15, 3, 10, 14};
    printf("\nEx 2\n");
    printf("Output: %d\n", find_minimum(arr2, 5));

    // Задача 3
    int arr3[] = {4, -5, 3, 10, -4, -6, 8, -10, 1, 0, 5, 7};
    printf("\nEx 3\n");
    shift_array(arr3, 12, 4);
    printf("Output: ");
    for (int i = 0; i < 12; ++i) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // Задача 4
    int arr4[] = {14, 25, 13, 30, 76, 58, 32, 11, 41, 97};
    printf("\nEx 4\n");
    bubble_sort_by_last_digit(arr4, 10);
    printf("Output: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr4[i]);
    }
    printf("\n");

    // Задача 5
    int arr5[] = {40, 105, 203, 1, 14, 1000, 22, 33, 44, 55};
    printf("\nEx 5\n");
    printf("Output: ");
    select_second_from_end_zero(arr5, 10);

    // Задача 6
    int arr6[] = {4, 1, 2, 1, 11, 2, 34, 11, 0, 11};
    printf("\nEx 6\n");
    printf("Output: %d\n", find_most_common(arr6, 10));

    return 0;
}