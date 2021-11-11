#include <stdio.h>

int main() {
	
	int n,i,j,x[10],y[10],k,razmax=0,bake;
	printf("Unesite broj tacaka: ");

	do{
		
		scanf("%d",&n);
		if(n<0||n>10){
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
		}
		continue;
	} while(n<0||n>10);
	
	
	for(i=0;i<n;i++){
	
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &x[i],&y[i]);
			if((x[i]<0||x[i]>10)||(y[i]<0||y[i]>10)){
				printf("Pogresan unos\n");
				printf("Unesite %d. tacku:", i+1);
				continue;
			}
		} 
		
		for(i=0;i<20;i++) {
			for(j=0;j<20;j++){
				for(k=0;k<n;k++){
					if(j==x[k] && i==y[k]){
					printf("*");
					razmax=1;
					break;
					}
				}
					if(razmax==0)
						printf(" ");
					else
						razmax=0;
				}
			
		printf("\n");
		}
	
	return 0;
}
