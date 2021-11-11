#include <stdio.h>
void ubaci(int niz [], int vel){
	int i,broj,noviBroj=0,j;
	for(i=0; i<vel; i++){
		broj=niz[i];
		if(broj<0)
		broj*=-1;
		noviBroj=0;
		while(broj>0){
			noviBroj+=broj%10;
			broj/=10;
		}
		i++;
		for(j=vel; j>=i;j--){
			niz[j]=niz[j-1];
		}
		niz[i]=noviBroj;
		vel++;
	}
}

int izbaci(int niz [], int vel){
	int i,j,z,l,fibonaci,r,k;
	for(z=0; z<vel; z++){
		fibonaci=0;
		i=1;
		j=1;
		k=i+j;
		for(l=1; l<niz[z]; l++){
			k=i+j;
			if(k==niz[z]){
				fibonaci=1;
				break;
			}
			i=j;
			j=k;
		}
		if(fibonaci==1 || niz[z]==1){
			for(r=z;r<vel-1; r++)
				niz[r]=niz[r+1];
			z--;
			vel--;
		}
	}
	return vel;
}

int main() {
	printf("Unesite niz od 10 brojeva: ");
	int i=0, niz[20];
	for(i; i<10; i++)
	scanf("%d ", &niz[i]);
	printf("Modificirani niz glasi: ");
	ubaci(niz,10);
	int velicina=izbaci(niz,20);
	int z;
	for(z=0;z<velicina; z++)
	if(z<velicina-1)
	printf("%d, ", niz[z]);
	else printf("%d.",niz[z]);
	return 0;
}
