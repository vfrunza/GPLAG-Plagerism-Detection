#include <stdio.h> 

Unesite clanove niza: 233 38 17777 7737 152
Finalni niz glasi:
	2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1

#define DUZINA1 100
#define DUZINA2 1000
#include <math.h>

int main() {
	int i,j=0,n,broj,nizP[DUZINA1],nizA[DUZINA1],nizB[DUZINA2],nizC[DUZINA2],m,brojac=1,k=0,f,pom,cifre=0,p;
	
	do
	{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n<0 || n>100);	
	
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&broj);
		if (broj<0)
		{
			i--;
			continue;
		}	
		nizA[i]=broj;
	}
	
	for(i=0;i<n;i++)
		nizP[i]=nizA[i];
	
	for(i=0;i<n;i++)
	{

		cifre=0;
		if(nizA[i]==0)
		{
			nizB[j]=0;
			j++;
		}
		while(nizA[i]!=0)
		{
			nizA[i]/=10;
			cifre++;
		}
		if (cifre==1)
		{
			nizB[j]=nizP[i];
			j++;
			continue;
		}
		for(p=0;p<cifre;p++)
		{
			pom=nizP[i]/(int)(pow(10,cifre-1-p)+0.5);
			nizB[j]=pom;
			j++;
			nizP[i]-=pom*(int)(pow(10,cifre-1-p)+0.5);
		}
	}
	
	
	
	m=j;
	for(i=0;i<m;i++)
	{
		if (i==m-1 && nizB[i]==nizB[i-1])
		{
		
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			continue;
		}
		else if (i==m-1 && nizB[i]!=nizB[i-1])
		{
			brojac=1;
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			continue;
		}
		if (nizB[i]==nizB[i+1])
		{
			brojac++;
		}
		if (nizB[i]!=nizB[i+1])
		{
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			brojac=1;
		}
		
	}
	f=k;
	printf("Finalni niz glasi: ");
	printf("\n");
	for(i=0;i<f;i++)
	{
		printf("%d ",nizC[i]);
	}
	
	return 0;
}#include <stdio.h>
#define DUZINA1 100
#define DUZINA2 1000
#include <math.h>

int main() {
	int i,j=0,n,broj,nizP[DUZINA1],nizA[DUZINA1],nizB[DUZINA2],nizC[DUZINA2],m,brojac=1,k=0,f,pom,cifre=0,p;
	
	do
	{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n<0 || n>100);	
	
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&broj);
		if (broj<0)
		{
			i--;
			continue;
		}	
		nizA[i]=broj;
	}
	
	for(i=0;i<n;i++)
		nizP[i]=nizA[i];
	
	for(i=0;i<n;i++)
	{

		cifre=0;
		if(nizA[i]==0)
		{
			nizB[j]=0;
			j++;
		}
		while(nizA[i]!=0)
		{
			nizA[i]/=10;
			cifre++;
		}
		if (cifre==1)
		{
			nizB[j]=nizP[i];
			j++;
			continue;
		}
		for(p=0;p<cifre;p++)
		{
			pom=nizP[i]/(int)(pow(10,cifre-1-p)+0.5);
			nizB[j]=pom;
			j++;
			nizP[i]-=pom*(int)(pow(10,cifre-1-p)+0.5);
		}
	}
	
	
	
	m=j;
	for(i=0;i<m;i++)
	{
		if (i==m-1 && nizB[i]==nizB[i-1])
		{
		
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			continue;
		}
		else if (i==m-1 && nizB[i]!=nizB[i-1])
		{
			brojac=1;
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			continue;
		}
		if (nizB[i]==nizB[i+1])
		{
			brojac++;
		}
		if (nizB[i]!=nizB[i+1])
		{
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			brojac=1;
		}
		
	}
	f=k;
	printf("Finalni niz glasi: ");
	printf("\n");
	for(i=0;i<f;i++)
	{
		printf("%d ",nizC[i]);
	}
	
	return 0;
}








SARIN I MOJ UZALUDNI POKUŠAJ

/*#include <stdio.h>
#define vel1 5
#define vel2 20

int main() {
	int vel,i, prvi[1000], drugi[1000], niz[1000], konacni[1000], j=0, velniz, brojac,k, cifra, konac, cifra1;
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	printf("Unesite clanove niza: ");
	for (i=0; i<vel; i++) scanf("%d", &prvi[i]);
	
	
	for (i=0; i<vel; i++) {
		cifra1=0;
		while (prvi[i]!=0) {
			konac=prvi[i]%10;
			cifra1=cifra1*10 + konac;
			prvi[i]/=10;		
		}
		drugi[i]=cifra1;
	}
	
	
	
	for (i=0; i<vel; i++) {
		while (drugi[i]!=0) {
			int cifra=drugi[i]%10;
			niz[j]=cifra;
			j++;
			drugi[i]/=10;
		}
		velniz=j;
	}
	

	for (i=0; i<velniz; i++) {
		brojac=0;
		for (j=i+1; j<velniz; j++) {
			if (niz[i]!=niz[j]) {
				brojac++;
				konacni[k]=niz[i];
				k++;
				konacni[k]=brojac;
				break;
			}
		}
	}

	return 0;
}
*/