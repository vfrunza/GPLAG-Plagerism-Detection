#include <stdio.h>

int main() {
	int n,m,i,j;
             for(i=0;i<1;i++){
    	printf("Unesite broj n: ");
    	scanf("%d",&n);
    	if(n<=0 || n>50){
    		printf("Pogresan unos\n");
    		i--;
    	 }
    	}
    	
    m=(n-1)*4;
    if(n==1){
    	printf("**");
    }
	for (i=0;i<n;i++) {
		for (j=0;j<=m;j++) {
			if(i==j && j<=n-1) {
				printf ("*"); 
				}
		else if (j==(n-1)*2-i && j<=(n-1)*2 && j>(n-1)) { 
			printf ("*");
		}
		else if (j==(n-1)*2+i && j<=(n-1)*3 && j>(n-1)*2) {
			printf ("*");
		}
		else if (j==m-i && j<=m && j>(n-1)*3) {
			printf ("*");
		}
		else printf (" ");
	} printf ("\n");
	}
	return 0;
}
