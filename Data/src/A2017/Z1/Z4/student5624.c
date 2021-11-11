#include <stdio.h>

int main() {

	int i,j,k,l;
	int br_redova, br_kolona,sirina_kolone;

do{ 
	printf("Unesite broj redova: ");
	scanf("%d",&br_redova);
	
} while(br_redova<=0 || br_redova>10);


do{
	printf("Unesite broj kolona: ");
	scanf("%d",&br_kolona);
}while(br_kolona<=0 || br_kolona>10);


do{ 
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina_kolone);
} while(sirina_kolone<=0 || sirina_kolone>10);
	
	for(i=0;i<br_redova*2+1;i++){
		if(i%2==0){
			for(j=0;j<br_kolona;j++){
				printf("+");
				for(k=0;k<sirina_kolone;k++){
					printf("-");
				}
			}
			printf("+\n");}
		else {
			for(j=0;j<br_kolona;j++){
				printf("|");
				for(l=0;l<sirina_kolone;l++)
					printf(" ");
			}
			printf("|\n");
		}
	}
	return 0;
}
