#include <stdio.h>

int main() {
	
	int red,kolona,sirina,i,j;
	
	printf("Unesite broj redova: ");
	scanf("%d",&red);
   
   
   do {
 	if(red>0 && red<=10)break;
 	printf("Unesite broj redova: ");
	scanf("%d",&red);
 }while(red<=0 || red>10);
   
   
    printf("Unesite broj kolona: ");
	scanf("%d",&kolona);
   
   do {
 	if(kolona>0 &&kolona<=10)break;
 	printf("Unesite broj kolona: ");
	scanf("%d",&kolona);
 }while(kolona<=0 || kolona>10);
    
    printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);


do {
 	if(sirina>0 && sirina<=10)break;
 	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);
 }while(sirina<=0 || sirina>10);



for(i=0;i<(red*2+1);i++){
	for(j=0;j<(kolona*sirina+kolona+1);j++){
		
		if(i%2==0 && (j==0 || j%(sirina+1)==0))printf("+");
		else if(i%2==0 && j>0 && j%(sirina+1)!=0)printf("-");
		else if(i%2!=0 && (j==0 || j%(sirina+1)==0))printf("|");
		else printf(" ");
		
		
	}
printf("\n"); 
}
	


	return 0;
}
