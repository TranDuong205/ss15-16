#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2, *file5;
    char ch;
    file1 = fopen("bt01.txt", "r");
    file5 = fopen("bt5.txt", "w");

    if (file1 == NULL || file5 == NULL) {
        fprintf(stderr, "loi khi mo file.\n");
        return 1;
    }
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file5);
    }
    fclose(file1);
    file2 = fopen("bt03.txt", "r");
    file5 = fopen("bt5.txt", "a");

    if (file2 == NULL || file5 == NULL) {
        fprintf(stderr, "loi khi mo file.\n");
        return 1;
    }
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, file5);
    }
    fclose(file2);
    fclose(file5);

    printf("noi dung tu bt01.txt và bt03.txt da duoc sao chep vao bt5.txt.\n");

    return 0;
}

