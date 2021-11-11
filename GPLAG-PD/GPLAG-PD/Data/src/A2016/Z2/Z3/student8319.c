#include <stdio.h>

int main(){
	
	int n,i,j,l;
	int niz[10],niz2[10];
	
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<1 || n>10){
			printf("Pogresan unos\n");
			
		}
		
	}while(n<1 || n>10);
	
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&niz[i],&niz2[i]);
		if(niz[i]<0 || niz2[i]<0 || niz[i]>19 || niz2[i]>19){
			printf("Pogresan unos\n");
			i--;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			int ispisao=0;
			for(l=0;l<n;l++){
			if(niz[l]==j && niz2[l]==i){
				printf("*");
				ispisao=1;
				break;
				
				
			}
		}
		if(ispisao==0){
		printf(" ");
	}
	
	
}
	printf("\n");
	
	
}
return 0;
}