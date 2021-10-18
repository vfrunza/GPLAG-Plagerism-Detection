#include <stdio.h>

int main() {
	int nizx[10],nizy[10],n,i,j,jel=0,k;
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
    while(n<=0 || n>10){
    	printf("Pogresan unos\n");
    	printf("Unesite broj tacaka: ");
    	scanf("%d",&n);
    }
	for(i=0;i<n;i++){
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d%d",&nizx[i],&nizy[i]);
			if(nizx[i]<0 || nizx[i]>19 || nizy[i]<0 || nizy[i]>19){
				printf("Pogresan unos\n");
				i--;
			}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			jel=0;
			for(k=0;k<n;k++){
				if(nizy[k]==i && nizx[k]==j){
					jel=1;
					printf("*");
					break;
				}
				
			}
		if(jel==0)	printf(" ");
		}
		printf("\n");
	}
	
		
	
	return 0;
}
