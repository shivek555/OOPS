#include<iostream.h>
#include<conio.h>
class book
{
char name[30];
long int tel;
public:
void read()
{
cout<<"name:" ;
cin>>name;
cout<<name;
cout<<"tel:";
cin>>tel;
}
void disp()
{
cout<<"PURCHASER DETAILS : ";
cout<<"Name : "<<name;
cout<<"Tel No.:"<<tel;
}
};
class shop:public book
{
char isbn[20],bname[30];
long int price;
public:
void read()
{
cout<<"Book-Name : ";
cin>>bname;
cout<<"ISBN NO. : ";
cin>>isbn;
cout<<"Price of Book : Rs.";
cin>>price;
}
void disp()
{
cout<<"BOOK DETAILS :";
cout<<"Book-Name :" <<bname;
cout<<"ISBN No. :"<<isbn;
cout<<"Price : Rs."<<price;
}
};
void main()
{
clrscr();
book *ptr;
book p;
ptr=&p;
cout<<"Enter details of purchaser : ";
(*ptr).read();
shop c;
ptr=&c;
cout<<"Enter the details of the book sold : ";
((shop *)ptr)->read();
(*ptr).disp();
((shop *)ptr)->disp();
getch();
}
