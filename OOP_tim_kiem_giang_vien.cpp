/*Thông tin về giảng viên Khoa CNTT ban đầu chỉ có họ tên và Bộ môn. 
Mã giảng viên sẽ tự động điền tăng dần, tính từ GV01.

Hãy tìm kiếm giảng viên theo tên (yêu cầu tìm gần đúng – 
tức là trong tên giảng viên xuất hiện từ hoặc cụm từ khóa, không phân biệt chữ hoa chữ thường).

Input

Dòng đầu ghi số giảng viên.

Mỗi giảng viên ghi trên 2 dòng gồm họ tên (không quá 50 ký tự) và Bộ môn (không quá 30 ký tự).

Tiếp theo là một dòng ghi số Q là số truy vấn.

Mỗi truy vấn là một từ khóa cần tìm.

Output

Danh sách các giảng viên tìm được theo từ khóa, trong đó mỗi giảng viên ghi trên một dòng. 
Mã được tự động điền theo thứ tự nhập, bộ môn được viết tắt theo các chữ cái đầu của từng từ và ở dạng in hoa.

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
aN

Output
DANH SACH GIANG VIEN THEO TU KHOA aN:
GV01 Nguyen Manh Son CNPM
GV03 Dang Minh Tuan ATTT
*/

#include <bits/stdc++.h>
using namespace std;

class GiangVien {
public:
    string mgv, hoTen, boMon, mon;

    friend istream &operator >> (istream &is, GiangVien &a) {
        scanf("\n");
        getline(cin, a.hoTen);
        getline(cin, a.boMon);

        string s2, res = "";
        stringstream ss2(a.boMon);
        while (ss2 >> s2) {
            res += toupper(s2[0]);
        }
        a.mon = res;

        return is;
    }

    friend ostream &operator << (ostream &os, GiangVien a) {
        cout << a.mgv << " " << a.hoTen << " " << a.mon << "\n";
        return os;
    }
};

bool canFind(string a, string b) {
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return (b.find(a) != -1);
}

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
    while (q--) {
        string s;
        cin >> s;
        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << s << ":\n";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < n; ++i) {
            if (canFind(s, a[i].hoTen))
                cout << a[i];
        }
    }
    return 0;
}