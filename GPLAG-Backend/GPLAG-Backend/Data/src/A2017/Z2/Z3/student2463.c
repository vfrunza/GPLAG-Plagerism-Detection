#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int broj_tacaka;
	int prolaz=1;
	while(prolaz){
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	if(broj_tacaka > 0 && broj_tacaka  <= 10){
	
	 	prolaz=0;
	}
	 else
	 printf("Pogresan unos\n");
	 
	 
	}
	
	int * x = malloc(broj_tacaka * sizeof(int));
	int * y = malloc(broj_tacaka * sizeof(int));
	
	 int i=0;
	 for(i=0;i<broj_tacaka;i++)
	 {
	 	int X,Y; prolaz=1;
	 	while(prolaz){
	 	printf("Unesite %d. tacku: ",i+1);
	 	scanf("%d %d",&X,&Y);
	 	if(X>=0 && X<=19 && Y>=0 && Y<=19)
	 	prolaz=0;
	 	else
	 	printf("Pogresan unos\n");
	 	}
	 	x[i]=X;
	 	y[i]=Y;
	 }
	 
	 
	 int j=0,k=0;
	 
	 for(j=0;j<=20;j++)
	 {
	 	for(k=0;k<=20;k++)
	 	{
	 		int z=0;
	 		for(z=0;z<broj_tacaka;z++)
	 		if(y[z]==j && x[z]==k)
	 		{
	 			printf("*");
	 			k++;
	 			continue;
	 		}
	 		printf(" ");
	 	}
	 	printf("\n");
	 }
	 
	 
	free(x);
	free(y);
	
	return 0;
}
