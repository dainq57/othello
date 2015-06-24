#ifndef BXH_H
#define BXH_H
using std::string;

class DiemSo {
	public:
		string ten;
		int diem ;
};

class BXH {
	public:
		DiemSo taiKhoan[100] ,taiKhoan2[100];
		void taoMangXepHang();
		void capNhat(DiemSo[], string, int, string, int);
		void capNhat(DiemSo[], string, int);
		void inBangXepHang();
};

#endif
