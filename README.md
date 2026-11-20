Dự án code C++ giải trí cho tôi :)
Mục đính dự án này là giúp tôi tính được điểm các môn được xếp loại gì A, B, C, D

Đồng thời có lựa chọn tính học lực nữa (case 2)

Trong trường hợp con điểm không đủ (giá trị NULL) thì sẽ tính theo kiểu trung bình nếu bạn đạt được trên x điểm thay cho ô NULL thì bạn sẽ được A, nếu đạt y điểm thì  trên B, nếu đạt z điểm thì trên C:



Mục đính giúp ước tính chính xác xếp loại điểm mà biết đừng mà cố gắng học xD

Chỉ 1 file code C++ biên dịch, chạy , sử dụng nhập xuất như thông thường. Hỏi gì nhập đấy

Những trường thông tin cần nhập

Case 1: Xác định điểm chữ của môn 

Điểm giữa kì: (0-10)

Số điểm thường xuyên (vòng lặp):
Nhập lần lượt từng điểm thường xuyên

Điểm cuối kì (thường là không - và để trống không nhập)



Case 2: Xác định học lực của kì học:

Nhập số môn học:

Nhập số tín chỉ từng môn học:
2 vòng lặp lồng nhau: nhập đan xe kẽ lần nhau



Đầu ra:
Case 1: bỏ trống điểm cuối kì

Ở những ô điểm còn trống:

Bạn cần đạt trung bình trên x điểm để đạt loại A

Bạn cần đạt trung bình trên y điểm để đạt loại B

Bạn cần đạt trung bình trên z điểm để đạt loại C

Bạn cần đạt trung bình trên t điểm để đạt loại D

....

Document:

Điểm cuối kì nhân 0.5

giữa kì nhân 0.2

thường xuyên là 0.3

----

**(Bảng quy đổi điểm):**

| **Điểm số (theo thang điểm 10)** | **Điểm chữ** | **Điểm số (theo thang điểm 4)** |
| -------------------------------- | ------------ | ------------------------------- |
| 8,5-10,0                         | A            | 4,0                             |
| 7,8-8,4                          | B+           | 3,5                             |
| 7,0-7,7                          | B            | 3,0                             |
| 6,2-6,9                          | C+           | 2,5                             |
| 5,5-6,1                          | C            | 2,0                             |
| 4,8-5,4                          | D+           | 1,5                             |
| 4,0-4,7                          | D            | 1,0                             |
| dưới 4,0                         | F            | 0,0                             |

**Bảng xếp loại học lực):**

| **Điểm số (theo thang điểm 4)** | **Xếp loại** |
| ------------------------------- | ------------ |
| Từ 3,60 đến 4,0                 | Xuất sắc     |
| Từ 3,20 đến 3,59                | Giỏi         |
| Từ 2,5 đến 3,19                 | Khá          |
| Từ 2,00 đến 2,49                | Trung bình   |
| Từ 1,00 đến 1,99                | Yếu          |
| Dưới 1,00                       | Kém          |

Bình thường các môn sẽ tình lẻ điểm theo bảng quy đổi điểm

----

## Chạy thử (ai lười đọc ở trên)

```bash
g++ main.cpp -o tinhdiem
./tinhdiem
```

Windows thì chạy `tinhdiem.exe`. Mở lên nó hỏi chọn 1 hay 2, chọn xong nhập điểm, nhập sai nó bắt nhập lại (năn nỉ luôn), xong bấm 0 để thoát.

Ví dụ: giữa kì 8, thường xuyên 9 với 10, cuối kì để trống thì nó in ra cần 8.10 điểm cuối kì để được A. Nghe hơi căng nhưng mà đúng công thức của trường.

## Ghi chú linh tinh

- Code một file, không thư viện ngoài, không CMake gì cho mệt. Copy đi đâu cũng biên dịch được.
- Case 2 thì nhập điểm hệ 4 (0–4) luôn cho nhanh, khỏi quy đổi từ hệ 10 rồi lại quy đổi ngược.
- Điểm nhập sai (chữ, số âm, 11 điểm) thì chương trình không sập, chỉ càu nhàu rồi hỏi lại. Tốt hơn tôi hồi làm bài.
- Chưa có điểm cuối kì thì cứ để trống, nó tính hộ mức điểm cần đạt cho từng loại A, B+, B, C+, C, D+, D.
- Còn gì chưa hoàn hảo thì kệ, dùng được là được. Thấy sai thì sửa rồi mở pull request, tôi duyệt (chắc vậy).




