#include <stdio.h>
int main() {
	int i,j,n,br;
	char mat[20][20];
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while (n<1 || n>10) {printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	}
	for(i=0; i<20; i++){
	 for(j=0; j<20; j++){
	  mat[i][j]=' ';
	 	}
	}
	for(br=0;br<n;br++){
		printf("Unesite %d. tacku: ", br+1);
		scanf("%d", &i);
		scanf("%d", &j);
		while((i<0 || i>19)||(j<0 || j>19)) 
		{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", br+1);
			scanf("%d", &i);
			scanf("%d", &j);
		}
	mat[i][j]='*'; 
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", mat[j][i]);
		}
		printf("\n");
}
return 0;
}