#include <stdio.h>

int main() {
	int i, j, k, red, kolona, sk;      /*sk-sirina jedne kolone*/
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	}
		while(red<=0 || red>10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &kolona);
	}
	
	while(kolona<=0 || kolona>10);
	
	do{
		
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);
	}
	
	
	while(sk<=0 || sk>10);
	
	
	
for(i=0; i<2*red+1; i++){
		for(j=0; j<2*kolona+1; j++){
			if(j%2==0){
				if(i%2==0)
				printf("+");
				else if (i%2==1)
				printf("|");
			}
			
				
			else {
				
			
			for(k=0; k<sk; k++){
			 	if(i%2==0)
				printf("-");
				else
				printf(" ");
			}
				}
			
			
			
			
			
		
		}
		printf("\n");
		
	} 

	
	
	
	








	return 0;
}
