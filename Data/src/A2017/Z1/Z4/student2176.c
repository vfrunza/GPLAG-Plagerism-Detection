#include <stdio.h>

int main() {
	int r=0,k=0,sk=0,i=0,j=0,n=0;
	do{
		printf("Unesite broj redova: ");
		scanf("%d",&r);
	  }while(r<=0 || r>10);
	  
	 do{
	 	printf("Unesite broj kolona: ");
	 	scanf("%d",&k);
	 } while(k<=0 || k>10);
	 
	 do{
	 	printf("Unesite sirinu jedne kolone: ");
	 	scanf("%d",&sk);
	 }while(sk<=0 || sk>10);
	 
	 for(i=0;i<r*2+1;++i){
	 	for(j=0;j<=k;++j){
	 	(i%2==0)?printf("+"):printf("|");
	 		for(n=0;n<sk;++n){
	 		if(j==k) break;
	 		(i%2==0)?printf("-"):printf(" ");
	 	}
	 	}
	 	printf("\n");
	 }
	return 0;
}
