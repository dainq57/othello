#include <iostream>
#include <cstring>
#include "OTrong.h"
using namespace std;

void OTrong::setTrangThai(char trangThai) {
	this->trangThai = trangThai; 
}
char OTrong::getTrangThai() {
	return trangThai;
}
void OTrong::setConTrong(bool x) {
	conTrong = x;
}
bool OTrong::getConTrong() {
	return conTrong;
}
