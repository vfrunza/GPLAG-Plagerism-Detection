#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int broj_clanova=0, i, j, clanovi[100];
	for(i=0; i<vel1; i++) {
		int ponavljanje=1;
		for(j=0; j<vel2; j++) {
			if (niz1[i]==niz2[j]) {
				ponavljanje++;
				break;
			}
		}
		for(j=0; j<vel3; j++) {
			if(niz1[i]==niz3[j]) {
				ponavljanje++;
				break;
			}
		}
		if (ponavljanje==2) {
			int ponavljanje_cifre=0;
			for(j=0; j<broj_clanova; j++)
				if (niz1[i]==clanovi[j]) ponavljanje_cifre++;
			if (ponavljanje_cifre==0) {
				clanovi[broj_clanova]=niz1[i];
				broj_clanova++;
			}
		}
	}

	for (i=0; i<vel2; i++) {
		int ponavljanje=1;
		for(j=0; j<vel1; j++) {
			if(niz2[i]==niz1[j]) {
				ponavljanje++;
				break;
			}
		}
		for(j=0; j<vel3; j++) {
			if(niz2[i]==niz3[j]) {
				ponavljanje++;
				break;
			}
		}
		if (ponavljanje==2) {
			int ponavljanje_cifre=0;
			for(j=0; j<broj_clanova; j++)
				if(niz2[i]==clanovi[j]) ponavljanje_cifre++;
			if(ponavljanje_cifre==0) {
				clanovi[broj_clanova]=niz2[i];
				broj_clanova++;
			}
		}
	}
	return broj_clanova;
}

int main()
{
	return 0;
}
