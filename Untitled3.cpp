#include <stdio.h>
#include <string.h>

struct SinhVien {
    char hoTen[50];
    int tuoi;
    char sodienthoai[20];
    char email[50];
};

struct danhsachsinhvien {
    struct SinhVien sv[100];
    int soluong;
};

void nhapthongtin(struct SinhVien *sv);
void themsinhvien(struct danhsachsinhvien *ds, const struct SinhVien *sv);
void suasinhvien(struct danhsachsinhvien *ds, int vitri, const struct SinhVien *sv);
void xoasinhvien(struct danhsachsinhvien *ds, int vitri);
void indanhsachsinhvien(const struct danhsachsinhvien *ds);

int main() {
    struct danhsachsinhvien danhsach;
    danhsach.soluong = 0;

    struct SinhVien sv1 = {"Nguyen Gia Thieu", 30, "1122334455", "nammario@example.com"};
    themsinhvien(&danhsach, &sv1);

    struct SinhVien sv2 = {"Dang To Ngoc Dung", 40, "12345678999", "dungthichdanhtaixiu@example.com"};
    themsinhvien(&danhsach, &sv2);

    printf("Danh sach sinh vien:\n");
    indanhsachsinhvien(&danhsach);

    struct SinhVien svSua = {"Tran Manh Duong", 10, "999999999", "duongkhongdanhtaixiu@example.com"};
    suasinhvien(&danhsach, 1, &svSua);

    printf("\nDanh sach sinh vien sau khi sua:\n");
    indanhsachsinhvien(&danhsach);

    xoasinhvien(&danhsach, 0);

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    indanhsachsinhvien(&danhsach);

    return 0;
}

void nhapthongtin(struct SinhVien *sv) {
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap so dien thoai: ");
    scanf("%s", sv->sodienthoai);
    printf("Nhap email: ");
    scanf("%s", sv->email);
    while (getchar() != '\n');
}

void themsinhvien(struct danhsachsinhvien *ds, const struct SinhVien *sv) {
    if (ds->soluong < 100) {
        ds->sv[ds->soluong] = *sv;
        ds->soluong++;
    } else {
        printf("Danh sach da day, khong the them sinh vien moi\n");
    }
}

void suasinhvien(struct danhsachsinhvien *ds, int vitri, const struct SinhVien *sv) {
    if (vitri >= 0 && vitri < ds->soluong) {
        ds->sv[vitri] = *sv;
    } else {
        printf("Vi tri khong hop le\n");
    }
}

void xoasinhvien(struct danhsachsinhvien *ds, int vitri) {
    if (vitri >= 0 && vitri < ds->soluong) {
        for (int i = vitri; i < ds->soluong - 1; i++) {
            ds->sv[i] = ds->sv[i + 1];
        }
        ds->soluong--;
    } else {
        printf("Vi tri khong hop le\n");
    }
}

void indanhsachsinhvien(const struct danhsachsinhvien *ds) {
    if (ds->soluong == 0) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        for (int i = 0; i < ds->soluong; i++) {
            printf("Sinh vien %d:\n", i + 1);
            printf("Ho va ten: %s\n", ds->sv[i].hoTen);
            printf("Tuoi: %d\n", ds->sv[i].tuoi);
            printf("So dien thoai: %s\n", ds->sv[i].sodienthoai);
            printf("Email: %s\n\n", ds->sv[i].email);
        }
    }
}

