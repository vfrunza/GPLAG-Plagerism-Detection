#include <stdio.h>
int suma_cifara(int n){
	int suma=0;
	if(n<0) n=-n;
	while(n!=0){
		suma+=n%10;
		n/=10;
	}
	return suma;
}
int ubaci(int *niz,int vel){
	int i,j,a;
	for(i=0; i<vel; i++){
		for(j=vel-1;j>=i; j--)
			niz[j+1]=niz[j];
		if(j>0){
			a=suma_cifara(niz[j-1]);
		    niz[j]=a;
		}
		i++;
		vel++;
		if(i==vel-1) niz[i]=suma_cifara(niz[vel-2]);
	}
}

int Fib(int n){
	int b=0,a=1,c=1;
	if(n==0) return 0;
	if(n==1) return 1;
	while(b<n){
		c=a+b;
		a=b;
		b=c;
	}
	if(b==n) return 1;
	return 0;
}
int izbaci(int *niz,int vel){
	int i,j;
	for(i=0; i<vel; i++){
		if(Fib(niz[i])==1){
			for(j=i; j<vel-1; j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel; 
}
int main() {
	int i,a,niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	a=izbaci(niz,20);
	printf("Modificirani niz glasi:");
	for(i=0; i<a; i++){
		if(i<a-1) printf(" %d,",niz[i]);
		else printf(" %d.",niz[i]);
	}
	return 0;
}
