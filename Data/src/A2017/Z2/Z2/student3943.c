#include <stdio.h>
#define DUZINA 100
#define DUZINA1 1000
#include <math.h>

int main() {
int i,j=0,n,broj,niz1[DUZINA],pom,m,k=0;
int pomocni[DUZINA],niz2[DUZINA1],cifre=0,broj1,niz3[DUZINA1],brojac=1,f;

do
{
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	
}while(n<0 || n>100);

printf("Unesite clanove niza: ");

for(i=0;i<n;i++)
{
	scanf("%d",&broj);
	if(broj<0)
	{
		i--;
		continue;
		
	}
niz1[i]=broj;	
}

for(i=0;i<n;i++)
pomocni[i]=niz1[i];



for(i=0;i<n;i++)
{
	
	
	cifre=0;
	if(niz1[i]==0)       // zbog testa
	{
		niz2[j]=0;
		j++;
		
	}
	
	while(niz1[i]!=0)
	{
		niz1[i]=niz1[i]/10;       // brojanje cifri clana
		cifre++;
		
	}
	if(cifre==1)
	{
		
		niz2[j]=pomocni[i];
		j++;
		continue;
		
	}
	
	
for(broj1=0;broj1<cifre;broj1++)	
{
	
	pom=pomocni[i]/(int)(pow(10,cifre-1-broj1)); //
	niz2[j]=pom;                                             //pravim neprekinuti niz
	j++;
	pomocni[i]-=pom*(int)(pow(10,cifre-1-broj1));
}
}

m=j;


for(i=0;i<m;i++)
{
	
if(i==m-1 && niz2[i]==niz2[i-1])	
{
	
	niz3[k]=niz2[i];
	k++;                       //nakon continue zavrsava se petlja
	niz3[k]=brojac;
	k++;
	continue;                                                                // da ne bi izletio iz opsega niza
	
	
}
else if(i==m-1 && niz2[i]!=niz2[i-1])	
{
	
	brojac=1;
	niz3[k]=niz2[i];
	k++;                               
	niz3[k]=brojac;
	k++;
	continue;
	
}
if(niz2[i]==niz2[i+1])	
{
	brojac++;
}
if(niz2[i]!=niz2[i+1])	
{
	niz3[k]=niz2[i];
	k++;
	niz3[k]=brojac;
	k++;
	brojac=1;
	
	
}
}




f=k;
printf("Finalni niz glasi:");
printf("\n");
for(i=0;i<f;i++)
{
	
	printf("%d ",niz3[i]);
}

	return 0;
}
