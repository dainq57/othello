#ifndef BanCo_H
#define BanCo_H
#include "OTrong.h"

const char trang = 4, den = 'x';
class BanCo {
	private:
		OTrong banCo[10][10];
	public:
		void taoBanCoBanDau();
		void inBanCoHienTai();
		bool chuaKetThuc();
		int soQuanMau(char);
		bool danhDuoc(char, char, int, int, bool&, bool&, bool&, bool&, bool&, bool&, bool&, bool&);
		bool danhDuoc(char, char, int, int);
		void latQuanCo(int, int, char, char, bool, bool, bool, bool, bool, bool, bool, bool);
		bool conDanhDuoc(char, char);
};

#endif
