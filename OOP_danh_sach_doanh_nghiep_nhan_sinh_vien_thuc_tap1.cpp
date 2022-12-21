/*Để chuẩn bị cho đợt thực tập tốt nghiệp của sinh viên năm cuối, 
Khoa CNTT1 trao đổi với các doanh nghiệp đối tác và chốt số lượng sinh viên có thể nhận thực tập.

Hãy sắp xếp các doanh nghiệp theo số lượng sinh viên có thể nhận giảm dần.

Input

Dòng đầu ghi số doanh nghiệp.

Mỗi doanh nghiệp ghi trên 3 dòng:

Mã doanh nghiệp (xâu ký tự không có dấu cách, độ dài không quá 10)
Tên doanh nghiệp (xâu ký tự độ dài không quá 150)
Số sinh viên có thể nhận: giá trị nguyên không quá 1000
Output

Ghi ra danh sách đã được sắp xếp theo số lượng giảm dần, mỗi thông tin ghi trên một dòng. 
Trong trường hợp cùng số lượng thì sắp xếp theo mã doanh nghiệp (thứ tự từ điển tăng dần).

Input
4
VIETTEL
TAP DOAN VIEN THONG QUAN DOI VIETTEL
40
FSOFT
CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE
300
VNPT
TAP DOAN BUU CHINH VIEN THONG VIET NAM
200
SUN
SUN*
50

Output
FSOFT CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE 300
VNPT TAP DOAN BUU CHINH VIEN THONG VIET NAM 200
SUN SUN* 50
VIETTEL TAP DOAN VIEN THONG QUAN DOI VIETTEL 40

*/

#include <bits/stdc++.h>
using namespace std;

class DoanhNghiep {
public:
    string ma, ten;
    int sluong;

    friend istream &operator >> (istream &is, DoanhNghiep &a) {
        scanf("\n");
        getline(cin, a.ma);
        getline(cin, a.ten);
        cin >> a.sluong;
        return is;
    }

    friend ostream &operator << (ostream &os, DoanhNghiep a) {
        cout << a.ma << " " << a.ten << " " << a.sluong << "\n";
        return os;
    }
};

bool cmp(DoanhNghiep a, DoanhNghiep b) {
    if (a.sluong == b.sluong) return a.ma < b.ma;
    return a.sluong > b.sluong;
}

int main() {
    int n;
    cin >> n;
    DoanhNghiep a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    return 0;
}