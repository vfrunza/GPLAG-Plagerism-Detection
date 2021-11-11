#include <stdio.h>

int main() {
	int red,kolona,sirina;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&red);
	}while (red>10 || red<=0);
	
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&kolona);
	}while (kolona>10 || kolona<=0);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf ("%d", &sirina);
	}while (sirina>10 || sirina<=0);
	
	int i,j,k;
	for(k=0;k<=red;k++){
		for(i=0;i<=kolona;i++){
			printf("+");
			if(i==kolona) break;
			for(j=1;j<=sirina;j++){
				printf("-");
			}
		} 
		printf("\n");
		if(k==red) break;
		for(j=0;j<=kolona;j++){
					printf("|");
			for (i=1;i<=sirina;i++){
				printf(" ");
			}
		}printf("\n");	
		
	}
	
	return 0;
}
