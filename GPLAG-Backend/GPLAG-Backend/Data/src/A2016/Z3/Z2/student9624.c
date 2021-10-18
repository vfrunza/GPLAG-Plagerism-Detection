#include <stdio.h>
int suma_cifara(int x) {
	int suma=0;
		if(x<0) x=(-1)*x;
	while(x>0) {
		suma=suma+(x%10);
		x=x/10;
	}
 return suma;
}


void ubaci (int *p, int vel) {
	int i,niz1[100];
	int *niz;
	niz=p;
	
	i=0;
	while(niz<p+vel) {
		niz1[i]= *niz;
		niz1[i+1]=suma_cifara(*niz);
		niz++;
		i+=2;
	}
	niz=p;
	for(i=0 ; i<2*vel ; i++) {
		*niz=niz1[i];
		niz++;
	}
	
}
int fib(int broj) {
	int a=1, b=1, x=2;
	if(broj==1) return 1;
	if(broj < 1) return 0;
	while(x<broj) {
		x=a+b;
		a=b;
		b=x;
	}
	
	if(x==broj) return 1;
	else return 0;
	
}
int izbaci(int *p,int vel) {
	int i, niz1[100], j=0;
	int *niz;
	niz=p;
	while(niz<p+vel) {
		if(fib(*niz)==0) {
			niz1[j]=*niz;
			j++;
		}
		niz++;
	}
	niz=p;
	for(i=0 ; i<j ; i++) {
		*niz=niz1[i];
		niz++;
	}
	return j;
}

int main() {
	int i=0, niz[25], vel=10;
		printf("Unesite niz od 10 brojeva: ");
	for(i=0 ; i<10 ; i++) {
		scanf("%d", &niz[i]);
	}

	ubaci(niz, vel);
	vel=izbaci(niz, 2*vel);
	printf("Modificirani niz glasi: " );
	for(i=0 ; i<vel ; i++) {
		if(i==vel-1) printf("%d.", niz[i]);	
		else printf("%d, ", niz[i]);
	}
	
	return 0;
}
