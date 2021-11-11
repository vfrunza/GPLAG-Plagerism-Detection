#include <stdio.h>

int main() {
	int x[10],y[10];
	int m=0,i=0,j=0;
	char n[20][20];
	printf("Unesite broj tacaka: ");
	scanf("%d",&m);
	while(m<=0 || m>10){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&m);
	}
	for(i=0;i<m;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
		while(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) {
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x[i],&y[i]);
		}
	}
	
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			n[i][j]=' ';
		}
	}
	
	for(i=0;i<m;i++){
			n[y[i]][x[i]]='*';
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",n[i][j]);
		}
		printf("\n");
	}
	return 0;
}
