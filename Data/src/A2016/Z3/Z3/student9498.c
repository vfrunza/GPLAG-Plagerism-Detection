#include <stdio.h>

int main() {
    int m, n, j, i, k, mat[200][200]={{0}}, da_li_su_isti=1, brojac=0;
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d%d", &m, &n);
        if(m>200 || m<1 || n>200 ||n<1) printf("Brojevi nisu u trazenom opsegu.\n");
    } while (m>200 || m<1 || n>200 || n<1);
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++) scanf("%d", &mat[i][j]);
        
    for(brojac=0; brojac<m; brojac++) {
        int jedan_red[200];
        for(j=0; j<n; j++) jedan_red[j]=mat[brojac][j];
        for(i=brojac+1; i<m; i++) {
            if(mat[i][0]==jedan_red[0]) {
                for(j=0; j<n; j++) {
                    if(mat[i][j]!=jedan_red[j]) da_li_su_isti=0;
                     }
                }
                else continue;
                if(da_li_su_isti==1) {
                    for(k=i; k<=m-1; k++) {
                        for(j=0; j<n; j++) {
                            mat[k][j]=mat[k+1][j];
                        }
                    }
                    m--; brojac=0;
                }
            
        }
    }
da_li_su_isti=1;
for(brojac=0; brojac<n; brojac++) {
    int jedna_kolona[200];
    for(i=0; i<m; i++) jedna_kolona[i]=mat[i][brojac];
    for(j=brojac+1; j<n; j++) {
        if(mat[0][j]==jedna_kolona[0]) {
            for(i=0; i<m; i++) {
                if(mat[i][j]!=jedna_kolona[i]) da_li_su_isti=0;
                
            }
        }
        else continue;
        if(da_li_su_isti==1) {
            for(i=0; i<m; i++) {
                for(k=j; k<=n-1; k++) {
                    mat[i][k]=mat[i][k+1];
                }
            }
            n--; brojac=0;
        }
    }
}
for(brojac=0; brojac<m; brojac++) {
    int jedan_red[200];
    for(j=0; j<n; j++) jedan_red[j]=mat[brojac][j];
    for(i=brojac+1; i<m; i++) {
        if(mat[i][0]==jedan_red[0]) {
            for(j=0; j<n; j++) if(mat[i][j]!=jedan_red[j]) da_li_su_isti=0;
        }
        else continue;
        if(da_li_su_isti==1) {
            for(k=i; k<=m-1; k++) {
                for(j=0; j<n; j++) {
                    mat[k][j]=mat[k+1][j];
                }
            }
            m--; brojac=0;
        }
    }
}
printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
for(i=0; i<m; i++) {
    for(j=0; j<n; j++) printf("%5d", mat[i][j]);
    printf("\n");
}
return 0;
}