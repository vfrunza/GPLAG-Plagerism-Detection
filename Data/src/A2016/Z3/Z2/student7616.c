#include <stdio.h>

//Funkcija koja ubacuje sumu predhodnog broja u nizu
void ubaci(int niz[], int vel)
{
	int i, suma,pom,j,vel1=vel;
	for(i=0; i < vel*2; i++)
	{
		suma=0;
		if(niz[i] < 0) pom=-niz[i];
		else pom=niz[i];
		//trazenje sume
		while(pom != 0)
		{
			suma+=pom%10;
			pom/=10;
		}
		//ubacivanje u niz
		for(j=vel1; j > i; j--)
		niz[j]=niz[j-1];
		niz[++i]=suma;
		vel1++;
	}
	
}
//Funkcija koja ispituje da li je broj u fib nizu
int fib(int n)
{
	if(n <= 2) return 1;
	int suma,a,b;
	a=1;
	b=1;
	for(;;)
	{
		suma= a+b;
		b=a;
		a=suma;
		if(suma ==n) return 1;
		if(suma > n) return 0;
	}
}
//Funkcija koja iz niza izbacuje fib brojeve
int izbaci(int niz[], int vel)
{
	int i,j;
	for(i=0; i < vel; i++)
	{
		if(niz[i] > 0)
		{
			if(fib(niz[i]))
			{
				for(j=i; j < vel-1; j++)
				niz[j]=niz[j+1];
				vel--;
				i--;
			}
		}
	}
	return vel;
}

int main()
{
	int niz[100], vel=10, i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i < vel; i++)
	scanf("%d", &niz[i]);
	ubaci(niz,vel); //poziv funkcije ubaci 
	vel*=2;
	vel=izbaci(niz,vel); // poziv funkcije izbaci
	printf("Modificirani niz glasi: ");
	for(i=0; i < vel; i++) //ispis
	if(i == vel-1) printf("%d.", niz[i]);
	else
	printf("%d, ", niz[i]);
	return 0;
}