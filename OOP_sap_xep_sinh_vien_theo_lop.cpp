/*Thông tin về mỗi sinh viên gồm: • Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không trùng nhau. • Họ và tên: độ dài không quá 100. • Lớp: dãy ký tự không có khoảng trống (không quá 15). • Email: dãy ký tự không có khoảng trống (không quá 15). Hãy nhập danh sách sinh viên và sắp xếp theo lớp tăng dần (thứ tự từ điển).

Input Format

Dòng đầu ghi số sinh viên. Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email. Có không quá 5000 sinh viên trong danh sách.

Constraints

N/A

Output Format

Ghi ra danh sách sinh viên đã sắp xếp theo lớp. Mỗi sinh viên trên một dòng, các thông tin cách nhau một khoảng trống. Nếu 2 sinh viên có cùng lớp thì sắp xếp theo mã tăng dần (thứ tự từ điển)

Sample Input 0

4
SV001
Nguyen Trong Duc Anh
CNTT1
sv1@gmail.com
SV002
To Ngoc Hieu
CNTT2
sv2@gmail.com
SV003
Nguyen Ngoc Son
HTTT2
sv3@gmail.com
SV004
Nguyen Trong Tung
CNTT1
sv4@gmail.com
Sample Output 0

SV001 Nguyen Trong Duc Anh CNTT1 sv1@gmail.com 
SV004 Nguyen Trong Tung CNTT1 sv4@gmail.com
SV002 To Ngoc Hieu CNTT2 sv2@gmail.com
SV003 Nguyen Ngoc Son HTTT2 sv3@gmail.com
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

bool cmp(SinhVien a, SinhVien b) {
    if (a.lop == b.lop) return a.msv < b.msv;
    return a.lop < b.lop;
}

int main() {
    int n;
    cin >> n;
    SinhVien a[1000];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    return 0;
}