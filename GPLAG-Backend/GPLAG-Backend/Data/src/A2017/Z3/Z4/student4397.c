#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
    int i,j,k,p;
    int brojaci[10001]={0};
    for(i=0;i<visina;i++) {
        for(j=0;j<sirina;j++) {
            for(p=0;p<=visina*sirina;p++) {
                if(matrica[i][j]==p) brojaci[p]++;
                }
        }
    }
    int maxi=0;    
    for (k=0;k<=sirina*visina;k++) {
        if(brojaci[k]>brojaci[maxi]) {
            maxi=k;
        }
    }
    return maxi;
    }

int izbaci_kolone(int matrica[100][100], int sirina, int visina, int N) {
    int broj_kolona=sirina;
    int i,j,k,s,p,q;
    
    for(i=0;i<visina;i++) {
        for(j=0;j<sirina;j++) {
            if(matrica[i][j]==N) {
               for(k=0;k<visina;k++) {
                   for(s=j;s<sirina-1;s++) {
                       matrica[k][s]=matrica[k][s+1];
                   }
               }
               broj_kolona--;
            }
        }
    }
    return broj_kolona;
}
int main() {
    int a,b,mat[100][100];
    int i,j,p,q,x;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &a,&b);
        for (i=0;i<b;i++) {
            printf("Unesite elemente %d. reda: ", i+1);
                for(j=0;j<a;j++) {
                    scanf("%d", &mat[i][j]);
                }
        }
    
return 0;
}



    