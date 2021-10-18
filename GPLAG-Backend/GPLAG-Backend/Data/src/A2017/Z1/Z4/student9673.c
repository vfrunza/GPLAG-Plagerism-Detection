#include <stdio.h>

int main() {
	
	int red,kolona,sirina;
	int n,i,j,k,l,m,p;
	
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	}	while (red<=0 || red>10);
	
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &kolona);
	}	while(kolona<=0 || kolona>10);
	
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	}	while(sirina<=0 || sirina>10);
	
	
	
		for(n=0;n<red;n++){
		
	for(i=0;i<kolona;i++){
		printf("+");
		
		for(j=0;j<sirina;j++)
		printf("-");
	}
	printf("+\n");
	for(k=0;k<kolona;k++) {
		printf("|");
	for(l=0;l<sirina;l++) 
	printf(" ");
	}
	printf("|\n");
		}
	for(m=0;m<kolona;m++){
		printf("+");
		
		for(p=0;p<sirina;p++){
		printf("-");}
	}
	printf("+");
		
	
	return 0;
}
