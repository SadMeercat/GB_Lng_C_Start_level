#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"

int main(int argc, char *argv[]) {
    char *filename = NULL;
    int month_filter = -1;
    int opt;

    // Считываем аргументы командной строки
    while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
        switch (opt) {
            case 'h':
                print_usage(argv[0]);
                exit(EXIT_SUCCESS);
            case 'f':
                filename = optarg;
                break;
            case 'm':
                month_filter = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -f <filename.csv> [-m <month_number>]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Проверяем наличие обязательного аргумента -f
    if (filename == NULL) {
        fprintf(stderr, "Missing argument: -f <filename.csv>\n");
        exit(EXIT_FAILURE);
    }

    // Обрабатываем файл с данными
    process_file(filename, month_filter);

    return 0;
}
