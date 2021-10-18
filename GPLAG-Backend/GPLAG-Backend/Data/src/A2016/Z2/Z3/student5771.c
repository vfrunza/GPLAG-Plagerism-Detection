#include <stdio.h>

int main() {
	printf("Unesite broj tacaka: ");
	int b,i,j,l,n,a;
	int mat[20][20]={'0'};
	do{
	scanf("%d", &b);
		if(b>10 || b<0 || b==0){ printf("Pogresan unos\n"); 	printf("Unesite broj tacaka: ");}
	}
	while(b<0 || b==0 || b>10);
	for(i=0; i<b; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a, &n); if(a<0 || a>19 || n<0 || n>19) {printf("Pogresan unos\n"); i--;}
	else {mat[n][a]='1';}}
for(l=0; l<20; l++){
	for(j=0; j<20; j++){
	
			if(mat[l][j]=='1')printf("*"); else printf(" ");
		
	
	}
	printf("\n");
}
		

	return 0;
}
