#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    char hoTen[100];
    int tuoi;
    char soDienThoai[20];
    char email[50];
};

int main() {
    FILE *fileStudents;
    int n;
    printf("nhap so luong sinh vien: ");
    scanf("%d", &n);
    fileStudents = fopen("students.txt", "w");
    if (fileStudents == NULL) {
        fprintf(stderr, "L?i khi m? file students.txt d? ghi.\n");
        return 1;
    }
    struct SinhVien danhSachSinhVien[n];
    for (int i = 0; i < n; ++i) {
        printf("Nh?p thông tin sinh viên %d:\n", i + 1);
        printf("H? và tên: ");
        scanf(" %[^\n]s", danhSachSinhVien[i].hoTen);
        printf("Tu?i: ");
        scanf("%d", &danhSachSinhVien[i].tuoi);
        printf("S? di?n tho?i: ");
        scanf(" %[^\n]s", danhSachSinhVien[i].soDienThoai);
        printf("Email: ");
        scanf(" %[^\n]s", danhSachSinhVien[i].email);
        fprintf(fileStudents, "%s %d %s %s\n",
                danhSachSinhVien[i].hoTen,
                danhSachSinhVien[i].tuoi,
                danhSachSinhVien[i].soDienThoai,
                danhSachSinhVien[i].email);
    }
    fclose(fileStudents);

    printf("Thông tin sinh viên dã du?c nh?p và luu vào file students.txt.\n");

    return 0;
}

