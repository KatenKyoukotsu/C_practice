#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

int main() {
    FILE *input_file, *output_file;
    char s[MAX_LEN + 1];
    char *found;

    // Открываем файл input.txt для чтения
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Dont open your fucking document, eblan na usere\n");
        return 1;
    }

    // Считываем строку из файла
    fgets(s, MAX_LEN + 1, input_file);

    // Закрываем файл
    fclose(input_file);

    // Заменяем все вхождения 'это' на 'то'
    while ((found = strstr(s, "это")) != NULL) {
        memmove(found + 2, found + 4, strlen(found + 4) + 1);
        strncpy(found, "то", 2);
    }

    // Открываем файл output.txt для записи
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Dont open document, sneak\n");
        return 1;
    }

    // Записываем измененную строку в файл
    fputs(s, output_file);

    // Закрываем файл
    fclose(output_file);

    return 0;
}