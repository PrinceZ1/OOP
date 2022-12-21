/*Danh sách giảng viên của trường đại học cần được sắp xếp lại theo tên. Thông tin về giảng viên ban đầu chỉ có họ tên và Bộ môn. Mã giảng viên tự động tăng, tính từ GV01. Cần sắp xếp lại theo tên (tức là từ cuối cùng trong xâu họ tên). Các giảng viên có cùng tên thì được sắp xếp theo mã giảng viên.

Input Format

Dòng đầu ghi số giảng viên (không quá 50). Mỗi giảng viên ghi trên 2 dòng gồm họ tên (không quá 50 ký tự) và Bộ môn (không quá 30 ký tự).

Constraints

N/A

Output Format

Danh sách đã sắp xếp trong đó mỗi giảng viên ghi trên một dòng. Mã được tự động điền theo thứ tự nhập, bộ môn được viết tắt theo các chữ cái đầu của từng từ và ở dạng in hoa.

Sample Input 0

5
Tran Duc Huong
Toan tin
Vu Ngoc Manh
Da phuong tien
Tran Van Huong
Cong nghe thong tin
Phan Xuan Minh
Ke toan
Phan Ngoc Huong
Ke toan
Sample Output 0

GV01 Tran Duc Huong TT
GV03 Tran Van Huong CNTT
GV05 Phan Ngoc Huong KT
GV02 Vu Ngoc Manh DPT
GV04 Phan Xuan Minh KT
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

        string s1;
        stringstream ss1(a.hoTen);
        while (ss1 >> s1) {
            a.ten = s1;
        }

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

bool cmp(GiangVien a, GiangVien b) {
    if (a.ten == b.ten) return a.mgv < b.mgv;
    return a.ten < b.ten;
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

    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    return 0;
}