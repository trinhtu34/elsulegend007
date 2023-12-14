#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;


struct ThongTinOTo
{
    string maOto;
    string loaiXe;
    string tenXe;
    string thuongHieu;
    int NgayNhap, ThangNhap, NamNhap;
    int NgayBan, ThangBan, NamBan;
    long long giaNhap;
    long long giaBan;
};
struct NodeThongTinOTo
{
    ThongTinOTo data;
    NodeThongTinOTo* link;
};

struct LoaiXe
{
    string tenloaixe;
};
struct NodeLoaiXe
{
    LoaiXe data;
    NodeLoaiXe* link;
};

struct ThuongHieu
{
    string ten;
};
struct NodeThuongHieu
{
    ThuongHieu data;
    NodeThuongHieu* link;
};

void khoitaothongtinoto(NodeThongTinOTo*& list);
void khoitaoloaixe(NodeLoaiXe*& list);
void khoitaothuonghieu(NodeThuongHieu*& list);

NodeThongTinOTo* TaoNodeOTo(ThongTinOTo x);
NodeLoaiXe* TaoNodeLoaiXe(LoaiXe x);
NodeThuongHieu* TaoNodeThuongHieu(ThuongHieu x);
NodeThongTinOTo* ThemDau(NodeThongTinOTo*& list, ThongTinOTo x);
NodeLoaiXe* ThemDau1(NodeLoaiXe*& list, LoaiXe x);
NodeThuongHieu* ThemDau2(NodeThuongHieu*& list, ThuongHieu x);

void GhiThongTinOTo(NodeThongTinOTo* car);
string ChuanHoa(string &str);
string DinhDangTienTe(long long so);
long long ChuyenChuoiThanhSo(const std::string& str);
void GhiLoaiXe(NodeLoaiXe* loaixe);
void GhiThuongHieu(NodeThuongHieu* thuonghieu);

void DocThongTinOTo();
void DocLoaiXe();
void DocThuongHieu();

bool laNamNhuan(int nYear);
bool laNgayHopLe(int nDay, int nMonth, int nYear);
int tinhSoNgayTrongThang(int nMonth, int nYear);

bool KiemTraTrungMaOToTrongFile(string maoto);
bool KiemTraTrungMaOTo(NodeThongTinOTo* list, const string& maoto);
bool KiemTraLoaiXeTrongFile(string loaixe);
bool KiemTraThuongHieuTrongFile(string thuonghieu);
bool KiemTraTrungTenLoaiXe(NodeLoaiXe* list, const string& tenloaixecankiemtra);
bool KiemTraTrungTenThuongHieu(NodeThuongHieu* list, const string& tenThuongHieuCanKiemTra);

void Nhap(NodeThongTinOTo*& list, NodeLoaiXe*& list1, NodeThuongHieu*& list2);

void XoaThongTinOToTuFile(NodeThongTinOTo*& list, const string& maOtoCanXoa);
void XoaLoaiXeTuFile(const string& loaiXeCanXoa);
void XoaThuongHieuTuFile(const string& thuongHieuCanXoa);


long long TinhTongGiaBanSauThue();
long long TinhTongGiaBanLoaiXe(const std::string& TenLoaiXe);
long long TinhTongGiaBanThuongHieu(const std::string& TenThuongHieu);
long long TinhTongGiaBanLoaiXeVaThuongHieu(const std::string& TenLoaiXe, const std::string& TenThuongHieu);

long long TinhTongVonDaBan();
long long TinhTongVonDaBanLoaiXe(const std::string& TenLoaiXe);
long long TinhTongVonDaBanThuongHieu(const std::string& TenThuongHieu);
long long TinhTongVonDaBanCuaLoaiXeVaThuongHieu(const std::string& TenLoaiXe, const std::string& TenThuongHieu);

void docDuLieuTuFile(NodeThongTinOTo*& head, string tenFile);
void NhapNamBan(NodeThongTinOTo*& list);

void SapXepThongTinOTo();
void demSoLuongOtoTheoThuongHieuVaLoaiXe(NodeThongTinOTo* head, string thuongHieu, string loaiXe);
void demSoLuongOtoTheoLoaiXe(NodeThongTinOTo* head, string loaixe);
void demSoLuongOtoTheoThuongHieu(NodeThongTinOTo* head, string thuongHieu);
void timKiemOtoTheoLoaiXeVaThuongHieu(NodeThongTinOTo* head, string loaiXe, string thuongHieu);
void timKiemOtoTheoKhoangGiaBan(NodeThongTinOTo* head, int giaBanThapNhat, int giaBanCaoNhat);
void timKiemOtoTheoTenXe(NodeThongTinOTo* head, string tenXe);
void timKiemOtoTheoLoaiXe(NodeThongTinOTo* head, string loaiXe);
void timKiemOtoTheoThuongHieu(NodeThongTinOTo* head, string thuongHieu);
ThongTinOTo* timKiemOto(NodeThongTinOTo* head, string maOto);
bool conBaoHanh(ThongTinOTo oto);
void XuatThongTinOToConBaoHanh(NodeThongTinOTo* head);

void SapXepThongTinOToGiaBanGiamDan();
void SapXepThongTinOToGiaBanTangDan();

void docDuLieuTuFileBanHang(NodeThongTinOTo*& head, string tenFile);

void menu();