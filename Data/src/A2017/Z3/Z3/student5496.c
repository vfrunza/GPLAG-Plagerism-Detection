#include <stdio.h>
#include <stdlib.h>
#define max 100000
int postoji_cifra(int broj, int cifra)
{
	int cifra1;
	int postoji=0;
	if(broj<0) broj=-broj;
	while(broj!=0) {
		cifra1=broj%10;
		if(cifra==cifra1) postoji=1;
		broj/=10;
	}
	return postoji;
}
int izbaci(int broj, int cifra)
{
	int cifra1;
	int novi_broj1=0, novi_broj2=0;
	int negativan=0;
	if (broj<0) {
		broj=-broj;
		negativan=1;
	}
	while(broj!=0) {
		cifra1=broj%10;
		if(cifra1==cifra) {
			broj/=10;
			continue;
		} else {
			novi_broj1=novi_broj1*10+cifra1;
			broj/=10;
		}
	}
	while(novi_broj1!=0) {
		novi_broj2=novi_broj2*10+novi_broj1%10;
		novi_broj1/=10;
	}
	if(negativan) return (-1)*novi_broj2;
	return novi_broj2;
}
int izbaci_cifre(int* niz1, int duzina1, int* niz2, int duzina2)
{
	int i, br_istih_c=0, el,j, broj,novi_br=0,novi_br2=0;

	/*provjera elemenata niza cifara*/
	for(i=0; i<duzina2; i++) {
		if(niz2[i]<0 || niz2[i]>9) return 0;
	}
	/*provjera da li ima istih cifara*/
	for(i=0; i<duzina2; i++) {
		el=niz2[i];
		for(j=i+1; j<duzina2; j++) {
			if(niz2[j]==el) br_istih_c++;
		}
		if(br_istih_c>0) return 0;
	}
	/*izbacivanje cifara iz niza*/
	for(i=0; i<duzina1; i++) {
		for(j=0; j<duzina2; j++) {
			if(postoji_cifra(niz1[i],niz2[j])==1)
				niz1[i]=izbaci(niz1[i],niz2[j]);

		}
	}
	return 1;
}
int main()
{
	int brojevi[max], cifre[max], br1=0,br2=0,i;
	printf("Unesite niz brojeva: ");
	for(i=0; i<max; i++) {
		scanf("%d", &brojevi[i]);
		if(brojevi[i]==-1) break;
		br1++;
	}
	printf("Unesite niz cifara: ");
	for(i=0; i<100; i++) {
		scanf("%d", &cifre[i]);
		br2++;
		if(cifre[i]==-1) break;
	}
	izbaci_cifre(brojevi,br1,cifre,br2);
	for(i=0; i<br1; i++)
		printf("%d ", brojevi[i]);
	return 0;
}
