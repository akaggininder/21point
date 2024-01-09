
#include "21.header file.h"

void writeToFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("無法開啟檔案 %s 進行寫入。\n", filename);
        return;
    }

    fprintf(file, "%s\n", content);
    fclose(file);
}