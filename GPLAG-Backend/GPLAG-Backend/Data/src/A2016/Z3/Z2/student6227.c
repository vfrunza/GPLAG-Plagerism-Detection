#include <stdio.h>
#include <math.h>

int zbir (int n){
	int a=1, zbir=0;
	if (n<0) n=-n;
	while (n!=0){
		a= n % 10;
		zbir=zbir+a;
		n=n/10;
	} 
	return zbir;
}

void ubaci (int *niz, int vel){
	int i,niz1[20];
	for (i=0;i<20;i++){
		niz1[i]=0;
	}
	for (i=0;i<vel;i++){
		if (i==0){ 
			niz1[i]=niz[i];
			niz1[i+1]=zbir(niz[i]);
			continue;
		}
		niz1[2*i]=niz[i];
		niz1[2*i+1]=zbir(niz[i]);
	}
	for (i=0;i<vel*2;i++){
		niz[i]=niz1[i];
	}
}

int fib (int broj){
	double x1, x2;
	long korijenx1, korijenx2;
	x1=5*pow(broj, 2)+4;
	x2=5*pow(broj, 2)-4;
	korijenx1=(long)sqrt(x1);
	korijenx2=(long)sqrt(x2);
	return ((korijenx1*korijenx1==x1) || (korijenx2*korijenx2==x2));
}

int izbaci (int niz[],int ve){
	int i, j;
	for (i=0;i<ve;i++){
		if (niz[i]<=0){
			continue;
		}
		if (fib(niz[i])==1){
		for (j=i;j<ve-1;j++){
			niz[j]=niz[j+1];
		}
		i--;
		ve--;
		}
	}
	return ve;
}

int main() {
	
	int  niz[20],i,a;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++){
		scanf ("%d", &niz[i]);
	}
	ubaci(niz, 10);
	a=izbaci(niz, 20);
	printf ("Modificirani niz glasi:");
	for (i=0;i<a;i++){
		if (i==a-1) {printf (" %d.", niz[i]); continue;}
		printf (" %d,", niz[i]);
	}
	return 0;
}
