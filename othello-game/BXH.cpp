#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "BXH.h"
#include "TrangTri.h"
using namespace std;

void BXH::taoMangXepHang() {
	ifstream f("BangXepHang.txt");
	ifstream f2("BangXepHang2.txt");
	for (int i=1; i<=10; i++) {
		f >> taiKhoan[i].ten >> taiKhoan[i].diem ;
		f2 >> taiKhoan2[i].ten >> taiKhoan2[i].diem ;
	}
	f2.close();
	f.close();
}
void BXH::capNhat(DiemSo taiKhoan[], string tk1, int d1, string tk2, int d2) {
	for(int i=1; i<=10; i++)
		if (d1 > taiKhoan[i].diem) {
			for (int j=11; j>=i; j--) {
				taiKhoan[j].diem = taiKhoan[j-1].diem;
				taiKhoan[j].ten = taiKhoan[j-1].ten;
			}
			taiKhoan[i].diem = d1;
			taiKhoan[i].ten = tk1;
			break;
		}
	for(int i=1; i<=10; i++)
		if (d2 > taiKhoan[i].diem) {
			for (int j=11; j>=i; j--) {
				taiKhoan[j].diem = taiKhoan[j-1].diem;
				taiKhoan[j].ten = taiKhoan[j-1].ten;
			}
			taiKhoan[i].diem = d2;
			taiKhoan[i].ten = tk2;
			break;
		}
	ofstream f2("BangXepHang.txt");
	for (int i=1; i<=10; i++)
		f2 << taiKhoan[i].ten << "\n" << taiKhoan[i].diem << endl;
	f2.close();
}
void BXH::capNhat(DiemSo taiKhoan[], string tk1, int d1) {
	for(int i=1; i<=10; i++)
		if (d1 >= taiKhoan[i].diem) {
			for (int j=11; j>=i; j--) {
				taiKhoan[j].diem = taiKhoan[j-1].diem;
				taiKhoan[j].ten = taiKhoan[j-1].ten;
				cout << "dkmdkm";
			}
			taiKhoan[i].diem = d1;
			taiKhoan[i].ten = tk1;
			break;
		}
	ofstream f2("BangXepHang2.txt");
	for (int i=1; i<=10; i++)
		f2 << taiKhoan[i].ten << "\n" << taiKhoan[i].diem << endl;
	f2.close();
} 
void BXH::inBangXepHang() {
	tieuDeTinh();
	cout << "\n\n\n                             BANG XEP HANG TOP CAO THU\n\n\n";
	gotoxy(15, 9);
	cout << "NGUOI vs NGUOI\n\n";
	for (int i=1; i<=10; i++) {
		gotoxy(15, 10+i);
		cout << taiKhoan[i].diem << "  " << taiKhoan[i].ten;
	}
	gotoxy(55, 9);
	cout << "NGUOI vs MAY\n\n";
	for (int i=1; i<=10; i++) {
		gotoxy(55, 10+i);
		cout << taiKhoan2[i].diem << "  " << taiKhoan2[i].ten;
	}
	cout << "\n\n\n";
	tieuDeTinh();
}

