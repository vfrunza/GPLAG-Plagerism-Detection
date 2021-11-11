#include <stdio.h>

int main() {
	int n=0,i=0,j=0,k=0,tackapostoji=0;
	int x[10];
	int y[10];
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1 || n>10){printf("Pogresan unos\n");}
	}while(n<1 || n>10);
	
	for(i=0;i<n;i++){
	
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19){
			printf("Pogresan unos\n");
			i--;
		}
		
		
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			
			for(k=0;k<n;k++){
				if(i==y[k] && j==x[k]){
					printf("*");
					tackapostoji=1;
					break;
				}
			}
			if(tackapostoji==0){printf(" ");}else {tackapostoji=0;}
			
		}
		printf("\n");
	}
	
	return 0;
}
