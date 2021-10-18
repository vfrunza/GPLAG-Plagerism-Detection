#include <stdio.h>
int daj_prost()
{
	int i=0,k=0;
	do{
	k=0;
	static int p=2;/*broj koji ispitujemo da li je prost*/
	for(i=2;i<p;i++)
		{
		if(p%i==0) k++;/*trazenje djelilaca broja kojeg ispitujemo*/
		}
	if(k==0) /*ako je broj djelilaca 0 broj je prost, povecavamo vrijednost za sljedeci put kada se funkcija pozove, a vracamo njegovu vrijednost koju testiramo*/
		{
		p++; return p-1;
		}
	p++;/*Trazim sljedeci broj koji je prost ako je uzeti broj slozen*/
	}while (k!=0);
}
int main() {
	int a,b,s=0,c;
	while(1)
	{
	printf("Unesite brojeve A i B: ");
	scanf(" %d %d", &a, &b);
	if(a>=b) printf("A nije manje od B.\n");
	else if (a<1) printf("A nije prirodan broj. \n");/*Ako je a prirodan broj i uslovom da je b>a slijedi da je b prirodan broj i nema potrebe ispitivati b*/
	else break;
	}
	c=daj_prost();/*pozivanje prvog prostog broja*/
	while(c<b)/*petlja ce se vrsiti sve dok je rezultat funkcije u intervalu(a,b)*/
	{
		
		if(a<c && c<b) s=s+c;
		c=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,s);
	return 0;
}

		
