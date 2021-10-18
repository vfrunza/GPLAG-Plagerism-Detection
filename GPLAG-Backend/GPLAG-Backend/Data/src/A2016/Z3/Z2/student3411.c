#include <stdio.h>
int fibonaci(int a){
	int x1=1, x2=1, temp, fib=0;
	while(a>=x2){
		if(a==x1) {fib=1; return 1;} 
		temp=x1;
		x1=x1+x2;
		x2=temp;
	}
	if (fib==0) return 0;
}
void ubaci(int* niz, int vel){
	int i,a,temp=0,suma=0;
	for(i=(vel-1); i>=0; i--){
		niz[2*i]=niz[i];
	}
	for(i=0; i<2*vel; i+=2){
		a=niz[i];
		if(a<0) a=a*(-1);
		suma=0;
		while(a>0){
			temp=a%10;
			a=a/10;
			suma=suma+temp;
		}
		niz[i+1]=suma;
	}
	
}
int izbaci(int *niz, int vel){
	int i,j,fib=1,a;
	for(i=0; i<vel; i++){
		a=niz[i];
		fib=fibonaci(a);
		if(fib==1){
			for(j=i; j<(vel-1); j++){
				niz[j]=niz[j+1];
			}
		vel--;
		i--;
		}
	}
	return vel;
}
int main() {
	int i,x;
	int niz[20] = {0};
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	x=izbaci(niz,20);
	printf("Modificirani niz glasi:");
	for(i=0; i<x; i++){
		if(i==x-1) printf(" %d.", niz[i]);
		else printf(" %d,", niz[i]);
	}
	return 0;
}
