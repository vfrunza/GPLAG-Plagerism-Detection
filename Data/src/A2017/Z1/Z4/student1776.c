#include <stdio.h>

int main() {
	int red, kolona, sirina, i, j;
	
	
 do{
 printf("Unesite broj redova: ");
 scanf("%d", &red);}
 while(red<1 || red>10);
 do{
 printf("Unesite broj kolona: ");
 scanf("%d", &kolona);}
 while(kolona<1 || kolona>10);
 do{
 printf("Unesite sirinu jedne kolone: ");
 scanf("%d", &sirina);}
  while(sirina<1 || sirina>10);
 
	for(i=0; i<=red*2; i++){
		if(i%2==0){
			for(j=0;j<(sirina+1)*kolona; j++){
				if(j%(sirina+1)==0){
				printf("+");}
				else{
					printf("-");
			}
			}
	}
	if(i%2!=0){
		for(j=0; j<(sirina+1)*kolona; j++){
			if(j%(sirina+1)==0){
				printf("|");
			}
			else{printf(" ");}
		}
	}
	
	if(i%2==0)
	printf("+\n");
	else{
	printf("|\n");
	}
	}
 

	return 0;
}
