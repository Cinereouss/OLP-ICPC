#include <bits/stdc++.h>

using namespace std;

int n, tg1, tg2, tg3, a[3], arr[25001][2];

void check(int a, int b, int c){
	if( a<b+c && b<a+c && c<a+b ){
        if( a*a==b*b+c*c || b*b==a*a+c*c || c*c== a*a+b*b)
            tg2++;
        else if(a==b==c)
            tg1++;
        else if(a==b || a==c || b==c)
            tg1++;
        else if(a*a > b*b+c*c || b*b > a*a+c*c || c*c > a*a+b*b)    
            tg3++;
        else
            tg1++;
    }
}

void chinhhop(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(arr[j][1]==0)
        {
            a[i]=arr[j][0];
            if(i==2){
            	check(a[0], a[1], a[2]);
            }
            else
            {
                arr[j][1]=1;
                chinhhop(i+1);
                arr[j][1]=0;
            }
        }
    }
}

main(){
	cin >> n;
	arr[0];
	
	for(int i = 1; i <= n; i ++){
		cin	>> arr[i][0];
		arr[i][1];
	}
	chinhhop(0);
	cout << tg1/6 << " " << tg2/6 << " " << tg3/6 << endl;
}
