/*Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán tự động tăng, bắt đầu từ 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn dd/mm/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy
Viết chương trình nhập danh sách nhân viên (không nhập mã) trong đó có sử dụng chồng toán tử nhập/xuất, 
sau đó sắp xếp theo thứ tự ngày sinh từ già nhất đến trẻ nhất và in ra màn hình danh sách đối tượng nhân viên đã sắp xếp.

Input

Dòng đầu ghi số N là số nhân viên (không quá 40). 
Mỗi nhân viên ghi trên 6 dòng lần lượt ghi các thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output

Ghi ra danh sách đầy đủ nhân viên đã sắp xếp, mỗi nhân viên trên một dòng, các thông tin cách nhau đúng một khoảng trống.

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
00003 Hoang Thi C Nu 04/02/1981 Mo Lao-Ha Dong-Ha Noi 8333012347 22/08/2011
00001 Nguyen Van A Nam 10/22/1982 Mo Lao-Ha Dong-Ha Noi 8333012345 31/12/2013
00002 Ly Thi B Nu 10/15/1988 Mo Lao-Ha Dong-Ha Noi 8333012346 22/08/2011
*/

#include <bits/stdc++.h>
using namespace std;

int stt = 1;

class NhanVien {
public:
    string mnv, ten, gtinh, dchi, msthue, ngay;
    int d, m, y;

    friend istream &operator >> (istream &is, NhanVien &a) {
        scanf("\n");
        getline(cin, a.ten);
        getline(cin, a.gtinh);
        scanf("%d/%d/%d\n", &a.m, &a.d, &a.y);
        getline(cin, a.dchi);
        getline(cin, a.msthue);
        getline(cin, a.ngay);
    
        // Chuẩn hóa mnv
        string s = to_string(stt++);
        while (s.length() < 5) {
            s = "0" + s;
        }
        a.mnv = s;
        return is;
    }

    friend ostream &operator << (ostream &os, NhanVien a) {
        cout << a.mnv << " " << a.ten << " " << a.gtinh;
        printf(" %.2d/%.2d/%.4d ", a.m, a.d, a.y);
        cout << a.dchi << " " << a.msthue << " " << a.ngay << "\n";
        return os;
    }
};

bool cmp(NhanVien a, NhanVien b) {  
    if (a.y < b.y) return 1;
    if (a.y == b.y) {
        if (a.m < b.m) return 1;
        if (a.m == b.m)  {
            if (a.d < b.d) return 1;
        }
    }
    return 0;
}

void sapxep(NhanVien ds[], int N) {
    sort(ds, ds + N, cmp);
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    sapxep(ds, N);
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}