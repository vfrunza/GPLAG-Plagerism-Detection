#include <stdio.h>
#include <math.h>

int suma(float broj) /* Funkcija koja će sumirati cifre u broju */
{
	int r=1,s=0;
	broj = fabs(broj * 10);  /* Mnozenje broja sa 10 da dobijemo cijeli broj */
	int br = (int)(broj);
	while (br != 0) {
		r=br%10;
		s=s+r;				/* U while petlji uzimamo cifru po cifru */
		br=br/10;
	}
	return s;
}

void zaokruzi1(float nizR[], int vel) /* Funkcija zaokruzi1 koja zaokruzuje broj na jednu decimalu */
{

	int i,min,p,q,temp,broj;
	for(i=0; i<vel; i++) {
		nizR[i] = (nizR[i]*10);
		nizR[i] = (round)(nizR[i]);
		nizR[i] = nizR[i] / 10;
	}
}

void preslozi(float niz[], int vel, int k) /* Funkcija preslozi */
{
	int i,p=0,q,c;
	float temp;
	zaokruzi1(niz,vel);
	int sp,sq;

	while(p<vel - 1) { /* Posmatramo nas niz od prvog clana i poredimo ga sa ostalim u nizu*/
		sp = suma(niz[p]);
		q= p + 1;
		if(sp >= k) /* Ako je suma broja na kojem je p veca ili jednaka k, onda program prelazi na sljedeci broj u nizu */
			goto kraj;

		while(q<vel) { /* Druga while petlja koja ide od sljedeceg clana p do kraja i provjerava uslove */
			sq = suma(niz[q]);
			if(sq >= k) {  /* Ako je suma cifara na kojem se nalazi q >= k, onda: */
				temp = niz[q];
				for(c=q; c>p; c--) { /* Vrsi se zamjena */
					niz[c] = niz[c-1];
				}
				niz[p] = temp;
				goto kraj;
			} else q++;
		}
kraj:
		p++;
	}
}

int main() /* int main sluzi za provjeru samo */
{
	int i;
	float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
	preslozi(niz, 5, 14);
	printf("Niz glasi: ");
	for (i=0; i<5; i++)
		printf("%g ", niz[i]);


	return 0;
}