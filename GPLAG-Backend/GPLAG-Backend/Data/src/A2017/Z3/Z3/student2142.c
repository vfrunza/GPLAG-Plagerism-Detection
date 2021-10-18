#include <stdio.h>
#include <math.h>

int sadrzicifru(int n, int a)
{
	while(n!=0)
	{
		if(n%10==a) return 1;
		n/=10;
	}
	return 0;
}

int izbacicifru(int n, int a)
{
	int suma=0, k=1;
	while(n!=0)
	{
		if(n%10!=a) {
			suma+=(n%10)*k;
			k*=10;
		}
		n/=10;
	}
	return suma;
}

int izbaci_cifre(int niz1[], int br1, int niz2[], int br2){
	int i, j, negativan;
	for(i=0; i<br2; i++)
	{
		if(niz2[i]<0 || niz2[i]>9) return 0;
	}
	for(i=0; i<br2-1; i++)
	{
		for(j=i+1; j<br2; j++)
		{
			if(niz2[i]==niz2[j]) return 0;
		}
	}
	for(i=0; i<br1; i++)
	{
		negativan=0;
		if(niz1[i]<0){
			negativan=1;
			niz1[i]=-niz1[i];
		}
		for(j=0; j<br2; j++)
		{
			if(sadrzicifru(niz1[i], niz2[j])==1)
			{
				niz1[i]=izbacicifru(niz1[i], niz2[j]);
			}
		}
		if(negativan==1) niz1[i]=-niz1[i];
	}
	return 1;
	
}
int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
