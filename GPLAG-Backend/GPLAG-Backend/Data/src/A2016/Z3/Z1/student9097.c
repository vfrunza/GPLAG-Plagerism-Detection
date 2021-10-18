#include <stdio.h>
int daj_prost(){
	int log_funk=0, i; /*log_funk je varijabla koja nam pokazuje ako je "n" prost broj, onda log_funk postaje 0, inace ce biti vece*/ 
	do{
	log_funk=0;
	static int n=2; /*Broj koji ispitujemo da li je prost*/
	for (i=2; i<n; i++)
	{
		if(n%i==0) /*Ukoliko je uslov ispunjen broj nije prost*/
		{
			log_funk++;
		}
	}
	if (log_funk==0) /*Broj "n" je prost*/
	{
		n++;
		return n-1;
	}
	n++; 
}while (log_funk!=0);
}
/*U slucaju ako je broj prost, on se povecava za sljedeci put kada se pozove funkcija, a funkcija vraca njegovu vrijednost koju je testirao*/
/*Dakle ako je n=2, nakon sto utvrdi da je broj prost poveca se na 3, a vraca 3-1, tj 2 */
int main() {
	int a, b, s, br;
	do{
	printf("Unesite brojeve A i B: ");
	scanf ("%d %d", &a, &b);
	if (a>=b)
	{
		printf ("A nije manje od B.\n");
	}
	if (a<1)
	{
	printf ("A nije prirodan broj.\n");
	} /*Nije potrebno ispitivati uslov da li je B prirodan broj, buduci da ce A ili biti manje od B ili ce i A takodjer biti manje od 0*/
	}while ((a<1||b<1)||(a>=b));
	s=0;
	br=daj_prost();
	while (br<b)
	{
		if (a<br&&br<b) /*Buduci da smo stavili brojac u funkciji j=2 postavljen je uslov koji ce proste brojeve dodavati u sumu samo ako su oni u intervalu koji smo zadali*/
		s=s+br;
		br=daj_prost();
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a, b, s);
	return 0;
}
