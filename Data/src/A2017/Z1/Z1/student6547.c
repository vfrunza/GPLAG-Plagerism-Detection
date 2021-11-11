#include <stdio.h>
#include <stdlib.h>

int main() {
	float restoranP,restoranH,restoranC;
	restoranP=6.80;
	restoranH=3.30;
	restoranC=5.00;
	float fastfoodP,fastfoodH,fastfoodC;
	fastfoodP=8.00;
	fastfoodH=3.00;
	fastfoodC=3.90;
	float bistroP,bistroH,bistroC;
	bistroP=5.30;
	bistroH=5.00;
	bistroC=6.00;
	char c;
	c='"';
	float popust,racun1,racun2,racun3;
	racun1=0;
	racun2=0;
	racun3=0;
	int P,H,C;
	P=0;
	H=0;
	C=0;
	char tarik,bojan,mirza,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c",&novi_red);
	
	if(tarik=='P')
	{
		P=P+1;
		racun1=racun1+restoranP;
		racun2=racun2+fastfoodP;
		racun3=racun3+bistroP;
	}
	if(tarik=='H')
	{
		H=H+1;
		racun1=racun1+restoranH;
		racun2=racun2+fastfoodH;
		racun3=racun3+bistroH;
	}
	if(tarik=='C')
	{
		C=C+1;
		racun1=racun1+restoranC;
		racun2=racun2+fastfoodC;
		racun3=racun3+bistroC;
	}
	if(bojan=='P')
	{
		P=P+1;
		racun1=racun1+restoranP;
		racun2=racun2+fastfoodP;
		racun3=racun3+bistroP;
	}
	if(bojan=='H')
	{
		H=H+1;
		racun1=racun1+restoranH;
		racun2=racun2+fastfoodH;
		racun3=racun3+bistroH;
	}
	if(bojan=='C')
	{
		C=C+1;
		racun1=racun1+restoranC;
		racun2=racun2+fastfoodC;
		racun3=racun3+bistroC;
	}
	if(mirza=='P')
	{
		P=P+1;
		racun1=racun1+restoranP;
		racun2=racun2+fastfoodP;
		racun3=racun3+bistroP;
	}
	if(mirza=='H')
	{
		H=H+1;
		racun1=racun1+restoranH;
		racun2=racun2+fastfoodH;
		racun3=racun3+bistroH;
	}
	if(mirza=='C')
	{
		C=C+1;
		racun1=racun1+restoranC;
		racun2=racun2+fastfoodC;
		racun3=racun3+bistroC;
	}
	float min_racun;
	min_racun=racun1;
	if(racun2<min_racun)
	{
		min_racun=racun2;
	}
	if(racun3<min_racun)
	{
		min_racun=racun3;
	}
	if(min_racun==racun1)
	printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",c,c,min_racun);
	if(min_racun!=racun1)
	{
		if(tarik=='P' || bojan=='P' || mirza=='P')
		{ popust=restoranP*10/100;
		racun1=racun1-(P*popust);
		}
		else if
		(tarik=='C' || bojan=='C' || mirza=='C')
		{ popust=restoranC*10/100;
		racun1=racun1-(C*popust);
		}
		else 
		{ popust=restoranH*10/100;
		racun1=racun1-(H*popust);
		}
	}
	if(min_racun==racun2)
	printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n", c,c,min_racun);
	if(min_racun==racun3)
	printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",c,c,min_racun);
	if(min_racun>racun1)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", racun1);
	
	return 0;
}
