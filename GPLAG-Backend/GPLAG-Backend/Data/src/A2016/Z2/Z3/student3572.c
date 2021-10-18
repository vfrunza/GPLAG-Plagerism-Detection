#include <stdio.h>

int main() {
	int i,j,n,k,osaX[20],osaY[20];
	char matrica[20][20];
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0||n>10)
	printf("Pogresan unos\n");
	}
	while(n<=0||n>10);
	
	for(k=0;k<n;k++){
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d %d", &osaX[k], &osaY[k]);
		while ((osaX[k]<0 || osaX[k]>19) || (osaY[k]<0 || osaY[k]>19)){
		printf("Pogresan unos\n");
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d %d", &osaX[k], &osaY[k]);
		}
		
	}
	
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			matrica[i][j]=' ';
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(i==osaY[k] && j==osaX[k])
			matrica[i][j]='*'; 
			
		}
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", matrica[i][j]);
		}
		printf("\n");	
	}
	
	
		
		
		
	return 0;
		}

	

