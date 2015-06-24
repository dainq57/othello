#ifndef NguoiChoi_H
#define NguoiChoi_H
using std::string;
class NguoiChoi {
	private:
		string ten;
		string tenMauCuaMinh;
		int soThuTu;
		char mauCuaMinh;
		char mauDoiPhuong;
	public:
		void setTenMauCuaMinh(string);
		string getTenMauCuaMinh();
		void setSoThuTu(int);
		void setMauCuaMinh(char);
		void setMauDoiPhuong(char);
		void setTen(string);
		int getSoThuTu();
		char getMauCuaMinh();
		char getMauDoiPhuong();
		string getTen();
		int diemSo();
		void goiY(int );
		NguoiChoi(){
			ten = "NO NAME";
			setSoThuTu(0);
		}
		NguoiChoi(int a) {
			ten = "COMPUTER";
			setSoThuTu(0);
		}	
}; 

#endif
