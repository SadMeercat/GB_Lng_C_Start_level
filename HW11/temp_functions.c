#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_functions.h"

#define MAX_LINE_LENGTH 1024
#define NUM_MONTHS 12

// Реализация функции вывода справки
void print_usage(char *program_name) {
    printf("Usage: %s -f <filename.csv> [-m <month_number>]\n", program_name);
    printf("-f <filename.csv>: input CSV file to process\n");
    printf("-m <month_number>: optional, specifies to output statistics only for the given month\n");
}

// Реализация функции обработки файла с данными
void process_file(char *filename, int month_filter) {
    // Открываем файл для чтения
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Переменные для хранения данных из CSV файла и для вычисления статистики
    int year, month, day, hour, minute, temperature;
    char line[MAX_LINE_LENGTH];
    int month_temperatures[NUM_MONTHS][3] = {0}; // [month][0]: сумма температур, [month][1]: минимальная температура, [month][2]: максимальная температура
    int year_sum = 0, year_min = 100, year_max = -100;
    int num_records[NUM_MONTHS] = {0}; // Количество записей по каждому месяцу

    // Считываем данные из файла
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Используем strtok для разделения строки на значения
        char *token = strtok(line, ";");
        year = atoi(token);

        token = strtok(NULL, ";");
        month = atoi(token);

        token = strtok(NULL, ";");
        day = atoi(token);

        token = strtok(NULL, ";");
        hour = atoi(token);

        token = strtok(NULL, ";");
        minute = atoi(token);

        token = strtok(NULL, ";");
        temperature = atoi(token);

        // Обновляем статистику только если данные соответствуют фильтру месяца (если задан)
        if (month_filter == -1 || month == month_filter) {
            month_temperatures[month - 1][0] += temperature;
            if (temperature < month_temperatures[month - 1][1])
                month_temperatures[month - 1][1] = temperature;
            if (temperature > month_temperatures[month - 1][2])
                month_temperatures[month - 1][2] = temperature;

            year_sum += temperature;
            if (temperature < year_min)
                year_min = temperature;
            if (temperature > year_max)
                year_max = temperature;

            num_records[month - 1]++;
        }
    }

    // Выводим статистику
    if (month_filter == -1) {
        printf("Monthly statistics:\n");
        for (int i = 0; i < NUM_MONTHS; i++) {
            if (num_records[i] > 0) {
                printf("Month %d: Avg: %.2f, Min: %d, Max: %d\n", 
                       i + 1, (float)month_temperatures[i][0] / num_records[i], 
                       month_temperatures[i][1], month_temperatures[i][2]);
            } else {
                printf("Month %d: No data\n", i + 1);
            }
        }
    }

    printf("\nYearly statistics:\n");
    printf("Avg: %.2f, Min: %d, Max: %d\n", 
           (float)year_sum / (NUM_MONTHS * 24 * 60), year_min, year_max);

    // Закрываем файл
    fclose(file);
}
