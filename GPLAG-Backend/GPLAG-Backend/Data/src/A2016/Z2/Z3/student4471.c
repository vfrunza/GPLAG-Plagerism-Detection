#include <stdio.h>

int main(){
	
	int x[10];
	int y[10];
    int niz[20][20] = {0};
    int i,j,n;
    
    do{
    printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    if(n<=0 || n>10){
    	printf("Pogresan unos\n");
    }
    }while(n<=0 || n>10);
    
    
    for(i=0;i<n;i++){
    	printf("Unesite %d. tacku: ",i+1);
    	scanf("%d %d",&y[i],&x[i]);
    	if((x[i]<0 || x[i]>19) || (y[i]<0 || y[i]>19)){
    		printf("Pogresan unos\n");
    		i--;
    	}else{
    	niz[ x[i] ][ y[i] ] = 1;
    	}
    }
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
		if(niz[i][j]==1){
			printf("*");
		}else printf(" ");
	}
	
	printf("\n");
	}
	return 0 ;
}










































