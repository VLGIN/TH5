#include <bits/stdc++.h>

using namespace std;
struct MonHoc{
    string Ma_mon;
    int so_tin_chi;
    int tin_chi_lt;
    int tin_chi_bt;
    int tin_chi_th;
    int tin_hoc_phi;
    string loaigio;
    MonHoc(string _Ma_mon, int _so_tin_chi, int _tin_chi_lt, int _tin_chi_bt, int _tin_chi_th, int _tin_hoc_phi, string _loaigio):
        Ma_mon(_Ma_mon), so_tin_chi(_so_tin_chi), tin_chi_lt(_tin_chi_lt), tin_chi_bt(_tin_chi_bt), tin_chi_th(_tin_chi_th), tin_hoc_phi(_tin_hoc_phi), loaigio(_loaigio){}
};

struct SinhVien{
    string name;
    int so_mon_hoc;
    int so_tien_mot_tin_chi;
    int hoc_phi_da_nop;

    SinhVien(string _name, int _so_mon_hoc, int _so_tien_mot_tin, int _hoc_phi_da_nop):
        name(_name), so_mon_hoc(_so_mon_hoc), so_tien_mot_tin_chi(_so_tien_mot_tin), hoc_phi_da_nop(_hoc_phi_da_nop){}
};

int option;
int soluongsinhvien = 0;
int temp_tt = 0;
int soluongmonhoc = 0;
int dem = 0;
int tin_hocphi[2] = {0, 0};
SinhVien ds[2] = {{"", 0, 0, 0},{"", 0, 0, 0}};
MonHoc ds_mon[5] = {{"", 0,0,0,0,0,""},
                    {"", 0,0,0,0,0,""},
                    {"", 0,0,0,0,0,""},
                    {"", 0,0,0,0,0,""},
                    {"", 0,0,0,0,0,""}};

void input_option();

void show_menu();
void input_danhsach_sinhvien();
void show_danhsach_sinhvien();
void input_monhoc();



int main(){
    cout<<" Vu Long Giang - 20183519 - "<<endl;
    cout<<"**    CHUONG TRINH QUAN LY HOC PHI    **"<<endl;
    cout<<"**1. Nhap cac sinh vien va mon hoc**"<<endl;
    cout<<"**2. In ds sinh vien va hoc phi cac mon**"<<endl;
    cout<<"**0. Thoat                           **"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"**       Nhap lua chon cua ban       **"<<endl;
    
    input_option();
}

void input_monhoc(){
    string ma_mon_hoc;
    int so_tin_chi;
    int tin_lt;
    int tin_bt;
    int tin_th;
    int tin_hoc_phi;
    string loaigio;
    cout<<"\t\t Mon hoc thu "<<temp_tt + 1<<endl;
    temp_tt++;
    cout<<"\t\t\t Ma mon hoc: ";
    getline(cin, ma_mon_hoc);
    getline(cin, ma_mon_hoc);
    cout<<"\t\t\t So tin chi: ";
    cin>>so_tin_chi;
    if(so_tin_chi == 12){
        tin_lt = 0;
        tin_bt = 0;
        tin_th = 12;
    }
    else{
        cout<<"\t\t\t Nhap tin chi ly thuyet: ";
        cin>>tin_lt;
        cout<<endl;
        cout<<"\t\t\t Nhap tin chi bai tap: ";
        cin>>tin_bt;
        cout<<endl;
        cout<<"\t\t\t Nhap tin thuc hanh: ";
        cin>>tin_th;
    }
    tin_hoc_phi = tin_bt + tin_lt + tin_th * 2;
    tin_hocphi[soluongsinhvien] += tin_hoc_phi;
    if(tin_th == 3 && tin_bt == 0 && tin_lt == 0) loaigio = "DAMH";
    else if(so_tin_chi == 6) loaigio = "DATN Cu Nhan";
    else if(so_tin_chi == 12) loaigio = "DATN Ky su";
    else {
        if(tin_lt == 0){
            if(tin_bt == 0){
                loaigio = "DA";
            }
            if(tin_bt != 0 && tin_th != 0) loaigio = "BT-TN";
        }
        if(tin_bt == 0){
            loaigio = "LT-TN";
        }
        if(tin_th == 0){
            loaigio = "LT-TH";
        }
    }
    ds_mon[soluongmonhoc] = MonHoc(ma_mon_hoc, so_tin_chi, tin_lt, tin_bt, tin_th, tin_hoc_phi, loaigio);
    soluongmonhoc++;
}

