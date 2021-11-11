#include <stdio.h>

int main() {
	int redovi,kolone,sirina,i,j,brojac,k=0;
	do{
		printf("Unesite broj redova: ");
		scanf("%d",&redovi);
	}while(redovi<=0 || redovi>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&kolone);
	}while(kolone<=0 || kolone>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina);
	}while(sirina<=0 || sirina>10);
	brojac=sirina+1;
	for(i=0;i<(redovi*2)+1;i++){
		for(j=0;j<((kolone*sirina)+(kolone+1));j++){
			if((i%2==0 && j==0)||(i%2==0 && j==brojac)) printf("+");
			if((i%2==0 && j>k && j<brojac)) printf("-");
			if((i%2!=0 && j==0)||(i%2!=0 && j==brojac)) printf("|");
			if(i%2!=0 && j>k && j<brojac) printf(" ");
			if(j==brojac){
			k=k+sirina+1;
			brojac=brojac+sirina+1;	
			}
		}
		brojac=sirina+1;
		k=0;
		printf("\n");
	}
	return 0;
}
