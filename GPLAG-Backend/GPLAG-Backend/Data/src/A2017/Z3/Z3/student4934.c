#include <stdio.h>
#include <math.h>

int izbaci_cifre(int* niz_brojeva, int broj_brojeva, int* niz_cifri, int broj_cifri)
{
	int i, j, ostatak, desetice=1, konacan_broj, preskoci=0, temp;

	for (i=0; i<broj_brojeva; i++) {
		desetice=1;
		konacan_broj=0;
        temp=niz_brojeva[i];
		while (niz_brojeva[i]!=0) {
			ostatak=niz_brojeva[i]%10;
			ostatak=fabs(ostatak);
			for (j=0; j<broj_cifri; j++) {
				preskoci=0;
				if (ostatak==niz_cifri[j]) {
					niz_brojeva[i]=niz_brojeva[i]/10;
					preskoci=1;
					break;
				}
			}
			if (j==broj_cifri) {
				(konacan_broj)=(konacan_broj) + desetice*ostatak;
				desetice=desetice*10;
			}
			if (preskoci==1) {
				continue;
			}
			niz_brojeva[i]=niz_brojeva[i]/10;
		} 
		if (temp<0) { niz_brojeva[i]=konacan_broj*-1; }
		else niz_brojeva[i]=konacan_broj;
	}

	for (j=0; j<broj_cifri; j++) {
		if (niz_cifri[j]<0 || niz_cifri[j]>9) {
			return 0;
		}
	}

	for(i=0; i<broj_cifri; i++) {
		for(j=i+1; j<broj_cifri; j++) {
			if(niz_cifri[i]==niz_cifri[j]) return 0;
		}
	}
	return 1;
	}


int main () {
	int i, j, niz_brojeva[100], niz_cifri[10], broj_brojeva, broj_cifri, a;
	printf ("Unesite niz cijelih brojeva: \n");
	for (i=0; i<100; i++) {
		scanf ("%d", &niz_brojeva[i]);
	}
	broj_brojeva=i;
	
	printf ("Unesite niz cifri koje zelite izbaciti iz prethodnog niza: \n");
	for (j=0; j<10; j++) {
		scanf ("%d", &niz_cifri[j]);
	}
	
	broj_cifri=j;
	a=izbaci_cifre(niz_brojeva, broj_brojeva, niz_cifri, broj_cifri);
	printf ("Rezultat je: %d ", a);
	return 0;
}
