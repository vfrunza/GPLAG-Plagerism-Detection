#include <stdio.h>
#define SIRINA 20
#define VISINA 20
int main() {
    char mat[SIRINA][VISINA];
    int n,i,j,ks=20;
    int x1,y1;
    do{
    	printf("Unesite broj tacaka: ");
    	scanf("%d",&n);
    	if(n<1 || n>10){
    		printf("Pogresan unos\n");
    }
    }while(n<1 || n>10);
    	for(i=0;i<ks;i++){
    		for(j=0;j<ks;j++){
    			mat[i][j]=' ';
    		}
    	}
    
    for(j=1;j<=n;j++){
    	do{
    		printf("Unesite %d. tacku: ",j);
    		scanf("%d %d",&x1,&y1);
    		if(x1<0 || y1<0 || x1>19 || y1>19){
    			printf("Pogresan unos\n");
    		}
    }while(x1<0 || y1<0 || x1>19 || y1>19 );
    mat[x1][y1]='*';
    	}
    for(i=0;i<ks;i++){
    	for(j=0;j<ks;j++){
    	printf("%c",mat[j][i]);
    	}printf("\n");
    }
    
	return 0;
}
