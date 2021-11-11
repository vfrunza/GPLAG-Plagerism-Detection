#include <stdio.h>

int main() {
	int i,j,k,r,ko,s;
	
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &r);
	}while(r<=0||r>10);
	
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &ko);
	}while(r<=0||r>10);
	
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &s);
	}while(r<=0||r>10);
		
		for(i=0;i<r+r+1;i++) 
		{
			if(i%2==0)
			{ 
				printf("+");
				for(j=0;j<ko;j++)
				{
					for(k=0;k<s;k++) printf("-");
				printf("+");
				}
			}
			else {
				printf("|");
				for(j=0;j<ko;j++)
				{
					for(k=0;k<s;k++) printf(" ");
					printf("|");
				}
				
			}
			 printf("\n");
	
	
		}
		
		
	return 0;
}
