#include <stdio.h>

int prost(int i) 		/*Funckija provjerava da li je poslani broj prost, te daje povratnu vrijednost 0 ili 1*/
{
	int j, brojac=0;
	for (j=1; j<=i; j++)
	{
		if(i%j==0)
		brojac++;
	}
	if (brojac==2)
	return 1;
	else 
	return 0;
	
}

int daj_prost (){  		/*Funkcija generise proste brojeve s time da svakim pozivom funkcije dobijamo sljedeci prost broj*/
	static int i; 		/*Iz uslova zadatka koristimo staticku varijablu jer funkcija mora "nastaviti" odakle je stala*/
	while(1)
	{
		if(prost(i)) 	/*Alternativno se moze koristiti goto: ponovo: i++; if (prost(i)) return i; else goto ponovo;*/	
		{
			i++;
			return i-1;
		}
		i++;
	}
	
}

int main() {
	int a, b, y, suma=0;
	do {
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		
		if (a<=0)
		printf("A nije prirodan broj.");
		else if (a>=b)
		printf("A nije manje od B.");
		
	}while(a>=b || a<=0); 	/*Omogućava da unesene vrijednosti budu prirodni brojevi, s time da se prvo unosi manji broj*/
	do{
		y=daj_prost();		/*Pozivanje funkcije koja generise proste brojeve*/
		if(y>a && y<b)
		suma+=y;
	}while(y<b); 			/*Ogranicava broj poziva funkcije dokle god vraceni prost broj ne postane veci od unesenog broja b*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b, suma);
	return 0;
}
