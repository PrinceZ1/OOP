/*Quán Game mùa này vắng khách nên chủ quán quyết định tính tiền chi tiết đến từng phút. Dựa trên dữ liệu giờ vào và giờ ra, hãy tính thời gian chơi game của các Game thủ nhé.

Input Format

Dòng đầu của dữ liệu vào ghi số lượng game thủ trong ngày (không quá 20). Thông tin về một game thủ đến chơi game được ghi lại trên 4 dòng lần lượt là:

• username (xâu ký tự độ dài không quá 20, không có khoảng trống). • password (xâu ký tự độ dài không quá 30, không có khoảng tróng). • Tên người chơi (xâu ký tự độ dài không quá 100, có thể có khoảng trống). • Giờ vào (định dạng hh:mm). • Giờ ra (định dạng hh:mm).

Constraints

N/A

Output Format

Ghi ra danh sách game thủ đã được sắp xếp theo thời gian chơi game giảm dần, nếu có 2 game thủ có cùng giờ chơi game thì bạn nào có username có thứ tự từ điển nhỏ hơn được in ra trước.

Sample Input 0

5
anhtuanvip
123
Nguyen Van Tuan
05:18
07:06
chickenzero
124
Nguyen Van Phuc
05:38
14:19
anhhung123
matkhau
Nguyen Manh Hung
06:58
14:18
loveyou
acb
Luong Van Manh
02:01
06:47
taikhoan123
matkhaumanh
Nguyen Thi Uyen
00:09
06:19
Sample Output 0

chickenzero 124 Nguyen Van Phuc 8 gio 41 phut
anhhung123 matkhau Nguyen Manh Hung 7 gio 20 phut
taikhoan123 matkhaumanh Nguyen Thi Uyen 6 gio 10 phut
loveyou acb Luong Van Manh 4 gio 46 phut
anhtuanvip 123 Nguyen Van Tuan 1 gio 48 phut
Sample Input 1

5
bHaqxvui
iGYZMmhekYzBq
PaGc VdA UaVWtt IsPt DhgKH
09:50
18:30
pGZKupUVGMeI
aADAgxFMmMvUn
kPmi OQt hnMIp NzYHS
02:24
12:18
LnIHfIzsUEz
FLlpZRmPWpROGF
tpsFu gbBtEt wlvk GGF INg
04:31
07:10
FfqqlBTOB
vKFBIHmBhR
VgFVPZ sju YqOZeV qnjxcO
00:31
03:05
aUuZXfMAx
cWcgqrKmq
muTd HZDtO EOXaNE LtuTy SGNA
11:52
13:42
Sample Output 1

pGZKupUVGMeI aADAgxFMmMvUn kPmi OQt hnMIp NzYHS 9 gio 54 phut
bHaqxvui iGYZMmhekYzBq PaGc VdA UaVWtt IsPt DhgKH 8 gio 40 phut
LnIHfIzsUEz FLlpZRmPWpROGF tpsFu gbBtEt wlvk GGF INg 2 gio 39 phut
FfqqlBTOB vKFBIHmBhR VgFVPZ sju YqOZeV qnjxcO 2 gio 34 phut
aUuZXfMAx cWcgqrKmq muTd HZDtO EOXaNE LtuTy SGNA 1 gio 50 phut
*/