#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Do an nho xiu thoi, mot file cho gon.
// Quy uoc cua truong: cuoi ki 0.5, giua ki 0.2, thuong xuyen 0.3
//
// Nhap lieu kieu gi cung duoc mien la dung:
//   -1 = huy / xong, quay ve menu
//    u = undo, xoa cai vua nhap (dang nhap diem thuong xuyen thi xoa diem cuoi)

enum KetQua { KQ_OK, KQ_HUY, KQ_UNDO };

void moDau(){
	cout << "=== HO TRO KIEM TRA KET QUA HOC TAP ===" << endl;
	cout << "[1]: Tinh diem tong ket mon " << endl;
	cout << "[2] Tinh hoc luc cuoi ki" << endl;
	cout << "[0] Thoat" << endl;
}

// Cat khoang trang o hai dau, de nguoi dung lo tay bam space cung khong sao
string catKhoangTrang(string s){
	int dau = 0, cuoi = (int)s.size() - 1;
	while (dau <= cuoi && (s[dau] == ' ' || s[dau] == '\t')) dau++;
	while (cuoi >= dau && (s[cuoi] == ' ' || s[cuoi] == '\t')) cuoi--;
	return s.substr(dau, cuoi - dau + 1);
}

// Doc mot dong, tra ve so trong khoang [min, max].
// false kem theo kieu = KQ_HUY (go -1) hoac KQ_UNDO (go u).
bool docSo(string loiNhac, double min, double max, double &ketQua, KetQua &kieu){
	while (true){
		cout << loiNhac;
		string s;
		if (!getline(cin, s)){ kieu = KQ_HUY; return false; }
		s = catKhoangTrang(s);

		if (s == "-1"){ kieu = KQ_HUY; return false; }
		if (s == "u" || s == "U"){ kieu = KQ_UNDO; return false; }
		if (s.empty()){ cout << "Nhap gi do di..." << endl; continue; }

		stringstream ss(s);
		double d;
		char thua;
		if (!(ss >> d) || (ss >> thua)){
			cout << "Nhap so thoi ba oi (hoac -1 de huy, u de undo)" << endl;
			continue;
		}
		if (d < min || d > max){
			cout << "Chi nhan tu " << min << " den " << max << " thoi nha" << endl;
			continue;
		}
		ketQua = d;
		kieu = KQ_OK;
		return true;
	}
}

// Nhu docSo nhung bat buoc so nguyen, dung cho menu, so mon, so tin chi
bool docSoNguyen(string loiNhac, int min, int max, int &ketQua, KetQua &kieu){
	while (true){
		double d;
		if (!docSo(loiNhac, min, max, d, kieu)) return false;
		if (d != (int)d){
			cout << "So nguyen thoi nha" << endl;
			continue;
		}
		ketQua = (int)d;
		return true;
	}
}

// Bang quy doi diem he 10 sang he 4
double quyDoi4(double d){
	if (d >= 8.5) return 4.0;
	if (d >= 7.8) return 3.5;
	if (d >= 7.0) return 3.0;
	if (d >= 6.2) return 2.5;
	if (d >= 5.5) return 2.0;
	if (d >= 4.8) return 1.5;
	if (d >= 4.0) return 1.0;
	return 0.0;
}

string diemChu(double d){
	if (d >= 8.5) return "A";
	if (d >= 7.8) return "B+";
	if (d >= 7.0) return "B";
	if (d >= 6.2) return "C+";
	if (d >= 5.5) return "C";
	if (d >= 4.8) return "D+";
	if (d >= 4.0) return "D";
	return "F";
}

string xepLoai(double gpa){
	if (gpa >= 3.60) return "Xuat sac";
	if (gpa >= 3.20) return "Gioi";
	if (gpa >= 2.50) return "Kha";
	if (gpa >= 2.00) return "Trung binh";
	if (gpa >= 1.00) return "Yeu";
	return "Kem";
}

// Chua co diem cuoi ki thi in ra "can bao nhieu diem" cho tung loai
void inMoc(const string &ten, double nen, double moc){
	double can = (moc - nen) / 0.5;
	cout << "Loai " << ten << " (tong >= " << moc << "): can cuoi ki ";
	if (can <= 0)
		cout << "0 diem, chi can di thi";
	else if (can > 10)
		cout << "tren 10 diem -> khong cuu noi, xin chia buon";
	else
		cout << can << " diem";
	cout << endl;
}

