#include <stdio.h>


int izbaci_cifre_iz_broja(int broj, int cifre[], int br_cifara)
{ 
	int tk=1, i,rez=0,ima_u_ciframa,zadnja_cifra_broja, broj_manji_od_nule=1;
	if(broj<0)
	{ 
		broj=broj*-1;
		broj_manji_od_nule=-1;
	}
	while(broj>0)
	{
		ima_u_ciframa = 0;
		zadnja_cifra_broja=broj%10; 
		for(i=0; i<br_cifara; i++)
		{
			if(zadnja_cifra_broja==cifre[i])
			{
				ima_u_ciframa = 1; 
				break;
			} 
		}
		
	if(ima_u_ciframa == 0) 
		{ 
			rez=zadnja_cifra_broja*tk+rez;
			tk=tk*10;
		}
	broj=broj/10;
	}
	
	return broj_manji_od_nule*rez;
}

int izbaci_cifre(int niz[], int broj_el, int cifre[], int br_cifara)
{ 
	int i, j, l;
	for(i=0; i<br_cifara; i++)
	{ 
		if(cifre[i]>9 || cifre[i]<0)
		{ 
			return 0;
		}
		
		for(j=1+i; j<br_cifara; j++)
		{
			if(cifre[i]==cifre[j])
			{
				return 0;
				
			}
			
		}
	}
		for(l=0; l<broj_el; l++)
		{ 	
			niz[l]=izbaci_cifre_iz_broja(niz[l], cifre, br_cifara);
			
		} 
	
	
	return 1; 
}

int main () {
	int brojevi[] = {123, 456};
	int cifre1[] = {1, 2, 3, 1};
	int cifre2[] = {1, 2, 10, 4};
	int cifre3[] = {1, 2, 3, -4};
	int i, rez;
	rez = izbaci_cifre(brojevi, 2, cifre1, 4);
	printf("%d\n", rez);
	rez = izbaci_cifre(brojevi, 2, cifre2, 4);
	printf("%d\n", rez);
	rez = izbaci_cifre(brojevi, 2, cifre3, 4);
	printf("%d\n", rez);
	cifre3[3] = 4;
	rez = izbaci_cifre(brojevi, 2, cifre3, 4);
	printf("%d\n", rez);
	printf("%d %d", brojevi[0], brojevi[1]);
}










