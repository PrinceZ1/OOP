/*Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán tự động tăng, bắt đầu từ 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn dd/mm/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy
Viết chương trình nhập danh sách nhân viên (không nhập mã) 
trong đó có sử dụng chồng toán tử nhập/xuất và in ra màn hình danh sách vừa nhập.

Input

Dòng đầu ghi số N là số nhân viên (không quá 40).
Mối nhân viên ghi trên 6 dòng lần lượt ghi các thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output

Ghi ra danh sách đầy đủ nhân viên, mỗi nhân viên trên một dòng, các thông tin cách nhau đúng một khoảng trống.

Input
3
Nguyen Van A
Nam
10/22/1982
Mo Lao-Ha Dong-Ha Noi
8333012345
31/12/2013
Ly Thi B
Nu
10/15/1988
Mo Lao-Ha Dong-Ha Noi
8333012346
22/08/2011
Hoang Thi C
Nu
04/02/1981
Mo Lao-Ha Dong-Ha Noi
8333012347
22/08/2011

Output
00001 Nguyen Van A Nam 10/22/1982 Mo Lao-Ha Dong-Ha Noi 8333012345 31/12/2013
00002 Ly Thi B Nu 10/15/1988 Mo Lao-Ha Dong-Ha Noi 8333012346 22/08/2011
00003 Hoang Thi C Nu 04/02/1981 Mo Lao-Ha Dong-Ha Noi 8333012347 22/08/2011
*/

#include <bits/stdc++.h>
using namespace std;

int stt = 1;

class NhanVien {
public:
    string mnv, ten, gtinh, nsinh, dchi, msthue, ngay;

    friend istream &operator >> (istream &is, NhanVien &a) {
        cin.ignore();
        getline(cin, a.ten);
        cin >> a.gtinh >> a.nsinh;
        cin.ignore();
        getline(cin, a.dchi);
        cin >> a.msthue >> a.ngay;
    
        // Chuẩn hóa mnv
        string s = to_string(stt++);
        while (s.length() < 5) {
            s = "0" + s;
        }
        a.mnv = s;
        return is;
    }

    friend ostream &operator << (ostream &os, NhanVien a) {
        cout << a.mnv << " " << a.ten << " " << a.gtinh << " " << a.nsinh << " " << a.dchi << " " << a.msthue << " " << a.ngay << "\n";
        return os;
    }
};

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}