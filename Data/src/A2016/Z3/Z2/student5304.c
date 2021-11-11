#include <stdio.h>

void ubaci(int b[], int k) {
	int i,j,a,temp;
	int zbir=0;
	for(i=1;i<k*2;i+=2){
		for(j=2*k-1;j>i;j--){
			b[j]=b[j-1];
		}
		temp=b[i-1];
		if(temp<0) temp=-temp;
		while(temp!=0){
			a=temp%10;
			temp/=10;
			zbir+=a;
			
		}
		b[i]=zbir;
		zbir=0;
	}
}
int izbaci(int b[],int l) {
	int i,j,p;
	int fib[47];
	fib[0]=1;
	fib[1]=1;
	for(i=2;i<47;i++) {
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(j=0;j<l;j++) {
		for(i=0;i<47;i++) {
			if(b[j]==fib[i]) {
				for(p=j;p<l-1;p++) {
					b[p]=b[p+1];
				}
				j--;
				l--;
				break;
			}
		}
	}
	return l;
}
int main() {
	int b[20];
	int i,x;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d",&b[i]);
	}
ubaci(b,10);
x=izbaci(b,20);
printf("Modificirani niz glasi: ");
for(i=0; i<x; i++) {
	if(i==x-1) {
		printf("%d.",b[i]);
	} else 
printf("%d, ", b[i]);
}
	return 0;
}