void input_danhsach_sinhvien(){
    string ten;
    int so_mon_hoc;
    int so_tien_mot_tin;
    int hoc_phi_da_nop;

    cout<<"Nhap thong tin cua sinh vien thu "<< soluongsinhvien + 1 << ":"<<endl;
    cout<<"\t\t Ten sinh vien: ";
    getline(cin, ten);
    getline(cin, ten);
    cout<<endl;
    cout<<"\t\t So mon hoc: ";
    cin>>so_mon_hoc;
    cout<<endl;
    cout<<"\t\t So tien mot tin chi: ";
    cin>>so_tien_mot_tin;

    for (int i = 0; i<so_mon_hoc; i++){
        input_monhoc();
    }
    temp_tt = 0;
    cout<<"\t\t Hoc phi da nop: ";
    cin>>hoc_phi_da_nop;
    ds[soluongsinhvien] = SinhVien(ten, so_mon_hoc, so_tien_mot_tin, hoc_phi_da_nop);
    soluongsinhvien++;
    show_menu();
};

void show_danhsach_sinhvien(){
    for (int i = 0; i<soluongsinhvien; i++){
        float tin_hoc_phi;
        
        cout<<"\t\t Ten sinh vien: "<<ds[i].name<<endl;
        cout<<"\t\t So mon hoc: "<<ds[i].so_mon_hoc<<endl;
        cout<<"\t\t To tien 1 TC: "<<ds[i].so_tien_mot_tin_chi<<endl;
        cout<<"\t\t Phai nop: "<<tin_hocphi[i] * ds[i].so_tien_mot_tin_chi <<endl;
        cout<<"\t\t Da nop dot 1: "<<ds[i].hoc_phi_da_nop<<endl;
        cout<<"\t\t Con thieu: "<<tin_hocphi[i] * ds[i].so_tien_mot_tin_chi -ds[i].hoc_phi_da_nop<< endl;
        cout<<"\t\t Tinh trang nop HP: "<<"Thieu"<<endl;
        cout<<"\t\t Chi tiet hoc phi cac mon hoc:"<<endl;
        cout<<"\t\t Ma MH \t\t Loai gio \t\t Khoi luong \t\t hoc phi phai nop"<<endl;
        for (int j = 0; j<ds[i].so_mon_hoc; i++){
            cout<<"\t\t"<<ds_mon[dem].Ma_mon<<"\t\t"<<ds_mon[dem].loaigio<<"\t\t"<<ds_mon[dem].so_tin_chi<<"("<<ds_mon[dem].tin_chi_lt<<"-"<<ds_mon[dem].tin_chi_bt<<"-"<<ds_mon[dem].tin_chi_th<<"-"<<2*ds_mon[dem].so_tin_chi<<")\t\t"<<ds_mon[dem].tin_hoc_phi * ds[i].so_tien_mot_tin_chi<<endl;
        }
        cout<<"-------------------------------------------------------------------------------";
    }
    show_menu();
};

void show_menu(){
    cout<<"**    CHUONG TRINH QUAN LY HOC PHI    **"<<endl;
    cout<<"**1. Nhap cac sinh vien va mon hoc**"<<endl;
    cout<<"**2. In ds sinh vien va hoc phi cac mon**"<<endl;
    cout<<"**0. Thoat                           **"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"**       Nhap lua chon cua ban       **"<<endl;

    input_option();
}

void input_option(){
    cin>>option;
    if(option == 1){
        input_danhsach_sinhvien();
    }
    else if(option == 2){
        show_danhsach_sinhvien();
    }
    else if(option == 0){
        exit(0);
    }
    else{
        cout<<"Nhap sai, moi nhap lai:"<<endl;
        input_option();
    }
}