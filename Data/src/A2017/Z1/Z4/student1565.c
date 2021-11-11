#include <stdio.h>

int main() {
	int BR,BK,SK;
	do {
		
		printf("Unesite broj redova: ");
		scanf("%d", &BR);
	}while(BR<=0 || BR>10);
		do {
		
		printf("Unesite broj kolona: ");
		scanf("%d", &BK);
	}while(BK<=0 || BK>10);
		do {
		
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &SK);
	}while(SK<=0 || SK>10);
	int i,j;
		for(i=0;i<2*BR+1;i++)
		{
			for( j=0;j<BK*(SK+1)+1;j++){
				if(i%2==0){
					if(j%(SK+1)==0)
					printf("+");
					else printf("-");
				}
				else{
					if(j%(SK+1)==0)
					printf("|");
					else printf(" ");
				}
			}
			printf("\n");
		}
	
	return 0;
}
