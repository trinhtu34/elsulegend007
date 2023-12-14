#include "Header.h"

void khoitaothongtinoto(NodeThongTinOTo*& list)
{
    list = nullptr;
}
void khoitaoloaixe(NodeLoaiXe*& list)
{
    list = nullptr;
}
void khoitaothuonghieu(NodeThuongHieu*& list)
{
    list = nullptr;
}
NodeThongTinOTo* TaoNodeOTo(ThongTinOTo x)
{
    NodeThongTinOTo* p = new NodeThongTinOTo;
    p->data = x;
    p->link = NULL;
    return p;
}
NodeLoaiXe* TaoNodeLoaiXe(LoaiXe x)
{
    NodeLoaiXe* p = new NodeLoaiXe;
    p->data = x;
    p->link = NULL;
    return p;
}
NodeThuongHieu* TaoNodeThuongHieu(ThuongHieu x)
{
    NodeThuongHieu* p = new NodeThuongHieu;
    p->data = x;
    p->link = NULL;
    return p;
}
NodeThongTinOTo* ThemDau(NodeThongTinOTo*& list, ThongTinOTo x)
{
    NodeThongTinOTo* p = TaoNodeOTo(x);
    p->link = list;
    list = p;
    return p;
}
NodeLoaiXe* ThemDau1(NodeLoaiXe*& list, LoaiXe x)
{
    NodeLoaiXe* p = TaoNodeLoaiXe(x);
    p->link = list;
    list = p;
    return p;
}
NodeThuongHieu* ThemDau2(NodeThuongHieu*& list, ThuongHieu x)
{
    NodeThuongHieu* p = TaoNodeThuongHieu(x);
    p->link = list;
    list = p;
    return p;
}
void GhiThongTinOTo(NodeThongTinOTo* car) {
    ofstream file("thongtinoto.txt", ios::app);
    while (car != nullptr) {
        file << "Ma oto: " << car->data.maOto << endl;
        file << "Loai xe: " << ChuanHoa(car->data.loaiXe) << endl;
        file << "Ten xe: " << ChuanHoa(car->data.tenXe) << endl;
        file << "Thuong hieu: " << ChuanHoa(car->data.thuongHieu) << endl;
        file << "Gia nhap: " << DinhDangTienTe(car->data.giaNhap) << endl;
        file << "Gia ban: " << DinhDangTienTe(car->data.giaBan) << endl;
        file << "Thoi gian nhap: ";

        // Định dạng cho ngày/tháng/năm như 2 ký tự
        if (car->data.NgayNhap < 10)
            file << "0";
        file << car->data.NgayNhap << "/";

        if (car->data.ThangNhap < 10)
            file << "0";
        file << car->data.ThangNhap << "/";

        file << car->data.NamNhap << endl;
        file << "--------------------------------" << endl;

        car = car->link;
    }
    file.close();
}
string ChuanHoa(string &str) {
    // Chuyển đổi tất cả các ký tự thành chữ thường
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    // Chuyển đổi ký tự đầu tiên của mỗi từ thành chữ hoa
    bool cap = true;
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && cap) {
            str[i] -= ('a' - 'A');
            cap = false;
        }
        else if (str[i] == ' ') {
            cap = true;
        }
    }

    return str;
}
string DinhDangTienTe(long long so) {
    string str = to_string(so);
    long long n = str.length();
    string res = "";

    // Thêm dấu '.' sau mỗi ba chữ số
    for (int i = 0; i < n; i++) {
        if (i > 0 && (n - i) % 3 == 0)
            res += ".";
        res += str[i];
    }

    return res;
}
long long ChuyenChuoiThanhSo(const std::string& str) {
    std::string strKhongDauCham = "";
    for (char c : str) {
        if (c != '.')
            strKhongDauCham += c;
    }
    return std::stoll(strKhongDauCham);
}
void GhiLoaiXe(NodeLoaiXe* loaixe)
{
    ofstream file("loaixe.txt", ios::app);
    while (loaixe != nullptr)
    {
        file << ChuanHoa(loaixe->data.tenloaixe) << endl;
        file << "--------------------------------" << endl;
        loaixe = loaixe->link;
    }
    file.close();
}

void GhiThuongHieu(NodeThuongHieu* thuonghieu)
{
    ofstream file("thuonghieu.txt", ios::app);
    while (thuonghieu != nullptr)
    {
        file << ChuanHoa(thuonghieu->data.ten) << endl;
        file << "--------------------------------" << endl;
        thuonghieu = thuonghieu->link;
    }
    file.close();
}

