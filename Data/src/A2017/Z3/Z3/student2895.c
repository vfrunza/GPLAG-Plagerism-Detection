/*#include <stdio.h>
#include <math.h>
int izbaci_cifre(int *niz1, int duz1, int *niz2, int duz2)
{
	int i,j,temp,cifra;
	int novibroj=0,br=0;

	for(i=0; i<duz2; i++) {
		for(j=0; j<duz2; j++) {
			if(niz2[i]<0 || niz2[i]>9 || (niz2[i]==niz2[j] && i!=j)) return 0;
		}
	}
	for(i=0; i<duz1; i++) {
		novibroj=0;
		br=0;
		temp=fabs(niz1[i]);
		while(temp!=0) {
			temp=temp/10;
			br++;//Brojimo koliko broj ima cifara
		}
		br--;
		temp=fabs(niz1[i]);
		while(br>=0) {
			cifra=temp/pow(10,br);//Uzimamo cifru iz clanova prvog niza i gledamo da li  se ona nalazi u drugom nizu
			for(j=0; j<duz2; j++) {
				if(cifra==niz2[j]) break;
			}
			if(j==duz2) {
				novibroj=novibroj*10+cifra;
			}
			temp=temp-cifra*pow(10,br);//izbacujemo cifru iz broja
			br--;
		}
		if(niz1[i]<0) niz1[i]=novibroj*(-1); //Ako je pocetni broj bio negativan vracamo mu -
		else
			niz1[i]=novibroj;
	}
	return 1;
}*/
#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *niz1, int vel1, int *niz2, int vel2)
{

	int i,j, tmp, brojac_cifara = 0, cifra, novi_broj = 0;
	for(i = 0; i < vel2; i++) {
		if(niz2[i] < 0 || niz2[i] > 9) return 0;
		for(j = i + 1; j < vel2; j++) {
			if (niz2[i] == niz2[j]) return 0;
		}
	}

	for(i = 0; i < vel1; i++) {
		novi_broj = 0;
		brojac_cifara = 0;
		tmp = fabs(niz1[i]);
		while(tmp != 0) {
			brojac_cifara++;
			tmp /= 10;
		}
		brojac_cifara--;
		tmp = fabs(niz1[i]);
		while( brojac_cifara >= 0) {
			cifra = tmp / pow(10, brojac_cifara);
			for(j = 0; j < vel2; j++) {
				if( cifra == niz2[j]) break;
			}
			if(j == vel2) {
				novi_broj = novi_broj * 10 + cifra;
			}
			tmp = tmp - cifra * pow(10, brojac_cifara);
			brojac_cifara--;
		}
		if(niz1[i] < 0) niz1[i] = novi_broj * (-1);
		else niz1[i] = novi_broj;

	}
	return 1;
}

int main()
{
	int brojevi[] = {123, 456};
	int cifre1[] = {1, 2, 3, 1};
	int cifre2[] = {1, 2, 10, 4};
	int cifre3[] = {1, 2, 3, -4};
	int i, rez;
	rez = izbaci_cifre(brojevi, 2, cifre1, 4);
	printf("%d\n", rez);
	rez = izbaci_cifre(brojevi, 2, cifre2, 4);
	printf("%d\n", rez);
	rez = izbaci_cifre(brojevi, 2, cifre3, 4);
	printf("%d\n", rez);
	cifre3[3] = 4;
	rez = izbaci_cifre(brojevi, 2, cifre3, 4);
	printf("%d\n", rez);
	printf("%d %d", brojevi[0], brojevi[1]);

	return 0;
}
