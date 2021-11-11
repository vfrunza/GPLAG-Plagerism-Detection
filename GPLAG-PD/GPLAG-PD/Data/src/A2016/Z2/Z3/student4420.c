#include <stdio.h>

int main(){
  int bkt,i,j,ktacke;
  char niz[20][20];
 printf("Unesite broj tacaka: ");
 scanf("%d",&bkt);
 while(bkt<1||bkt>10){
 	printf("Pogresan unos\n");
 	printf("Unesite broj tacaka: ");
 	scanf("%d",&bkt);}
       for(i=0;i<20;i++){
 	       for(j=0;j<20;j++){
 		niz[i][j] =' ';
 			}
 }
 	for(ktacke=0;ktacke<bkt;ktacke++){
 		printf("Unesite %d. tacku: ",ktacke+1);
 		scanf("%d %d",&i,&j);
 		while(i<0||j<0||i>19||j>19){
 			printf("Pogresan unos\n");
 			printf("Unesite %d. tacku: ",ktacke+1);
 			scanf("%d %d",&i,&j);}
 			niz[i][j]='*';
 	}
 	for(i=0;i<20;i++){
 		for(j=0;j<20;j++){
 			printf("%c",niz[j][i]);
 	}
 	printf("\n");}
 	return 0;
 }





