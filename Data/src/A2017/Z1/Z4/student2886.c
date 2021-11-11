#include <stdio.h>

int main() {
	int r,k,s,i,j,p,q,w;
	do{
			printf("Unesite broj redova: ");
		scanf("%d",&r); 
		}while( r<=0 || r>10 );
		do{
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
		}while(k<=0 || k>10);
		do{
			printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s);
		}while(s<=0 || s>10);

	
	for(p=0;p<r;p++){
		
	for(i=k;i>=0;i--){
		printf("+");
		if(i==0)
		break;
		for(j=s;j>0;j--){
			printf("-");
		}
	}
	printf("\n");
	 for(q=k;q>=0;q--){
	 	printf("|");
	 	if(q==0)
	 	break;
	 	for(w=s;w>0;w--){
	 		printf(" ");
	 	}
	 }
	printf("\n");
	
	}
	
	for(i=k;i>=0;i--){
		printf("+");
		if(i==0)
		break;
		for(j=s;j>0;j--){
			printf("-");
			if(j==0)
			break; }
	}
	
	return 0;
}
