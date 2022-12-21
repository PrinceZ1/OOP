/*Để chuẩn bị cho đợt thực tập tốt nghiệp của sinh viên năm cuối, 
Khoa CNTT1 trao đổi với các doanh nghiệp đối tác và chốt số lượng sinh viên có thể nhận thực tập.

Hãy lọc ra các doanh nghiệp nhận số lượng sinh viên trong đoạn [a,b].  

Input

Dòng đầu ghi số doanh nghiệp.

Mỗi doanh nghiệp ghi trên 3 dòng:

Mã doanh nghiệp (xâu ký tự không có dấu cách, độ dài không quá 10)
Tên doanh nghiệp (xâu ký tự độ dài không quá 150)
Số sinh viên có thể nhận: giá trị nguyên không quá 1000
Tiếp theo là một dòng ghi số truy vấn Q. Mỗi truy vấn là 2 số nguyên a, b viết trên một dòng 
trong đó a<b và dữ liệu đảm bảo luôn có ít nhất 1 doanh nghiệp nhận số lượng sinh viên trong đoạn [a,b].

Output

Ghi ra danh sách đã lọc trong đoạn [a,b] và được sắp xếp theo số lượng giảm dần, mỗi thông tin ghi trên một dòng. 
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
1
30 50

Output
DANH SACH DOANH NGHIEP NHAN TU 30 DEN 50 SINH VIEN:
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

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << "DANH SACH DOANH NGHIEP NHAN TU " << l << " DEN " << r << " SINH VIEN:\n";
        for (int i = 0; i < n; ++i) {
            if (a[i].sluong > r)    
                continue;
            if (a[i].sluong < l)
                break;
            cout << a[i];
        }
    }
    return 0;
}