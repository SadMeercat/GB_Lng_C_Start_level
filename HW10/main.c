#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Задача 1: Пары соседних символов
void swapAdjacentPairs(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i += 2) {
        if (str[i] != ' ' && str[i + 1] != ' ') {
            char temp = str[i];
            str[i] = str[i + 1];
            str[i + 1] = temp;
        }
    }
}

// Задача 2: Удалить пробелы из текста
void removeExtraSpaces(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Задача 3: Изменить расширение
void changeExtension(char *filename) {
    char *extension = strrchr(filename, '.');
    if (extension != NULL) {
        strcpy(extension, ".html");
    } else {
        strcat(filename, ".html");
    }
}

int main() {
    // Открытие файла для задачи 1
    FILE *file1 = fopen("hello world.txt", "r+");
    if (file1 == NULL) {
        perror("Error open hello world.txt");
        return EXIT_FAILURE;
    }

    // Чтение содержимого файла для задачи 1
    char str1[1000];
    fgets(str1, sizeof(str1), file1);

    // Задача 1: Пары соседних символов
    swapAdjacentPairs(str1);

    // Перемещаем указатель файла в начало для перезаписи
    rewind(file1);

    // Перезаписываем измененные данные в файл
    fputs(str1, file1);

    // Закрываем файл для задачи 1
    fclose(file1);

    // Открытие файла для задачи 2
    FILE *file2 = fopen("hello world2.txt", "r+");
    if (file2 == NULL) {
        perror("Error open hello world2.txt");
        return EXIT_FAILURE;
    }

    // Чтение содержимого файла для задачи 2
    char str2[1000];
    fgets(str2, sizeof(str2), file2);

    // Задача 2: Удалить пробелы из текста
    removeExtraSpaces(str2);

    // Перемещаем указатель файла в начало для перезаписи
    rewind(file2);

    // Перезаписываем измененные данные в файл
    fputs(str2, file2);

    // Закрываем файл для задачи 2
    fclose(file2);

    // Открытие файла для задачи 3
    FILE *file3 = fopen("filename.txt", "r+");
    if (file3 == NULL) {
        perror("Error open filename.txt");
        return EXIT_FAILURE;
    }

    // Чтение содержимого файла для задачи 3
    char filename[1000];
    fgets(filename, sizeof(filename), file3);

    // Задача 3: Изменить расширение
    changeExtension(filename);

    // Перемещаем указатель файла в начало для перезаписи
    rewind(file3);

    // Перезаписываем измененные данные в файл
    fputs(filename, file3);

    // Закрываем файл для задачи 3
    fclose(file3);

    return EXIT_SUCCESS;
}
