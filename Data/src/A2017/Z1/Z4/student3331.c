#include <stdio.h>

int main() {
	
	int i,j,k,brr,brk,brs;
	
	printf("Unesite broj redova: \n");
	scanf("%d",&brr);
	printf("Unesite broj kolona: \n");
	scanf("%d",&brk);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&brs);
	
	for(i=1;i<=brr;i++){
		for(j=1;j<=brk;j++){
		
			
				if((i==1&&j==1)||(i==1&&j==brs+1)||(i==brr-i&&j==brs+1)) printf("+");
				else printf("-");
			if((i==1&&j==1)||(i==1&&j==brs+1)||(i==brr-i&&j==brs+1)) printf("\n|");
			
				
		}
		
		
	}



	return 0;
}
