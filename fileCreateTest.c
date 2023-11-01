#include <stdio.h>

int main() {
    // Создаем и открываем входной бинарный файл для записи
    FILE *inputFile = fopen("input.bin", "wb");

    if (inputFile == NULL) {
        printf("Ошибка создания входного файла.\n");
        return 1;
    }

    // Заполняем входной файл данными "FF FF FF FF FE FF FF FF"
    unsigned char data[] = {0x00, 0x00, 0x00, 0x05};
    size_t dataSize = sizeof(data) / sizeof(data[0]);
    size_t elementsWritten = fwrite(data, sizeof(unsigned char), dataSize, inputFile);

    if (elementsWritten != dataSize) {
        printf("Ошибка записи данных во входной файл.\n");
        fclose(inputFile);
        return 1;
    }

    fclose(inputFile);  // Закрываем входной файл

    // Далее, вы можете использовать ваш исходный код для чтения и обработки входного файла и записи результата в выходной файл.

    return 0;
}
