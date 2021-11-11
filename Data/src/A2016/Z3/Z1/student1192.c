#include <stdio.h>
int prost (int broj) /*Funkcija provjerava da li je broj prost*/
{
	int i;
	if(broj==1)
	return 0;
	for(i=2;i<broj; i++)
	{
		if((broj%i)==0)
		return 0;
		
	}
	return 1;
}
int daj_prost() 
{
	static int pbroj=1;
	if(pbroj==1)
	{
		pbroj++;
	return 2;
	}
	do 
	{
		pbroj++;
	}
	while(prost(pbroj)==0);
	return  pbroj;

}
int main() {
	int i, a, b ,prostb,suma;
	suma=0;
	/*Ulaz i program provjera da li se A i B nalaze u zadanom intervalu.*/
	do {
	printf("Unesite brojeve A i B: ");
	scanf ("%d %d", &a, &b);
	if(a<=0)
	{
	printf("A nije prirodan broj.\n");
	}
	if(a>=b)
	{
	printf("A nije manje od B.\n");
	}
	}
	while ((a<=0)||(a>=b));
	
	
	/*Obrada*/
	
	for(i=2; i<b; i++)
	{
	/*pozivanje funkcije daj prost za sve proste brojeve koji su prije broja A */
		if(prost(i)==1){    
    	prostb=daj_prost();
		}
	/*Racunanje sume svih prostih brojeva izmedju A i B*/
	if((i>a))
	{
		if(prost(i)==1)
		{
		suma = suma + prostb;
		}
	}
	}
	
	/*Izlaz*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b, suma);
	return 0;
}
