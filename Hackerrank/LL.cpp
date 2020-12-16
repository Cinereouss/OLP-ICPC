#include<stdio.h>
#include<math.h>
void nhap(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void sap_xep(int a[], int n){
	int i, j, t;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(a[i]>a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
void ktra(int a[], int n){
	int i, demcn=0, demct=0, demv=0, demcnt=0;
	for(i=0; i<n-floor(n/2); i++){
		if(a[i]+a[i+1]<a[i+2]) break;
		else{
			if(a[i]==a[i+1] && a[i]*a[i]+a[i+1]*a[i+1]>a[i+2]*a[i+2]|| a[i]==a[i+2]&& a[i]*a[i]+a[i+2]*a[i+2]>a[i+1]*a[i+1]|| a[i+1]==a[i+2]&& a[i+1]*a[i+1]+a[i+2]*a[i+2]>a[i]*a[i]){
				demcn++;
				do{
					demcn++;
				}while(a[i]!=a[i+1] || a[i]!=a[i+2] || a[i+1]!=a[i+2]);
			}
			if(a[i]*a[i]+a[i+1]*a[i+1]==a[i+2]*a[i+2]||a[i]*a[i]+a[i+2]*a[i+2]==a[i+1]*a[i+1]|| a[i+1]*a[i+1]+a[i+2]*a[i+2]==a[i]*a[i]){
				demv++;
			}
	
			if(a[i]==a[i+1] && a[i]*a[i]+a[i+1]*a[i+1]<a[i+2]*a[i+2]|| a[i]==a[i+2]&& a[i]*a[i]+a[i+2]*a[i+2]<a[i+1]*a[i+1]|| a[i+1]==a[i+2]&& a[i+1]*a[i+1]+a[i+2]*a[i+2]<a[i]*a[i]){
				demct++;
			}
			
		}
	}
	printf("%d %d %d", demcn, demv, demct);
}
int main(){
	int a[25000], n;
	scanf("%d", &n);
	nhap(a, n);
	sap_xep(a, n);
	ktra(a, n);
	return 0;
	
}

