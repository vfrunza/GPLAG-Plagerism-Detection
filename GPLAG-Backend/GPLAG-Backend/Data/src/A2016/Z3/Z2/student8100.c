#include <stdio.h>
#include <stdlib.h>

void ubaci(int* niz, int vel){
	int i, j=0, a;
	int niza[100], nizb[100];
	for(i=0; i<vel; i++)
		niza[i]=niz[i];
	for(i=0; i<vel; i++){
		a = abs(niz[i]);
		nizb[i]=0;
		while(a!=0){
			nizb[i]+=a%10;
			a/=10;
		}
	}
	for(i=0; i<2*vel; i++){
		if(i%2==0) niz[i]=niza[i/2];
		else{
			niz[i]=nizb[j];
			j++;
		}
	}
}

int fibonaci(int broj){
	int a=1, b=1, c;
	if(broj==1) return 1;
	while(1){
		c=a+b;
		if(c==broj) return 1;
		if(c>broj) return 0;
		a=b;
		b=c;
	}
}

int izbaci(int* niz, int vel){
	int i, j;
	for(i=0; i<vel; i++){
		if(fibonaci(niz[i])){
			for(j=i; j<vel-1; j++)
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}


int main() {
	int niz[20], i, velicina;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d", &niz[i]);
	ubaci(niz, 10);
	velicina = izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<velicina; i++){
		if(i==velicina-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}
	return 0;
}
