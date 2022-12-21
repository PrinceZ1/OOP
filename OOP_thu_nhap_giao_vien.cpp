/*Trường phổ thông XYZ tính lương giáo viên theo quy tắc sau: 
Mỗi giáo viên có mã ngạch gồm 4 ký tự trong đó. 
2 ký tự đầu là chức vụ (HT: Giáo viên kiêm nhiệm Hiệu trưởng, HP: Giáo viên kiêm nhiệm Hiệu phó, GV: Giáo viên thường). 
2 ký tự số cuối cùng cho biết hệ số bậc lương (không quá 20). 
Lương cơ bản của mỗi giáo viên cũng có thể khác nhau. 
Phụ cấp quy định như sau. HT: 2.000.000. HP: 900.000. GV: 500.000. 
Thu nhập được tính bằng lương cơ bản nhân với hệ số bậc lương cộng thêm phụ cấp. 
Hãy tính lương cho 1 giáo viên theo quy tắc trên.

Input Format

Có 3 dòng lần lượt là mã ngạch, họ tên và lương cơ bản.

Constraints

Lương cơ bản là số nguyên không quá 10^7

Output Format

Chỉ có một dòng ghi lần lượt các thông tin: mã ngạch, họ tên, bậc lương, thu nhập.

Sample Input 0

HP05
Nguyen Van Ha
1748000
Sample Output 0

HP05 Nguyen Van Ha 5 9640000
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct GV{
	string ma, ten;
	int luongcb;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	GV x;
	cin >> x.ma;
	cin.ignore();
	getline(cin, x.ten);
	cin >> x.luongcb;
	string chucvu = x.ma.substr(0, 2);
	int bc=stoi(x.ma.substr(2));
	int thunhap=bc*x.luongcb;
	int phucap=0;
	if(chucvu=="HT"){
		thunhap+=2000000;
		phucap=2000000;
	}
	else if(chucvu=="HP"){
		thunhap+=900000;
		phucap=900000;
	}
	else{
		thunhap+=500000;
		phucap=500000;
	}
	cout << x.ma << ' ' << x.ten << ' ' << bc << ' ' << thunhap << endl;
}