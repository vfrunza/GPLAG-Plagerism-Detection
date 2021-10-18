#include <stdio.h>
#define MAX 10

int main() {
	
    int tacke[MAX][2], n, i, j, k, l;
    int mat[20][20], pret=0;
    
    for(;;) {
        printf("Unesite broj tacaka: ");
        scanf("%d", &n);
        if(n>0 && n<11) break;
        else printf("Pogresan unos\n");
    }
    
    for(i=0; i<n; i++) {
        printf("Unesite %d. tacku: ", i+1);
        for(j=0; j<2; j++) {
            scanf("%d", &tacke[i][j]);
            if(tacke[i][j]<0 || tacke[i][j]>19) pret=1;
        }
        if(pret==1) {
            pret=0;
            printf("Pogresan unos\n");
            i--;
        
        }
        
    }
    
    
    for(k=0; k<20; k++) {
        for(l=0; l<20; l++) {
            mat[l][k]=0;
        }
    }
    
    for(k=0; k<20; k++) {
        for(l=0; l<20; l++) {
            for(i=0; i<n; i++) {
                if(tacke[i][0]==l && tacke[i][1]==k)  {
                    mat[l][k]=1;
                    break;}
            }
        }
    }
    
    for(k=0; k<20; k++) {
        for(l=0; l<20; l++) {
            if (mat[l][k]==1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    
	return 0;
}
