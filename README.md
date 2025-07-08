# Banking-Record

##  Folder Structure & Usage

Mô tả các thư mục và file:

```
presentation/          // Giao diện & nhận input
  view/                // In menu, nhận input, gọi service (AccountView.h/.cpp)
  input_model/         // Dữ liệu người dùng nhập (AccountInputModel.h)

business/              // Xử lý logic nghiệp vụ
  entity/              // Class Account (có method) (Account.h/.cpp)
  service/             // Gọi từ view để xử lý logic (AccountService.h/.cpp)

data/                  // Lưu/đọc từ file
  entity/              // Model để ghi file (pure data) (AccountDataModel.h)
  repository/          // Đọc/ghi file (AccountRepository.h/.cpp)
  storage/             // Thư mục chứa file .txt (accounts.txt)

utils/                 // Hàm tiện ích dùng chung (DateUtils.h/.cpp, Validation.h/.cpp)

main.cpp               // Chạy menu chính
README.md              // Mô tả
```

##  Hướng dẫn sử dụng Feature Branch Workflow (GitHub)

1. **Clone repository:**
   ```sh
   git clone <repo-url>
   cd Banking-Record
   ```
2. **Tạo branch mới cho từng tính năng:**
   ```sh
   git checkout -b name/feature/<ten-tinh-nang>
   ```
3. **Làm việc, chỉnh sửa code trên branch này.**

4. **Add & commit thay đổi:**
   ```sh
   git add .
   git commit -m "Add <ten-tinh-nang>"
   ```
5. **Push branch lên GitHub:**
   ```sh
   git push origin name/feature/<ten-tinh-nang>
   ```
6. **Tạo Pull Request** trên GitHub để merge vào `main`.

7. **Sau khi được review và duyệt, merge Pull Request.**

8. **Cập nhật branch main local:**
   ```sh
   git checkout main
   git pull origin main
   ```

**Lưu ý:** Luôn tạo branch mới cho mỗi tính năng/bugfix. Không commit trực tiếp lên `main`.
---

### Quy tắc đặt tên branch

- Đặt tên branch theo dạng: `name/feature/<ten-tinh-nang>`, `name/fix/<ten-bug>`, ...
- Trong đó `name` là tên thành viên (hoặc username), giúp dễ quản lý khi làm việc nhóm.
- Tên branch viết bằng tiếng Anh, ngắn gọn, phân tách bằng dấu gạch ngang (-).

**Ví dụ:**
```
nam/feature/add-login
linh/fix/validate-email
hoang/update/account-service
```

## Quy tắc commit message

---

Tuân theo chuẩn commit rõ ràng với các prefix sau:

| Prefix    | Ý nghĩa                                              |
|-----------|------------------------------------------------------|
| ADD:      | Thêm mới file, tính năng                             |
| UPDATE:   | Cập nhật logic, dữ liệu hoặc cấu trúc                 |
| FIX:      | Sửa lỗi                                              |
| REMOVE:   | Xoá file hoặc đoạn code không cần thiết               |
| STYLE:    | Format code, chỉnh sửa style không ảnh hưởng logic   |
| REFACTOR: | Cải tiến cấu trúc code, không thay đổi hành vi       |
| DOC:      | Cập nhật tài liệu, comment                           |

**Ví dụ:**

```sh
git commit -m "ADD: user model and registration controller"
git commit -m "STYLE: format server.js with Prettier"
```

