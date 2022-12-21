/*Thông tin về mỗi sinh viên gồm: • Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không trùng nhau. • Họ và tên: độ dài không quá 100, chưa được chuẩn hóa và cần được chuẩn hóa trước khi in. • Lớp: dãy ký tự không có khoảng trống (không quá 15). • Email: dãy ký tự không có khoảng trống (không quá 15). Hãy nhập danh sách sinh viên và liệt kê sinh viên theo khóa học. Chú ý: dữ liệu khóa học thể hiện qua 4 chữ số đầu tiên trong mã sinh viên

Input Format

Dòng đầu ghi số sinh viên (không quá 1000). Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email. Sau đó sẽ có giá trị số Q là số truy vấn. Tiếp theo là Q dòng, mỗi dòng ghi năm bắt đầu khóa học theo định dạng yyyy.

Constraints

1<=Q<=100

Output Format

Với mỗi truy vấn, liệt kê danh sách sinh viên của khóa đó theo mẫu như trong ví dụ. Mỗi sinh viên ghi trên một dòng, các thông tin cách nhau một khoảng trống. Thứ tự sinh viên vẫn giữ nguyên như thứ tự ban đầu.

Sample Input 0

4
20132238
hoang dinh NAm
CNTT1
namhd@gmail.com
20142231
PhAM nGoc     tHuan
HTTT2
thuanpn@gmail.com 
20148971
Nguyen duc XUAN
CNTT1
xuannd@gmail.com 
20132038
PhAM vAn Hung
CNTT2
hungpv@gmail.com
1
2013
Sample Output 0

DANH SACH SINH VIEN KHOA 2013 :
20132238 Hoang Dinh Nam CNTT1 namhd@gmail.com
20132038 Pham Van Hung CNTT2 hungpv@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

class SinhVien {
public:
    string msv, ten, lop, email;

    friend istream &operator >> (istream &is, SinhVien &a) {
        scanf("\n");
        getline(cin, a.msv);
        getline(cin, a.ten);
        getline(cin, a.lop);
        getline(cin, a.email);
        return is;
    }

    friend ostream &operator << (ostream &os, SinhVien a) {
        cout << a.msv << " " << a.ten << " " << a.lop << " " << a.email << "\n";
        return os;
    }
};

int main() {
    int n;
    cin >> n;

    SinhVien a[1000];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << "DANH SACH SINH VIEN KHOA " << s << ":\n";
        for (int i = 0; i < n; ++i) {
            if (a[i].lop[1] == s[2] && a[i].lop[2] == s[3])
                cout << a[i];
        }
    }
    return 0;
}