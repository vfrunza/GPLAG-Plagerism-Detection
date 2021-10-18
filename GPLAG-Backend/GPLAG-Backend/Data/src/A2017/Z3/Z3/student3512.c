#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre(int [],int, int[],int);
int izbaciUljeza(int,int[],int);


int main()
{
	/*
		int brojevi[5]={25, 235, 1235, 252, 22552255};
		int cifre[3]= {2,3,5};

		izbaci_cifre(brojevi, 5,cifre, 3);
	*/
	return 0;
}



int izbaci_cifre(int brojevi[],int x, int cifre[], int y)  //f-ja prima 2 niza i njihove velcine
{
	int i;
	int t=0;
	int gg=1;

	int q,n;

	//provjera za cifre
	for(q=0; q<y; q++) {

		if(cifre[q]<0 || cifre[q]>9)
			return 0;
	}
	for(q=0; q<x; q++) {
		for(n=q+1; n<y; n++) {
			if (cifre[q]==cifre[n])
				return 0;
		}
	}


	for (i=0; i<x; i++) {
		gg=1;
		t=brojevi[i];

		if (t<0) {
			gg=-1;
		}
		//f-ja koja radi zadatak izbacuje cire iz broja provjeravajci sta se nalazi u drugom nizu cifara
		brojevi[i]=izbaciUljeza (abs(t),cifre,y) * gg ;
	}

	return 1;
}


int izbaciUljeza(int broj,int cifre[], int y)
{
	int VrBr=0;
	int pot=0;
	int c=0;
	int cifraX = 0;
	int j;

	//cijepa broj na cifre
	while(broj>0) {
		c=broj%10;
		broj = broj /10;

		cifraX=0;

		for(j=0; j<y; j++) {
			//provjera
			if(cifre[j] == c) {
				cifraX=1;
				break;
			}
		}

		if (!cifraX) {
			//floor koristim zbog toga sto je za neke brojeve umjesto 4 vracalo 3.999999 jer pow radi u double, sa floor osiguramo da broje bude OK
			VrBr += c * floor(pow(10,pot));
			pot++;
		}
	}
	return VrBr;
}
