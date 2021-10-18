#include <stdio.h>

int main() {
    int Broj_redova=0 , Broj_kolona=0 , sirina=0;
    int i,j,k;
    do{
    	printf("Unesite broj redova : ");
    	scanf("%d",&Broj_redova);
    } while (Broj_redova<=0 || Broj_redova>10);
     do{
    	printf("Unesite broj kolona : ");
    	scanf("%d",&Broj_kolona);
    } while (Broj_kolona<=0 || Broj_kolona>10);
     do{
    	printf("Unesite sirinu jedne kolone : ");
    	scanf("%d",&sirina);
    } while (sirina<=0 || sirina>10);
    for(i=0;i<Broj_redova*2+1;i++)
    {
    	for (j=0;j<Broj_kolona;j++)
	{if (i%2==0) 
	printf("+");
	else 
	printf("|");
	for(k=1;k<=sirina;k++)
	{
		if(i%2==0)
		printf("-");
		else 
		printf(" ");
	}
		
	}
	if(i%2==0)
	printf("+\n");
	else printf("|\n");
	}

	return 0;
}
