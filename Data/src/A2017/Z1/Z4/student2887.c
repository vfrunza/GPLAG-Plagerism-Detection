#include <stdio.h>

int main() {
	int i,j,r=0;
	int m,n,k;
	printf("Unesite broj redova: ");
	scanf("%d",&m);
	do{
		if(m<=0 || m>10){
		printf("Unesite broj redova: ");
		scanf("%d",&m);
		}
	}while(m<=0 || m>10);
	printf("Unesite broj kolona: ");
	scanf("%d",&n);
	do{
		if(n<=0 || n>10){
		printf("Unesite broj kolona: ");
		scanf("%d",&n);
		}
	}while(n<=0 || n>10);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&k);
	do{
		if(k<=0 || k>10){
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&k);
		}
	}while(k<=0 || k>10);
	
	for(i=0;i<(2*m+1);i++){
		for(j=0;j<((n*k)+n+1);j++){
			if(i%2==0){
				if(j==0 || r==k){
					printf("+");
					r=0;
				}else{
					printf("-");
					r++;
				}
			}else{
				if(j==0 || r==k){
					printf("|");
					r=0;
				}else{
					printf(" ");
					r++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
