#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Задача 1. По одному разу
void find_unique_characters(const char *words) {
    char word1[101], word2[101];
    sscanf(words, "%s %s", word1, word2);
    int count[256] = {0};
    for (int i = 0; word1[i] != '\0'; i++) {
        count[(int)word1[i]]++;
    }
    for (int i = 0; word2[i] != '\0'; i++) {
        if (count[(int)word2[i]] == 1) {
            printf("%c ", word2[i]);
            count[(int)word2[i]] = 0; // чтобы не выводить символ повторно
        }
    }
}

// Задача 2. Заменить a на b
void replace_a_with_b(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'a')
            text[i] = 'b';
        else if (text[i] == 'b')
            text[i] = 'a';
        else if (text[i] == 'A')
            text[i] = 'B';
        else if (text[i] == 'B')
            text[i] = 'A';
    }
}

// Задача 3. Числа в массив
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void extract_numbers(const char *text) {
    int numbers[1000]; // assuming max length of numbers array
    int index = 0;
    char *token = strtok((char *)text, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            numbers[index++] = atoi(token);
        }
        token = strtok(NULL, " ");
    }
    qsort(numbers, index, sizeof(int), compare);
    for (int i = 0; i < index; i++) {
        printf("%d ", numbers[i]);
    }
}



// Задача 4. Удалить повторяющиеся символы
void remove_duplicates_and_spaces(char *text) {
    int hash[256] = {0};
    int len = strlen(text);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (text[i] != ' ' && hash[text[i]] == 0) {
            text[j++] = text[i];
            hash[text[i]] = 1;
        }
    }
    text[j] = '\0';
}

// Задача 5. Самое длинное слово
void longest_word(const char *text) {
    char longest[101] = "", word[101];
    sscanf(text, "%s", longest);
    while (sscanf(text, "%s", word) == 1) {
        if (strlen(word) > strlen(longest)) {
            strcpy(longest, word);
        }
        text += strlen(word) + 1;
    }
    printf("%s", longest);
}

// Задача 6. Заканчивается на a
int words_ending_with_a(const char *sentence) {
    int count = 0;
    char word[101];
    while (sscanf(sentence, "%s", word) == 1) {
        if (word[strlen(word) - 1] == 'a' || word[strlen(word) - 1] == 'A') {
            count++;
        }
        sentence += strlen(word) + 1;
    }
    return count;
}

int main() {
    // Пример вызова для задачи 1
    const char *words_input = "hello world";
    find_unique_characters(words_input);

    // Пример вызова для задачи 2
    char text_input[] = "aabbccddABCD";
    replace_a_with_b(text_input);
    printf("%s\n", text_input);

    // Пример вызова для задачи 3
    const char *text_input_3 = "data 48 call 9 read13 blank0a";
    extract_numbers(text_input_3);
    printf("\n");

    // Пример вызова для задачи 4
    char text_input_4[] = "abc cde def";
    remove_duplicates_and_spaces(text_input_4);
    printf("%s\n", text_input_4);

    // Пример вызова для задачи 5
    const char *text_input_5 = "Hello beautiful world";
    longest_word(text_input_5);
    printf("\n");

    // Пример вызова для задачи 6
    const char *sentence_input = "Mama mila ramu";
    int result = words_ending_with_a(sentence_input);
    printf("%d\n", result);

    return 0;
}
