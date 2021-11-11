#include <stdio.h>

/*Trazimo sljedeci prost broj u datom intervalu*/
int provjeri_je_li_prost(int n) { 
	int i, br=0;
	for (i=1; i<=n; i++) 
		if (n%i==0) 
		br++;
		if (br==2) return 1; 
	    else return 0;
}	    

/*Funkcija vraca prost broj*/	    
int daj_prost() {
	static int x=1;
	x++;
	while (provjeri_je_li_prost(x)==0)
	x++;
	return x;
}

int main () {
	int A, B, i, suma=0;
	do {
	printf ("Unesite brojeve A i B: ");
	scanf ("%d %d", &A, &B);
	if (A<=0) printf ("A nije prirodan broj.\n");
	else if (B<=A) printf ("A nije manje od B.\n");
	else if (B<=0) printf ("B nije prirodan broj.\n");
	} while (A<=0 || B<=0 || A>=B); 
	
	/*Racunanje sume prostih brojeva u intervalu (A,B)*/
	i=daj_prost();
	while (i<=A) {
		i=daj_prost();
	}
	
	while (i<B) {
		if (provjeri_je_li_prost(i)==1) { 
		suma=suma+i;
		i=daj_prost();
		}
	}

printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
return 0; 
}
