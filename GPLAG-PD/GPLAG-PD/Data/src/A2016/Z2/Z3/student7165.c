#include <stdio.h>
int main() {
	int broj_tacaka;
	int i,j;
	int k=0;
	int matrica[20][20]={5};
	int unos[10][2];
	int n=0;
	
	for(; ;){
		printf("Unesite broj tacaka: ");
		scanf("%d",&broj_tacaka);
		if(broj_tacaka<=10 && broj_tacaka>0) break;
		if(broj_tacaka>10 || broj_tacaka<=0);
		{
			printf("Pogresan unos\n");
		}
		
	}

	for(i=0;i<broj_tacaka;i++){
	for(j=0;j<1;j++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&unos[j][i],&unos[j][i+1]);
		if(unos[j][i]>19 || unos[j][i+1]>19 || unos[j][i]<0 || unos[j][i+1]<0){
			printf("Pogresan unos\n");
			i--;
		}
	else	{matrica[unos[j][i]][unos[j][i+1]]=2;}
	}
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(matrica[j][i]==2) printf("*");
			else printf(" ");
		}
	
		printf("\n"); 
	}	
	
		
	
	return 0;
}
