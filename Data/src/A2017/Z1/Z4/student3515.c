#include <stdio.h>

int main() {
	int m,n,l,i,j;
	do {
		printf("Unesite broj redova: ");
	  	scanf("%d",&m);
	}while(m<=0 || m>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&l);
	}while (l<=0 || l>10);
	do{ 
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&n);
	} while(n<=0 ||n>10 );
	for (i=1;i<2*m+2;i++){
		if(i%2==1){
		for(j=1;j<l*n+l+2;j++){
			if(j%(n+1)==1)
				printf("+");
			else 
				printf("-");	
		}
	}else for(j=1;j<n*l+l+2;j++){
		if(j%(n+1)==1)	
			printf("|");
		else
			printf(" ");
	}
	printf("\n");
		
	}
	
	return 0;
}
