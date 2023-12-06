#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char user_input[100];
    printf("Nhap chuoi ban muon ghi vao file: ");
    fgets(user_input, sizeof(user_input), stdin);
    file = fopen("bt01.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Khong the mo file bt01.txt de ghi.\n");
        return 1; 
    }
    fprintf(file, "%s", user_input);
    fclose(file);

    printf("Chuoi '%s' da duoc ghi vao file bt01.txt.\n", user_input);

    return 0;
}

