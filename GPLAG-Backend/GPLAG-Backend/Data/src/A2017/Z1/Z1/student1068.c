#include <stdio.h>

/*
1. Restoran "Kod Konja i Konjusara"
2. Fast-food "Trovac"
3. Bistro "Lorelei"
*/

/* Cijene pizze, hamburgera i cevapa za sve restorane. */
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00 
#define C2 3.90
#define C3 6.00

/* Popust na jedno jelo iznosi 10%. */
#define POPUST 0.1

int main() 
{
	/* Varijable. */
	char tarik, bojan, mirza, nova_linija;
	int counter_H, counter_P, counter_C;
	counter_C = counter_P = counter_H = 0;
	float c1, c2, c3, min, a, b, c, min_popust;
	c1 = c2 = c3 = 0;

	/* Unos. */
	printf("Unesite jelo za Tarika: "); scanf("%c", &tarik); scanf("%c", &nova_linija);
	printf("Unesite jelo za Bojana: "); scanf("%c", &bojan); scanf("%c", &nova_linija);
	printf("Unesite jelo za Mirzu: "); scanf("%c", &mirza); scanf("%c", &nova_linija);
	
	/* Izracune cijene svih restorana (bez popusta). */
	switch(tarik)
	{
		case 'H':
			c1 += H1;
			c2 += H2;
			c3 += H3;
			counter_H++;
			break;
		
		case 'P':
			c1 += P1;
			c2 += P2;
			c3 += P3;
			counter_P++;
			break;
		
		case 'C':
			c1 += C1;
			c2 += C2;
			c3 += C3;
			counter_C++;
			break;
	}
	
	switch(bojan)
	{
		case 'H':
			c1 += H1;
			c2 += H2;
			c3 += H3;
			counter_H++;
			break;
		
		case 'P':
			c1 += P1;
			c2 += P2;
			c3 += P3;
			counter_P++;
			break;
		
		case 'C':
			c1 += C1;
			c2 += C2;
			c3 += C3;
			counter_C++;
			break;
	}
	
	switch(mirza)
	{
		case 'H':
			c1 += H1;
			c2 += H2;
			c3 += H3;
			counter_H++;
			break;
		
		case 'P':
			c1 += P1;
			c2 += P2;
			c3 += P3;
			counter_P++;
			break;
		
		case 'C':
			c1 += C1;
			c2 += C2;
			c3 += C3;
			counter_C++;
			break;
	}
	
	/* Nade najmanju cijenu. */
	min = c1;
	if (min > c2)
		min = c2;
	if (min > c3)
		min = c3;
		
	/* Ispis. */
	printf("Najjeftiniji je ");	
	if (min == c1)
		printf("Restoran \"Kod konja i konjusara\" (%.2f KM).\n", c1);
	else if (min == c2)
		printf("Fast-food \"Trovac\" (%.2f KM).\n", c2);
	else if (min == c3)
		printf("Bistro \"Lorelei\" (%.2f KM).\n", c3);
	
	/* Popusti. */
	a = c1 - counter_H * (H1 * POPUST);
	b = c1 - counter_P * (P1 * POPUST);
	c = c1 - counter_C * (C1 * POPUST);
	
	/* Nade najnizu od snizenih cijena. */
	if (a < b)
		if (b > c)
			min_popust = a;
        else
        	min_popust = a;
    else
	 	if (b > c)
		    min_popust = c;
       	else
        	min_popust = b;
        	
    /* Ispis. */
    if (min_popust < min && min != c1)
    	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", min_popust);
    
	return 0;
}

