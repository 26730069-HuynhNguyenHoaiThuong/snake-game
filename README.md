# 🐍 Dự Án Rắn Săn Mồi (Snake Game) - C++ Console

> **Môn học:** Kỹ năng nghề nghiệp (SS004) - Lớp: SS004.F31.CN1.CNTT  
> **Trường:** Đại học Công nghệ Thông tin - ĐHQG TP.HCM (UIT)  
> **Giảng viên hướng dẫn:** ThS. Nguyễn Văn Toàn  
> **Repository:** [https://github.com/26730069-HuynhNguyenHoaiThuong/snake-game](https://github.com/26730069-HuynhNguyenHoaiThuong/snake-game)  

---

## 👥 Danh Sách Thành Viên & Phân Công Nhiệm Vụ

| Vai trò | Thành viên phụ trách | MSSV | GitHub | Nhánh (Branch) | Nhiệm vụ chính |
| :--- | :--- | :---: | :--- | :---: | :--- |
| **SV1 (Trưởng nhóm)** | **Huỳnh Nguyễn Hoài Thương** | `26730069` | [`26730069-HuynhNguyenHoaiThuong`](https://github.com/26730069-HuynhNguyenHoaiThuong) | `main` | Định hướng cấu trúc dự án, điều phối nhóm, review code và chốt merge Pull Request |
| **SV2 (Thành viên)** | **Nguyễn Ngọc Duy** | `26730013` | [`26730013-NguyenNgocDuy`](https://github.com/26730013-NguyenNgocDuy) | `Ve-Khung` | Xây dựng hàm `VeKhung()` hiển thị viền bàn chơi cố định trên Console |
| **SV3 (Thành viên)** | **Phạm Phú Nguyễn Hưng** | `26730023` | [`26730023-PhamPhuNguyenHung`](https://github.com/26730023-PhamPhuNguyenHung)) | `An-Moi` | Xử lý logic sinh mồi ngẫu nhiên (`Point Qua`), cơ chế rắn ăn mồi tăng độ dài và tính điểm thời gian thực |

## 🧱 Chi Tiết Function `VeKhung()` (SV2: Nguyễn Ngọc Duy)

Function `VeKhung()` có nhiệm vụ vẽ khung cố định bao quanh khu vực chơi trên màn hình Console. Khung giúp người chơi nhận biết giới hạn di chuyển của rắn và tạo ranh giới trực quan cho bàn chơi.

1. **Xác định kích thước khung**:
   - Sử dụng các hằng số `MINX = 2`, `MINY = 2`, `MAXX = 35` và `MAXY = 20`.
   - Khung có tọa độ từ `(2, 2)` đến `(35, 20)` trên Console.
2. **Thuật toán vẽ viền**:
   - Duyệt toàn bộ các tọa độ trong phạm vi từ `MINX` đến `MAXX` và từ `MINY` đến `MAXY`.
   - Chỉ in ký tự `+` tại hàng trên, hàng dưới, cột trái và cột phải:
     - `i == MINX` hoặc `i == MAXX` là hai cạnh dọc.
     - `j == MINY` hoặc `j == MAXY` là hai cạnh ngang.
   - Function `gotoxy(i, j)` đưa con trỏ đến đúng vị trí trước khi in ký tự.
3. **Phối hợp với nhánh `An-Moi`**:
   - Khung bao phủ vùng sinh mồi của nhánh `An-Moi`, trong đó mồi được sinh tại `x` từ 5 đến 34 và `y` từ 3 đến 17.
   - Nhờ đó, rắn và mồi xuất hiện bên trong khu vực chơi, không che lên đường viền.
4. **Kết quả**:
   - Mỗi vòng lặp game gọi lại `VeKhung()` sau khi xóa màn hình bằng `system("cls")`, bảo đảm khung luôn được hiển thị ổn định.
   - Function chỉ chịu trách nhiệm vẽ khung, tách biệt với logic di chuyển, sinh mồi và tính điểm.

---

## 🎯 Chi Tiết Tính Năng Nhánh `An-Moi` (SV3: Phạm Phú Nguyễn Hưng)

Nhánh `An-Moi` giải quyết trọn vẹn luồng tương tác giữa rắn và thức ăn trong game:

1. **Cấu trúc dữ liệu Mồi (`struct Point Qua`)**:
   - Tọa độ `(x, y)` của quả mồi trên màn hình Console.
2. **Thuật toán sinh mồi an toàn (`SinhMoi(Point &Qua)`)**:
   - Sử dụng hàm ngẫu nhiên `rand()` có khởi tạo seed theo thời gian thực `time(NULL)`.
   - Giới hạn tọa độ mồi sinh ra nằm gọn trong vùng di chuyển hợp lệ (`x` từ 5 đến 34, `y` từ 3 đến 17).
   - Kiểm tra va chạm với toàn bộ thân rắn thông qua hàm `TrungThan(Point p)` để đảm bảo mồi **không bao giờ sinh đè lên thân rắn**.
3. **Hiển thị trực quan (`Ve(Point Qua)`)**:
   - Vẽ thân rắn bằng ký tự `X`.
   - Hiển thị mồi bằng ký tự dấu sao `*` tại đúng tọa độ được sinh ra.
4. **Xử lý va chạm & Rắn lớn dần (`DiChuyen(int Huong, Point &Qua)`)**:
   - Khi tọa độ đầu rắn `A[0]` trùng với mồi `Qua`:
     - Tăng độ dài thân rắn `DoDai++` (tối đa 100 đốt).
     - Tự động gọi hàm `SinhMoi(Qua)` để tạo quả mồi mới.
5. **Hệ thống tính điểm thời gian thực (Real-time Score)**:
   - Hiển thị trực tiếp trên giao diện Console tại tọa độ cố định:
     $$\text{Điểm số} = (\text{DoDai} - 3) \times 10$$
   - Mỗi lần ăn mồi thành công người chơi nhận ngay 10 điểm.
6. **Tối ưu chuẩn C++ & Tránh compiler warning**:
   - Ép kiểu tường minh `static_cast<SHORT>` cho tọa độ `COORD` của Windows API `SetConsoleCursorPosition`.

---

## 🎮 Hướng Dẫn Biên Dịch & Chơi Game

### 1. Yêu cầu hệ thống
- Hệ điều hành: Windows (sử dụng thư viện `<windows.h>` và `<conio.h>`).
- Trình biên dịch: GCC / MinGW (`g++`) hoặc Clang.

### 2. Biên dịch mã nguồn
Mở terminal (PowerShell hoặc Command Prompt) tại thư mục dự án và chạy:
```powershell
g++ Snake.cpp -o Snake.exe
```

### 3. Khởi chạy trò chơi
```powershell
.\Snake.exe
```

### 4. Bảng phím điều khiển
| Phím | Hướng di chuyển |
| :---: | :--- |
| `W` | Đi lên |
| `S` / `X` | Đi xuống |
| `A` | Rẽ trái |
| `D` | Rẽ phải |

---

## 🔄 Quy Trình Đóng Góp & Merge Code (Pull Request)

1. Thành viên phát triển tính năng trên nhánh riêng (`An-Moi`, `Ve-Khung`).
2. Kiểm tra biên dịch không có lỗi và logic chạy chính xác tại máy cục bộ.
3. Push nhánh lên GitHub và tạo Pull Request vào nhánh `main`.
4. Trưởng nhóm (**Huỳnh Nguyễn Hoài Thương**) review mã nguồn, phản hồi và thực hiện merge vào nhánh chính.
