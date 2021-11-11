#include <stdio.h>

int main() {
	int   mat[20][20]={0}, i, n=11, j, x, y, k=0;
	while(n<=0|| n>10){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10)
			printf("Pogresan unos\n");
	}

for(k=0; k<n; k++){
	printf("Unesite %d. tacku: ", k+1);
	scanf("%d %d", &x, &y);
	if(x>-1 && x<20 && y>-1 && y<20)
	mat[x][y]=1;
	else{
	printf("Pogresan unos\n");
	k--;
	}
}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
				if(mat[j][i]!=0)
				printf("*");
				else printf(" ");
				
			}
			printf("\n");
		}
	return 0;
}