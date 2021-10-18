#include <stdio.h>

int main() {
	int br_redova,br_kolona,sirina_kolone,i=0,j=0,brojac1=0,brojac2=0,brojac3=0;
	
	//Unos podataka sa eventualnim ponavljanjem
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&br_redova);}
	while(br_redova<=0 || br_redova>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&br_kolona);
	}while(br_kolona<=0 || br_kolona>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina_kolone);}
		while(sirina_kolone<=0 || sirina_kolone>10);
		
		//Ispitivanje uslova i ispis na ekran
		for(i=0;i<(2*br_redova)+1;i++){
			for(j=0;j<(sirina_kolone*br_kolona+br_kolona+1);j++){
				if((i%2!=0) && (j==brojac1*(sirina_kolone+1)))
				{
					printf("|");
					brojac1++;
				}
			else if (i%2!=0 && j!=(brojac2*(sirina_kolone+1))){
			printf(" ");
			brojac2++;
			}
			else if(j==brojac3*(sirina_kolone+1) && i%2==0)
			{printf("+");
			brojac3++;
			}
			else printf("-");
		}
		brojac1=0;
		brojac2=0;
		brojac3=0;
		printf("\n");
	}
	return 0;
}
