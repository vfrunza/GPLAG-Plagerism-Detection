#include <stdio.h>

void rastavi_broj_na_cifre(int br, int a[], int vel_a)
{
	int  cifra;
	int *pok = a;

	while(br != 0) {
		cifra = br % 10;
		while(pok != a + vel_a) {
			if(cifra == *pok) {
				pok = a + vel_a - 2;
				vel_a--;
			}
			pok++;
		}
		br = br/10;
	}
}

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{
	int *p =  niz2;
	int *q = niz2;
	int cifra;

	/*Provjera  da li postoje iste cifre u nizu*/
	while(q < niz2 + vel2) {
		p = q;
		while(p < niz2 + vel2) {
			if(*q == *(p+1))
				return 0;
			p++;
		}
		q++;
	}

	/*Provjera da li su cifre u validnom intervalu*/
	p = niz2;
	while(p < niz2 + vel2) {
		if(*p < 0 || *p > 9)
			return 0;
			p++;
	}

	for(i = 0; i < vel1; i++) {
		rastavi_broj_na_cifre(niz1[i], niz2, vel2);
	}
	return 1;
}
int main()
{
	int a1[100], velicina1;
	int a2[100], velicina2;
	int i;

	scanf("%d", &velicina1);
	for(i = 0; i < velicina1; i++) {
		scanf("%d", &a1[i]);
	}
	scanf("%d", &velicina2);
	for(i = 0; i < velicina2; i++) {
		scanf("%d", &a2[i]);
	}
	izbaci_cifre(a1,velicina1,a2,velicina2);
	return 0;
}
