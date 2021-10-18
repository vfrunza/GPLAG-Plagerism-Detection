#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int saberi (int n){
	int a=0,m=n;
	int suma=0;
	while (m!=0) {
		a=m%10;
		m=m/10;
		suma+=a;
	}
	return abs(suma);
}


void ubaci (int niz[], int vel){
	int i,b,j;
	int novi[1000]={0};
	for(i=0; i<vel; i++) {
		b=saberi(niz[i]);
		novi[i*2]=niz[i];
		novi[i*2+1]=b;
	}
	for(j=0; j<vel*2; j++) niz[j]=novi[j];
}

int izbaci (int niz[], int vel){
	int i, j, k,fibonaci[46]={1,1};
	int iff=0;
	for(i=2; i<46; i++)
	fibonaci[i]=fibonaci[i-1]+fibonaci[i-2];
	for(i=0; i<vel; i++){
		if(iff!=0){iff=0; i--;}
		for(j=1; j<46; j++){
			if(fibonaci[j]==niz[i]){
				for(k=i; k<vel-1; k++)
				niz[k]=niz[k+1];
				vel--;
				if(i==0) iff++;
				else i--;
			}
		}
	}
	for(i=0;i<46;i++)
	if(niz[0]== fibonaci[i]){vel=0;break;}
	return vel;
}
int main(){
	int z,i,l,niz[20];
	printf("Unesite niz od 10 brojeva:");
	for(i=0; i<10; i++) {
	scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	l=izbaci(niz,20);
	printf(" Modificirani niz glasi:");
	for(z=0; z<l;z++){
		if(l-1==z)printf(" %d.",niz[z]);
		else printf(" %d,", niz[z]);
	}
	return 0;
	}




