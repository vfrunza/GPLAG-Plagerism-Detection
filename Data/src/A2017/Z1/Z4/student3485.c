#include <stdio.h>

int main() {

	int m, n, l;
	int i,j;
	do{
		printf("Unesite broj redova: ");
		scanf("%d",&n);
	}while(n<=0||n>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&m);
	}while(m<=0||m>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&l);
		
	} while(l<=0||l>10);
	
	
	for(i=0; i<=(n*2); i++)
	{
		for(j=0; j<=(m*l)+m; j++) {
			
			if(i%2==0 && j%(l+1)==0) { printf("+"); }
			else if(i%2!=0 && j%(l+1)==0) { printf("|"); }
			else if(i%2==0 && j%(l+1)!=0) { printf("-"); }
			else printf(" ");
		}
		printf("\n");
	}
	
	
	
	return 0;
}