bool KiemTraTrungMaOToTrongFile(string maoto) {
    ifstream file("thongtinoto.txt");
    string line;

    while (getline(file, line))
    {
        if (line == maoto)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
bool KiemTraTrungMaOTo(NodeThongTinOTo* list, const string& maoto) {
    NodeThongTinOTo* p = list;
    while (p != NULL)
    {
        if (p->data.maOto == maoto) {
            return true;
        }
        p = p->link;
    }
    return false;
}
bool KiemTraLoaiXeTrongFile(string loaixe)
{
    ifstream file("loaixe.txt");
    string line;

    // Đọc toàn bộ file và kiểm tra chuỗi
    while (getline(file, line))
    {
        if (line == loaixe)
        {
            file.close();
            return true;  // Tìm thấy chuỗi trong file
        }
    }
    file.close();

    return false;  // Không tìm thấy chuỗi trong file
}
bool KiemTraTrungTenLoaiXe(NodeLoaiXe* list, const string& tenloaixecankiemtra) {
    NodeLoaiXe* p = list;
    while (p != NULL)
    {
        if (p->data.tenloaixe == tenloaixecankiemtra)
        {
            return true;
        }
        p = p->link;
    }
    return false;
}
bool KiemTraThuongHieuTrongFile(string thuonghieu)
{
    ifstream file("thuonghieu.txt");
    string line;

    // Đọc toàn bộ file và kiểm tra tên thương hiệu
    while (getline(file, line))
    {
        if (line == thuonghieu)
        {
            file.close();
            return true;  // Tìm thấy tên thương hiệu trong file
        }
    }
    file.close();

    return false;  // Không tìm thấy tên thương hiệu trong file
}
bool KiemTraTrungTenThuongHieu(NodeThuongHieu* list, const string& tenThuongHieuCanKiemTra) {
    NodeThuongHieu* current = list;

    // Duyệt danh sách liên kết kiểm tra từng tên thương hiệu
    while (current != nullptr) {
        if (current->data.ten == tenThuongHieuCanKiemTra) {
            // Nếu tên thương hiệu đã tồn tại trong danh sách, trả về true
            return true;
        }
        current = current->link;
    }

    // Nếu không tìm thấy tên thương hiệu trong danh sách, trả về false
    return false;
}
// Hàm kiểm tra năm nhuận
bool laNamNhuan(int nYear)
{
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
    {
        return true;
    }
    return false;

    // <=> return ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0);
}

// Hàm trả về số ngày trong tháng thuộc năm cho trước
int tinhSoNgayTrongThang(int nMonth, int nYear)
{
    int nNumOfDays;

    switch (nMonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        nNumOfDays = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        nNumOfDays = 30;
        break;
    case 2:
        if (laNamNhuan(nYear))
        {
            nNumOfDays = 29;
        }
        else
        {
            nNumOfDays = 28;
        }
        break;
    }

    return nNumOfDays;
}

// Hàm kiểm tra ngày dd/mm/yyyy cho trước có phải là ngày hợp lệ
bool laNgayHopLe(int nDay, int nMonth, int nYear)
{
    // Kiểm tra năm
    if (nYear < 0)
    {
        return false; // Ngày không còn hợp lệ nữa!
    }

    // Kiểm tra tháng
    if (nMonth < 1 || nMonth > 12)
    {
        return false; // Ngày không còn hợp lệ nữa!
    }

    // Kiểm tra ngày
    if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
    {
        return false; // Ngày không còn hợp lệ nữa!
    }

    return true; // Trả về trạng thái cuối cùng...
}
void Nhap(NodeThongTinOTo*& list, NodeLoaiXe*& list1, NodeThuongHieu*& list2)
{
    ThongTinOTo ttot;
    LoaiXe lx;
    ThuongHieu th;

    do
    {
        do
        {
            cout << "Nhap ma oto: ";
            cin >> ttot.maOto;
            if (KiemTraTrungMaOTo(list, ttot.maOto) == true && KiemTraTrungMaOToTrongFile(ttot.maOto) == true)
            {
                cout << "\nMa o to bi trung , Xin hay nhap lai ! " << endl;
            }
        } while (KiemTraTrungMaOTo(list, ttot.maOto) == true && KiemTraTrungMaOToTrongFile(ttot.maOto) == true);

        cout << "Nhap loai xe: ";
        cin.ignore(); // Xóa ký tự newline từ bộ đệm nhập chuẩn , dùng khi nhập xen kẽ giữa chữ và số 
        getline(cin, ttot.loaiXe);
        ChuanHoa(ttot.loaiXe);
        if (KiemTraTrungTenLoaiXe(list1, ttot.loaiXe) == false && KiemTraLoaiXeTrongFile(ttot.loaiXe) == false)
        {
            lx.tenloaixe = ttot.loaiXe;
            ThemDau1(list1, lx);
        }
        cout << "Nhap ten xe: ";
        getline(cin, ttot.tenXe);

        cout << "Nhap thuong hieu: ";
        getline(cin, ttot.thuongHieu);
        ChuanHoa(ttot.thuongHieu);
        if (KiemTraTrungTenThuongHieu(list2, ttot.thuongHieu) == false && KiemTraThuongHieuTrongFile(ttot.thuongHieu) == false)
        {
            th.ten = ttot.thuongHieu;
            ThemDau2(list2, th);
        }

        cout << "Nhap gia nhap: ";
        cin >> ttot.giaNhap;

        cout << "Nhap gia ban: ";
        cin >> ttot.giaBan;

        // nhập ngày tháng năm nhập
        do
        {
            cout << "Nhap ngay nhap: ";
            cin >> ttot.NgayNhap;
            cout << "Nhap thang nhap: ";
            cin >> ttot.ThangNhap;
            cout << "Nhap nam nhap: ";
            cin >> ttot.NamNhap;
            if (laNgayHopLe(ttot.NgayNhap, ttot.ThangNhap, ttot.NamNhap) == false)
            {
                cout << "\nNgay nhap khong hop le, xin hay nhap lai ! " << endl;
            }
        } while (laNgayHopLe(ttot.NgayNhap, ttot.ThangNhap, ttot.NamNhap) == false);

        // kiểm tra xem ngày tháng năm nhập đã có trong listDate chưa
        ThemDau(list, ttot);

        int exit = 1;
        cout << "\nNhap 0 de dung chuong trinh nhap ! ";
        cin >> exit;

        if (exit == 0)
        {
            GhiThongTinOTo(list);
            GhiLoaiXe(list1);
            GhiThuongHieu(list2);
            break;
        }

    } while (true);
}

//// Hàm đọc thông tin ô tô từ file thongtinoto.txt
//void DocThongTinOTo()
//{
//    ifstream file("thongtinoto.txt");
//    string line;
//    while (getline(file, line))
//    {
//        cout << line << endl;
//    }
//    file.close();
//}
void DocThongTinOToDaBan() {
    ifstream file("banhang.txt");
    string line;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << setw(20) << "Thoi gian ban" << endl;
    while (getline(file, line))
    {
        cout << left << setw(20) << line.substr(7);
        getline(file, line);
        cout << setw(20) << line.substr(9);
        getline(file, line);
        cout << setw(35) << line.substr(8);
        getline(file, line);
        cout << setw(20) << line.substr(13);
        getline(file, line);
        cout << setw(25) << line.substr(10);
        getline(file, line);
        cout << setw(25) << line.substr(9);
        getline(file, line);
        cout << setw(20) << line.substr(15);
        getline(file, line);
        cout << setw(20) << line.substr(14) << endl;
        getline(file, line); // Đọc dòng trống
        cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|---------------|" << endl;
    }
}
void DocThongTinOTo()
{
    ifstream file("thongtinoto.txt");
    string line;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << endl;
    while (getline(file, line))
    {
        cout << left << setw(20)<<line.substr(7);
        getline(file, line);
        cout << setw(20)<< line.substr(9);
        getline(file, line);
        cout << setw(35) << line.substr(8);
        getline(file, line);
        cout << setw(20) << line.substr(13);
        getline(file, line);
        cout << setw(25) << line.substr(10);
        getline(file, line);
        cout << setw(25) << line.substr(9);
        getline(file, line);
        cout << setw(20) << line.substr(15) << endl;
        getline(file, line); // Đọc dòng trống
        cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|" << endl;
    }
}
// Hàm đọc thông tin loại xe từ file loaixe.txt
void DocLoaiXe()
{
    ifstream file("loaixe.txt");
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

// Hàm đọc thông tin thương hiệu từ file thuonghieu.txt
void DocThuongHieu()
{
    ifstream file("thuonghieu.txt");
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
bool KTThoiGian(int NgayNhap, int ThangNhap, int NamNhap, int NgayBan, int ThangBan, int NamBan)
{
    if (NamNhap < NamBan) return true;
    if (NamNhap > NamBan) return false;

    if (ThangNhap < ThangBan) return true;
    if (ThangNhap > ThangBan) return false;

    if (NgayNhap < NgayBan) return true;
    if (NgayNhap > NgayBan) return false;

    return true;
}

void NhapNamBan(NodeThongTinOTo*& list) {
    ThongTinOTo ttot;
    do
    {
        cout << "Nhap ngay ban: ";
        cin >> ttot.NgayBan;
        cout << "Nhap thang ban: ";
        cin >> ttot.ThangBan;
        cout << "Nhap nam ban: ";
        cin >> ttot.NamBan;
        if (laNgayHopLe(ttot.NgayBan, ttot.ThangBan, ttot.NamBan) == false)
        {
            cout << "\nNgay ban khong hop le, xin hay nhap lai ! " << endl;
        }
    } while (laNgayHopLe(ttot.NgayBan, ttot.ThangBan, ttot.NamBan) == false);
    ThemDau(list, ttot);
}
void XoaThongTinOToTuFile(NodeThongTinOTo*& list, const string& maOtoCanXoa) {

    ifstream inputFile("thongtinoto.txt");
    ofstream tempFile("tempfile.txt");
    ofstream banHangFile("banhang.txt", ios::app);

    if (!inputFile || !tempFile || !banHangFile) {
        cerr << "Khong mo duoc file hoac file khong ton tai." << endl;
        return;
    }
    string line;
    bool found = false;
    string loaiXeCanXoa, thuongHieuCanXoa;
    NhapNamBan(list);
    while (getline(inputFile, line)) {
        if (line == "Ma oto: " + maOtoCanXoa)
        {
            found = true;
            banHangFile << line << endl; // Ghi Ma oto vào file banhang.txt
            for (int i = 0; i < 6; ++i) {
                getline(inputFile, line);
                banHangFile << line << endl; // Ghi thông tin còn lại của ô tô vào file banhang.txt
                if (i == 0) {
                    loaiXeCanXoa = line.substr(9); // Lưu loại xe cần xóa
                }
                if (i == 2) {
                    thuongHieuCanXoa = line.substr(13); // Lưu thương hiệu cần xóa
                }
            }
            banHangFile << "Thoi gian ban: ";
            if (list->data.NgayBan < 10)
                banHangFile << "0";
            banHangFile << list->data.NgayBan << "/";

            if (list->data.ThangBan < 10)
                banHangFile << "0";
            banHangFile << list->data.ThangBan << "/";

            banHangFile << list->data.NamBan << endl;
            banHangFile << "--------------------------------" << endl;
            getline(inputFile, line); // Bỏ qua dòng "--------------------------------"
        }
        else
        {
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();
    banHangFile.close();

    // Xóa file thongtinoto.txt cũ
    remove("thongtinoto.txt");

    // Đổi tên tệp tạm thời thành thongtinoto.txt
    rename("tempfile.txt", "thongtinoto.txt");

    if (found) {
        cout << "Da xoa thanh cong thong tin oto voi ma oto " << maOtoCanXoa << " tu file." << endl;
        // Kiểm tra xem loại xe và thương hiệu còn tồn tại trong file hay không
        ifstream checkFile("thongtinoto.txt");
        string checkLine;
        bool loaiXeFound = false, thuongHieuFound = false;
        while (getline(checkFile, checkLine)) {
            if (checkLine == "Loai xe: " + loaiXeCanXoa) {
                loaiXeFound = true;
            }
            if (checkLine == "Thuong hieu: " + thuongHieuCanXoa) {
                thuongHieuFound = true;
            }
        }
        checkFile.close();
        // Nếu loại xe hoặc thương hiệu không còn tồn tại, xóa chúng khỏi file tương ứng
        if (!loaiXeFound) {
            XoaLoaiXeTuFile(loaiXeCanXoa);
        }
        if (!thuongHieuFound) {
            XoaThuongHieuTuFile(thuongHieuCanXoa);
        }
    }
    else {
        cout << "Khong tim thay thong tin oto voi ma oto " << maOtoCanXoa << " trong file." << endl;
    }
}
void XoaLoaiXeTuFile(const string& tenLoaiXe)
{
    ifstream inFile("loaixe.txt");
    ofstream outFile("tempLX.txt");

    if (!inFile || !outFile) {
        cout << "Khong the mo file." << std::endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (line != tenLoaiXe) {
            outFile << line << "\n";
            getline(inFile, line); // Đọc dòng "--------------------------------"
            outFile << line << "\n";
        }
        else {
            getline(inFile, line); // Bỏ qua dòng "--------------------------------"
        }
    }

    inFile.close();
    outFile.close();

    // Đổi tên file temp.txt thành loaixe.txt
    remove("loaixe.txt");
    rename("tempLX.txt", "loaixe.txt");
}
void XoaThuongHieuTuFile(const string& tenThuongHieu)
{
    ifstream inFile("thuonghieu.txt");
    ofstream outFile("tempTH.txt");

    if (!inFile || !outFile) {
        cout << "Khong the mo file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (line != tenThuongHieu) {
            outFile << line << "\n";
            getline(inFile, line); // Đọc dòng "--------------------------------"
            outFile << line << "\n";
        }
        else {
            getline(inFile, line); // Bỏ qua dòng "--------------------------------"
        }
    }

    inFile.close();
    outFile.close();

    // Đổi tên file temp.txt thành thuonghieu.txt
    remove("thuonghieu.txt");
    rename("tempTH.txt", "thuonghieu.txt");
}
void SapXepThongTinOTo() {
    ifstream inputFile("thongtinoto.txt");

    if (!inputFile) {
        cerr << "Khong mo duoc file hoac file khong ton tai." << endl;
        return;
    }

    NodeThongTinOTo* head = nullptr;
    std::string line;

    while (getline(inputFile, line)) {
        NodeThongTinOTo* node = new NodeThongTinOTo;
        node->data.maOto = line.substr(8);
        getline(inputFile, line);
        node->data.loaiXe = line.substr(9);
        getline(inputFile, line);
        node->data.tenXe = line.substr(8);
        getline(inputFile, line);
        node->data.thuongHieu = line.substr(13);
        getline(inputFile, line);
        node->data.giaNhap = stoi(line.substr(10));
        getline(inputFile, line);
        node->data.giaBan = stoi(line.substr(9));
        node->link = nullptr;

        if (head == nullptr || head->data.giaBan > node->data.giaBan) {
            node->link = head;
            head = node;
        }
        else {
            NodeThongTinOTo* current = head;
            while (current->link != nullptr && current->link->data.giaBan < node->data.giaBan) {
                current = current->link;
            }
            node->link = current->link;
            current->link = node;
        }

        getline(inputFile, line); // Bỏ qua dòng "--------------------------------"
    }

    inputFile.close();

    ofstream outputFile("thongtinoto.txt");

    NodeThongTinOTo* current = head;
    while (current != nullptr) {
        outputFile << "Ma oto: " << current->data.maOto << endl;
        outputFile << "Loai xe: " << current->data.loaiXe << endl;
        outputFile << "Ten xe: " << current->data.tenXe << endl;
        outputFile << "Thuong hieu: " << current->data.thuongHieu << endl;
        outputFile << "Gia nhap: " << current->data.giaNhap << endl;
        outputFile << "Gia ban: " << current->data.giaBan << endl;
        outputFile << "--------------------------------" << endl;
        current = current->link;
    }

    outputFile.close();
}

// Hàm tính tổng giá bán từ file "banhang.txt"
long long TinhTongGiaBanSauThue() {
    std::ifstream file("banhang.txt");
    if (!file) {
        std::cerr << "Khong mo duoc file." << std::endl;
        return 0; // Trả về 0 nếu không mở được file
    }

    long long tongGiaBan = 0;
    bool foundXM = false, foundXT = false, foundXBT = false;
    std::string line;
    while (getline(file, line)) {
        if (line == "Loai xe: Xe May")
        {
            foundXM = true;
        }
        else if (line == "Loai xe: Xe Ban Tai")
        {
            foundXBT = true;
        }
        else if (line == "Loai xe: Xe Tai")
        {
            foundXT = true;
        }
        else if (foundXM && line.find("Gia ban: ") != std::string::npos) {
            // Tìm dòng chứa thông tin "Gia ban: "
            int giaBan = ChuyenChuoiThanhSo(line.substr(9)) * 92 / 100; // Lấy giá trị số từ dòng thông tin
            tongGiaBan += giaBan;
            foundXM = false;
        }
        else if (foundXBT && line.find("Gia ban: ") != std::string::npos)
        {
            long long giaBan = ChuyenChuoiThanhSo(line.substr(9)) * 91 / 100;
            tongGiaBan += giaBan;
            foundXBT = false;
        }
        else if (foundXT && line.find("Gia ban: ") != std::string::npos)
        {
            long long giaBan = ChuyenChuoiThanhSo(line.substr(9)) * 90 / 100;
            tongGiaBan += giaBan;
            foundXT = false;
        }
        else if (line.find("Gia ban: ") != std::string::npos)
        {
            long long giaBan = ChuyenChuoiThanhSo(line.substr(9)); // Lấy giá trị số từ dòng thông tin
            tongGiaBan += giaBan;
        }
    }

    file.close();
    return tongGiaBan;
}
long long TinhTongGiaBanLoaiXe(const std::string& TenLoaiXe) {
    std::ifstream file("banhang.txt");
    if (!file) {
        std::cerr << "Khong mo duoc file." << std::endl;
        return 0; // Trả về 0 nếu không mở được file
    }

    long long tongGiaBan = 0;
    string line;
    bool foundLoaiXe = false;
    string giaBanString;
    while (getline(file, line)) {
        if (line == "Loai xe: " + TenLoaiXe) {
            foundLoaiXe = true;
        }
        else if (foundLoaiXe && line.find("Gia ban: ") != std::string::npos) {
            // Tìm dòng chứa thông tin "Gia ban: "
            long long giaBan = ChuyenChuoiThanhSo(line.substr(9));
            tongGiaBan += giaBan;
            foundLoaiXe = false;
        }
    }

    file.close();
    return tongGiaBan;
}

long long TinhTongGiaBanThuongHieu(const std::string& TenThuongHieu) {
    std::ifstream file("banhang.txt");
    if (!file) {
        std::cerr << "Khong mo duoc file." << std::endl;
        return 0; // Trả về 0 nếu không mở được file
    }

    long long tongGiaBan = 0;
    std::string line;
    bool FoundThuongHieuXM = false, FoundThuongHieuXBT = false, FoundThuongHieuXT = false, FoundThuongHieu = false;
    bool foundXM = false, foundXBT = false, foundXT = false;
    while (getline(file, line))
    {
        if (line == "Loai xe: Xe May")
        {
            foundXM = true;
        }
        else if (line == "Loai xe: Xe Ban Tai")
        {
            foundXBT = true;
        }
        else if (line == "Loai xe: Xe Tai")
        {
            foundXT = true;
        }
        //
        else if (foundXM && line == "Thuong hieu: " + TenThuongHieu)
        {
            FoundThuongHieuXM = true;
        }
        else if (foundXBT && line == "Thuong hieu: " + TenThuongHieu)
        {
            FoundThuongHieuXBT = true;
        }
        else if (foundXT && line == "Thuong hieu: " + TenThuongHieu)
        {
            FoundThuongHieuXT = true;
        }
        else if (!foundXT && !foundXBT && !foundXM && line == "Thuong hieu: " + TenThuongHieu)
        {
            FoundThuongHieu = true;
        }
        //
        else if (FoundThuongHieuXM && line.find("Gia ban: ") != std::string::npos)
        {
            long long giabanxm = ChuyenChuoiThanhSo(line.substr(9)) * 92 / 100;
            tongGiaBan += giabanxm;
            FoundThuongHieuXM = false;
            foundXM = false;
        }
        else if (FoundThuongHieuXBT && line.find("Gia ban: ") != std::string::npos)
        {
            long long giabanxbt = ChuyenChuoiThanhSo(line.substr(9)) * 91 / 100;
            tongGiaBan += giabanxbt;
            FoundThuongHieuXBT = false;
            foundXBT = false;
        }
        else if (FoundThuongHieuXT && line.find("Gia ban: ") != std::string::npos)
        {
            long long giabanxt = ChuyenChuoiThanhSo(line.substr(9)) * 90 / 100;
            tongGiaBan += giabanxt;
            FoundThuongHieuXT = false;
            foundXT = false;
        }
        else if (FoundThuongHieu && line.find("Gia ban: ") != std::string::npos)
        {
            long long giaban = ChuyenChuoiThanhSo(line.substr(9));
            tongGiaBan += giaban;
            FoundThuongHieu = false;
        }

    }
    file.close();
    return tongGiaBan;
}

long long TinhTongGiaBanLoaiXeVaThuongHieu(const std::string& TenLoaiXe, const std::string& TenThuongHieu) {
    std::ifstream file("banhang.txt");
    if (!file) {
        std::cerr << "Khong mo duoc file." << std::endl;
        return 0; // Trả về 0 nếu không mở được file
    }

    long long tongGiaBan = 0;
    std::string line;
    bool foundLoaiXe = false;
    bool foundThuongHieu = false;
    std::string giaBanString;
    while (getline(file, line)) {
        if (line == "Loai xe: " + TenLoaiXe) {
            foundLoaiXe = true;
        }
        else if (line == "Thuong hieu: " + TenThuongHieu && foundLoaiXe) {
            foundThuongHieu = true;
        }
        else if (foundThuongHieu && line.find("Gia ban: ") != std::string::npos) {
            // Tìm dòng chứa thông tin "Gia ban: "
            long long giaBan = ChuyenChuoiThanhSo(line.substr(9));
            tongGiaBan += giaBan;
            foundLoaiXe = false;
            foundThuongHieu = false;
        }
    }

    file.close();
    return tongGiaBan;
}
long long TinhTongVonDaBan() {
    ifstream file("banhang.txt");
    if (!file)
    {
        cerr << "Khong mo duoc file" << endl;
        return 0;
    }
    long long TongGiaNhap = 0;
    string line;
    while (getline(file, line))
    {
        if (line.find("Gia nhap: ") != std::string::npos) {
            // Tìm dòng chứa thông tin "Gia nhap: "
            long long giaBan = ChuyenChuoiThanhSo(line.substr(10)); // Lấy giá trị số từ dòng thông tin
            TongGiaNhap += giaBan;
        }
    }

    file.close();
    return TongGiaNhap;
}
long long TinhTongVonDaBanLoaiXe(const std::string& TenLoaiXe) {
    ifstream file("banhang.txt");
    if (!file)
    {
        cerr << "Khong mo duoc file" << endl;
        return 0;
    }
    string line;
    bool foundLoaiXe = false;
    long long TongGiaNhapTheoLX = 0;
    while (getline(file, line))
    {
        if (line == "Loai xe: " + TenLoaiXe)
        {
            foundLoaiXe = true;
        }
        else if (foundLoaiXe && line.find("Gia nhap: ") != std::string::npos) {
            // Tìm dòng chứa thông tin "Gia nhap: "
            long long giaNhap = ChuyenChuoiThanhSo(line.substr(10)); // Lấy giá trị số từ dòng thông tin
            TongGiaNhapTheoLX += giaNhap;
            foundLoaiXe = false;
        }
    }
    file.close();
    return TongGiaNhapTheoLX;
}
long long TinhTongVonDaBanThuongHieu(const std::string& TenThuongHieu) {
    ifstream file("banhang.txt");
    if (!file)
    {
        cerr << "Khong mo duoc file" << endl;
        return 0;
    }
    string line;
    bool foundThuongHieu = false;
    long long TongGiaNhapTheoTH = 0;
    while (getline(file, line))
    {
        if (line == "Thuong hieu: " + TenThuongHieu)
            foundThuongHieu = true;
        else if (foundThuongHieu && line.find("Gia nhap: ") != std::string::npos)
        {
            long long giaNhap = ChuyenChuoiThanhSo(line.substr(10));
            TongGiaNhapTheoTH += giaNhap;
            foundThuongHieu = false;
        }
    }
    file.close();
    return TongGiaNhapTheoTH;
}
long long TinhTongVonDaBanCuaLoaiXeVaThuongHieu(const std::string& TenLoaiXe, const std::string& TenThuongHieu) {
    ifstream file("banhang.txt");
    if (!file)
    {
        cerr << "Khong mo duoc file" << endl;
        return 0;
    }
    string line;
    bool foundThuongHieu = false;
    bool foundLoaiXe = false;
    long long TongGiaTHvaLX = 0;
    while (getline(file, line))
    {
        if (line == "Loai xe: " + TenLoaiXe)
        {
            foundLoaiXe = true;
        }
        else if (foundLoaiXe && line == "Thuong hieu: " + TenThuongHieu)
        {
            foundThuongHieu = true;
        }
        else if (foundLoaiXe && foundThuongHieu && line.find("Gia nhap: ") != std::string::npos)
        {
            long long giaNhap = ChuyenChuoiThanhSo(line.substr(10));
            TongGiaTHvaLX += giaNhap;
            foundLoaiXe = false;
            foundThuongHieu = false;
        }
    }
    file.close();
    return TongGiaTHvaLX;
}void docDuLieuTuFile(NodeThongTinOTo*& head, string tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "Không thể mở file " << tenFile << endl;
        return;
    }

    string dong;
    while (getline(file, dong)) {
        if (dong.find("Ma oto:") != string::npos) {
            ThongTinOTo oto;
            oto.maOto = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.loaiXe = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.tenXe = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.thuongHieu = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.giaNhap = ChuyenChuoiThanhSo(dong.substr(dong.find(":") + 2));

            getline(file, dong);
            oto.giaBan = ChuyenChuoiThanhSo(dong.substr(dong.find(":") + 2));

            getline(file, dong);
            string ngayNhap = dong.substr(dong.find(":") + 2);
            oto.NgayNhap = stoi(ngayNhap.substr(0, ngayNhap.find("/")));
            oto.ThangNhap = stoi(ngayNhap.substr(ngayNhap.find("/") + 1, ngayNhap.rfind("/") - ngayNhap.find("/") - 1));
            oto.NamNhap = stoi(ngayNhap.substr(ngayNhap.rfind("/") + 1));

            NodeThongTinOTo* node = new NodeThongTinOTo;
            node->data = oto;
            node->link = NULL;

            if (head == NULL) {
                head = node;
            }
            else {
                NodeThongTinOTo* temp = head;
                while (temp->link != NULL) {
                    temp = temp->link;
                }
                temp->link = node;
            }
        }
    }

    file.close();
}

ThongTinOTo* timKiemOto(NodeThongTinOTo* head, string maOto) {
    NodeThongTinOTo* temp = head;
    while (temp != NULL) {
        if (temp->data.maOto == maOto) {
            return &(temp->data);
        }
        temp = temp->link;
    }
    return NULL;
}
void timKiemOtoTheoThuongHieu(NodeThongTinOTo* head, string thuongHieu) {
    NodeThongTinOTo* temp = head;
    bool found = false;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << endl;
    while (temp != NULL) {
        if (temp->data.thuongHieu == thuongHieu) {
            cout << left << setw(20) << temp->data.maOto;
            cout << setw(20) << ChuanHoa(temp->data.loaiXe);
            cout << setw(35) << ChuanHoa(temp->data.tenXe);
            cout << setw(20) << ChuanHoa(temp->data.thuongHieu);
            cout << setw(25) << DinhDangTienTe(temp->data.giaNhap);
            cout << setw(25) << DinhDangTienTe(temp->data.giaBan);
            if (temp->data.NgayNhap < 10)
                cout << "0";
            cout << temp->data.NgayNhap << "/";

            if (temp->data.ThangNhap < 10)
                cout << "0";
            cout << temp->data.ThangNhap << "/";

            cout << temp->data.NamNhap << endl;
            cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|" << endl;
            found = true;
        }
        temp = temp->link;
    }
    if (!found) {
        cout << "Khong tim thay o to voi " << thuongHieu << endl;
    }
}
void timKiemOtoTheoLoaiXe(NodeThongTinOTo* head, string loaiXe) {
    NodeThongTinOTo* temp = head;
    bool found = false;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << endl;
    while (temp != NULL) {
        if (temp->data.loaiXe == loaiXe) {
            cout << left << setw(20) << temp->data.maOto;
            cout << setw(20) << ChuanHoa(temp->data.loaiXe);
            cout << setw(35) << ChuanHoa(temp->data.tenXe);
            cout << setw(20) << ChuanHoa(temp->data.thuongHieu);
            cout << setw(25) << DinhDangTienTe(temp->data.giaNhap);
            cout << setw(25) << DinhDangTienTe(temp->data.giaBan);
            if (temp->data.NgayNhap < 10)
                cout << "0";
            cout << temp->data.NgayNhap << "/";

            if (temp->data.ThangNhap < 10)
                cout << "0";
            cout << temp->data.ThangNhap << "/";

            cout << temp->data.NamNhap << endl;
            cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|" << endl;
            found = true;
        }
        temp = temp->link;
    }
    if (!found) {
        cout << "Khong tim thay o to voi loi xe: " << loaiXe << endl;
    }
}
void timKiemOtoTheoTenXe(NodeThongTinOTo* head, string tenXe) {
    NodeThongTinOTo* temp = head;
    bool found = false;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << endl;
    while (temp != NULL) {
        if (temp->data.tenXe == tenXe) {
            cout << left << setw(20) << temp->data.maOto;
            cout << setw(20) << ChuanHoa(temp->data.loaiXe);
            cout << setw(35) << ChuanHoa(temp->data.tenXe);
            cout << setw(20) << ChuanHoa(temp->data.thuongHieu);
            cout << setw(25) << DinhDangTienTe(temp->data.giaNhap);
            cout << setw(25) << DinhDangTienTe(temp->data.giaBan);
            if (temp->data.NgayNhap < 10)
                cout << "0";
            cout << temp->data.NgayNhap << "/";

            if (temp->data.ThangNhap < 10)
                cout << "0";
            cout << temp->data.ThangNhap << "/";

            cout << temp->data.NamNhap << endl;
            cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|" << endl;
            found = true;
        }
        temp = temp->link;
    }
    if (!found) {
        cout << "Khong tim thay o to voi " << tenXe << endl;
    }
}
void timKiemOtoTheoKhoangGiaBan(NodeThongTinOTo* head, int giaBanThapNhat, int giaBanCaoNhat) {
    NodeThongTinOTo* temp = head;
    bool found = false;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << endl;
    while (temp != NULL) {
        if (temp->data.giaBan >= giaBanThapNhat && temp->data.giaBan <= giaBanCaoNhat) {
            if (!found) {
                cout << "Cac o to nam trong khoang gia can tim la: " << endl;
                found = true;
            }
            cout << left << setw(20) << temp->data.maOto;
            cout << setw(20) << ChuanHoa(temp->data.loaiXe);
            cout << setw(35) << ChuanHoa(temp->data.tenXe);
            cout << setw(20) << ChuanHoa(temp->data.thuongHieu);
            cout << setw(25) << DinhDangTienTe(temp->data.giaNhap);
            cout << setw(25) << DinhDangTienTe(temp->data.giaBan);
            if (temp->data.NgayNhap < 10)
                cout << "0";
            cout << temp->data.NgayNhap << "/";

            if (temp->data.ThangNhap < 10)
                cout << "0";
            cout << temp->data.ThangNhap << "/";

            cout << temp->data.NamNhap << endl;
            cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|" << endl;
            found = true;
        }
        temp = temp->link;
    }
    if (!found) {
        cout << "khong tim thay o to nao trong khoang gia tu " << giaBanThapNhat << " đen " << giaBanCaoNhat << endl;
    }
}
void timKiemOtoTheoLoaiXeVaThuongHieu(NodeThongTinOTo* head, string loaiXe, string thuongHieu) {
    NodeThongTinOTo* temp = head;
    bool found = false;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << endl;
    while (temp != NULL) {
        if (temp->data.loaiXe == loaiXe && temp->data.thuongHieu == thuongHieu) {
            if (!found) {
                cout << "Cac o to co loai xe va thuong hieu can tim: " << endl;
                found = true;
            }
            cout << left << setw(20) << temp->data.maOto;
            cout << setw(20) << ChuanHoa(temp->data.loaiXe);
            cout << setw(35) << ChuanHoa(temp->data.tenXe);
            cout << setw(20) << ChuanHoa(temp->data.thuongHieu);
            cout << setw(25) << DinhDangTienTe(temp->data.giaNhap);
            cout << setw(25) << DinhDangTienTe(temp->data.giaBan);
            if (temp->data.NgayNhap < 10)
                cout << "0";
            cout << temp->data.NgayNhap << "/";

            if (temp->data.ThangNhap < 10)
                cout << "0";
            cout << temp->data.ThangNhap << "/";

            cout << temp->data.NamNhap << endl;
            cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|" << endl;
        }
        temp = temp->link;
    }
    if (!found) {
        cout << "Khong tim thay o to nao voi " << loaiXe << " va thuong hieu " << thuongHieu << endl;
    }
}
void demSoLuongOtoTheoThuongHieu(NodeThongTinOTo* head, string thuongHieu) {
    NodeThongTinOTo* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->data.thuongHieu == thuongHieu) {
            count++;
        }
        temp = temp->link;
    }
    if (count == 0) {
        cout << "Khong tim thay o to voi thuong hieu " << thuongHieu << endl;
    }
    else {
        cout << "So luong o to thuoc thuong hieu " << thuongHieu << ": " << count << endl;
        cout << "Thong tin chi tiet ve cac o to thuoc thuong hieu " << thuongHieu << " la: " << endl;
        timKiemOtoTheoThuongHieu(head, thuongHieu);
    }
}
void demSoLuongOtoTheoLoaiXe(NodeThongTinOTo* head, string loaixe) {
    NodeThongTinOTo* temp = head;
    int count = 0;
    //cout << left << setw(10) << "Ma O To" << setw(15) << "Loai Xe" << setw(20) << "Ten O To" << setw(15) << "Thuong Hieu" << setw(15) << "Gia nhap" << setw(15) << "Gia ban" << setw(15) << "Thoi gian nhap" << endl;
    while (temp != NULL) {
        if (temp->data.loaiXe == loaixe) {
 /*           cout << left << setw(10) << temp->data.maOto;
            cout << setw(15) << ChuanHoa(temp->data.loaiXe);
            cout << setw(20) << ChuanHoa(temp->data.tenXe);
            cout << setw(15) << ChuanHoa(temp->data.thuongHieu);
            cout << setw(15) << DinhDangTienTe(temp->data.giaNhap);
            cout << setw(15) << DinhDangTienTe(temp->data.giaBan);
            cout << setw(15) ;
            if (head->data.NgayNhap < 10)
                cout << "0";
            cout << head->data.NgayNhap << "/";

            if (head->data.ThangNhap < 10)
                cout << "0";
            cout << head->data.ThangNhap << "/";

            cout << head->data.NamNhap << endl;            
            cout << "--------|--------------|--------------------|--------------|--------------|--------------|----------------|" << endl;*/

            count++;
        }
        temp = temp->link;
    }
    if (count == 0) {
        cout << "Khong tim thay o to voi thuong hieu " << loaixe << endl;
    }
    else {
        cout << "So luong o to thuoc thuong hieu " << loaixe << ": " << count << endl;
        cout << "Thong tin chi tiet ve cac o to thuoc thuong hieu " << loaixe << " la: " << endl;
        timKiemOtoTheoLoaiXe(head, loaixe);
    }
}
void demSoLuongOtoTheoThuongHieuVaLoaiXe(NodeThongTinOTo* head, string thuongHieu, string loaiXe) {
    NodeThongTinOTo* temp = head;
    int count = 0;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap" << endl;
    while (temp != NULL) {
        if (temp->data.thuongHieu == thuongHieu && temp->data.loaiXe == loaiXe) {
            cout << left << setw(20) << temp->data.maOto;
            cout << setw(20) << ChuanHoa(temp->data.loaiXe);
            cout << setw(35) << ChuanHoa(temp->data.tenXe);
            cout << setw(20) << ChuanHoa(temp->data.thuongHieu);
            cout << setw(25) << DinhDangTienTe(temp->data.giaNhap);
            cout << setw(25) << DinhDangTienTe(temp->data.giaBan);
            if (temp->data.NgayNhap < 10)
                cout << "0";
            cout << temp->data.NgayNhap << "/";

            if (temp->data.ThangNhap < 10)
                cout << "0";
            cout << temp->data.ThangNhap << "/";

            cout << temp->data.NamNhap << endl;
            cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|" << endl;
            count++;
        }
        temp = temp->link;
    }
    if (count == 0) {
        cout << "Khong tim thay o to voi thuong hieu " << thuongHieu << " va loai xe " << loaiXe << endl;
    }
    else {
        cout << "So luong o to thuoc thuong hieu " << thuongHieu << " va loai xe " << loaiXe << ": " << count << endl;
    }
}

//Ham doc file ban hang
void docDuLieuTuFileBanHang(NodeThongTinOTo*& head, string tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "Không thể mở file " << tenFile << endl;
        return;
    }

    string dong;
    while (getline(file, dong)) {
        if (dong.find("Ma oto:") != string::npos) {
            ThongTinOTo oto;
            oto.maOto = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.loaiXe = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.tenXe = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.thuongHieu = dong.substr(dong.find(":") + 2);

            getline(file, dong);
            oto.giaNhap = stoi(dong.substr(dong.find(":") + 2));

            getline(file, dong);
            oto.giaBan = stoi(dong.substr(dong.find(":") + 2));

            getline(file, dong);
            string ngayNhap = dong.substr(dong.find(":") + 2);
            oto.NgayNhap = stoi(ngayNhap.substr(0, ngayNhap.find("/")));
            oto.ThangNhap = stoi(ngayNhap.substr(ngayNhap.find("/") + 1, ngayNhap.rfind("/") - ngayNhap.find("/") - 1));
            oto.NamNhap = stoi(ngayNhap.substr(ngayNhap.rfind("/") + 1));

            getline(file, dong);
            string ngayBan = dong.substr(dong.find(":") + 2);
            oto.NgayBan = stoi(ngayBan.substr(0, ngayBan.find("/")));
            oto.ThangBan = stoi(ngayBan.substr(ngayBan.find("/") + 1, ngayBan.rfind("/") - ngayBan.find("/") - 1));
            oto.NamBan = stoi(ngayBan.substr(ngayBan.rfind("/") + 1));

            NodeThongTinOTo* node = new NodeThongTinOTo;
            node->data = oto;
            node->link = NULL;

            if (head == NULL) {
                head = node;
            }
            else {
                NodeThongTinOTo* temp = head;
                while (temp->link != NULL) {
                    temp = temp->link;
                }
                temp->link = node;
            }
        }
    }

    file.close();
}
bool conBaoHanh(ThongTinOTo oto) {
    // Lấy thời gian hiện tại
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // Tính số năm từ ngày bán đến hiện tại
    int soNam = 1900 + ltm->tm_year - oto.NamBan;

    // Nếu số năm nhỏ hơn 5, ô tô còn bảo hành
    if (soNam < 5) {
        return true;
    }
    // Nếu số năm bằng 5, kiểm tra tháng
    else if (soNam == 5) {
        if (oto.ThangBan > 1 + ltm->tm_mon) {
            return true;
        }
        // Nếu tháng bằng nhau, kiểm tra ngày
        else if (oto.ThangBan == 1 + ltm->tm_mon) {
            if (oto.NgayBan > ltm->tm_mday) {
                return true;
            }
        }
    }

    // Nếu không đáp ứng các điều kiện trên, ô tô không còn bảo hành
    return false;
}
//Ham xuat thong tin o to con bao hang
void XuatThongTinOToConBaoHanh(NodeThongTinOTo* head) {
    NodeThongTinOTo* node = head;
    bool found = false;
    cout << left << setw(20) << "Ma O To" << setw(20) << "Loai Xe" << setw(35) << "Ten O To" << setw(20) << "Thuong Hieu" << setw(25) << "Gia nhap" << setw(25) << "Gia ban" << setw(20) << "Thoi gian nhap"<<setw(20)<<"Thoi gian ban" << endl;
    while (node != NULL) {
        ThongTinOTo oto = node->data;
        if (conBaoHanh(oto)) {
            if (!found) {
                cout << "Cac o to con bao hanh: " << endl;
                found = true;
            }
            cout << left << setw(20) << node->data.maOto;
            cout << setw(20) << ChuanHoa(node->data.loaiXe);
            cout << setw(35) << ChuanHoa(node->data.tenXe);
            cout << setw(20) << ChuanHoa(node->data.thuongHieu);
            cout << setw(25) << DinhDangTienTe(node->data.giaNhap);
            cout << setw(25) << DinhDangTienTe(node->data.giaBan);
            if (node->data.NgayNhap < 10)
                cout << "0";
            cout << node->data.NgayNhap << "/";

            if (node->data.ThangNhap < 10)
                cout << "0";
            cout << node->data.ThangNhap << "/";

            cout << node->data.NamNhap << endl;            
            cout << setw(20);
            if (node->data.NgayBan < 10)
                cout << "0";
            cout << node->data.NgayBan << "/";

            if (node->data.ThangBan < 10)
                cout << "0";
            cout << node->data.ThangBan << "/";

            cout << node->data.NamBan << endl;
            cout << "-------------------|-------------------|----------------------------------|-------------------|------------------------|-------------------------|---------------|---------------|" << endl;

            found = true;
        }
        node = node->link;
    }
    if (!found) {
        cout << "khong tim thay o to nao con bao hanh " << endl;
    }
}
void SapXepThongTinOToGiaBanTangDan() {
    ifstream inputFile("thongtinoto.txt");

    if (!inputFile) {
        cerr << "Khong mo duoc file hoac file khong ton tai." << endl;
        return;
    }

    NodeThongTinOTo* head = nullptr;
    std::string line;

    while (getline(inputFile, line)) {
        NodeThongTinOTo* node = new NodeThongTinOTo;
        node->data.maOto = line.substr(8);
        getline(inputFile, line);
        node->data.loaiXe = line.substr(9);
        getline(inputFile, line);
        node->data.tenXe = line.substr(8);
        getline(inputFile, line);
        node->data.thuongHieu = line.substr(13);
        getline(inputFile, line);
        node->data.giaNhap = ChuyenChuoiThanhSo(line.substr(10));
        getline(inputFile, line);
        node->data.giaBan = ChuyenChuoiThanhSo(line.substr(9));
        getline(inputFile, line);
        sscanf(line.substr(16).c_str(), "%d/%d/%d", &node->data.NgayNhap, &node->data.ThangNhap, &node->data.NamNhap);
        node->link = nullptr;

        if (head == nullptr || head->data.giaBan > node->data.giaBan) {
            node->link = head;
            head = node;
        }
        else {
            NodeThongTinOTo* current = head;
            while (current->link != nullptr && current->link->data.giaBan < node->data.giaBan) {
                current = current->link;
            }
            node->link = current->link;
            current->link = node;
        }

        getline(inputFile, line); // Bỏ qua dòng "--------------------------------"
    }

    inputFile.close();

    ofstream outputFile("thongtinoto.txt");

    NodeThongTinOTo* current = head;
    while (current != nullptr) {
        outputFile << "Ma oto: " << current->data.maOto << endl;
        outputFile << "Loai xe: " << current->data.loaiXe << endl;
        outputFile << "Ten xe: " << current->data.tenXe << endl;
        outputFile << "Thuong hieu: " << current->data.thuongHieu << endl;
        outputFile << "Gia nhap: " << DinhDangTienTe(current->data.giaNhap) << endl;
        outputFile << "Gia ban: " << DinhDangTienTe(current->data.giaBan) << endl;
        outputFile << "Thoi gian nhap: " << current->data.NgayNhap << "/" << current->data.ThangNhap << "/" << current->data.NamNhap << endl;
        outputFile << "--------------------------------" << endl;
        current = current->link;
    }

    outputFile.close();
}

void SapXepThongTinOToGiaBanGiamDan() {
    ifstream inputFile("thongtinoto.txt");

    if (!inputFile) {
        cerr << "Khong mo duoc file hoac file khong ton tai." << endl;
        return;
    }

    NodeThongTinOTo* head = nullptr;
    std::string line;

    while (getline(inputFile, line)) {
        NodeThongTinOTo* node = new NodeThongTinOTo;
        node->data.maOto = line.substr(8);
        getline(inputFile, line);
        node->data.loaiXe = line.substr(9);
        getline(inputFile, line);
        node->data.tenXe = line.substr(8);
        getline(inputFile, line);
        node->data.thuongHieu = line.substr(13);
        getline(inputFile, line);
        node->data.giaNhap = ChuyenChuoiThanhSo(line.substr(10));
        getline(inputFile, line);
        node->data.giaBan = ChuyenChuoiThanhSo(line.substr(9));
        getline(inputFile, line);
        sscanf(line.substr(16).c_str(), "%d/%d/%d", &node->data.NgayNhap, &node->data.ThangNhap, &node->data.NamNhap);
        node->link = nullptr;

        if (head == nullptr || head->data.giaBan < node->data.giaBan) {
            node->link = head;
            head = node;
        }
        else {
            NodeThongTinOTo* current = head;
            while (current->link != nullptr && current->link->data.giaBan > node->data.giaBan) {
                current = current->link;
            }
            node->link = current->link;
            current->link = node;
        }

        getline(inputFile, line); // Bỏ qua dòng "--------------------------------"
    }

    inputFile.close();

    ofstream outputFile("thongtinoto.txt");

    NodeThongTinOTo* current = head;
    while (current != nullptr) {
        outputFile << "Ma oto: " << current->data.maOto << endl;
        outputFile << "Loai xe: " << current->data.loaiXe << endl;
        outputFile << "Ten xe: " << current->data.tenXe << endl;
        outputFile << "Thuong hieu: " << current->data.thuongHieu << endl;
        outputFile << "Gia nhap: " << DinhDangTienTe(current->data.giaNhap) << endl;
        outputFile << "Gia ban: " << DinhDangTienTe(current->data.giaBan) << endl;
        outputFile << "Thoi gian nhap: " << current->data.NgayNhap << "/" << current->data.ThangNhap << "/" << current->data.NamNhap << endl;
        outputFile << "--------------------------------" << endl;
        current = current->link;
    }

    outputFile.close();
}
void menu() {
    NodeThongTinOTo* ttot;
    NodeLoaiXe* lx;
    NodeThuongHieu* th;

    int chon;
    do
    {
        string MaOToStr, LoaiXeStr, ThuongHieuStr, TenXeStr;
        long long TinhTienLoaiXeThuongHieu = 0, TongTienLoaiXe = 0, TongTienThuongHieu = 0, tongtien = 0;
        long long TongVonLoaiXe = 0, TongVonThuongHieu = 0, TongVonLXvaTH = 0, tongvon = 0;
        long long MinPrice =0, MaxPrice=0;
        long long tempLX = 0, tempTH = 0, tempTongLai = 0, tempTongVon = 0;

        khoitaothongtinoto(ttot);
        khoitaoloaixe(lx);
        khoitaothuonghieu(th);
        cout << endl;
        cout << "||=======================================================================||" << endl;
        cout << "|| 0. de dung chuong trinh                                               ||" << endl;
        cout << "|| 1.Them vao thong tin o to                                             ||" << endl;
        cout << "|| 2.Xuat thong tin o to tu file                                         ||" << endl;
        cout << "|| 3.Xuat tat ca loai xe trong cua hang                                  ||" << endl;
        cout << "|| 4.Xuat tat ca thuong hieu co trong cua hang                           ||" << endl;
        cout << "|| 5.Ban Xe                                                              ||" << endl;
        cout << "|| 6.Xuat tat ca thong tin o to da ban                                   ||" << endl;
        cout << "|| 7.Tinh tong so tien ban duoc cua cua hang                             ||" << endl;
        cout << "|| 8.Tinh tong so tien ban duoc cua loai xe ban muon                     ||" << endl;
        cout << "|| 9.Tinh tong so tien ban duoc cua thuong hieu ban muon                 ||" << endl;
        cout << "|| 10.Tinh tong so tien ban duoc cua loai xe va thuong hieu ban muon     ||" << endl;
        cout << "|| 11.Tinh so lai cua hang nhan duoc theo loai xe ( da tru thue )        ||" << endl;
        cout << "|| 12.Tinh so lai cua hang nhan duoc theo thuong hieu ( da tru thue )    ||" << endl;
        cout << "|| 13.So lai cua hang nhan duoc tong tat ca ( da tru thue VAT )          ||" << endl;
        cout << "|| 14.Tim kiem o to theo ma                                              ||" << endl;
        cout << "|| 15.Tim kiem thong tin o tto theo thuong hieu                          ||" << endl;
        cout << "|| 16.Tim kiem o to theo loai xe                                         ||" << endl;
        cout << "|| 17. Tim kiem thong tin o to theo ten                                  ||" << endl;
        cout << "|| 18.Tim kiem thong tin o to theo loai xe va thuong hieu                ||" << endl;
        cout << "|| 19.Tim kiem o to theo khoang gia                                      ||" << endl;
        cout << "|| 20.Xem so luong thuong hieu co trong cua hang                         ||" << endl;
        cout << "|| 21.Xem so luong loai xe co trong cua hang                             ||" << endl;
        cout << "|| 22.Xem so luong cua o to co loai xe va thuong hieu theo yeu cau       ||" << endl;
        cout << "|| 23.Xuat thong tin o to con bao hanh                                   ||" << endl;
        cout << "|| 24. Sap xep thong tin o to theo gia ban tang dan                      ||" << endl;
        cout << "|| 25.Sap xep thong tin o to theo gia ban giam dan                       ||" << endl;
        cout << "||=======================================================================||" << endl;
        cout << "Nhap vao chuc nang ban muon : ";
        cin >> chon;
        cout << endl;
        switch (chon)
        {
        case 1:
            Nhap(ttot, lx, th);
            break;
        case 2:
            DocThongTinOTo();
            break;
        case 3:
            DocLoaiXe();
            break;
        case 4:
            DocThuongHieu();
            break;
        case 5:
            cout << "\nNhap vao ma o to ban muon Mua : ";
            cin >> MaOToStr;
            XoaThongTinOToTuFile(ttot, MaOToStr);
            break;
        case 6:
            DocThongTinOToDaBan();
            break;
        case 7:
            tongtien = TinhTongGiaBanSauThue();
            //cout << "\nTinh tat ca tien cua so xe da ban duoc trong cua hang truoc thue la : " <<  << endl;
            cout << "Va so tien cua hang thu duoc sau tru thue VAT la : " <<DinhDangTienTe( tongtien);
            break;
        case 8:
            cout << "\nNhap loai xe can tinh tong so tien ban : ";
            cin.ignore(); // Xóa ký tự newline từ bộ đệm nhập chuẩn , dùng khi nhập xen kẽ giữa chữ và số 
            getline(cin, LoaiXeStr);
            ChuanHoa(LoaiXeStr);
            TongTienLoaiXe = TinhTongGiaBanLoaiXe(LoaiXeStr);
            tempLX = TongTienLoaiXe;
            cout << "\nTong so tien ban duoc cua loai xe " << LoaiXeStr << " truoc thue la : " << DinhDangTienTe(tempLX) << endl;
            if (LoaiXeStr == "Xe Tai")
            {
                cout << "So tien ban duoc sau thue 10% cua loai xe " << LoaiXeStr << " la : " <<DinhDangTienTe(TongTienLoaiXe * 90 / 100) << endl;
            }
            else if (LoaiXeStr == "Xe Ban Tai")
            {
                cout << "So tien ban duoc sau thue 9% cua loai xe " << LoaiXeStr << " la : " <<DinhDangTienTe( TongTienLoaiXe * 91 / 100) << endl;
            }
            else if (LoaiXeStr == "Xe May")
            {
                cout << "So tien ban duoc sau thue 8% cua loai xe " << LoaiXeStr << " la : " <<DinhDangTienTe( TongTienLoaiXe * 92 / 100 )<< endl;
            }
            else
            {
                cout << "Khong ap thue đoi voi loai xe " << LoaiXeStr << endl;
            }
            break;
        case 9:
            cout << "\nNhap thuong hieu can tinh tong so tien ban : ";
            cin.ignore(); // Xóa ký tự newline từ bộ đệm nhập chuẩn , dùng khi nhập xen kẽ giữa chữ và số 
            getline(cin, ThuongHieuStr);
            ChuanHoa(ThuongHieuStr);
            TongTienThuongHieu = TinhTongGiaBanThuongHieu(ThuongHieuStr);
            cout << "\nTong so tien ban duoc cua thuong hieu " << ThuongHieuStr << " sau khi tru thue la : " << DinhDangTienTe(TongTienThuongHieu);
            break;
        case 10:
            cout << "\nNhap loai xe can tinh tong so tien ban : ";
            cin.ignore(); // Xóa ký tự newline từ bộ đệm nhập chuẩn , dùng khi nhập xen kẽ giữa chữ và số 
            getline(cin, LoaiXeStr);
            cout << "\nNhap thuong hieu can tinh tong so tien ban : ";
            getline(cin, ThuongHieuStr);
            ChuanHoa(LoaiXeStr);
            ChuanHoa(ThuongHieuStr);
            TinhTienLoaiXeThuongHieu = TinhTongGiaBanLoaiXeVaThuongHieu(LoaiXeStr, ThuongHieuStr);
            tempTH = TinhTienLoaiXeThuongHieu;
            cout << "\nTong so tien ban duoc cua loai xe " << LoaiXeStr << " va thuong hieu " << ThuongHieuStr << " la : " << DinhDangTienTe(tempTH)<< endl;
            if (LoaiXeStr == "Xe Tai")
            {
                cout << "So tien ban duoc sau thue 10% cua loai xe " << LoaiXeStr << " va " << ThuongHieuStr << " la : " <<DinhDangTienTe( TinhTienLoaiXeThuongHieu * 90 / 100) << endl;
            }
            else if (LoaiXeStr == "Xe Ban Tai")
            {
                cout << "So tien ban duoc sau thue 9% cua loai xe " << LoaiXeStr << " va " << ThuongHieuStr << " la : " <<DinhDangTienTe( TinhTienLoaiXeThuongHieu * 91 / 100) << endl;
            }
            else if (LoaiXeStr == "Xe May")
            {
                cout << "So tien ban duoc sau thue 8% cua loai xe " << LoaiXeStr << " va " << ThuongHieuStr << " la : " <<DinhDangTienTe( TinhTienLoaiXeThuongHieu * 92 / 100) << endl;
            }
            else
            {
                cout << "Khong ap thue đoi voi loai xe " << LoaiXeStr << endl;
            }
            break;
        case 11:
            cout << "\nNhap vao loai xe ban can tinh so lai da ban : ";
            cin.ignore();
            getline(cin, LoaiXeStr);
            ChuanHoa(LoaiXeStr);
            TongVonLoaiXe = TinhTongVonDaBanLoaiXe(LoaiXeStr);
            TongTienLoaiXe = TinhTongGiaBanLoaiXe(LoaiXeStr);
            cout << "\nTong so von tu Loai xe " << LoaiXeStr << " da ban duoc la : " <<DinhDangTienTe( TongVonLoaiXe);
            cout << "\nSo lai sau khi tru thue thu duoc tu loai xe " << LoaiXeStr << " da ban duoc la : " <<DinhDangTienTe( TongTienLoaiXe - TongVonLoaiXe);
            break;
        case 12:
            cout << "\nNhap vao thuong hieu ban can tinh so lai da ban : ";
            cin.ignore();
            getline(cin, ThuongHieuStr);
            ChuanHoa(ThuongHieuStr);
            TongVonThuongHieu = TinhTongVonDaBanThuongHieu(ThuongHieuStr);
            TongTienThuongHieu = TinhTongGiaBanThuongHieu(ThuongHieuStr);
            cout << "\nTong so von tu thuong hieu " << ThuongHieuStr << " da ban duoc la : " <<DinhDangTienTe( TongVonThuongHieu);
            cout << "\nSo lai sau khi tru thue thu duoc tu thuong hieu " << ThuongHieuStr << " da ban duoc la : " <<DinhDangTienTe( TongTienThuongHieu - TongVonThuongHieu);
            break;
        case 13:
            tongvon = TinhTongVonDaBan();
            tempTongLai = TinhTongGiaBanSauThue();
            cout << "\nTong tat ca so von tu nhung xe da ban duoc cua cua hang la : " << DinhDangTienTe(tongvon);
            cout << "\nTong so lai sau khi tru thue cua tat ca xe da ban duoc la : " << DinhDangTienTe(tempTongLai);
            break;
        case 14:
        {
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "\nNhap vao ma o to ban muon tim : ";
            cin >> MaOToStr;
            ThongTinOTo* oto = timKiemOto(ttot, MaOToStr);
            if (oto != NULL)
            {
                cout << "Thong tin oto ma ban can tim: " << endl;
                cout << "Ma oto: " << oto->maOto << endl;
                cout << "Loai xe: " <<ChuanHoa( oto->loaiXe) << endl;
                cout << "Ten xe: " <<ChuanHoa( oto->tenXe) << endl;
                cout << "Thuuong hieu: " <<ChuanHoa( oto->thuongHieu) << endl;
                cout << "Gia nhap: " << oto->giaNhap << endl;
                cout << "Gia ban: " << oto->giaBan << endl;
                cout << "Thoi gian nhap: " << oto->NgayNhap << "/" << oto->ThangNhap << "/" << oto->NamNhap << endl;
            }
            else {
                cout << "Khong tim thay o to voi ma " << MaOToStr << endl;
            }
            break;
        }
        case 15:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap thuong hieu ma ban muon tim: ";
            cin.ignore();
            getline(cin, ThuongHieuStr);
            ChuanHoa(ThuongHieuStr);
            timKiemOtoTheoThuongHieu(ttot, ThuongHieuStr);
            break;
        case 16:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap loai xe ban can tim: ";
            cin.ignore();
            getline(cin, LoaiXeStr);
            ChuanHoa(LoaiXeStr);
            timKiemOtoTheoLoaiXe(ttot, LoaiXeStr);
            break;
        case 17:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap ten o to ma ban muon tim: ";
            cin.ignore();
            getline(cin, TenXeStr);
            ChuanHoa(TenXeStr);
            timKiemOtoTheoTenXe(ttot, TenXeStr);
            break;
        case 18:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap loai xe ban can tim: ";
            cin.ignore();
            getline(cin, LoaiXeStr);
            cout << "Nhap thuong hieu ban can tim: ";
            getline(cin, ThuongHieuStr);
            ChuanHoa(LoaiXeStr);
            ChuanHoa(ThuongHieuStr);
            timKiemOtoTheoLoaiXe(ttot,LoaiXeStr);
            timKiemOtoTheoLoaiXeVaThuongHieu(ttot, LoaiXeStr, ThuongHieuStr);
            break;
        case 19:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap khoang gia ban can tim: " << endl;
            cout << "Gia ban tu: ";
            cin >> MinPrice;
            cout << "den ";
            cin >> MaxPrice;
            timKiemOtoTheoKhoangGiaBan(ttot, MinPrice, MaxPrice);
        case 20:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap thuong hieu: ";
            cin.ignore();
            getline(cin, ThuongHieuStr);
            ChuanHoa(ThuongHieuStr);
            demSoLuongOtoTheoThuongHieu(ttot, ThuongHieuStr);
            break;
        case 21:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap loai xe: ";
            cin.ignore();
            getline(cin, LoaiXeStr);
            ChuanHoa(LoaiXeStr);
            demSoLuongOtoTheoLoaiXe(ttot, LoaiXeStr);
            break;
        case 22:
            docDuLieuTuFile(ttot, "thongtinoto.txt");
            cout << "Nhap thuong hieu: ";
            cin.ignore();
            getline(cin, ThuongHieuStr);
            cout << "Nhap loai xe: ";
            getline(cin, LoaiXeStr);
            ChuanHoa(ThuongHieuStr);
            ChuanHoa(LoaiXeStr);
            demSoLuongOtoTheoThuongHieuVaLoaiXe(ttot, ThuongHieuStr, LoaiXeStr);
            break;
        case 23:
            docDuLieuTuFileBanHang(ttot, "banhang.txt");
            XuatThongTinOToConBaoHanh(ttot);
            break;
        case 24:
            SapXepThongTinOToGiaBanTangDan();
            break;
        case 25:
            SapXepThongTinOToGiaBanGiamDan();
            break;
        default:
            break;
        }
        if (chon == 0)
        {
            break;
        }
    } while (true);
}