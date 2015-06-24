#include <iostream>
#include <cstring>
#include "BanCo.h"
#include "NguoiChoi.h"
#include "TrangTri.h"
using namespace std;

extern BanCo banCo;

int NguoiChoi::diemSo() {
	return banCo.soQuanMau(mauCuaMinh);
}
void NguoiChoi::setTenMauCuaMinh(string a) {
	tenMauCuaMinh = a;
}
string NguoiChoi::getTenMauCuaMinh(){
	return tenMauCuaMinh;
}
int NguoiChoi::getSoThuTu() {
	return soThuTu;
}
char NguoiChoi::getMauCuaMinh() {
	return mauCuaMinh;
}
char NguoiChoi::getMauDoiPhuong() {
	return mauDoiPhuong;
}
string NguoiChoi::getTen() {
	return ten;
}
void NguoiChoi::setTen(string a) {
	ten = a;
}
void NguoiChoi::setMauCuaMinh(char a) {
	mauCuaMinh = a;
}
void NguoiChoi::setMauDoiPhuong(char a) {
	mauDoiPhuong = a;
}
void NguoiChoi::setSoThuTu(int a) {
	soThuTu = a;
}
void NguoiChoi::goiY(int a) {
	if (a == 1) {
		int dem = 1;
		char s;
		gotoxy(8, 11);
		cout <<"--------";
		gotoxy(11, 13);
		cout << "GOI Y";
		for (int i=1; i<=8; i++)
			for (int j=1; j<=8; j++)
				if (dem <=5 ) {
					gotoxy(11, 13 + dem*2);
					if (banCo.danhDuoc(mauCuaMinh, mauDoiPhuong, i, j)) {
						switch (j) {
							case 1: s = 'A' ; break;
							case 2: s = 'B' ; break;
							case 3: s = 'C' ; break;
							case 4: s = 'D' ; break;
							case 5: s = 'E' ; break;
							case 6: s = 'F' ; break;
							case 7: s = 'G' ; break;
							case 8: s = 'H' ; break;
						}
						cout << "[" << i << "," << s << "]";
						dem++;
					}
				}
	} else {
		int dem = 1;
		char s;
		gotoxy(65, 11);
		cout <<"--------";
		gotoxy(65, 13);
		cout << "GOI Y";
		for (int i=1; i<=8; i++)
			for (int j=1; j<=8; j++)
				if (dem <=5 ) {
					gotoxy(65, 13 + dem*2);
					if (banCo.danhDuoc(mauDoiPhuong, mauCuaMinh, i, j)) {
						switch (j) {
							case 1: s = 'A' ; break;
							case 2: s = 'B' ; break;
							case 3: s = 'C' ; break;
							case 4: s = 'D' ; break;
							case 5: s = 'E' ; break;
							case 6: s = 'F' ; break;
							case 7: s = 'G' ; break;
							case 8: s = 'H' ; break;
						}
						cout << "[" << i << "," << s << "]";
						dem++;
					}
				}
	}
}	
