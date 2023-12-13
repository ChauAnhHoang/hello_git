#include<iostream>
#include<iomanip>
using namespace std;
class nguoi{
	protected:
		string hoten;
		int namsinh;
	public:	
	void nhap(){
		cin.ignore();		
		cout<<"Nhap ho ten: ";	getline(cin,hoten);
		cout<<"\nNhap nam sinh: ";	cin>>namsinh;
	}
	void xuat(){
		cout<<left<<setw(15)<<hoten<<setw(10)<<namsinh;
	}
};
class monhoc{
	protected:
		string tenmon;
		float CC,KT,DT;
	public:
	void nhap(){
		cin.ignore();		
		cout<<"\nNhap ten mon hoc : ";	getline(cin,tenmon);
		cout<<"\nNhap diem chuyen can: ";cin>>CC;	
		cout<<"\nNhap diem kiem tra: ";		cin>>KT;
		cout<<"\nNhap diem thi: ";	cin>>DT;
		}
	void xuat(){
		cout<<left<<setw(15)<<tenmon<<setw(10)<<CC<<setw(10)<<KT<<setw(10)<<DT;		
	}

};
class sinhvien: public nguoi,public monhoc{
	private:
		string msv;
		float dtb ;
	public:
		void nhap(){
			nguoi::nhap();
			monhoc::nhap();
		cin.ignore();		
		cout<<"\nNhap ma sinh vien: ";	getline(cin,msv);
		cout<<"\nNhap diem trung binh: ";	cin>>dtb;
	}
	void xuat(){
		nguoi::xuat();
		monhoc::xuat();
		cout<<left<<setw(10)<<msv<<setw(5)<<dtb<<endl;
		
	}
	
	friend void sapxep(sinhvien sv[],int n);
	friend void camthi(sinhvien sv[],int n);
	friend void tim(sinhvien sv[],int n);
	friend void maxtd(sinhvien sv[],int n);
};

void sapxep(sinhvien sv[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(sv[i].dtb < sv[j].dtb){
				sinhvien tg=sv[i];
					sv[i]=sv[j];
					sv[j]=tg;
			}
		}
	}
	cout<<"\nSinh vien theo thu tu giam dan: "<<endl;

}
void tim(sinhvien sv[],int n){
	string timkiem;
	cin.ignore();
	cout<<"\nNhap ho ten hoac ma sinh vien muon tim: "; getline(cin,timkiem);
	bool timthay=false;
	for(int i=0;i<n;i++){
		if(sv[i].hoten == timkiem || sv[i].msv ==timkiem ){
			timthay =true;
			sv[i].xuat();
			break;
		}
	}
	if(!timthay){		
		cout<<"\nKhong co sinh vien nay trong danh sach!"<<endl;
	}
}
 void camthi(sinhvien sv[],int n){
 		for(int i=0;i<n;i++){		
		if(sv[i].CC<5 || sv[i].KT==0){		
		sv[i].xuat();
	}
}
}
  void maxtd(sinhvien sv[],int n){
		sinhvien  tongdmax=sv[0];		 	  
		for(int i=0;i<n;i++){
			float tongdiem= sv[i].CC +sv[i].KT +sv[i].DT;
			if(tongdiem > (tongdmax.CC + tongdmax.KT +tongdmax.DT)){
				tongdmax= sv[i];
			}
		}
	tongdmax.xuat();	
	}

void tieude(){
	cout<<left<<setw(15)<<"Ho ten"<<setw(10)<<"Nam sinh"<<setw(15)<<"Mon"<<setw(10)<<"CC"<<setw(10)<<"KT"<<setw(10)<<"DT"<<setw(10)<<"Msv"<<setw(5)<<"Dtb"<<endl;	
}
int main(){
	int n;
	cout<<"\nNhap so luong sinh vien: ";	cin>>n;
	sinhvien *sv= new sinhvien[n];
	cout<<"\nNhap thong tin sinh vien: ";
	for(int i=0;i<n;i++){
		cout<<"\nSinh vien thu "<<i+1<<endl;
		sv[i].nhap();
	}
	sapxep(sv,n);
	tieude();
	for(int i=0;i<n;i++){		
		sv[i].xuat();
}
	cout<<"\nSinh vien bi cam thi: "<<endl;
	tieude();
	camthi(sv,n);
	tim(sv,n);	
	cout<<"\nSinh vien co tong diem lon nhat: "<<endl;
	tieude();
	maxtd(sv,n);
}
