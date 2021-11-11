#include <stdio.h>
int main() {
	
	int m, n, i, j, k, g, h, redovi=1, kolonice=1, heh[200][200]={0};
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m>200 || n>200 || m<=0 || n<=0)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m>200 || n>200 || m<0 || n<0);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; ++i) {
		for(j=0; j<n; ++j) {
			scanf("%d", &heh[i][j]);
		}
	}
	if(m!=1) {
    	for(i=0; i<m; i++) {
        	for(j=i+1; j<m; ++j) {
        		redovi=1;
        		for(k=0; k<n; ++k) {
        			if(heh[i][k]!=heh[j][k]) {
        				redovi=0;
        				break;
        			}
        		}
        		if(redovi==1) {
        			if(m==2) {
        				m--;
        				j=m;
        				break;
        			}
        			if(j==m-1) {
        				m--;
        				break;
        			}
        			for(g=j; g<m; g++) {
        				for(h=0; h<n; ++h) {
        					heh[g][h]=heh[g+1][h];
        				}
        			m--;
        			j--;
        			}
        		}
        	}
    	}
	}
    if(n!=1) {
    	for(i=0; i<n; ++i) {
    		for(j=i+1; j<n; ++j) {
    			kolonice=1;
    			for(k=0; k<m; ++k) {
    				if(heh[k][i]!=heh[k][j]) {
    					kolonice=0;
    					break;
    				}
    			}
    			if(kolonice==1) {
    				if(j==n-1) {
    					n--;
    					break;
    				}
    				for(g=j; g<n-2; ++g) {
    					for(h=0; h<m; ++h) {
    						heh[h][g]=heh[h][g+2];
    					}
    					if(m!=1)
    						j--;
    					n--;
    					if(m==1)
    						n--;
    				}
    			}
    		}
    	}
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<m; ++i) {
    	for(j=0; j<n; ++j) {
    		printf("%5d", heh[i][j]);
    	}
    	printf("\n");
    }
    return 0;
}