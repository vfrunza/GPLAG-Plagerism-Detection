#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int izbaci_cifre(int *br,int vel_br,int *cif,int vel_cif);
int provjera_cifre(int n,int *niz,int velicina);
int da_li_je_broj(int *niz,int velicina);

int provjera_cifre(int n,int *niz,int velicina)
{
	/*Provjerava da li postoji element in niza niz sa istom vrijednoscu kao n*/
	int i;
	for(i=0; i<velicina; i++)
		if(n==niz[i])
			return 1;
	return 0;
}

int da_li_je_broj(int *niz,int velicina)
{
	/*provjera niza cifara da li odgovara kriterijima zadatka*/
	int i,j;
	for(i=0; i<velicina-1; i++) {
		for(j=i+1; j<velicina; j++) {
			if(niz[i]==niz[j] || niz[i]<0 || niz[i]>9 || niz[j]<0 || niz[j]>10)
				return 1;
		}
	}
	return 0;
}

int izbaci_cifre(int *br,int vel_br,int *cif,int vel_cif)
{
	int i,temp,cifra,znak,k;
	/*testiranje validnosti niza cifara*/
	if(da_li_je_broj(cif,vel_cif)==1)
		return 0;
	for(i=0; i<vel_br; i++) {
		if(*br<0)
			znak=-1;
		else
			znak=1;
		temp=abs(*br);
		*br=0;
		/*k koristimo kako bi lakse formirali broj upotpunosti ili bez nekih cifara*/
		k=0;
		do {
			cifra=temp%10;
			temp/=10;
			/*provjeramo da li cifra odgovara jednom od elemenata iz niza cif, ako ne, onda se ta cifra dodaje na izmjenjeni broj
			koji provjeravamo*/
			if(provjera_cifre(cifra,cif,vel_cif)==0) {
				*br+=(cifra*((int)pow(10,k)));
				k++;
			}
		} while(temp!=0);
		*br*=znak;
		br++;
	}
	return 1;
}



int main()
{
	int brojevi[100],cifre[100];
	int vel_br,vel_cif;
	int i;
	do {
		scanf("%d",&vel_br);
	} while(vel_br<0 || vel_br>1000);
	for(i=0; i<vel_br; i++) {
		scanf("%d",&brojevi[i]);
	}
	do {
		scanf("%d",&vel_cif);
	} while(vel_cif<0 || vel_cif>20);
	for(i=0; i<vel_cif; i++) {
		scanf("%d",&cifre[i]);
	}

	return 0;
}
