#include <iostream>
#include <windows.h>
#include <iomanip>
#include "NguoiChoi.h"
#include "BanCo.h"
#include "TrangTri.h"
using namespace std;
extern NguoiChoi p1, p2, com, p;
extern BanCo banCo;
void datMauNen() {
	system("color 17");
}
void DongKe() {
	cout << " +";
	for (int i=1; i<=76; i++) {
		cout << "-";
		Sleep(4);
	}
	cout << "+";
	cout << endl;
}
void tieuDeDong() {
	cout << "\n";
	DongKe();
	char tieude[100] = " |\t\t\t\t  OTHELLO GAME                              |\n";
	for (int i=0; i<20; i++) {
		cout << tieude[i];
		Sleep(30);
	}
	cout << "                                |\n";
	DongKe();
}
void tieuDeTinh() {
	cout << " +";
	for (int i=1; i<=76; i++)
		cout << "-";
	cout << "+";
	cout << endl;
	cout << " |\t\t\t\t  OTHELLO GAME                                |\n";
	cout << " +";
	for (int i=1; i<=76; i++)
		cout << "-";
	cout << "+";
	cout << endl;
}
void dangSuyNghi() {
	cout << endl;
	for (int i=1; i<=15; i++) cout << "  ";
		for (int i=1; i<=10; i++) {
			cout << ". ";
			Sleep(150);
		}
		cout << "\n";
		Sleep(700);
}
void xoaManHinh() {
	system("cls");
}
void hienThiThongTin() {
	gotoxy(5, 5);
	cout << setw(11) << p1.getTen();
	gotoxy(60, 5);
	cout << setw(5) << "  " << p2.getTen();
	gotoxy(5, 7);
	cout << setw(11) << p1.getTenMauCuaMinh();
	gotoxy(60, 7);
	cout << setw(5) << "  " << p2.getTenMauCuaMinh();
}
void hienThiGoiY() {
	p1.goiY(1);
	p1.goiY(2);
}
void capNhatDiemSo() {
	gotoxy(5, 9);
	cout << setw(11) << p1.diemSo();
	gotoxy(60, 9);
	cout << setw(5) << "  " << p2.diemSo();
}
void inKetQua() {
	xoaManHinh();
	tieuDeTinh();
	cout << "\n\t\t\t\t   KET THUC\n";
	banCo.inBanCoHienTai();
	hienThiThongTin();
	capNhatDiemSo();
	gotoxy(1,27);
	Sleep(1500);
	if (p1.diemSo() > p2.diemSo()) cout << "\a\n\n                                " << p1.getTen() << " THANG !\n\n";
	else if (p1.diemSo() < p2.diemSo()) cout << "\a\n\n                                 " << p2.getTen() << " THANG !\n\n";
	else cout << "\n\a                                  KET QUA HOA !\n\n";
	tieuDeTinh();
	cout << "\n\n\n\n";
	Sleep(2000);
	gotoxy(40, 40);
}
void loading() {
	cout << "\n\n\t\t\t\t    STARTING \n";
	for (int i=1; i<=33; i++) cout << " ";
	for (int i=1; i<=8; i++) {
		cout << ". ";
		Sleep(400);
	}
	cout << "\n\n";
}
void wait() {
	cout << "\n + LUOT COMPUTER : \n ";
	cout << "\n + WAIT ";
	for(int i=1; i<=3; i++) {
		cout << ".";
		Sleep(500);
	}
	cout << "\n";
}
void gotoxy(int x, int y) { 
     HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; 
     COORD position = {x,y} ; 
     SetConsoleCursorPosition(hStdout,position ) ; 
} 
