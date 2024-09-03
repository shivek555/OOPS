#include <iostream.h>
#include<stdio.h>
#include <conio.h>
/*class rectangle{
 private:
 int len,br;
 public: void getdata()
 {
  printf("enter length and breadth:\n");
  scanf("%d",&len);
  scanf("%d",&br);
 };
 public: void display()
 {
  printf("length=%d\n",len);
  printf("breadth=%d\n",br);
 };
 public: void setdata(int i,int j){
  len=i;
  br=j;
 }
 public: void areaperi()
  {
   int a,p;
   a=len*br;
   p=2*(len+br);
   printf("area =%d\n",a);
   printf("area =%d\n",p);
 }
};

void main()
{
 rectangle r1,r2,r3;

 r1.getdata();
 r1.display();
 r1.areaperi();
 r2.getdata();
 r2.display();
 r2.areaperi();
 r3.setdata(10,20);
 r3.display();
 r3.areaperi();
}
class integers
{
 private:
 int i;
 public: void data(){
  cout<<endl<<"enter any integer:";
  cin>>i;
 };
 public:void set(int j)
 {
  i=j;
 };
 public: void display()
 {
  cout<<endl<<"value of i="<<i<<endl;
 };
 public:integers(){};
 public:integers(int j){i=j;};
};

void main()
{
 integers i1(100),i2,i3;
 i1.display() ;
 i3.data();
 i3.display();
 i2.set(200);
 i2.display();
}
class example
{
 private:
 int data;
 public:
 example(){cout<<endl<<"inside";
 };
 public: ~example(){cout<<endl<<"destructor"<<endl;};
};
void main()
{
 example e;
}*/
class complex
{
 private:
 float real,imag;
 public : complex()
 {
 };
 public: complex(float r,float i){
 real = r;
 imag = i;
 };
 public:void displaydata()
 {
  cout<<"z=x+iy="<<real<<"+i"<<imag<<endl;
 };
 public:void addc(complex x,complex y){
  real=x.real+y.real;
  imag=x.imag+y.imag;
 };
 public:complex addcomplex(complex y)
 {
  complex t;
  t.real=real+y.real;
  t.imag=imag+y.imag;
  return(t);
 };

};
void main(){
 clrscr();
 complex c1(1.1,2.2),c2(3.5,4.4),c3;
 c3.addc(c1,c2);
 c3.displaydata();
 c1.displaydata();
 getch();
}