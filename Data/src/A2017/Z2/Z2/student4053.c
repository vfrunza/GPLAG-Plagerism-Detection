#include <stdio.h>

int main() {
	long int niz[100];
	long int niz2[100];
	int niz3[100];
	int vel_niza=0, i=0, j, broj=0, pom, pom_br=0;
	
	printf("Unesite velicinu niza: ");
	do
	{
		scanf("%d", &vel_niza);
	}while(vel_niza<=0 || vel_niza>100);
	
	i=0;
	pom=vel_niza;
	printf("Unesite clanove niza: ");
	do
	{
		scanf("%d", &broj);
		if(broj<0) continue;
		niz[i]=broj;
		pom--;
		i++;
	}while(pom>0);
	j=0;
	for(i=vel_niza-1; i>=0;i--)
	{
		pom= niz[i];
		if(pom==0) 
		{
			niz2[j]=pom;
			j++;
			continue;
		}
		while(pom>0)
		{
			niz2[j]= pom%10;
			pom=pom/10; 
			j++;
		}
	
	}
	
	broj=niz2[0];
	pom=1;
	for(i=1;i<j;i++)
	{
		if(broj==niz2[i])
		{
			pom++;
		}
		else 
		{
			niz3[pom_br]=pom;
			niz3[pom_br+1]= broj;
			broj=niz2[i];
			pom=1;
			pom_br+=2;
		}
		
	}
	niz3[pom_br]=pom;
	niz3[pom_br+1]= broj;
	pom_br+=2;
	printf("Finalni niz glasi:\n");
	for(i=pom_br-1; i>=0; i--) printf("%d ", niz3[i]);
	
	return 0;
}
