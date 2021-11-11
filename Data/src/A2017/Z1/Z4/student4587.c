#include <stdio.h>

int main() {
	int n,k,sk,i,j,m;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&n);
		
	} while((n<1) || (n>10));
	 
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
	} while((k<1) || (k>10));
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sk);
	} while((sk<1) || (sk>10));
	

	for(i=0;i<n;i++){   
			
		for(j=0;j<k;j++) {           
		printf("+"); 
		for (m=0;m<sk;m++)
		printf("-");
		
				} 
				printf("+");          
			printf("\n");
		
		for(j=0;j<k;j++){        
	printf("|");
	for(m=0;m<sk;m++)
	printf(" ");
	
			}
			printf("|");           
			printf("\n");
	}
	
	for(j=0;j<k;j++){         
		printf("+");
		for(m=0;m<sk;m++)
		printf("-");
		
	}
	
	printf("+");           
	return 0; 
	}