#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
    int i,j,p,q,br=0,max_ponavljanja=0,izbaci=matrica[0][0],min_vrijednost=matrica[0][0];
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            for(p=0; p<visina; p++) {
                for(q=0; q<sirina; q++) {
                    if(matrica[i][j]==matrica[p][q]) br++;
                }
            }
            if(br>max_ponavljanja) {
                max_ponavljanja=br;
                min_vrijednost=matrica[i][j];
                izbaci=matrica[i][j];
            } else if(br==max_ponavljanja) if(matrica[i][j]<min_vrijednost) izbaci=matrica[i][j];
            br=0;
        }
    }
    return izbaci;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina,int N)
{
    int i,j,p,q,k=0;
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            if(matrica[i][j]==N) {
                for(p=0; p<visina; p++) {
                    for(q=j; q<sirina; q++) {
                        if(q==99) matrica[p][q]=0;
                        else matrica[p][q]=matrica[p][q+1];
                    }
                }
                sirina--;
                j--;
            }
        }
    }
    k=sirina;
    return k;
}
int main()
{
    int mat[100][100]= {0},i,j,sirina,visina,k=0;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d%d",&sirina,&visina);
    for(i=0; i<visina; i++) {
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0; j<sirina; j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
    while(sirina>1) {
        izbaci_kolone(mat,visina,sirina,max(mat,visina,sirina));
        sirina=izbaci_kolone(mat,visina,sirina,max(mat,visina,sirina));
        if(sirina==0) break;
        printf("Nakon %d. prolaza matrica glasi:\n",k+1);
        for(i=0; i<visina; i++) {
            for(j=0; j<sirina; j++) {
                printf("%5d",mat[i][j]);
            }
            printf("\n");
        }

        k++;
    }
    printf("Nakon %d. prolaza matrica je prazna!",k+1);

    return 0;
}