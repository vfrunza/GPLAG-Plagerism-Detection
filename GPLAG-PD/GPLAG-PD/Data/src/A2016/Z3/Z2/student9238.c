#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int digit_sum(int n) {
	int sum=0;
	n=abs(n);
	while(n) {
		sum+=n%10;
		n/=10;
	}
	return sum;
}
void ubaci(int *arr, int n) {
	int i;
	for(i=n-1; i>=0; i--) {
		arr[2*i]=arr[i];
		arr[2*i+1]=digit_sum(arr[i]);
	}
}
int isfibonacci(int n) {
	int i1=1, i2=1;
	if(n==1) return TRUE;
	while(i2<n) {
		int tmp=i1+i2;
		i1=i2;
		i2=tmp;
		if(n==i2) return TRUE;
	}
	return FALSE;
}
int izbaci(int *arr, int n) {
	int i,j,ndeld=0;
	for(i=0; i<n;) {
		if(isfibonacci(arr[i])) {
			for(j=i+1; j<n-ndeld; j++) {
				arr[j-1]=arr[j];
			}
			for(j=n-ndeld; j<n; j++) {
				arr[j]=0;
			}
			ndeld++;
		}
		else i++;
	}
	return n-ndeld;
}

int main() {
int i, n=10, arr[20]={};
printf("Unesite niz od 10 brojeva: ");
for(i=0; i<n; i++) {
	scanf("%d", arr+i);
}
ubaci(arr,n);
n*=2;
n=izbaci(arr,n);
 printf("Modificirani niz glasi: ");
for(i=0; i<=n; i++) {
	 if(i<n) printf("%d, ", arr[i]);
	 else if(i==n-1 || i==n) printf("%d", arr[i]);
} 
printf(".");
	return 0;
}
