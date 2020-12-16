#include <iostream>
#include<cmath>
#define PI 3.1415926535898
using namespace std;

int T, N, a, b, c, d;

void bacnhat(float a,float b)
{
	float rt = -b/a;
  	cout << rt;
}

void bachai(float a,float b,float c)
{
	float d,x1,x2;
	d=b * b-4 *a *c;
   if(d==0)
   {
     cout << -b/(2*a);
   } 
   else
   {
     x1=(-b-sqrt(d))/(2*a);
     x2=(-b+sqrt(d))/(2*a);
	cout << min(x1, x2);
   }
}

void bacba(float a, float b, float c, float d)
{
  float dt,k,x1,x2,x3,x;

  dt=pow(b,2)-3*a*c;
  k=(9*a*b*c-2*pow(b,3)-27*pow(a,2)*d)/(2*sqrt(pow(fabs(dt),3)));
  if(dt>0)
  {
    if(fabs(k)<=1)
    {
      x1=(2*sqrt(dt)*cos(acos(k)/3)-b)/(3*a);
      x2=(2*sqrt(dt)*cos(acos(k)/3-(2*PI/3))-b)/(3*a);
		cout << min(min(x1, x2), x3);
    }
    if(fabs(k)>1)
    {
      x=((sqrt(dt)*fabs(k))/(3*a*k))*(pow((fabs(k)+sqrt(pow(k,2)-1)),1.0/3)+pow((fabs(k)-sqrt(pow(k,2)-1)),1.0/3))-(b/(3*a));
      cout << x;
    }
   }
  else if(dt==0)
  {
    x=(-b-pow(-(pow(b,3)-27*a*a*d),1.0/3))/(3*a);
    cout << x;
  }
  else
  {
    cout << x;
  }
}
int main()
{
  	cin >> T;
  	while(T--){
  		cin >> N;
		if(N==1)
		{
  			cin >> a >> b;
			bacnhat(a,b);
		}
		if(N==2){
  			cin >> a >> b >> c;
			bachai(a,b,c);
		}
		if(N==3){
  			cin >> a >> b >> c >> d;
			bacba(a,b, c, d);
		}
	}
}
