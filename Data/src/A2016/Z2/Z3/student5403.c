#include <stdio.h>

int main() {
	
	int a[10],b[10],n,i,j,k;
	char matrica[20][20];
	
	/*Provjera uslova*/
	
	do {
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>10 || n<=0)
	 printf("Pogresan unos\n");
	 continue;

    } while(n>10 || n<=0);
	
   /*Ispis praznog mjesta*/
   for(k=0;k<20;k++){
   	for(j=0;j<20;j++){
   		matrica[k][j]=' ';
   	}
   }	
   
  /*Ispis zvjezdica*/
   for(i=0;i<n;i++){
   	printf("Unesite %d. tacku: ", i+1);
   	scanf("%d %d", &a[i], &b[i]);
   	if (a[i]<0 || a[i]>19 || b[i]<0 || b[i]>19){
   		printf("Pogresan unos\n");
   		i--;
   		continue;
   	}
   	matrica[a[i]][b[i]]='*';
   }	
	
  /*Ispis matrice*/
   
	for(k=0;k<20;k++){
		for(j=0;j<20;j++){
			printf("%c",matrica[j][k]);
		}
		printf("\n");
	}
	return 0;
}
