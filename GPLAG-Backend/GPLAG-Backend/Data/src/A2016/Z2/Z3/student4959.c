#include <stdio.h>
#include <math.h>
int main() {
	int mat[20][20]={0},x,y,i,j,n;
	t:
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<=0 || n>10){ printf("Pogresan unos \n");
	goto t;
	}
	for(i=0;i<n;i++){
	    
	    printf("Unesite %d. tacku: ",i+1);
	    scanf("%d %d",&x, &y);
	    while(x>19 || y>19 || x<0 || y<0){
	    	printf("Pogresan unos\nUnesite %d. tacku: ",i+1);
	    	scanf("%d %d", &x, &y);
	    }
		mat[y][x]++;
	}
	for(i=0;i<20;i++)
	{ for(j=0;j<20;j++){
		if(mat[i][j]==0) printf(" ");
		else printf("*");
	}
	printf("\n");
	}
	
	return 0;
}
