#include <stdio.h>
int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3)
{
	int konbr=1,i,j,noviniz1[100],noviniz2[100],noviniz3[100],razl=0,br1=1,br2=1,br3=1,kbr=0;
	noviniz1[0]=niz1[0];
	//rjesavamo se brojeva koji se pojavljuju vise puta u nizu
	for(i=1; i<vel1; i++) {
		razl=0;
		for(j=0; j<br1; j++) {
			if(noviniz1[j]==niz1[i])
				razl++;
		}
		if(razl==0) {
			noviniz1[br1]=niz1[i];
			br1++;
		}
	}
	noviniz2[0]=niz2[0];
	for(i=1; i<vel2; i++) {
		razl=0;
		for(j=0; j<br2; j++) {
			if(noviniz2[j]==niz2[i])
				razl++;

		}
		if(razl==0) {
			noviniz2[br2]=niz2[i];
			br2++;
		}
	}
	noviniz3[0]=niz3[0];
	for(i=1; i<vel3; i++) {
		razl=0;
		for(j=0; j<br3; j++) {
			if(noviniz3[j]==niz3[i])
				razl++;
		}
		if(razl==0) {
			noviniz3[br3]=niz3[i];
			br3++;
		}
	}
	//pomocu vrijednosti brojaca kbr provjeravamo da li se posmatrani element nalazi iskljucivo u dva od tri niza
	for(i=0; i<br1; i++) {
		kbr=0;
		for(j=0; j<br2; j++) {
			if(noviniz1[i]==noviniz2[j]) {
				kbr++;
				break;
			}
		}
		for(j=0; j<br3; j++) {
			if(noviniz1[i]==noviniz3[j]) {
				kbr++;
				break;
			}
		}

		if(kbr==1) konbr++;
	}
	for(i=0; i<br2; i++) {
		kbr=0;
		for(j=0; j<br3; j++) {
			if(noviniz2[i]==noviniz3[j]) {
				kbr++;
				break;
			}
		}
		for(j=0; j<br1; j++) {
			if(noviniz2[i]==noviniz1[j]) {
				kbr++;
				break;
			}
		}

		if(kbr==1) konbr++;
	}
	for(i=0; i<br3; i++) {
		kbr=0;
		for(j=0; j<br1; j++) {
			if(noviniz3[i]==noviniz1[j]) {
				kbr++;
				break;
			}
		}
		for(j=0; j<br2; j++) {
			if(noviniz3[i]==noviniz2[j]) {
				kbr++;
				break;
			}
		}

		if(kbr==1) konbr++;
	}
	return konbr/2;

}

int main()
{

	return 0;
}

//NADIJINA VERZIJA 
#include <stdio.h>
int dva_od_tri(int*niz1, int vel1, int*niz2, int vel2, int*niz3, int vel3)
{
	int j, *z, br1=0, br2=0;
	int*p = niz1;
	int*q = niz2;
	int*r = niz3;
	while(p < niz1 + vel1) {
		br1 = 0;
		//koristeci pomocni pokazivac, osiguravamo da se cifre koje se ponavljaju preskacu
		for(z = niz1; z < p; z++)
			if(*z == *p)
				break;
		if(z < p) {
			p++;
			continue;
		}
		for(j = 0; j < vel2; j++) {
			if(*p == *(q+j)) {
				br1++;
				break;
			}
		}
		for(j = 0; j < vel3; j++) {
			if(*p == *(r+j)) {
				br1++;
				break;
			}
		}
		if(br1 == 1)
			br2++;
		p++;

	}
	//posto smo vrsili operacije nad p, moramo ga vratiti na pocetnu vrijednost
	p = niz1;
	while(q < niz2 + vel2) {
		for(z = niz2; z < q; z++)
			if(*z == *q)
				break;
		if(z < q) {
			q++;
			continue;
		}
		br1 = 0;
		for(j = 0; j < vel1; j++) {
			if(*q == *(p+j)) {
				br1++;
				break;
			}
		}
		for(j = 0; j < vel3; j++) {
			if(*q == *(r+j)) {
				br1++;
				break;
			}
		}
		if(br1 == 1)
			br2++;
		q++;

	}
	q = niz2;
	while(r < niz3 + vel3) {
		for(z = niz3; z < r; z++)
			if(*z == *r)
				break;
		if(z < r) {
			r++;
			continue;
		}

		br1 = 0;
		for(j = 0; j < vel1; j++) {
			if(*r == *(p+j)) {
				br1++;
				break;
			}
		}
		for(j = 0; j < vel2; j++) {
			if(*r == *(q+j)) {
				br1++;
				break;
			}
		}
		if(br1 == 1)
			br2++;
		r++;

	}
	//vracamo vrijednost br2/2 iz razloga sto ce se u svakoj od prethodnih for petlji svaki od nizova porediti jedan sa drugim dva puta
	return br2/2;
}
int main()
{
	int niz1[]= {1,2,3,5}, niz2[]= {1,2,4,6,7}, niz3[]= {1,3,4,8,9,10};
	printf("%d", dva_od_tri(niz1,4,niz2,5,niz3,6));
	return 0;
}
