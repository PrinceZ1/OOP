/*Viết chương trình khai báo lớp Sinh Viên gồm các thông tin: Mã SV, Họ tên, Ngày sinh, Lớp và Điểm GPA (dạng số thực). Hàm khởi tạo không có tham số, gán các giá trị thuộc tính ở trạng thái mặc định (xâu ký tự rỗng, giá trị số bằng 0). Đọc thông tin N thí sinh từ bàn phím (không có mã sinh viên) sau đó sắp xếp theo điểm GPA giảm dần và in ra lần lượt màn hình mỗi dòng 1 sinh viên. Trong đó Mã SV được tự tạo ra theo quy tắc thêm mã SV sau đó là giá trị nguyên tự động tăng tính từ 001 (tối đa là 099). Họ tên được xử lý đưa về dạng chuẩn. Ngày sinh được chuẩn hóa về dạng dd/mm/yyyy

Input Format

Dòng đầu tiên ghi số sinh viên N (0 < N < 50). Mỗi sinh viên ghi trên 4 dòng lần lượt là Họ tên, Lớp, Ngày sinh và Điểm GPA. Trong đó: • Họ tên không quá 30 chữ cái. • Lớp là một chuỗi kí tự không có dấu cách. • Ngày sinh có đủ 3 phần ngày tháng năm nhưng có thể chưa đúng chuẩn dd/mm/yyyy. • Điểm GPA đảm bảo trong thang điểm 4 với 2 nhiều nhất 2 số sau dấu phẩy.

Constraints

N/A

Output Format

Ghi ra danh sách lần lượt các sinh viên có đầy đủ Mã sinh viên, Họ tên, Lớp, Ngày sinh (đã chuẩn hóa), điểm GPA (với đúng 2 số sau dấu phẩy) đã được sắp xếp theo điểm GPA giảm dần. Nếu 2 bạn có cùng GPA thì bạn nào có mã sinh viên nhỏ hơn sẽ xếp trước. Mỗi sinh viên ghi trên 1 dòng, mỗi thông tin cách nhau 1 khoảng trống.

Sample Input 0

2
ngUYen Van NaM
CNTT1
2/12/1994
2.17
Nguyen QuanG hAi
CNTT2
1/9/1994
3.0
Sample Output 0

SV002 Nguyen Quang Hai CNTT2 01/09/1994 3.00
SV001 Nguyen Van Nam CNTT1 02/12/1994 2.17
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SV{
    string msv, ten, ns, lop;
    double gpa;
};
bool cmp(SV a, SV b){
    return a.gpa > b.gpa;
}

string chten(string &s)
{
    stringstream ss(s);
    string tmp;
    string name="";
    while(ss>>tmp)
    {
        tmp[0]=toupper(tmp[0]);
        for(int i=1;i<tmp.size();i++) tmp[i]=tolower(tmp[i]);
        name=name+ tmp + " ";
    }
    name.pop_back();
    return name;
}

void chuanHoa(string &s){
    if(s[1]=='/')
        s="0"+s;
    if(s[4]=='/')
        s.insert(3,"0");
}

int main(){
    int n; cin >> n;
    SV a[n];
    for(int i=0; i<n; i++){
        cin.ignore();
        a[i].msv = to_string(i+1);
        while(a[i].msv.size() < 3)
            a[i].msv = "0"+a[i].msv;
        a[i].msv = "SV" + a[i].msv;
        getline(cin, a[i].ten);
        a[i].ten=chten(a[i].ten);
        getline(cin, a[i].lop);
        getline(cin, a[i].ns);
        chuanHoa(a[i].ns);
        cin >> a[i].gpa;
    }
    stable_sort(a,a+n,cmp);
    for(int i=0; i<n; i++)
        cout << a[i].msv << ' ' << a[i].ten << ' ' << a[i].lop << ' ' << a[i].ns << ' ' << fixed << setprecision(2) << a[i].gpa << endl;
}