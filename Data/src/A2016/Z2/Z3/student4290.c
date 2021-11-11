#include <stdio.h>

int main() {
	char sistem[20][20];
	int n,i,j;
	int x[10];
	int y[10];
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			sistem[i][j]=' ';
		}
	}
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while((n<0)||(n>10)){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	}
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
		while((x[i]<0)||(y[i]<0)||(x[i]>19)||(y[i]>19)){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x[i],&y[i]);
		}
	}
	for(i=0;i<n;i++){
			sistem[y[i]][x[i]]='*';
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",sistem[i][j]);
		}
		printf("\n");
	}
	return 0;
}
