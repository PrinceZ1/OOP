/*Thông tin về mỗi sinh viên gồm: • Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không trùng nhau. • Họ và tên: độ dài không quá 100.
• Lớp: dãy ký tự không có khoảng trống (không quá 15). • Email: dãy ký tự không có khoảng trống (không quá 15). Hãy nhập danh sách sinh viên và liệt kê sinh viên theo ngành. Ngành học của sinh viên sẽ dựa trên 4 chữ cái đầu tiên của lớp bao gồm các ngành : CNTT : Công nghệ thông tin. DTVT : Điện tử viễn thông. KT : Kế toán. MKT : Marketing.

Input Format

Dòng đầu ghi số sinh viên (không quá 1000) Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email. Sau đó sẽ có giá trị số Q là số truy vấn. Mỗi truy vấn sẽ là 1 trong 4 ngành nêu trên.

Constraints

1<=q<=100

Output Format

Với mỗi truy vấn, liệt kê danh sách sinh viên của ngành đó theo mẫu như trong ví dụ. Mỗi sinh viên ghi trên một dòng, các thông tin cách nhau một khoảng trống. Thứ tự sinh viên vẫn giữ nguyên như thứ tự ban đầu

Sample Input 0

3
20211000
Nguyen Ngoc Huong
CNTT2
DqFvSInO@gmail.com
20181001
Vu Duc Huong
CNTT2
KBvHj@gmail.com
20191002
Pham Duc Hoang
DTVT2
HEKglq@gmail.com
1
CNTT
Sample Output 0

DANH SACH SINH VIEN NGANH CONG NGHE THONG TIN :
20211000 Nguyen Ngoc Huong CNTT2 DqFvSInO@gmail.com
20181001 Vu Duc Huong CNTT2 KBvHj@gmail.com
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

string solve(string s) {
    if (s == "Ke toan") return "KT";
    if (s == "Cong nghe thong tin") return "CN";
    if (s == "An toan thong tin") return "AT";
    if (s == "Vien thong") return "VT";
    if (s == "Dien tu") return "DT";
}

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
        scanf("\n");
        string s;
        getline(cin, s);

        string major = solve(s);
        transform(s.begin(), s.end(), s.begin(), ::toupper);

        cout << "DANH SACH SINH VIEN NGANH " << s << ":\n";
        for (int i = 0; i < n; ++i) {
            if (major == "CN" || major == "AT") {
                if (a[i].msv[5] == major[0] && a[i].msv[6] == major[1] && a[i].lop[0] != 'E')
                    cout << a[i];
            }
            else {
                if (a[i].msv[5] == major[0] && a[i].msv[6] == major[1])
                    cout << a[i];
            }
        }
    }
    return 0;
}