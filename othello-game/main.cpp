#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include "BXH.h"
#include "TrangTri.h"
#include "OTrong.h"
#include "BanCo.h"
#include "NguoiChoi.h"
using namespace std;
int HANG = 8;
int COT = 8;
NguoiChoi p1, p2 ,p, com(1);
BanCo banCo;
BXH bangXepHang;
int toInt(char a) {
	return a - 48;
}
int main(int argc, char *argv[]) {
	bangXepHang.taoMangXepHang();
	string name;
	int hang, cot, c, STT = 1;
	banCo.taoBanCoBanDau();
	datMauNen();
	tieuDeDong();
	while(1) {
		cout << "\n + CHON CHE DO CHOI:\n\n\t 1.NGUOI vs NGUOI\n\n\t 2.NGUOI vs MAY\n";
		c = getch();
		if (c == '1') {
			cout << "\n + NHAP TEN NGUOI CHOI THU NHAT: ";
			getline(cin, name);
			p1.setTen(name);
			cout << "\n + NHAP TEN NGUOI CHOI THU HAI: ";
			getline(cin, name);
			p2.setTen(name);
			cout << endl;
			break;
		} else if ( c != '2') cout << "\n + NHAP LAI !\n";
		else {
			cout << "\n + NHAP TEN NGUOI CHOI : ";
			getline(cin, name);
			p1.setTen(name);
			p2 = com;
			cout << endl;
			break;
		}
	}
	
	tieuDeTinh();
	loading();
	srand(time(0));
	int ran = rand();
		if (ran % 2 == 0) {
			p1.setSoThuTu(1);
			p1.setMauCuaMinh(den);
			p1.setMauDoiPhuong(trang);
			p1.setTenMauCuaMinh("QUAN DEN");
			p2.setSoThuTu(-1);
			p2.setMauCuaMinh(trang);
			p2.setTenMauCuaMinh("QUAN TRANG");
			p2.setMauDoiPhuong(den);
			cout << "\n + " << p1.getTen() << " CAM MAU DEN, DANH TRUOC !\n";
			Sleep(1000);
		} else {
			p2.setSoThuTu(1);
			p2.setMauCuaMinh(den);
			p2.setMauDoiPhuong(trang);
			p2.setTenMauCuaMinh("QUAN DEN");
			p1.setSoThuTu(-1);
			p1.setMauCuaMinh(trang);
			p1.setTenMauCuaMinh("QUAN TRANG");
			p1.setMauDoiPhuong(den);
			cout << "\n + " << p2.getTen() << " CAM MAU DEN, DANH TRUOC !\n";	
			Sleep(1000);
		}
	Sleep(1000);	

	while(1){
		xoaManHinh();
		tieuDeTinh();
		banCo.inBanCoHienTai();
		hienThiThongTin();
		hienThiGoiY();
		capNhatDiemSo();
		gotoxy(0, 25);
		tieuDeTinh();
		if (STT == p1.getSoThuTu()) p = p1; 
		else p = p2;
		if (banCo.conDanhDuoc(p.getMauCuaMinh(), p.getMauDoiPhuong()) == false) {
			cout << "\n + LUOT " << p.getTen() << " BI MAT DO KHONG THE DANH DUOC NUA! \a\n";
			Sleep(1500);
			STT = -STT;
			if (STT == p1.getSoThuTu()) p = p1; 
			else p = p2;
		}  
		bool dongPhai = false, dongTrai = false, cotTren = false, cotDuoi = false, cheoLen45 = false, cheoXuong45 = false, cheoLen135 = false, cheoXuong135 = false;
			if (p.getTen() != "COMPUTER") {
				label:
				while (1) {
					char cotc;
					char hangc;
					cout << "\n + LUOT " << p.getTen() << ", NHAP TOA DO MUON DANH: ";
					cin >> hangc >> cotc;
					hang = toInt(hangc);
					if ( hang >= 1 && hang <= 8 );
					else {
						cout << "\n + NHAP SAI, NHAP LAI!\n";
						goto label; 
					}
					switch(cotc) {
						case 'A': cot = 1; break;
						case 'a': cot = 1; break;
						case 'B': cot = 2; break;
						case 'b': cot = 2; break;
						case 'C': cot = 3; break;
						case 'c': cot = 3; break;
						case 'D': cot = 4; break;
						case 'd': cot = 4; break;
						case 'E': cot = 5; break;
						case 'e': cot = 5; break;
						case 'F': cot = 6; break;
						case 'f': cot = 6; break;
						case 'G': cot = 7; break;
						case 'g': cot = 7; break;
						case 'H': cot = 8; break;
						case 'h': cot = 8; break;
						default: cout << "\n + NHAP SAI, NHAP LAI!\n"; goto label; break;
					} 
					if (banCo.danhDuoc(p.getMauCuaMinh(), p.getMauDoiPhuong(), hang, cot, dongPhai, dongTrai, cotTren, cotDuoi, cheoLen45, cheoXuong45, cheoLen135, cheoXuong135)) {
						cout << "\n + DANH THANH CONG, " << p.getTen() << " DANH : [ " << hang << "," << cotc << " ]\n";
						banCo.latQuanCo(hang, cot, p.getMauCuaMinh(), p.getMauDoiPhuong(), dongPhai, dongTrai, cotTren, cotDuoi, cheoLen45, cheoXuong45, cheoLen135, cheoXuong135);
						break;
					}  else cout << "\n + KHONG DANH DUOC, DANH LAI! \a\n";
				}
			} else {
				int q = 0;
				for (int i=1; i<=HANG; i++) {
					for (int j=1; j<=COT; j++)
						if(banCo.danhDuoc(p.getMauCuaMinh(), p.getMauDoiPhuong(), i, j, dongPhai, dongTrai, cotTren, cotDuoi, cheoLen45, cheoXuong45, cheoLen135, cheoXuong135)) {
							hang = i;
							cot = j;
							char cotc;
							switch(cot) {
								case 1: cotc = 'A'; break;
								case 2: cotc = 'B'; break;
								case 3: cotc = 'C'; break;
								case 4: cotc = 'D'; break;
								case 5: cotc = 'E'; break;
								case 6: cotc = 'F'; break;
								case 7: cotc = 'G'; break;
								case 8: cotc = 'H'; break;
							} 
							wait();
							cout << "\n + DANH THANH CONG, " << p.getTen() << " DANH : [ " << hang << "," << cotc << " ]\n";
							q = 1;
							if (q == 1) break;
						}
					if (q == 1) break;
				}
				banCo.latQuanCo(hang, cot, p.getMauCuaMinh(), p.getMauDoiPhuong(), dongPhai, dongTrai, cotTren, cotDuoi, cheoLen45, cheoXuong45, cheoLen135, cheoXuong135);
			}
		dangSuyNghi();		
		STT = -STT; 
		if (banCo.chuaKetThuc() == false || (banCo.conDanhDuoc(p1.getMauCuaMinh(), p1.getMauDoiPhuong()) == 0 && banCo.conDanhDuoc(p2.getMauCuaMinh(), p2.getMauDoiPhuong()) == 0) ) {
			cout << "\n\t\t       DANH THANH CONG, TRAN DAU KET THUC !\n";
			Sleep(2000);
			break;
		}
		if (banCo.conDanhDuoc(p1.getMauCuaMinh(), p1.getMauDoiPhuong()) == 0 && banCo.conDanhDuoc(p2.getMauCuaMinh(), p2.getMauDoiPhuong()) == 0) break;
	}
	inKetQua();
	if (p2.getTen() != "COMPUTER") bangXepHang.capNhat(bangXepHang.taiKhoan, p1.getTen(), p1.diemSo(), p2.getTen(), p2.diemSo());
	else bangXepHang.capNhat(bangXepHang.taiKhoan2, p1.getTen(), p1.diemSo());
	xoaManHinh();
	bangXepHang.inBangXepHang();
	Sleep(3000);
	return 0;
}
