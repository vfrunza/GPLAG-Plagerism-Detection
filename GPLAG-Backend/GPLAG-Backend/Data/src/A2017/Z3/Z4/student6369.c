#include <stdio.h>
#include <stdlib.h>

int izbaci_kolone(int mat[100][100],int visina,int sirina, int N){
int i,j,k,l;
    for(i=0;i<visina;i++){
        for(j=0;j<sirina;j++){
    
         if(mat[i][j]==N){
                for(k=0;k<visina;k++)    
                    for(l=j+1;l<sirina;l++)
                        mat[k][l-1]=mat[k][l];
             sirina--;
             j--;
            }
        }
    }
    return sirina;
}


int max(int matrica[100][100],int visina,int sirina)
{
    int i,j,brojac,k,l,broj=matrica[0][0],maxi=0;
    for(i = 0; i < visina; i++)
    {
        for(j = 0; j < sirina; j++)
        {
            brojac = 0;
            for(k = 0; k < visina; k++)
                for(l = 0; l < sirina; l++)
                    if(matrica[i][j] == matrica[k][l]){
                        brojac++;
                    }
            
           
            
            if(brojac>maxi){
                maxi=brojac;
                broj=matrica[i][j];
                }
            else if(brojac==maxi){
                if(matrica[i][j]<broj){
                        broj=matrica[i][j];
                }
            }
        }
    }
    return broj;
}
int main()
{
    int mat[100][100];
    int i, j, sirina, visina,br=1;

    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d",&sirina);
    scanf("%d",&visina);
    for(i=0;i<visina;i++){

        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0;j<sirina;j++){
        scanf("%d", &mat[i][j]);
        }
    }

    do{
        sirina=izbaci_kolone(mat,visina,sirina,max(mat,visina,sirina));
        if(sirina==0)
             break;
        printf("\nNakon %d. prolaza matrica glasi: \n",br); 
        for(i=0;i<visina;i++){
            for(j=0;j<sirina;j++)
                printf("%5d",mat[i][j]);
            printf("\n");
        }
        br++;
    }while(sirina>0);

    printf("\nNakon %d. prolaza matrica je prazna!\n",br);

    return 0;
}
