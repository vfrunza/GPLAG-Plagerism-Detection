#include <stdio.h>
static int A=0;
int daj_prost();
int je_li_prost(int);

int daj_prost () {
	static int zadnji_prost=1;
	
	int broj=0;
	int i,trazi=1;

	if (A==0) {
		
		if (zadnji_prost==1)
			broj=2;
		else broj=zadnji_prost + 1;
		
		while (trazi) {
			if (je_li_prost(broj)) {
				trazi=0;
				zadnji_prost=broj;
				return broj;
			}
			broj++;
		}
	}
		else {
			
			if (A!=0 && zadnji_prost==1)
				zadnji_prost=A;
				
			for (i=zadnji_prost; i<zadnji_prost + 1; i++) {
				if (je_li_prost(i)) {
					zadnji_prost=zadnji_prost + 1;
					return i;
				}
				else {
					zadnji_prost=zadnji_prost + 1;
					return 0;
				}
			}
		}
		return zadnji_prost;
}

int je_li_prost (int broj) {
	
	int prost=1;
	int i;
	
	for (i=2; i<broj; i++) {
		
		if (broj%i==0) {
			prost=0;
			break;
		}
	}
	if (prost)
		return 1;
	return 0;
}
		

int main() {

	int i,B=0,suma=0, pokrenut = 1;
	do {	
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d",&A,&B);
		
			if (A>=B) { 
				
			printf ("A nije manje od B.\n");
			
			continue;
			}
		
			if (A<=0 || B<=0) {
		
			printf ("A nije prirodan broj.\n");
		
			continue;
			}
			
			pokrenut = 0;

		
	} while (pokrenut);
		// A>B || A>=0 || B>=0);
	
	int A_prost = 0;
	int B_prost = 0;
	
	for (i=A; i<=B; i++) {
		if (i==A && je_li_prost(i))
		    A_prost++;
		
		if (i==B && je_li_prost(i))
		    B_prost++;
		    
		suma=suma+daj_prost();
	}
	
	
	// ako su prvi i zadnji brojevi prosti oduzmi ih od sume
	if (A_prost == 1 && B_prost == 1)
	    printf ("Suma prostih brojeva izmedju %d i %d je %d.\n",A,B,suma-A-B);
	
	// ako je prvi prost broj a zadnji nije onda oduzmi prvi broj od sume    
	else if (A_prost == 1 && B_prost == 0)
	    printf ("Suma prostih brojeva izmedju %d i %d je %d.\n",A,B,suma-A);
	
	else 
	   printf ("Suma prostih brojeva izmedju %d i %d je %d.\n",A,B,suma);
	
	return 0;
}
