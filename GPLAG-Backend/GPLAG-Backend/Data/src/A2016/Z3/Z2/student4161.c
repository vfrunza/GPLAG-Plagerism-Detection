#include <stdio.h>
int suma_cifara(int n){
	int suma=0;
	if(n<0) n=n*(-1);
	while(n>0){
		suma=suma+n%10;
		n=n/10;
	}
	return suma;
}
int da_li_je_fib(int n){
	
	int prvi=1,drugi=1,suma=0;
	if(n==1) return 1;
	for(;;){
		suma=prvi+drugi;
		prvi=drugi;
		drugi=suma;
		if(suma==n) return 1;
		else if(suma>n) return 0;
	}
}
void ubaci(int *niz,int n){
	int i=0;
	while(i!=n){
		niz[2*n-2-2*i]=niz[n-i-1];
		niz[2*n-1-2*i]=suma_cifara(niz[n-i-1]);
		
		i++;
	}
}
int izbaci(int *niz,int n){
	int i,j;
	int x=n;
	for(i=0;i<x;i++){
		if(da_li_je_fib(niz[i])==1){
			j=i;
			while(j!=x-1){
				niz[j]=niz[j+1];
				j++;
			}
			x--;
			i--;
		}
	}
	return x ;
}
int main() {
	int i;
	int a[20];
	int vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	{
		scanf("%d",&a[i]);
	}
	ubaci(a,10);
	vel=izbaci(a,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i==vel-1) printf("%d.", a[i]);
		else printf("%d, ", a[i]);
		
	}
	return 0;
}
