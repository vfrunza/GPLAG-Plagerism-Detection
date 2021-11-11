#include <stdio.h>
#include <math.h>
int main() {
	
	int niz[100];
	int nniz[1000];
	int j=0,i,n,g=0;
	int brojac=1;
	int temp;
	int ostatak=0;
	int brdj=0;
	int powbr;
	printf("Unesite velicinu niza: ");scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++)
	scanf("%d",&niz[i]);
	
	for(i=0;i<n;i++)
	{
		brdj=0;
		temp=niz[i];
		do
		{
			temp/=10; 
			brdj++;
		}while(temp>0);
		temp=niz[i];
		brdj--;
		do
		{
			powbr=pow(10,brdj);
		    ostatak=temp/powbr;
			nniz[j]=ostatak;
			j++;
			temp=temp-ostatak*powbr;
			brdj--;
		}while(brdj>=0);
	}
	for(i=0;i<j;i++)
	{niz[i]=nniz[i];}
	niz[j]=10;
	
	for(i=0;i<j;i++)
	{
		if(niz[i]==niz[i+1])brojac++;
		else {nniz[g]=niz[i];g++;nniz[g]=brojac;g++;brojac=1; }
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0;i<g;i++)
		printf("%d ",nniz[i]);
	
	return 0;
}
