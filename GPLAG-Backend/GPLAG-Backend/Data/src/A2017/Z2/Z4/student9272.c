#include <stdio.h>

int main() {
	
		int matrica[3][100][100]={{{0}}},i=0,j=0,k=0,m=0,n=0,temp,a=0,pamti=1,niz[3][10000]={{0}};
		
		
		do {
		    printf("Unesite brojeve M i N: ");
		    scanf("%d %d",&m,&n);
		} while (m>100 || n>100);
		printf("Unesite clanove matrice A: ");
		while (i<m) {
		    for(j=0;j<n;j++)
		    scanf("%d",&matrica[0][i][j]);
		    i++;
		}
        printf("Unesite clanove matrice B: ");
        i=0;
        while (i<m) {
            for (j=0;j<n;j++)
            scanf("%d",&matrica[1][i][j]);
            i++;
        }
        
        printf("Unesite clanove matrice C: ");
        i=0;
        while (i<m) {
            for (j=0;j<n;j++)
            scanf("%d",&matrica[2][i][j]);
        i++;
        }
        while(k<3) { /*Ubacivanje matrica u niz */
            for(i=0;i<m;i++) {
                j=0;
                while(j<n) {
                niz[k][i*m+j] = matrica[k][i][j++];
                }
            }
        if(m>n) a=m*m;
        else a=n*n;
        i=0;
        while (i<a) { /*sortiranje nizaova */
            for(j=i;j<a;j++){
            if (niz[k][i]>niz[k][j]) {
                temp = niz[k][i];
                niz[k][i] = niz[k][j];
                niz[k][j]=temp;
            }}
            i++;
        }
        k++;
        }
        for (i=0;i<a;i++) {
            if(niz[1][i]!=niz[0][i] || niz[0][i]!= niz[2][i]) {
                pamti = 0;
                break;
            }}
            if(pamti)
            printf("DA\n");
            else printf("NE\n");
            return 0;
        }