#include<iostream>
using namespace std;
int dt = 0;
class Hinh {
protected:
    int chieurong, chieudai;
public:
    Hinh(int a = 0, int b = 0)
    {
        chieurong = a;
        chieudai = b;
    }
    virtual int dientich()//them virtual vao de thanh ham ao 
    {
        dt = (chieurong * chieudai);
        cout << "Dien tich cua lop cha:" << "???" << endl;
        return 0;    }
};
class HinhChuNhat : public Hinh {
public:
    HinhChuNhat(int a = 0, int b = 0) :Hinh(a, b) { }
    int dientich()
    {
        dt = (chieurong * chieudai);
        cout << "Dien tich cua lop HinhChuNhat la: " << dt << endl;
        return 0;
    }
};
class TamGiac : public Hinh {
public:
    TamGiac(int a = 0, int b = 0) :Hinh(a, b) { }
    int dientich()
    {
        dt = (chieurong * chieudai / 2);
        cout << "Dien tich cua lop TamGiac la: " << dt << endl;
        return 0;
    }
};
int main()
{
    Hinh* hinh;
    HinhChuNhat hcn(13, 6);
    TamGiac tg(8, 9);
    // luu giu dia chi cua HinhChuNhat
    hinh = &hcn;
    // goi dien tich cua hinh chu nhat.
    hinh->dientich();
    // luu giu dia chi cua TamGiac
    hinh = &tg;
    // goi dien tich cua tam giac.
    hinh->dientich();
    return 0;}

