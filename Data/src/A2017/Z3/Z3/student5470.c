#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre(int niz[], int vel, int arr[], int siz)
{
	int i, j, cifra, temp, eksponent=0, br_izbacenih=0, flag_neg=0;
	/* Provjera za niz cifri <0 ili >9 i ponavlja li se*/
	for(i=0; i<siz; i++) {
		if(arr[i]<0 || arr[i]>9) return 0;
		/* provjera ponavljanja */
		for(j=i+1; j<siz; j++) {
			if(arr[i]==arr[j]) return 0;
		}
	}
	/* Izbacivanje cifri */
	for(i=0; i<vel; i++) {
		temp=abs(niz[i]);
		eksponent=0;
		flag_neg=0;
		if(niz[i]<0) flag_neg=1;
		niz[i]=0; /* Default */
		do {
			br_izbacenih=0;
			cifra=temp%10;
			temp/=10;
			for(j=0; j<siz; j++) {
				if(cifra==arr[j]) {
					br_izbacenih++;
				}
			}
			if(br_izbacenih==0) {
				niz[i]=niz[i]+cifra*pow(10, eksponent);
			} else eksponent--;
			eksponent++;
		} while(temp>0);
		if(flag_neg==1) niz[i]=(-1)*niz[i];
	}
	return 1;
}

int main()
{
	return 0;
}
