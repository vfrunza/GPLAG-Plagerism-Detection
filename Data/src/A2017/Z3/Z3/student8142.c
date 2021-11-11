#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *niz1, int n1, int *niz2, int n2)
{
	int i, j, k, l;
	int novi_niz=0;
	int temp=0;
	int pom_niz[100];
	int brojac=0;
	for (i = 0; i < n2; i++) {
		for (j = 0; j < n2; j++) {

			if(niz2[j]<0 || niz2[j]>9) return 0;
			if(niz2[i]==niz2[j] && i!=j) return 0;

		}

	}

	for (i = 0; i < n1; i++) {
		
		brojac=0;
		temp=fabs(niz1[i]);
		while(temp>0)
		{
			pom_niz[brojac]=temp%10;
			temp/=10;
			brojac++;
		}
		for(j = 0; j < n2; j++)
		{
			for(k = 0; k < brojac; k++)
			{
				if(pom_niz[k]==niz2[j]) pom_niz[k]=-1;
			}
		}
		
		for(k = brojac-1; k >= 0; k--)
		{
			if(pom_niz[k]!=-1) 
			{
				temp+=pom_niz[k];
				temp*=10;
			}
		}
		temp/=10;
		if(niz1[i]<0) temp*=-1;
		niz1[i]=temp;

	}
	return 1;
}


int main()
{

	return 0;
}
