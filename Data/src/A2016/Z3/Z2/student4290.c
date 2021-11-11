#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Perfect(int n){
	int a;
	for(a=0;a<=abs(n);a++){
		if(abs(n)==a*a)return 1;
	}
	return 0;
}
int Fibonacci(long n){
	if((Perfect(5*n*n+4)==1)||(Perfect(5*n*n-4)==1))return 1;
	else return 0;
}
int Sumacifara(int n){
	int suma=0;
	if(n<10&&n<-10) return n;
	while(n>0){
		suma+=n%10;
		n=n/10;
	}
	return suma;
}

void ubaci(int*niz,int vel){
		int size,i;
		size=vel*2;
		for(i=size-2;i>=0;i-=2){
			niz[i]=niz[vel-1];
			vel--;
		}
		for(i=1;i<size;i+=2){
			niz[i]=Sumacifara(niz[i-1]);
		}
	
	}
	

int izbaci(int* niz,int vel){
	int*p;
	int*q;
	for(p=niz;p<niz+vel;p++){
		if(Fibonacci(*p)==1){
			for(q=p;q<niz+vel-1;q++){
				*q=*(q+1);
			}
			vel--;
			p--;
		}
	}
	return vel;
}
int main() {
	int niz[100];
	int i,n,vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	vel=i;
	ubaci(niz,vel);
	n=izbaci(niz,10);
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++){
		if(i<n-1){
		printf("%d,",niz[i]);
		}
		else
		printf("%d.",niz[n-1]);
	}
	return 0;
}
