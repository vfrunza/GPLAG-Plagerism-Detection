#include <stdio.h>

int main() {
	char m[20][20];
	int n1[20],n2[20],i,n,k,j;
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<1 || n>10)
		printf("Pogresan unos\n");
	}while(n<1 || n>10);

for (j = 0; j < 20; j++) {
    			for (k = 0; k < 20; k++) {
    				m[j][k] = ' ';
    			}
    		}

for(i=0 ; i<n ; i++) {
				do {
				printf("Unesite %d. tacku: ",i+1);
    			scanf("%d %d",&n1[i],&n2[i]);
    			if(n1[i]<0 || n1[i]>19 ||  n2[i]<0 ||  n2[i]>19) printf("Pogresan unos\n");
		
		
				} while(n1[i]<0 || n1[i]>19 ||  n2[i]<0 ||  n2[i]>19);
    	}


    	
    	
    	for (i = 0; i < n; i++) {
    		for (j = 0; j < 20; j++) {
    			for (k = 0; k < 20; k++) {
    				if (k == n1[i] && j == n2[i]) m[j][k] = '*';
    			}
    		}
    	}
    	
    	for (j = 0; j < 20; j++) {
    			for (k = 0; k < 20; k++) {
    				printf ("%c", m[j][k]);
    			}
    			printf ("\n");
    		}
    	
    
	return 0;
}
