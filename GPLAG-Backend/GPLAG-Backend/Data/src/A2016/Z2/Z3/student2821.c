#include <stdio.h>
#include <math.h>
int main() {
	int mat[20][20]={0};
	int r,k,i,j,br,n;
	br=1;
do {
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>10 || n<=0)printf("Pogresan unos\n");}
while(n>10 || n<=0);
	while(br<n+1){
		printf("Unesite %d. tacku: ",br);
		scanf("%d %d",&r, &k); 
		if (r<0 || r>=20 || k<0 || k>=20 ){printf("Pogresan unos\n");}
		else { br++; 
		mat[k][r]=1;}
		}  
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				if(mat[i][j]==1) printf("*");
				else printf(" ");
			} printf("\n");
		}
	return 0;
}
