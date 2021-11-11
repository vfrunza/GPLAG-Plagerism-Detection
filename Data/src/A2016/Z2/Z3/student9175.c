#include <stdio.h>

int main() {
	char mat[20][20];
	int n,i,j,k;
	int niz1[19],niz2[19];
	
	do{
		printf("Unesite broj tacaka: ");
        scanf("%d",&n);
        
		if(n>20)printf("Pogresan unos");
	}while(n>20);
	

	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=' ';
		}
	}
	
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&niz1[i],&niz2[i]);
		if(niz1[i]>20 || niz2[i]>20){
			i--;
			printf("Pogresan unos");continue;
		}
	}
	
	for(k=0;k<n;k++){
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				if(i==niz2[k]&& j==niz1[k])mat[i][j]='*';
			}
		}
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
