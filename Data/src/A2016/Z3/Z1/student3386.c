#include <stdio.h>

int daj_prost()
{
	int i;
	/*prost postavljamo kao staticku promjenljivu jer 
	nam treba da svaki sljedeci put imamo sljedeci prost broj*/
	static int prost=1;
	prost++;
	/*racunanje prostog broja*/
	for(i=2;i<prost;i++)
	{
		if(prost%i==0)
		{
			prost++;
			i=2;
		}
	}
	return prost;
	
}
int main() 
{
	int a,b,i,suma=0,j,broj_neprostih=0,broj_prostih=0,prvi_br;
	/*unos i provjera da li su u zadanom opsegu*/
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)
			printf("A nije prirodan broj.\n");
		else if(a>=b)
			printf("A nije manje od B.\n");
		
	}while((a<=0)||(b<=0)||(a>=b));
	/*provjeravam koliko ima neprostih brojeva da bih znao
	koliko ima prostih i na osnovu toga znao koliko puta 
	pozivam funkciju daj_prost*/
	for (j=(a+1);j<b;j++)
	{
		for(i=2;i<j;i++)
		{
			if(j%i==0)
			{
				broj_neprostih++;
				break;
			}
		}
	}
	broj_prostih=b-a-broj_neprostih-1;
	
	if(broj_prostih==0)
		printf("Suma prostih brojeva izmedju %d i %d je 0.",a,b);
	else
	{	
		/*trazim prvi prosti broj koji je veci od broja A*/
		prvi_br=a;
		do
		{
			prvi_br=daj_prost();
		}while(prvi_br<=a);
		suma=prvi_br;
		/*promjenljiva i ce nam biti 1 jer vec znamo prvi
		broj trazene sume gornjom do while petljom te njega
		preskacemo u sljedecoj petlji*/
		for(i=1;i<broj_prostih;i++)
		{
			suma+=daj_prost();
		
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	}
	return 0;
}
