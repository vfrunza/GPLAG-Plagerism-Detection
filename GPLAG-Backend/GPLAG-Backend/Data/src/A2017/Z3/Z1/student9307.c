#include <stdio.h>

int dva_od_tri(int niz1[],int clanovi_1,int niz2[],int clanovi_2, int niz3[],int clanovi_3)
{
	int i,j,rez=0,poz_brojac12[10000]= {0},poz_brojac23[10000]= {0},poz_brojac13[10000]= {0},neg_brojac12[10000]= {0},neg_brojac23[10000]= {0},neg_brojac13[10000]= {0};

	if ((clanovi_1==0 && clanovi_2 ==0) || (clanovi_1==0 && clanovi_3 ==0) || (clanovi_3==0 && clanovi_2 ==0))
		return 0;
	for (i=0; i<clanovi_1; i++) {
		for (j=0; j<clanovi_2; j++) {
			if (niz1[i]==niz2[j] && (niz1[i]>=0 || niz2[j]>=0))
				poz_brojac12[niz1[i]]++;
			else if (niz1[i]==niz2[j] && niz1[i]<0 && niz2[j]<0)
				neg_brojac12[-niz1[i]]++;
		}
	}
	for (i=0; i<clanovi_2; i++) {
		for (j=0; j<clanovi_3; j++) {
			if (niz2[i]==niz3[j] && (niz2[i]>=0 || niz3[j]>=0))
				poz_brojac23[niz2[i]]++;
			else if (niz2[i]==niz3[j] && niz2[i]<0 && niz3[i]<0)
				neg_brojac23[-niz2[i]]++;
		}
	}
	for (i=0; i<clanovi_1; i++) {
		for (j=0; j<clanovi_3; j++) {
			if (niz1[i]==niz3[j] && (niz1[i]>=0 || niz3[j]>=0))
				poz_brojac13[niz1[i]]++;
			else if (niz1[i]==niz3[j] && niz1[i]<0 && niz3[i]<0)
				neg_brojac13[-niz1[i]]++;
		}
	}
	for (i=0; i<10000; i++) {
		if ((poz_brojac12[i]>0 && poz_brojac23[i]==0 && poz_brojac13[i]==0) || (poz_brojac12[i]==0 && poz_brojac13[i]>0 && poz_brojac23[i]==0) || (poz_brojac13[i]==0 && poz_brojac23[i]>0 && poz_brojac12[i]==0))
			rez++;
		if ((neg_brojac12[i]>0 && neg_brojac23[i]==0 && neg_brojac13[i]==0) || (neg_brojac12[i]==0 && neg_brojac13[i]>0 && neg_brojac23[i]==0) || (neg_brojac13[i]==0 && neg_brojac23[i]>0 && neg_brojac12[i]==0))
			rez++;
	}
	return rez;
}

int main ()
{
	int niz1[100],niz2[100],niz3[100],clanovi_1,clanovi_2,clanovi_3,i;

	printf ("Unesite broj clanova prvog niza: ");
	scanf ("%d", &clanovi_1);
	printf ("Unesite clanove prvog niza: ");
	for (i=0; i<clanovi_1; i++) {
		scanf ("%d", &niz1[i]);
	}

	printf ("Unesite broj clanova drugog niza: ");
	scanf ("%d", &clanovi_2);
	printf ("Unesite clanove drugog niza: ");
	for (i=0; i<clanovi_2; i++) {
		scanf ("%d", &niz2[i]);
	}

	printf ("Unesite broj clanova treceg niza: ");
	scanf ("%d", &clanovi_3);
	printf ("Unesite clanove treceg niza: ");
	for (i=0; i<clanovi_3; i++) {
		scanf ("%d", &niz3[i]);
	}
	printf ("%d", dva_od_tri(niz1,clanovi_1,niz2,clanovi_2,niz3,clanovi_3));
	return 0;
}
