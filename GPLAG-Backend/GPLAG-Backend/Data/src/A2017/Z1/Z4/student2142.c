#include <stdio.h>

int main() {
	int i,j,r,k,brk;
	do{
		printf("Unesite broj redova: ");
		scanf("%d",&r);
	}while(r<=0 || r>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
	}while(k<=0 || k>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&brk);
	}while(brk<=0 || brk>10);
	for(i=0;i<=r*2;i++){
		for(j=0;j<=k*(brk+1);j++){
			if(i%2==0 && j%(brk+1)==0)
				printf("+");
			else if(j%(brk+1)==0 && i%2!=0)
				printf("|");
			else if(i%2==0)
				printf("-");
			else	
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
