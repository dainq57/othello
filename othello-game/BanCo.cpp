#include <iostream>
#include <windows.h>
#include "OTrong.h"
#include "BanCo.h"
#include "TrangTri.h"

extern int HANG, COT;
using namespace std;

void BanCo::latQuanCo(int dong, int cot, char mauCuaMinh, char mauDoiPhuong, bool dongPhai, bool dongTrai, bool cotTren, bool cotDuoi, bool cheoLen45, bool cheoXuong45, bool cheoLen135, bool cheoXuong135) {
	int i, j;
	j = cot + 1;
	if (dongPhai)
	while (banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauDoiPhuong) {
		banCo[dong][j].setTrangThai(mauCuaMinh);
		j++;
	}
	j = cot - 1;
	if (dongTrai)
	while (banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauDoiPhuong) {
		banCo[dong][j].setTrangThai(mauCuaMinh);
		j--;
	} 

	i = dong + 1;
	if (cotDuoi)
	while (banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauDoiPhuong) {
		banCo[i][cot].setTrangThai(mauCuaMinh);
		i++;
	}
	i = dong - 1;
	if (cotTren)
	while (banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauDoiPhuong)  {
		banCo[i][cot].setTrangThai(mauCuaMinh);
		i--;
	}
	i = dong - 1;
	j = cot + 1;
	if (cheoLen135)
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		banCo[i][j].setTrangThai(mauCuaMinh);
		i--;
		j++;
	}
	i = dong + 1;
	j = cot - 1;
	if (cheoXuong135)
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		banCo[i][j].setTrangThai(mauCuaMinh);
		i++;
		j--;
	}
	
	i = dong + 1;
	j = cot + 1;
	if (cheoXuong45)
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		banCo[i][j].setTrangThai(mauCuaMinh);
		i++;
		j++;
	}
	i = dong - 1;
	j = cot - 1;
	if (cheoLen45)
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		banCo[i][j].setTrangThai(mauCuaMinh);
		i--;
		j--;
	}	
}
bool BanCo::danhDuoc(char mauCuaMinh, char mauDoiPhuong, int dong, int cot, bool& dongPhai, bool& dongTrai, bool& cotTren, bool& cotDuoi, bool& cheoLen45, bool& cheoXuong45, bool& cheoLen135, bool& cheoXuong135) {
	if (dong > HANG || dong < 1 || cot > HANG || cot < 1 || banCo[dong][cot].getConTrong() == false) return false;	
	banCo[dong][cot].setTrangThai(mauCuaMinh);
	banCo[dong][cot].setConTrong(false);
	int j, i;
	int dem = 0;
	
	j = cot + 1;
	while (banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauDoiPhuong) j++; 
	if (j!=cot + 1 && banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauCuaMinh) {
		dongPhai = 1;
		dem++;
	}
	j = cot - 1;
	while (banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauDoiPhuong) j--; 
	if (j!=cot - 1 && banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauCuaMinh) {
		dongTrai = 1;
		dem++;
	}
		
	i = dong + 1;
	while (banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauDoiPhuong) i++; 
	if (i!=dong + 1 && banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauCuaMinh) {
		cotDuoi = 1;
		dem++;
	}
	i = dong - 1;
	while (banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauDoiPhuong) i--; 
	if (i!=dong - 1 && banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauCuaMinh) {
		cotTren = 1;
		dem++;
	}
	
	i = dong - 1;
	j = cot + 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i--;
		j++;
	}
	if (i!=dong - 1 && j!=cot+1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh) {
		cheoLen135 = 1;
		dem++;
	}
	i = dong + 1;
	j = cot - 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i++;
		j--;
	}
	if (i!=dong + 1 && j!=cot-1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh) {
		cheoXuong135 = 1;
		dem++;
	}
	
	i = dong - 1;
	j = cot - 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i--;
		j--;
	}
	if (i!=dong - 1 && j!=cot-1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh) {
		cheoLen45 = 1;
		dem++;
	}
	i = dong + 1;
	j = cot + 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i++;
		j++;
	}
	if (i!=dong + 1 && j!=cot+1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh) {
		cheoXuong45 = 1;
		dem++;
	}

	if (dem != 0) return true;
	banCo[dong][cot].setConTrong(true);
	return false; 
}
bool BanCo::danhDuoc(char mauCuaMinh, char mauDoiPhuong, int dong, int cot) {
	if (dong > HANG || dong < 1 || cot > HANG || cot < 1 || banCo[dong][cot].getConTrong() == false) return false;	
	int j, i;
	int dem = 0;	
	j = cot + 1;
	while (banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauDoiPhuong) j++; 
	if (j!=cot + 1 && banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauCuaMinh) 
		return true;
	j = cot - 1;
	while (banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauDoiPhuong) j--; 
	if (j!=cot - 1 && banCo[dong][j].getConTrong() == false && banCo[dong][j].getTrangThai() == mauCuaMinh) 
		return true;
		
	i = dong + 1;
	while (banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauDoiPhuong) i++; 
	if (i!=dong + 1 && banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauCuaMinh)
		return true;
	i = dong - 1;
	while (banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauDoiPhuong) i--; 
	if (i!=dong - 1 && banCo[i][cot].getConTrong() == false && banCo[i][cot].getTrangThai() == mauCuaMinh) 
		return true;
	i = dong - 1;
	j = cot + 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i--;
		j++;
	}
	if (i!=dong - 1 && j!=cot+1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh)
		return true;
	i = dong + 1;
	j = cot - 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i++;
		j--;
	}
	if (i!=dong + 1 && j!=cot-1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh) 
		return true;
	
	i = dong - 1;
	j = cot - 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i--;
		j--;
	}
	if (i!=dong - 1 && j!=cot-1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh) 
		return true;
	i = dong + 1;
	j = cot + 1;
	while (banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauDoiPhuong) {
		i++;
		j++;
	}
	if (i!=dong + 1 && j!=cot+1 && banCo[i][j].getConTrong() == false && banCo[i][j].getTrangThai() == mauCuaMinh) 
		return true;
}
bool BanCo::conDanhDuoc(char mauCuaMinh, char mauDoiPhuong) {
	bool a , b, c, d, e, f, g, h;
	for (int i=1; i<=HANG; i++)
		for (int j=1; j<=COT; j++)
			if(danhDuoc(mauCuaMinh, mauDoiPhuong, i, j, a, b, c, d, e, f, g, h)) {
				banCo[i][j].setTrangThai('x');
				banCo[i][j].setConTrong(true);
				return true;
			}
	return false;
}
int BanCo::soQuanMau(char mau) {
	int sum = 0;
	for (int i=1; i<=HANG; i++) 
		for (int j=1; j<=COT; j++)
			if (banCo[i][j].getTrangThai() == mau && banCo[i][j].getConTrong() == false )
				sum++;
	return sum;
}
bool BanCo::chuaKetThuc() {
	for (int i=1; i<=HANG; i++)
		for (int j=1; i<=COT; j++)
			if (banCo[i][j].getConTrong()) return true;
	return false;
}
void BanCo::taoBanCoBanDau() {
	banCo[HANG/2][COT/2].setTrangThai(den);
	banCo[HANG/2][COT/2].setConTrong(0);
	banCo[HANG/2][COT/2+1].setTrangThai(trang);
	banCo[HANG/2][COT/2+1].setConTrong(0);
	banCo[HANG/2+1][COT/2].setTrangThai(trang);
	banCo[HANG/2+1][COT/2].setConTrong(0);
	banCo[HANG/2+1][COT/2+1].setTrangThai(den);
	banCo[HANG/2+1][COT/2+1].setConTrong(0);
}
void BanCo::inBanCoHienTai() {
	
	cout << "\n\n\t\t          A   B   C   D   E   F   G   H  \n";
	cout << "\t\t        +---+---+---+---+---+---+---+---+\n";
	for (int i=1; i<=HANG; i++) {
		cout << "\t\t      " << i << " | ";
		for (int j=1; j<=COT; j++)
			if (banCo[i][j].getConTrong() == 1) cout << "  | ";
			else
			cout << banCo[i][j].getTrangThai() << " | ";
		cout << i << "\n";
		cout << "\t\t        +---+---+---+---+---+---+---+---+\n";
	}
	cout << "\t\t          A   B   C   D   E   F   G   H  \n\n";
}

