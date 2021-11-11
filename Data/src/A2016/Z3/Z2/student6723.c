#include <stdio.h>
#include <math.h>

int suma_cifara (int n) {
	int suma=0,cifra=0;
	while(n!=0) {
		cifra=n%10;
		suma+=cifra;
		n/=10;
	}
	return suma;
}

void ubaci (int* niz, int br_elemenata) {
	int i;
	for(i=br_elemenata-1;i>=0;i--) {
		niz[i*2]=niz[i];
		if(i==0) break;
	}
	
	for(i=1;i<br_elemenata*2;i+=2) {
		niz[i]=suma_cifara(fabs(niz[i-1]));
	}
}

int fibonacijev_broj (int n) {
	int i,niz[100]={1},a;
	if(n==1) return n;
	for(i=2;i<100;i++) {
		niz[i]=niz[i-2]+niz[i-1];
		if(n==niz[i]) {
			a=niz[i];
			return a;
		}
	}
	if(i==100) return -100;
}

int izbaci (int* niz, int br_elemenata) {
	int i,j;
	for(i=0;i<br_elemenata;i++){
		if(niz[i]==fibonacijev_broj(niz[i])) {
			for(j=i;j<br_elemenata-1;j++) {
				niz[j]=niz[j+1];
			}br_elemenata--;
			i--;
		}
	} return br_elemenata;
}
	
int main() {
	int niz[20],i,br_elemenata=10,vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<br_elemenata;i++) {
	scanf("%d",&niz[i]);
}
ubaci(niz,br_elemenata);
vel=izbaci(niz,br_elemenata*2);
printf("Modificirani niz glasi: ");
for(i=0;i<vel;i++) {
	if(i==vel-1) printf("%d.",niz[i]);
	else printf("%d, ",niz[i]);
}
return 0;
}
