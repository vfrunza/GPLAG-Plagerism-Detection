#include <stdio.h>
int daj_prost() {
	/*Kao staticku promjenjivu postavljamo prost_broj*/
	int i;
	static int prost_broj=1;
	prost_broj++;
	/* Racunamo prost_broj*/
	for(i=2;i<prost_broj;i++)
	{
		if (prost_broj%i==0)
		{
			prost_broj++;
			i=2;
			
		}
		
	}
	return prost_broj;
	
}
int main() {
	int i,j,broj_a,broj_b,suma_pr,slozeni_br,prosti_br,broj1;
	do {
	printf("\nUnesite brojeve A i B: ");
	scanf("%d %d",&broj_a,&broj_b);
	if(broj_a<=0)
	{
		printf("A nije prirodan broj.");
		
	}
	else if(broj_a>=broj_b)
	{
		printf("A nije manje od B.");
		
	}
	}while((broj_a<=0) || (broj_a>=broj_b) || (broj_b<=0));
	slozeni_br=0;
	/* Racunamo broj slozenih brojeva da bismo dobili i broj prostih jer 
	broj prostih ujedno oznacava i broj koji pokazuje koliko puta cemo pozvati funkciju daj_prost */
	for(i=(broj_a+1);i<broj_b;i++)
	{
		for (j=2;j<i;j++)
		{
			if(i%j==0)
			{   
				slozeni_br++;
				break;
			}
		}
		
	}
	suma_pr=0;
	prosti_br=0;
	prosti_br=(broj_b-broj_a-slozeni_br-1);
	if(prosti_br>0)
	/* Racunamo prvi broj veci od A koji je prost */
	{   
		broj1=broj_a;
		do {
			broj1=daj_prost();
			
		} while(broj1<=broj_a);
		suma_pr=(suma_pr+broj1);
		for(i=1;i<prosti_br;i++)
		{
			suma_pr=(suma_pr + daj_prost());
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.\n",broj_a,broj_b,suma_pr);
	} 
	else if(prosti_br==0)
	{
		printf("Suma prostih brojeva izmedju %d i %d je 0.\n",broj_a,broj_b);
		
	}
	return 0;
		
	}
		