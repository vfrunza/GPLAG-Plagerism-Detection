#include <stdio.h>
#include <math.h>

void ubaci (int niz[], int vel) {
	int i,x,y,suma;
	x=2*vel-2;
	for (i=vel-1; i>=0; i--) {
		niz[x]=niz[i];
		x=x-2;
	}
	for(i=0; i<2*vel; i+=2) {
		suma=0;
		y=fabs(niz[i]);
		do {
			suma=suma+y%10;
			y=y/10;
		} while (y!=0);
		niz[i+1]=suma;
		
	}

}
int izbaci (int niz[], int vel) {
	int i,j,niz1[100],k,l,m;
	niz1[0]=1;
	niz1[1]=1;
	for (i=2; i<100; i++) {
		niz1[i]=niz1[i-1]+niz1[i-2];
	}
	for (l=0; l<vel; l++) {
		if (niz[l]==1) {
			for (m=l; m<vel-1; m++) {
				niz[m]=niz[m+1];
			}
			vel--;
			l--;
		
		}
		
		else {
			for (j=2; j<100; j++) {
				if (niz[l]==niz1[j]) {
					for (k=l; k<vel-1; k++) {
						niz[k]=niz[k+1];
					}
					vel--;
					l--;
					break;
				}
			}
	
		}
	}
	return vel;
}
int main() {
	int niz[100],i,z;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf ("%d", &niz[i]);
	}
	ubaci (niz,10);
	z=izbaci (niz,20);
	printf ("Modificirani niz glasi: ");
	for (i=0; i<z; i++) {
		if (i<z-1){
		printf ("%d, ", niz[i]);
		}
		else {
			printf ("%d.", niz[i]);
		}
	}
	return 0;
}
