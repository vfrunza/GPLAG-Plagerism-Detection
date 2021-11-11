#include <stdio.h>

int main() {
	int i,j,k,broj_redova,broj_kolona,sirnia_jedne_kolone;
	printf("Unesi broj redova:");
	scanf("%d",&broj_redova);
	printf("Unesi broj kolona:");
	scanf("%d",&broj_kolona);
	printf("Unesite sirinu jedne kolone:");
	scanf("%d",&sirnia_jedne_kolone);
	
	for(i=0;i<broj_redova;i++){
		for(j=0;j<broj_kolona;j++){
			for(k=0;k<sirnia_jedne_kolone;k++){
				if(k==1) printf("/");
			}
			if(j==3) printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
