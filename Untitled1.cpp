#include <stdio.h>
#include <string.h>

struct SinhVien {
	char hoTen[50];
	int tuoi;
	char soDienThoai[15];
	char email[50];
};
int main(){
	struct SinhVien sinhVien1;
	strcpy(sinhVien1.hoTen, "Nguyen Van Thon");
	sinhVien1.tuoi = 90;
	strcpy(sinhVien1.soDienThoai, "0982057636");
	strcpy(sinhVien1.email, "nguyenvanthon1120@example.com");
	printf("thong tin cau sinh vien:\n");
	printf("ho va ten %s\n", sinhVien1.hoTen);
	printf("tuoi %d\n", sinhVien1.tuoi);
	printf("so dien thoai %s\n", sinhVien1.soDienThoai);
	printf("email %s\n", sinhVien1.email);
	return 0;
}
