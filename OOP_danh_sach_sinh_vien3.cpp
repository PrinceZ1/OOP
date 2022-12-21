/*Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Lớp và Điểm GPA (dạng số thực float).
Hàm khởi tạo không có tham số, gán các giá trị thuộc tính ở trạng thái mặc định (xâu ký tự rỗng, giá trị số bằng 0).

Yêu cầu sử dụng chồng toán tử nhập và xuất để nhập đối tượng sinh viên với cin và in ra đối tượng sinh viên với cout.

Đọc thông tin N thí sinh từ bàn phím (không có mã sinh viên) sau đó sắp xếp theo điểm GPA giảm dần và in ra lần lượt màn hình mỗi dòng 1 sinh viên.

Trong đó Mã SV được tự tạo ra theo quy tắc thêm mã B20DCCN sau đó là giá trị nguyên tự động tăng tính từ 001 (tối đa là 099). 
Họ tên được xử lý đưa về dạng chuẩn. Ngày sinh được chuẩn hóa về dạng dd/mm/yyyy

Input

Dòng đầu tiên ghi số sinh viên N (0 < N < 50).

Mỗi sinh viên ghi trên 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA.

Trong đó:

Họ tên không quá 30 chữ cái.
Lớp theo đúng định dạng thường dùng ở PTIT
Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy.
Điểm GPA đảm bảo trong thang điểm 4 với 2 nhiều nhất 2 số sau dấu phẩy. 
Dữ liệu đảm bảo không có hai sinh viên nào có điểm GPA bằng nhau.

Output

Ghi ra danh sách lần lượt các sinh viên có đầy đủ Mã sinh viên, Họ tên, Lớp, Ngày sinh (đã chuẩn hóa), 
điểm GPA (với đúng 2 số sau dấu phẩy) đã được sắp xếp theo điểm GPA giảm dần.

Mỗi sinh viên ghi trên 1 dòng, mỗi thông tin cách nhau 1 khoảng trống.

Input
2
ngUYen Van NaM
D20DCCN01-B
2/12/2002
2.17
Nguyen QuanG hAi
D20DCCN02-B
1/9/2002
3.0

Output
B20DCCN002 Nguyen Quang Hai D20DCCN02-B 01/09/2002 3.00
B20DCCN001 Nguyen Van Nam D20DCCN01-B 02/12/2002 2.17
*/

#include <bits/stdc++.h>
using namespace std;

int stt = 1;

class SinhVien {
public:
    string msv, ten, lop, nsinh;
    float gpa;

    friend istream &operator >> (istream &is, SinhVien &a) {
        scanf("\n");
        getline(is, a.ten);
        is >> a.lop >> a.nsinh >> a.gpa;

        // Chuẩn hóa họ tên
        string str = "", temp;
        stringstream ss(a.ten);
        while (ss >> temp) {
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            temp[0] = toupper(temp[0]);
            str += temp + " ";
        }
        str.pop_back();
        a.ten = str;

        // Chuẩn hóa msv
        string s = to_string(stt++);
        while (s.length() < 3)
            s = '0' + s;
        a.msv = "B20DCCN" + s;

        // Chuẩn hóa ngày sinh
        if (a.nsinh[2] != '/') a.nsinh.insert(0, "0");
        if (a.nsinh[5] != '/') a.nsinh.insert(3, "0");
        return is;
    }

    friend ostream &operator << (ostream &os, SinhVien a) {
        os << a.msv << " " << a.ten << " " << a.lop << " " << a.nsinh << " ";
        os << fixed << setprecision(2) << a.gpa << "\n";
        return os;
    }
};

bool cmp(SinhVien a, SinhVien b) {
    return a.gpa > b.gpa;
}

void sapxep(SinhVien ds[], int N) {
    sort(ds, ds + N, cmp);
}

int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    sapxep(ds, N);
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}