#include <stdio.h>

int main() {
	int niz[100], niz1[1000], niz2[1000];
	int n,i,j,a,k,broj,brojac,duzina2;
	brojac=0; j=0;
	a=0;
	do
	{
		printf("Unesite velicinu niza: "); scanf("%d", &n);
	}
	while (n<0);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) scanf("%d", &niz[i]);
	
	if(n>0) a=niz[0];
	do {broj=a%10; a=a/10; }while(a!=0);
	
	for(i=0; i<n; i++)
	{
		k=0; a=niz[i];
		do
		{
			niz2[k]=a%10; k++; a=a/10;
		} 
		while(a!=0);
		duzina2=k; k--;
		
		do
		{
			if(broj==niz2[k]) brojac++;
			else
			{
				niz1[j]=broj; niz1[j+1]=brojac; brojac=1; j=j+2; broj=niz2[k];
			}
			if(i==n-1 && k==0){niz1[j]=broj; niz1[j+1]=brojac; brojac=1; j=j+2; broj=niz2[k];}
			k--;
		}
		while(k>=0);
	}
	
	printf("Finalni niz glasi: \n");
	for(i=0; i<j; i++) printf("%d ",niz1[i]);
	
	return 0;
}
