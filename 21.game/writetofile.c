
#include "21.header file.h"

void writeToFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("�L�k�}���ɮ� %s �i��g�J�C\n", filename);
        return;
    }

    fprintf(file, "%s\n", content);
    fclose(file);
}