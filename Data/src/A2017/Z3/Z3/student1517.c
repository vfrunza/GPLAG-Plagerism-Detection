#include <stdio.h>
#include <math.h>

int izbaci_cifre (int *niz1, int v1, int *niz2, int v2)
{
	int i, j, k, a, b, duzina_niza, brojac, izbaci;
	int n1[100], n2[100];
	int *p=niz1;
   /*mozda na dno*/
	for(i=0; i<v2; i++)
	{
		if(niz2[i]<0 || niz2[i]>9) return 0;
		for(j=i+1; j<v2; j++)
		{
			if(niz2[i]==niz2[j]) return 0;
		}
	}

	for(i=0; i<v1; i++)
	{
		duzina_niza=0; n2[i]=0; brojac=0; a=fabs(niz1[i]);  
		do
		{
			b=a%10; a=a/10; n1[duzina_niza]=b; duzina_niza++; 
		}while(a>0);
		
		
		for(j=0; j<duzina_niza; j++)
		{
			izbaci=1;
			for(k=0; k<v2; k++)	if(n1[j]==niz2[k]) izbaci=0;
				if(izbaci==1)
				{
					n2[i]=n2[i]+n1[j]*pow(10,brojac);
					brojac++;
					izbaci=0;
				}
			
		}
	}
	

	for(i=0; i<v1; i++)
	{
		if(niz1[i]<0) n2[i]=n2[i]*(-1);
	}
	
	for(i=0; i<v1; i++)
	{
		*p=n2[i]; p++;
	}
	
	
	return 1;
}

int main() 
{
	int brojevi[] = {12345, -12345};
	int cifre[] = {3,5};
	
	izbaci_cifre(brojevi, 2, cifre, 2);
	printf("%d %d", brojevi[0], brojevi[1]);
	
	return 0;
}














