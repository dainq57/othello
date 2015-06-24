#ifndef OTrong_H
#define OTrong_H

class OTrong {
	private:
		char trangThai;
		bool conTrong;
	public:
		OTrong() {
			trangThai = 'x';
			conTrong = true;
		}
		void setTrangThai(char);
		char getTrangThai();
		void setConTrong(bool);
		bool getConTrong();
};

#endif
