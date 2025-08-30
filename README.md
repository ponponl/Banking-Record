# Banking-Record

## Thành viên: 
Đinh Gia Hội Anh - 22127009
Huỳnh Quốc Thái  - 24127535
## Giới thiệu đồ án

### Tên đề tài: 

Hệ thống lưu giữ tài khoản ngân hàng - Banking Record System 

### Mô tả: 

Banking Record System là một ứng dụng console (không có giao diện đồ hoạ) viết bằng C/C++, dùng để quản lý thông tin tài khoản ngân hàng. Người dùng có thể tạo, xem, tìm, chỉnh sửa, xóa tài khoản và xử lý bằng xử lý file cơ bản (file as database).

### Link:

- Link đề tài: [Banking Record System C++ Project](https://www.codewithc.com/banking-record-system-project-c/)
- Nhưng vì mã nguồn đề tài không truy cập được nên nhóm em đã generate một mã nguồn cơ bản bằng AI và cải tiến từ đó: [Mã nguồn mẫu](https://onlinegdb.com/jI9RIWolC)

## Link repo github

 [Banking Record](https://github.com/ponponl/Banking-Record)

## Video Demo

 [Video demo](https://youtu.be/qqtolYkyQZ4)

## Phân công công việc

| Thành viên           | Công việc phụ trách                                                                                       |
|----------------------|----------------------------------------------------------------------------------------------------------|
| Đinh Gia Hội Anh     | Tìm hiểu kiến trúc, pattern, kỹ thuật OOP<br>Set up Jira, Github<br>Account DAO & Business Entity<br>Account Service<br>Account Repository<br>User Repository<br>Format số, phân trang, số điện thoại<br>Code parser<br>Mapping cho Account<br>Validate nhập liệu<br>Card Account & Adapter<br>Cải thiện Account Model<br>Refactor code<br>Đọc/ghi File<br>Controller<br>Unit test data/business layer<br>Doxygen<br>Vẽ class diagram<br>Video demo<br>Viết ReadMe |
| Huỳnh Quốc Thái      | Tìm hiểu kiến trúc, pattern, kỹ thuật OOP<br>Code giao diện menu<br>Bổ sung dữ liệu file txt<br>Input model cho user<br>User DAO & Business entity<br>Account input model<br>Cải tiến giao diện sử dụng phím<br>Hiển thị bảng<br>Tạo id tự động cho account<br>Account Factory<br>Cải tiến kế thừa vip/regular<br>Mapping User Entity<br>Manual test presentation layer<br>Viết test plan<br>Test đồ án |

Tỉ lệ đóng góp: 
- Hội Anh: 60%
- Quốc Thái 40%

Quản lý công việc nhóm bằng công cụ Jira.

Biên bản họp meeting: [Biên bản họp](https://drive.google.com/file/d/10m-P_H6o4D9JKqZkvYlAzEWpTU6FwfuW/view?usp=sharing)

Lưu ý: Biên bản họp nhóm chỉ tới tháng 7 vì qua tháng 8 nhóm trao đổi qua tin nhắn nhiều hơn vì tần suất thi cử và đồ án cao. Những việc phân công trong biên bản không giống 100% công việc thực hiện của mỗi người đã nêu vì lúc đó chỉ là phân công.

## Cải tiến

### Giao diện
- Giao diện có menu dùng phím mũi tên để thao tác
- Các số tiền và điện thoại được format dễ nhìn
- Có phân trang bảng
- Có hướng dẫn nhập liệu rõ ràng và báo lỗi cùng hướng dẫn nhập lại.

### Chức năng thêm
- Thêm các loại account: vip (số dư trên 2000), regular, card
- Loại thẻ được tự động gán không cần người dùng nhập
- Các id được tự động cấp
- Thêm tìm kiếm bằng user ID, tên người dùng, số điện thoại
- Có thể mở thêm tài khoản thẻ cho những người dùng đã có tài khoản thường (vip/regular).
- Khi tạo tài khoản cho người dùng mới, cũng sẽ tạo thêm người dùng.
- Xóa hết tài khoản sẽ xóa người dùng
- Có phần validate input để đảm bảo không xảy ra lỗi
- Có thể update thông tin theo ý muốn (có/không).

### Kiến trúc
- Đồ án kết hợp mô hình ba lớp + MVC trong tầng presentation.
- Pattern đã sử dụng: Singleton (repo, account), Adapter (card account), Factory
- Có sử dụng Interface cho Repo
- Áp dụng dependency injection, sRP
- Data Access Layer: Xử lý liên quan đến dữ liệu trong file 
- Business Layer: Xử lý nghiệp vụ
- Presentation Layer: Xử lý giao diện có sử dụng controller
- Mapping dùng để parse các entity của các lớp để chúng không cần biết gì về nhau

## Testing

Test Plan:[Test plan](https://drive.google.com/file/d/1Pe8shoUGwlSJ5a0d27yWhod6PMzaoZwK/view?usp=drive_link) 

File testcase: [Test case](https://docs.google.com/spreadsheets/d/1M2dBvCbKb0W83VgtzH7Amly4n3g43QzW92q7UG5cYCg/edit?usp=sharing) 

Chạy unit test:
```
cd release
./BankingCoreTests.exe
```

## Compile và chạy

Compile:

```sh
g++ -std=c++23 -O -I. App.cpp main.cpp PresentationLayer/Controller/AccountController.cpp PresentationLayer/InputModel/AccountModel.cpp PresentationLayer/InputModel/UserModel.cpp PresentationLayer/Validation/InputValidation.cpp PresentationLayer/View/AccountView.cpp PresentationLayer/View/Inputview.cpp PresentationLayer/View/MenuView.cpp PresentationLayer/View/UserView.cpp BusinessLayer/AccountFactory.cpp BusinessLayer/BusinessEntity/Account.cpp BusinessLayer/BusinessEntity/CardAccount.cpp BusinessLayer/BusinessEntity/RegularAccount.cpp BusinessLayer/BusinessEntity/User.cpp BusinessLayer/BusinessEntity/VipAccount.cpp BusinessLayer/Service/AccountService.cpp BusinessLayer/Service/CardAccountAdapter.cpp BusinessLayer/Service/UserService.cpp DataAccessLayer/DAOEntity/AccountRecord.cpp DataAccessLayer/DAOEntity/UserDAO.cpp DataAccessLayer/File/FileHandle/FileReader.cpp DataAccessLayer/File/FileHandle/FileWriter.cpp DataAccessLayer/File/Parser/AccountParser.cpp DataAccessLayer/File/Parser/UserParser.cpp DataAccessLayer/Repository/AccountRepo.cpp DataAccessLayer/Repository/UserRepo.cpp Utils/BalanceFormatter.cpp -o BankingApp.exe
```

Chạy:

```
 ./BankingApp.exe
```

## Coding Convention

- Đặt tên biến, hàm, class rõ nghĩa, dùng tiếng Anh, theo chuẩn camelCase cho biến/hàm, PascalCase cho class.
- Tên file, thư mục dùng PascalCase hoặc snake_case, không dùng tiếng Việt có dấu.
- Hàm, biến, class đều có comment mô tả chức năng nếu không tự giải thích được.
- Sử dụng dấu ngoặc nhọn mở ở cuối dòng khai báo hàm/class, đóng ở dòng riêng.
- Mỗi file chỉ chứa một class chính, các class phụ (struct, enum) liên quan có thể đi kèm.
- Không khai báo biến toàn cục trừ trường hợp đặc biệt (const, config).
- Sử dụng smart pointer (unique_ptr, shared_ptr) thay cho con trỏ thô.
- Không dùng magic number, mọi giá trị đặc biệt đều có biến đặt tên rõ ràng.
- Format code bằng tab hoặc 4 dấu cách, thống nhất toàn bộ project.
- Mỗi commit đều có prefix rõ ràng: ADD, UPDATE, FIX, REMOVE, STYLE, REFACTOR, DOC.
- Không push code lỗi, luôn kiểm tra build/test trước khi commit.
- Tách rõ các layer: Presentation, Business, Data, Mapping, Utils.
- Sử dụng const, override, final, noexcept khi cần thiết để tăng độ an toàn.
- Đặt tên hàm là động từ, tên biến là danh từ, tên class là danh từ hoặc cụm danh từ.
- Đặt tên enum class rõ nghĩa, dùng PascalCase cho từng giá trị.
- Không lồng quá 3 cấp if/for/while trong một hàm.
- Mỗi hàm không quá 50 dòng, nếu dài thì tách nhỏ.
- Sử dụng std::expected cho xử lý lỗi thay cho return code hoặc exception.
- Đảm bảo các file header có include guard hoặc pragma once.
- Không dùng using namespace std ở phạm vi toàn cục file header.

## Class Diagram 

- Có thể coi file classDiagram.md hoặc bằng link sau:

https://www.mermaidchart.com/app/projects/8d563c8f-ff3f-4521-abd7-899b3bf15736/diagrams/ad97eefe-2888-422f-b073-18d397bcc1f6/version/v0.1/edit


