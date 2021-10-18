#include <stdio.h>

int main(){
	
	int i, j, k, a, b, c;
	
	do{
		
	printf("Unesite broj redova: ");
	scanf("%d", &a);
	}while(a<=0 || a>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &b);
	}while(b<=0 || b>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &c);
	}while(c<=0 || c>10);
	
	for(i=0; i<=(a*2); i++){
		
		for(j=0; j<b; j++){
			
			if(i%2==1){
				
				printf("|");
				
		for(k=0; k<c; k++){
					
				printf(" ");
		}
		}else if(i%2==0){
					
				printf("+");
		for(k=0; k<c; k++)
						
				printf("-");
					
		}		
	
	}
	if(i%2==0)
	
	printf("+\n");
	
	else if(i%2==1)
	printf("|\n");
}
 
return 0;
	
}
