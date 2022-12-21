/*Thông tin về giảng viên Khoa CNTT ban đầu chỉ có họ tên và Bộ môn. 
Mã giảng viên sẽ tự động điền tăng dần, tính từ GV01.

Hãy liệt kê danh sách giảng viên của Bộ môn được yêu cầu.

Input

Dòng đầu ghi số giảng viên.

Mỗi giảng viên ghi trên 2 dòng gồm họ tên (không quá 50 ký tự) và Bộ môn (không quá 30 ký tự).

Tiếp theo là một dòng ghi số Q là số truy vấn.

Mỗi truy vấn là tên một bộ môn trên một dòng.

Output

Danh sách các giảng viên của bộ môn theo từng truy vấn, 
trong đó mỗi giảng viên ghi trên một dòng. Mã được tự động điền theo thứ tự nhập, 
bộ môn được viết tắt theo các chữ cái đầu của từng từ và ở dạng in hoa.

Thứ tự giảng viên của mỗi bộ môn được liệt kê theo đúng thứ tự ban đầu.

Input
3
Nguyen Manh Son
Cong nghe phan mem
Vu Hoai Nam
Khoa hoc may tinh
Dang Minh Tuan
An toan thong tin
1
Cong nghe phan mem

Output
DANH SACH GIANG VIEN BO MON CNPM:
GV01 Nguyen Manh Son CNPM

*/

#include <bits/stdc++.h>
using namespace std;

class GiangVien {
public:
    string mgv, hoTen, boMon, ten, mon;

    friend istream &operator >> (istream &is, GiangVien &a) {
        scanf("\n");
        getline(cin, a.hoTen);
        getline(cin, a.boMon);

        string s, res = "";
        stringstream ss(a.boMon);
        while (ss >> s) {
            res += toupper(s[0]);
        }
        a.mon = res;

        return is;
    }

    friend ostream &operator << (ostream &os, GiangVien a) {
        cout << a.mgv << " " << a.hoTen << " " << a.mon << "\n";
        return os;
    }
};

int main() {
    int n;
    cin >> n;
    GiangVien a[100];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        a[i].mgv = "GV" + to_string(i + 1);
        if (i + 1 < 10) 
            a[i].mgv.insert(2, "0");
    }

    int q;
    cin >> q;
    scanf("\n");
    while (q--) {
        string str, s, res = "";
        getline(cin, str);
        stringstream ss(str);
        while (ss >> s) {
            res += toupper(s[0]);
        }

        cout << "DANH SACH GIANG VIEN BO MON " << res << ":\n";
        for (int i = 0; i < n; ++i) {
            if (a[i].mon == res)
                cout << a[i];
        }
    }
    return 0;
}