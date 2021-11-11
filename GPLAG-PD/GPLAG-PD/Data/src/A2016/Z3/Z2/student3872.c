#include <stdio.h>
#define broj_el 100
int suma_svih_cifara(int broj)
{
	int i, temp, ostatak;
	int suma=0;
	temp=broj;
	if(broj==0) { return 0;}
	while(temp!=0)
	{
		ostatak=temp%10;
		suma+=ostatak;
		temp/=10;
	}
	return suma;
	
}
int DaLiJeFinobnaccijevBroj(int broj)

{
	int prvi=1, drugi=1, suma=0;
	while(suma<broj)
	{
		suma=prvi+drugi;
		prvi=drugi;
		drugi=suma;
	}
	if((suma==broj || broj==1) && suma!=0)
	return 1;
	else return 0;
	 
	
	
}
void PomjerajClanove(int *niz, int vel, int q)
{
	int i;
	for(i=vel;i>q;i--)
	{
		niz[i]=niz[i-1];
	}
}

void ubaci(int *niz, int velicina)
{
	int i;
int	nova=velicina;
	for(i=0;i<2*nova;i++)
	{
		 
		 if(i%2!=0)
		{


			PomjerajClanove(niz, velicina,i);
			velicina++;
			niz[i]=suma_svih_cifara(niz[i-1]);
			if(niz[i]<0) { niz[i]=-(niz[i]);}
		}
	}
			
		}
	





int izbaci(int *niz, int velicina)
{
int i, j;


for(i=0;i<velicina;i++)
{
	if(DaLiJeFinobnaccijevBroj(niz[i]))
	{
		/*Izbacujemo ga iz niza*/
		for(j=i;j<velicina-1;j++)
		{
			niz[j]=niz[j+1];
		}
		velicina--;
		i--;
	}
}
return velicina;}





int main() {
	int niz[20];
	int i;
	int brojac;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{
		scanf("%d", &niz[i]);
	}

	ubaci(niz, 10);

brojac=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	
	for(i=0;i<brojac-1;i++)
	{
		printf("%d, ", niz[i]);
	}
	for(i=brojac-1;i<brojac;i++)
	{
		printf("%d.", niz[i]);
	}
	return 0;
}
