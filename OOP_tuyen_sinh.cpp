/*Trường Đại học XYZ tuyển sinh theo hình thức xét điểm thi ba môn Toán – Lý – Hóa. Để đơn giản, khu vực tuyển sinh được quy định luôn bởi ba chữ cái đầu tiên trong mã thí sinh. Do rất thích các thí sinh đến từ Khu vực 3 nên trường XYZ tự quy định giá trị điểm ưu tiên Khu vực như trong bảng sau:

KV1 : 0,5
KV2 : 1.0
KV3 : 2.5
Giả sử biết trước điểm chuẩn là 24. Hãy xác định tình trạng tuyển sinh của thí sinh.

Input Format

Chỉ bao gồm thông tin của một thí sinh trên 5 dòng lần lượt là: - Mã thí sinh - Họ tên - Điểm toán - Điểm lý - Điểm hóa

Constraints

Các giá trị điểm đều đảm bảo trong phạm vi [0,10] và có thể có 1 chữ số phần thập phân.

Output Format

Ghi ra các thông tin: - Mã thí sinh - Họ tên - Khu vực - Tổng điểm – có tính ưu tiên (có thể có 1 số phần thập phân), trong trường hợp điểm là số thực với phần thập phân bằng 0 thì không in ra phần thập phân. - Trạng thái: TRUNG TUYEN hoac TRUOT (sau khi đã tính cả điểm ưu tiên)

Sample Input 0

KV2B
Hoang Ngoc Long
3.4
9
0
Sample Output 0

KV2B Hoang Ngoc Long 2 13.4 TRUOT
*/