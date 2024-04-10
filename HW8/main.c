#include <stdio.h>
// Задача 1: Сортировка по возрастанию
void sort_array(int size, int a[]) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Задача 2: Четные в начало
void sort_even_odd(int n, int a[]) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (a[i] % 2 == 0 && i < j) {
            ++i;
        }
        while (a[j] % 2 != 0 && i < j) {
            --j;
        }
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

// Задача 3: Максимум в массиве
int find_max_array(int size, int a[]) {
    int max = a[0];
    for (int i = 1; i < size; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Задача 4: Два одинаковых
int is_two_same(int size, int a[]) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (a[i] == a[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Задача 5: Поменять местами
void change_max_min(int size, int a[]) {
    int min_index = 0, max_index = 0;
    for (int i = 1; i < size; ++i) {
        if (a[i] < a[min_index]) {
            min_index = i;
        }
        if (a[i] > a[max_index]) {
            max_index = i;
        }
    }
    int temp = a[min_index];
    a[min_index] = a[max_index];
    a[max_index] = temp;
}

// Задача 6: Больше среднего
int count_positive_above_diagonal(int matrix[5][5]) {
    int sum = 0, count = 0;
    for (int i = 0; i < 5; ++i) {
        sum += matrix[i][i]; // Суммируем элементы главной диагонали
    }
    int average = sum / 5;
    for (int i = 0; i < 5; ++i) {
        if (matrix[i][i] > average) {
            ++count;
        }
    }
    return count;
}

int main() {
    // Пример вызова для задачи 1: Сортировка по возрастанию
    int arr1[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    sort_array(size1, arr1);
    printf("Sorted arr: ");
    for (int i = 0; i < size1; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Пример вызова для задачи 2: Четные в начало
    int arr2[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    sort_even_odd(size2, arr2);
    printf("Sorted arr: ");
    for (int i = 0; i < size2; ++i) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Пример вызова для задачи 3: Максимум в массиве
    int arr3[] = {773, 307, 371, 548, 531, 765, 402, 27, 573, 591, 217, 859, 662, 493, 173, 174, 125, 591, 324, 231, 130, 394, 573, 65, 570, 258, 343, 3, 586, 14, 785, 296, 140, 726, 598, 262, 807, 794, 510, 465, 66, 895, 182, 218, 302, 34, 205, 252, 687, 660, 952, 737, 2, 32, 310, 680, 36, 139, 346, 139, 489, 217, 767, 544, 158, 774, 883, 154, 802, 136, 569, 377, 867, 423, 224, 176, 118, 660, 513, 734, 45, 978, 983, 749, 909, 601, 270, 147, 433, 737, 789, 304, 842, 769, 815, 503, 190, 399, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Max element: %d\n", find_max_array(size3, arr3));

    // Пример вызова для задачи 4: Два одинаковых
    int arr4[] = {1, 2, 1, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    if (is_two_same(size4, arr4)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Пример вызова для задачи 5: Поменять местами
    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    change_max_min(size5, arr5);
    printf("Changed arr: ");
    for (int i = 0; i < size5; ++i) {
        printf("%d ", arr5[i]);
    }
    printf("\n");

    // Пример вызова для задачи 6: Больше среднего
    int matrix[5][5] = {{1, 1, 1, 1, 1},
                        {2, 2, 2, 2, 2},
                        {3, 3, 3, 3, 3},
                        {4, 4, 4, 4, 4},
                        {5, 5, 5, 5, 5}};
    printf("Ex 6: %d\n", count_positive_above_diagonal(matrix));

    return 0;
}
