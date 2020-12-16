#include<iostream>
using namespace std;
class TH;
class Node{
int data;
Node *link;
public:
Node(int dt,Node *lk)
{
data=dt;
link=lk;
}
int get_dt(){return data;}
Node* get_lk(){return link;}
friend class TH;
};

class TH{
protected:
Node *head;
int spt;
public:
TH(){
head=NULL;
spt=0;
}
~TH();
TH(TH &th);
friend istream &operator>>(istream &is,TH &t);
friend ostream &operator<<(ostream &os,TH &t);
friend TH operator+(TH a,TH b);
friend TH operator*(TH a,TH b);
void push_front(int a); 
void pop_front();
int begin() const ;
bool empty();
bool find(int a);
int operator[](int i);
};

TH::~TH(){
Node *p=head;
while(p!=NULL)
{
head=head->link;
delete p;
p=head;
}
}
//co van de
TH::TH(TH &th)
{
Node *p=th.head;
while(p!=NULL)
{
int t=p->data;
push_front(t);
p=p->link;
}
}

void TH::push_front(int a){
if(find(a))return;
Node *p=new Node(a,NULL);
p->link=head;
head=p;
spt++;
}
void TH::pop_front(){
if(empty()) return;
Node *p=head;
head=head->link;
delete p;
spt--;
}

int TH::begin() const 
{
return head->data;
}
bool TH::empty()
{
return spt==0;
}
bool TH::find(int a){
Node *p=head;
while(p!=NULL)
if(p->data==a) return true;
else p=p->link;
return false;
}
istream &operator>>(istream &is,TH &t){
int d;
do{
cout<<"\nNhap du lieu: ";
is>>d;
if(d!=-1)
t.push_front(d);
}while(d!=-1);
return is;
}
ostream &operator<<(ostream &os,TH &t)
{
Node *p=t.head;
os<<"{ ";
while(p!=NULL)
{
os<<p->get_dt()<<", ";
p=p->get_lk();
}
os<<"}";
return os;
}
TH operator+(TH a,TH b)
{
TH c; 
if(a.empty()) 
c = b;
else 
if(b.empty()) 
c = a;
else
{
c=a;
while(!b.empty())
{
int d=b.begin();
c.push_front(d);
b.pop_front();
}
}
return c; 
}
TH operator*(TH a,TH b)
{
if(a.empty()) return a;
else if(b.empty()) return b;
else
{
TH c;
while(!a.empty())
{
int d=a.begin();
if(b.find(d))
c.push_front(d);
a.pop_front();
}
return c;
}
}
int TH::operator[](int i)
{
if(!(i<=0||i>spt||empty()))
{
int d=1;
Node *p=head;
while(d<i)
{
p=p->link;
d++;
}
return p->data;
}
}
int main()
{
TH a,b,c;
int i,t;
cout<<"Nhap hai tap hop ban dau: ";
cout<<"\nNhap tap hop thu nhat:\n";
cin>>a;
cout<<"\nNhap tap hop thu hai:\n";
cin>>b;

cout<<"\nTap hop thu nhat: "<<a;
cout<<"\nTap hop thu hai: "<<b;
c=a;
cout<<"\nTap hop thu ba: "<<c;
cout<<"\nNhap i: ";
cin>>i;
cout<<"\nPhan tu thu i cua tap hop = : "<<a[i];
c=a+b;
cout<<"\nHop hai tap hop: "<<c;
//c=a*b;
//cout<<"\nGiao hai tap hop: "<<c;
return 0;
}
