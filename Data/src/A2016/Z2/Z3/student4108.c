#include <stdio.h>

int main() {
	int br,i,j,mat[20][20]= {{0}},x,y;
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &br);
		if (br<1 || br>10) {
			printf("Pogresan unos\n");
		}
		
	}  while (br<1 || br>10);
	
	
	i=	1;
	do{
	
	printf("Unesite %d. tacku: ",i);
	scanf("%d,%d", &x, &y);
	if(x<0 || x>19 || y<0 || y>19) {
		printf("pogresan unos\n");
	}else {
		mat[y][x]=1;
		i++;
	}
	}
	
	
	
	while (i<br+1);
	
	
	for(i=0;i<20;i++){
		for(j=0; j<20;j++) {
			if(mat[i][j]==0) {
				printf(" ");
			}else {printf("*");}
		}
		
		printf("\n");
	
	}
	
	
		return 0;
}
	
	
	
	
	
	
	
