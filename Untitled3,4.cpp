#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[100];
    int numLines;
    printf("Nhap so dong ban muon nhap: ");
    scanf("%d", &numLines);
    file = fopen("bt03.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Khong the mo hoac tao file bt03.txt de ghi.\n");
        return 1; 
    }
    for (int i = 0; i < numLines; ++i) {
        printf("Nhap noi dung dong %d: ", i + 1);
        scanf(" %[^\n]s", buffer);
        fprintf(file, "%s\n", buffer);
    }
    fclose(file);
    file = fopen("bt03.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Khong the mo file bt03.txt de doc.\n");
        return 1; 
    }
    printf("\nNoi dung trong file bt03.txt:\n");
    int lineCount = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Dong %d: %s", ++lineCount, buffer);
    }
    fclose(file);
    printf("So dong trong file: %d\n", lineCount);

    return 0;
}

