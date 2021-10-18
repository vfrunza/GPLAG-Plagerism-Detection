#include <stdio.h>
#include <math.h>

int suma_cifara(int broj){
	int suma=0;
	while((broj=fabs(broj))!=0){
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}

void ubaci(int niz[],int broj_el){
	int i,j=0;
	int *pok,*kraj;
	kraj=niz+2*broj_el-2;
	pok=niz+broj_el-1;
	while(j++<broj_el-1){
		*kraj=*(pok);
		kraj-=2;
		pok--;
	}
	for(i=1;i<2*broj_el;i+=2) niz[i]=suma_cifara(niz[i-1]);
}

int jeli_fibonacijev_broj(int broj){
	int a=1,b=1,c;
	do{
		c=a+b;
		a=b;
		b=c;
		if(c==broj || broj==1) return 1;
	}while(c<=broj);
	return 0;
}

int izbaci(int niz[],int broj_el){
	int i,j;
	for(i=0;i<broj_el;i++)
		if(jeli_fibonacijev_broj(niz[i])==1){
			for(j=i;j<broj_el-1;j++)
			    niz[j]=niz[j+1];	
		    broj_el--;
		    i--;
		}
		return broj_el;
}

int main() {
	int niz[20],i,broj_el;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) scanf("%d", &niz[i]);
	ubaci(niz,10);
	broj_el=izbaci(niz,20);
	printf("Modificirani niz glasi:");
	for(i=0;i<broj_el;i++) i!=broj_el-1 ? printf(" %d,", niz[i]) : printf(" %d.", niz[i]);
	
	return 0;
}
