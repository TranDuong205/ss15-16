#include <stdio.h>
#include <string.h>

// Khai báo c?u trúc sinh viên
struct SinhVien {
    char hoTen[50];
    int tuoi;
    char SoDienThoai[20];
    char email[50];
};

// Prototypes c?a các hàm
void nhapThongTin(struct SinhVien *sv);
void xuatThongTin(const struct SinhVien *sv);

int main() {
    struct SinhVien sinhVien1;

    nhapThongTin(&sinhVien1);
    xuatThongTin(&sinhVien1);

    return 0;
}

void nhapThongTin(struct SinhVien *sv) {
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap so dien thoai: ");
    scanf("%s", sv->SoDienThoai);
    printf("Nhap email: ");
    scanf("%s", sv->email);
    while (getchar() != '\n');
}

void xuatThongTin(const struct SinhVien *sv) {
    printf("Thong tin cua sinh vien:\n");
    printf("Ho va ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s\n", sv->SoDienThoai);
    printf("Email: %s\n", sv->email);
}

