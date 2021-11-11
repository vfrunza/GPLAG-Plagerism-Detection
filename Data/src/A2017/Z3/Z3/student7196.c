#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int izbaci_cifre(int niz[], int vel1, int niz_cifara[], int vel2) {
	int i, j;
	
	for (i=0; i<vel2; i++) {
		if (niz_cifara[i]<0 || niz_cifara[i]>9) {
			return 0;
		}
	}
	
	for (i=0; i<vel2-1; i++) {
		for (j=i+1; j<vel2; j++) {
			if (niz_cifara[i]==niz_cifara[j]) {
				return 0;
			}
		}
	}
	
	int cifra, novi_broj, najnoviji, negativan;
	
	if (vel2==0) {
		return 1;
	}
	
	for (i=0; i<vel1; i++) {
		negativan=0;
		novi_broj=0;
		najnoviji=0;
		
		if (niz[i]<0) {
			negativan=1;
		}
		
		while (niz[i]!=0) {
			cifra=niz[i]%10;
			cifra=abs(cifra);
			
			for (j=0; j<vel2; j++) {
				if (cifra==niz_cifara[j]) {
					j=vel2+1;  /*Ako ne nadje tu cifru u drugom nizu, j ni do kraja petlje nece postati vel2+1, nego ce doci samo do vel2*/
				}
			}
			if (j<vel2+1) {  /*Ako nismo naisli na tu cifru u drugom nizu, onda je ubacujemo u novi broj*/
				novi_broj=novi_broj*10+cifra;
			}
			niz[i]/=10;
		}
		
		while (novi_broj!=0) {
			najnoviji=najnoviji*10+novi_broj%10;  /*novi_broj je obrnut pocetni broj sa izbacenim odgovarajucim ciframa, pa ga moramo jos jednom obrnuti*/
			novi_broj/=10;
		}
		niz[i]=najnoviji;
		
		if (negativan) {
			niz[i]=-niz[i];
		}
	}
	
	return 1;
}


int main() {
	int niz1[]={-255, 643, -476};
	int niz2[]={5, 4};
	int i;
	
	izbaci_cifre(niz1, 3, niz2, 2);
	for (i=0; i<3; i++) {
		printf("%d ", niz1[i]);
	}
	
	return 0;
}
