#include <stdio.h>

int main() {
	char mat[20][20]={" "};
	int i,j,k,n,a,b;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n>10 || n<=0) printf("Pogresan unos\n");
	} while(n>10 || n<=0);
    for(i=0; i<n; i++){
    	do{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&a,&b);
		if(a>19 || a<0 || b>19 || b<0) printf("Pogresan unos\n");
    	} while(a>19 || a<0 || b>19 || b<0);
		for(j=0; j<20; j++){
			if(j==a){
			for(k=0; k<20; k++)
			{
				if(k==b) mat[k][j]='*';
			}
		}
	}
    }
	for(i=0; i<20; i++){
		for(j=0; j<20; j++)
		{
			if(mat[i][j]=='*') printf("%c",mat[i][j]);
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}
