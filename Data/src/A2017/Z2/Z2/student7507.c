#include <stdio.h>
 
int main()
{
	int n, j, a=0, niz[100]={0}, novi_niz[1000]={0}, i, k, cifra, temp, brojac;
	/*j-duzina novog niza cifara, a-duzina novog niza; i, k petlja, brojac-broji ponavljanja*/

	/*unos velicine*/
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	} while (n>100 || n<0 );

	/*unos clanova*/
	do {
		printf("Unesite clanove niza: ");
		for(i=0; i<n; i++)
			scanf("%d,", &niz[i]);
	} while(niz[i]<0);

	/*razdvajanje cifara i upis u novi niz naopako*/
	j=0;
	for(i=n-1; i>=0; i--) {
		/*if(niz[i]==0) novi_niz[i]=niz[i];*/
		do {
			cifra=niz[i]%10;
			niz[i]/=10;
			novi_niz[j]=cifra;
			j++;
		} while (niz[i]>0);

	}
	/*novi niz je sada niz pojedinacnih cifara prvobitnog niza, okrenut ispravno*/
	for(i=0; i<j; i++) {
		temp=novi_niz[0];
		for(k=0; k<j-1-i; k++) {
			novi_niz[k]=novi_niz[k+1];
		}
		novi_niz[j-1-i]=temp;
	}


	/*novi niz je prosiren za (cifra, broj ponavljanja)*/
	for(i=0; i<j; i++) {
		brojac=1;
		temp=novi_niz[i];  
		for(k=i+1; k<j; k++) {
			if(novi_niz[k]==temp) brojac++;
			else break;
		}
		novi_niz[j+a]=temp;
		novi_niz[j+a+1]=brojac;
		a+=2;
		i+=brojac;
		i--;
	}

	/*Novi niz sada na početku ima ono što nas interesuje*/
	for(i=0; i<j; i++) {
		temp=novi_niz[0];
		for(k=0; k<j+a-1; k++) {
			novi_niz[k]=novi_niz[k+1];
		}
		novi_niz[j+a-1]=temp;
	}

	/*poslije ovog koraka novi niz ima a clanova koji nas interesuju, ostalo su nule*/
	for(i=a+1; i<j+a; i++) {
		novi_niz[i]=0;
	}

	printf("Finalni niz glasi: \n");
	for(i=0; i<a; i++) {
		if(i==a-1) printf("%d",novi_niz[i] );
		else printf ("%d ",novi_niz[i] );
	}

	return 0;
}