void diemTongKet(){
	cout << "\n--- Case 1: diem tong ket cua mon ---" << endl;
	cout << "(Nhap -1 o bat ky cau nao de huy, quay ve menu)" << endl;

	KetQua kieu;
	double giuaKi;
	if (!docSo("Diem giua ki: ", 0, 10, giuaKi, kieu)) return;

	// Khong can dem truoc, nhap den dau hay den do, go -1 la xong
	double diemThuongXuyen[100];
	int soDiem = 0;
	double tongThuongXuyen = 0;

	while (true){
		stringstream loiNhac;
		loiNhac << "Diem thuong xuyen " << soDiem + 1 << " (-1 = xong): ";
		double d;
		if (!docSo(loiNhac.str(), 0, 10, d, kieu)){
			if (kieu == KQ_UNDO){
				if (soDiem == 0){
					cout << "Chua nhap diem nao thi undo cai gi :)" << endl;
					continue;
				}
				soDiem--;
				tongThuongXuyen -= diemThuongXuyen[soDiem];
				cout << "Da xoa diem " << diemThuongXuyen[soDiem]
				     << ", con " << soDiem << " diem." << endl;
				continue;
			}
			// go -1: xong, nhung phai co it nhat 1 diem moi tinh duoc
			if (soDiem == 0){
				cout << "Can it nhat 1 diem thuong xuyen moi tinh duoc, thoi ve menu nha." << endl;
				return;
			}
			break;
		}
		if (soDiem >= 100){
			cout << "100 diem thuong xuyen la qua suc roi, dung o day thoi." << endl;
			break;
		}
		diemThuongXuyen[soDiem] = d;
		soDiem++;
		tongThuongXuyen += d;
	}

	double thuongXuyen = tongThuongXuyen / soDiem;

	// Diem cuoi ki de trong duoc. Khong dung docSo vi no bat nhap so.
	double cuoiKi = 0;
	bool coCuoiKi = false;
	while (true){
		cout << "Diem cuoi ki (bo trong = chua co, -1 = huy): ";
		string s;
		if (!getline(cin, s)) return;
		s = catKhoangTrang(s);
		if (s == "-1") return;
		if (s.empty()) break;

		stringstream ss(s);
		char thua;
		if (!(ss >> cuoiKi) || (ss >> thua) || cuoiKi < 0 || cuoiKi > 10){
			cout << "Diem 0-10 thoi nha, nhap lai di (hoac -1 de huy)" << endl;
			continue;
		}
		coCuoiKi = true;
		break;
	}

	cout << fixed << setprecision(2);
	double nen = 0.2 * giuaKi + 0.3 * thuongXuyen;

	if (!coCuoiKi){
		cout << "\nChua co diem cuoi ki, vay can cu the nay:" << endl;
		inMoc("A", nen, 8.5);
		inMoc("B+", nen, 7.8);
		inMoc("B", nen, 7.0);
		inMoc("C+", nen, 6.2);
		inMoc("C", nen, 5.5);
		inMoc("D+", nen, 4.8);
		inMoc("D", nen, 4.0);
		cout << "(Duoi 4.0 thi la F, mon nay hoc lai do nha)" << endl;
		return;
	}

	double tongKet = 0.5 * cuoiKi + nen;
	cout << "\nDiem tong ket: " << tongKet << endl;
	cout << "Diem chu: " << diemChu(tongKet) << endl;
	cout << "Quy ra he 4: " << quyDoi4(tongKet) << endl;
}

void hocLuc(){
	cout << "\n--- Case 2: hoc luc ca ki ---" << endl;
	cout << "(Nhap diem he 4 thoi nha, -1 = huy)" << endl;

	KetQua kieu;
	int soMon;
	if (!docSoNguyen("Nhap so mon ban dang hoc: ", 1, 50, soMon, kieu)) return;

	double tongDiem4 = 0;
	int tongTinChi = 0;

	// Vong lap long nhau: moi mon nhap so tin roi nhap diem, dan xen nhau
	for (int i = 1; i <= soMon; i++){
		cout << "\nMon " << i << "/" << soMon << ":" << endl;

		int tinChi;
		if (!docSoNguyen("  So tin chi: ", 1, 20, tinChi, kieu)) return;

		double diem;
		if (!docSo("  Diem mon nay (he 4): ", 0, 4, diem, kieu)) return;

		tongDiem4 += diem * tinChi;
		tongTinChi += tinChi;
	}

	double gpa = tongDiem4 / tongTinChi;
	cout << fixed << setprecision(2);
	cout << "\nTong tin chi: " << tongTinChi << endl;
	cout << "GPA he 4: " << gpa << endl;
	cout << "Xep loai: " << xepLoai(gpa) << endl;
}

int main(){
	while (true){
		moDau();

		KetQua kieu;
		int chon;
		if (!docSoNguyen("Chon: ", 0, 2, chon, kieu)){
			if (kieu == KQ_UNDO){
				cout << "Menu thi undo cai gi, chon 0 1 2 di" << endl;
				continue;
			}
			break; // go -1 hoac het input thi thoat
		}

		if (chon == 0){
			cout << "Tam biet, chuc ban hoc gioi (hoac it nhat la qua mon)!" << endl;
			break;
		}

		switch (chon){
			case 1:
				diemTongKet();
				break;
			case 2:
				hocLuc();
				break;
		}
		cout << endl;
	}

	return 0;
}
