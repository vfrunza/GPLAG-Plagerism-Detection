#include <stdio.h>

int main() {
	int a,b,c,i,j,k;

	
	printf("Unesite broj redova: ");
	 
	    scanf("%d",&a);
	    printf("Unesite broj kolona: ");
	    scanf("%d,",&b);
	
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&c);
		
	
     
	
	for(i=0;i<a;i++){
		
			
			for(j=0;j<b;j++){
				printf("+");
			
				for(k=0;k<c;k++){
					printf("-");
			}
		}
		printf("+\n");
	
	
	
		for(j=0;j<b;j++){
			printf("|");
			
			for(k=0;k<c;k++){
			    printf(" ");
			}
		}
		printf("|\n");
	
	for(j=0;j<b;j++){
		printf("+");
		
		for(k=0;k<c;k++){
			printf("-");
		}
	}
	
}
	return 0;
}
