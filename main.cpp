#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Do an nho xiu thoi, mot file cho gon.
// Quy uoc cua truong: cuoi ki 0.5, giua ki 0.2, thuong xuyen 0.3
// Neu thay cho nao sai thi cu sua, minh cung moi hoc C++ thoi =))

void moDau(int &chon){
	cout << "=== HO TRO KIEM TRA KET QUA HOC TAP ===" << endl;
	cout << "[1]: Tinh diem tong ket mon " << endl;
	cout << "[2] Tinh hoc luc cuoi ki" << endl;
	cout << "[0] Thoat" << endl;
	cout << "Chon: ";
	cin >> chon;
}

// Nhap diem tu 0 den 10. Nhap sai thi hoi lai, kien nhan len.
double nhapDiem(string loiNhac){
	double d;
	while (true){
		cout << loiNhac;
		cin >> d;
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Nhap so thoi ba oi :(" << endl;
			continue;
		}
		if (d < 0 || d > 10){
			cout << "Diem gi ma kinh vay, 0-10 thoi nha" << endl;
			continue;
		}
		return d;
	}
}

// Nhap so nguyen duong, dung cho so mon voi so tin
int nhapSoDuong(string loiNhac){
	int n;
	while (true){
		cout << loiNhac;
		cin >> n;
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Nhap so thoi nha" << endl;
			continue;
		}
		if (n <= 0){
			cout << "Phai lon hon 0 chu" << endl;
			continue;
		}
		return n;
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

// Cat khoang trang o hai dau, de nguoi dung lo tay bam space cung khong sao
string catKhoangTrang(string s){
	int dau = 0, cuoi = (int)s.size() - 1;
	while (dau <= cuoi && (s[dau] == ' ' || s[dau] == '\t')) dau++;
	while (cuoi >= dau && (s[cuoi] == ' ' || s[cuoi] == '\t')) cuoi--;
	return s.substr(dau, cuoi - dau + 1);
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

	double giuaKi = nhapDiem("Diem giua ki: ");

	int soThuongXuyen = nhapSoDuong("So diem thuong xuyen: ");
	double tongThuongXuyen = 0;
	for (int i = 1; i <= soThuongXuyen; i++){
		stringstream loiNhac;
		loiNhac << "Diem thuong xuyen " << i << ": ";
		tongThuongXuyen += nhapDiem(loiNhac.str());
	}
	double thuongXuyen = tongThuongXuyen / soThuongXuyen;

	// Xoa bo dem, khong thi getline an luon cai Enter con sot lai
	cin.ignore(1000, '\n');

	cout << "Diem cuoi ki (bo trong neu chua co): ";
	string nhap;
	getline(cin, nhap);
	nhap = catKhoangTrang(nhap);

	cout << fixed << setprecision(2);
	double nen = 0.2 * giuaKi + 0.3 * thuongXuyen;

	if (nhap.empty()){
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

	// Nguoi dung nhap chu thi cung chiu, khong biet thi in ra loi roi thoi
	stringstream ss(nhap);
	double cuoiKi;
	if (!(ss >> cuoiKi) || cuoiKi < 0 || cuoiKi > 10){
		cout << "Diem cuoi ki khong doc duoc, thoi tinh lai tu dau nha." << endl;
		return;
	}

	double tongKet = 0.5 * cuoiKi + nen;
	cout << "\nDiem tong ket: " << tongKet << endl;
	cout << "Diem chu: " << diemChu(tongKet) << endl;
	cout << "Quy ra he 4: " << quyDoi4(tongKet) << endl;
}

void hocLuc(){
	cout << "\n--- Case 2: hoc luc ca ki ---" << endl;

	int soMon = nhapSoDuong("Nhap so mon ban dang hoc: ");
	double tongDiem4 = 0;
	int tongTinChi = 0;

	// Vong lap long nhau: moi mon nhap so tin roi nhap diem, dan xen nhau
	for (int i = 1; i <= soMon; i++){
		cout << "\nMon " << i << ":" << endl;
		int tinChi = nhapSoDuong("  So tin chi: ");
		stringstream loiNhac;
		loiNhac << "  Diem mon nay (he 10): ";
		double diem = nhapDiem(loiNhac.str());
		tongDiem4 += quyDoi4(diem) * tinChi;
		tongTinChi += tinChi;
	}

	double gpa = tongDiem4 / tongTinChi;
	cout << fixed << setprecision(2);
	cout << "\nTong tin chi: " << tongTinChi << endl;
	cout << "GPA he 4: " << gpa << endl;
	cout << "Xep loai: " << xepLoai(gpa) << endl;
}

int main(){
	int chon = 0;
	do {
		moDau(chon);
		switch (chon){
			case 1:
				diemTongKet();
				break;
			case 2:
				hocLuc();
				break;
			case 0:
				cout << "Tam biet, chuc ban hoc gioi (hoac it nhat la qua mon)!" << endl;
				break;
			default:
				cout << "Gia tri khong hop le, chon 0 1 2 thoi" << endl;
				break;
		}
		cout << endl;
	} while (chon != 0);

	return 0;
}
