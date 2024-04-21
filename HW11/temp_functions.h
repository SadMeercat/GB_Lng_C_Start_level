#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

// Структура для хранения данных о температуре
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureData;

// Прототипы функций
void print_usage(char *program_name);
void process_file(char *filename, int month_filter);

#endif /* TEMP_FUNCTIONS_H */
