#include<iostream>
using namespace std;
class a
{
	public:
	virtual void xuat()
	{
		cout<<"\ntoi la a: ";
		}
	};
class b: public a{
public:
	void xuat()
	{
	
		cout<<"\ntoi la b";
		}
};
class c:public b{
	public:
	void xuat()
	{
		cout<<"\ntoi la c";
		}
	};
int main()
{
/*	c h; // h là d?i tu?ng ki?u C
 h.xuat() ; // G?i t?i phuong th?c h.C::xuat()
 h.b::xuat() ; // G?i t?i phuong th?c h.B::xuat() 
 h.a::xuat(); // G?i t?i phuong th?c h.A::xuat()*/

a *nguyet, *huy, *loi;
a A;
b B;
c C;
nguyet=&A;
huy=&B;
loi=&C;
nguyet->xuat() ;
huy->xuat() ;
loi->xuat();
}

