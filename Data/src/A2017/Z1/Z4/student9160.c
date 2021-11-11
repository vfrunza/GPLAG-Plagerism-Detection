#include <stdio.h>

int main() {
	
	int D,D1,H1,H,n,i,j;
	
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&H1);
	
		
	if(H1<=0 || H1>10) continue;
	else break;
	} while (1==1); 
	
		do {
	
	printf("Unesite broj kolona: ");
	scanf("%d",&n);
	
		
	if (n<=0 || n>10) continue;
	else break;
	} while (1==1); 
	
		do{
	
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&D1);
		
	if (D1<=0 || D1>10) continue;
	else break;
	} while (1==1); 
	
	
	D=(n*D1)+n+1;
	H=H1*2+1; 
	

	for(i=0; i<H;i++){
		for(j=0; j<D;j++){
			if( (i==0 && j==0) || (i==0 && j==D-1) || (i==H-1 && j==0) || (i==H-1 && j==D-1)) printf("+");
			else if( (i==0 && j%(D1+1)==0)) printf("+");
			else if( i==H-1 && j%(D1+1)==0)printf("+");
			else if( i%2==0 && j%(D1+1)==0)printf("+"); 
			else if( i==0 || i==H-1 || i%2==0)printf("-");
			else if( j%(D1+1)==0)printf("|");
			else printf(" ");
			
		}printf("\n");
	}
	
	return 0;
}
