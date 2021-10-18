#include <stdio.h>
#include <math.h>

int izbaci_cifre (int *pok1, int n1, int *pok2, int n2)
{
	int *vel1=pok1+n1, *vel2=pok2+n2;
	int broj, eksp, duzina, cifra, a;
	int brojac, predznak;
	int *pocetak=pok2, *i;

	/* provjera ispravnosti niza cifara, ako nije ispravan vraca se 0 i odmah prekida program */
	for (; pok2<vel2; pok2++) {
		if (*pok2<0 || *pok2>9)
			return 0;
			
		for (i=pocetak; i<vel2; i++)
			if (*pok2==*i && i!=pok2)
				return 0;
	}

	pok2-=n2; /* resetovanje pokazivaca na pocetak */
	
	for (; pok1<vel1; pok1++) {
		
		predznak=*pok1; 
		
		/* odredjivanje duzine broja,
		mora biti za 1 manja zbog eksp */
		duzina=-1; 
		a=fabs(*pok1);
		do {
			a/=10;
			duzina++;
		} while (a>0);
		
		broj=fabs(*pok1);
		*pok1=0;
		
		do {
			eksp=pow(10,duzina);
			cifra=broj/eksp; /* na ovaj nacin se cifre uzimaju redom, s lijeva na desno */
			brojac=0;
			
			for (; pok2<vel2; pok2++)
				if (cifra==*pok2) brojac++;
			pok2-=n2;
			
			if (brojac==0) *pok1=*pok1*10+cifra;
			
			broj-=cifra*eksp;
			duzina--;
			
		} while (duzina>=0);
		
		/* ako je vrijednost predznaka na pocetku petlje bila negativna broj postaje negativan */
		if (predznak<0) *pok1*=-1;
	}
	
	return 1;
}

int main (void) {
	return 0;
}