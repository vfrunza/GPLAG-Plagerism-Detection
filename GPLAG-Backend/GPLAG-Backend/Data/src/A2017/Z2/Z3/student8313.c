#include <stdio.h>

int main() {
    double ma[100][100], mb[100][100], temp;
    int i, j, sa, va, sb, vb, gr;
    
    sa = 0;
    sb = 0;
    va = 0;
    vb = 0;
    gr = 0;
    
    do{
	    printf("Unesite sirinu i visinu matrice A: ");
        scanf("%d %d", &sa, &va);
    } while (sa > 100 || sa < 1 || va > 100 || va < 1);

    
    printf("Unesite clanove matrice A: ");
    for(i=0; i<va; i++){
        for(j=0; j<sa; j++) {
    	scanf("%lf", &ma[i][j]);
        }
    }
    
    do{
	    printf("Unesite sirinu i visinu matrice B: ");
        scanf("%d %d", &sb, &vb);
    } while (sb > 100 || sb < 1 || vb > 100 || vb < 1);

    printf("Unesite clanove matrice B: ");
    for(i=0; i<vb; i++){
        for(j=0; j<sb; j++){
    	scanf("%lf", &mb[i][j]);
        }
    }

    
    for(i=0; i<va; i++){
     for(j=(i+1); j<sa; j++){
         temp = ma[i][j];
         ma[i][j] = ma[j][i];
         ma[j][i] = temp;
     }
    } 
    
    
    for(i=0; i<va; i++){
        for(j=0; j<(sa/2); j++){
            temp = ma[i][j];
            ma[i][j] = ma[i][sa - 1 -j];
            ma[i][sa - 1 -j] = temp;
        }
    }
    
    for(i=0; i<va; i++){
        for(j=0; j<sa; j++){
            if(ma[i][j] == mb[i][j]) gr++;
            if(ma[i][j] != mb[i][j]) {
                printf("NE");
                return 1;
            }
        }
    }
    
    if(gr == (va*sa) || gr == (vb*sb)) printf("DA");
    
    
	return 0;
}
