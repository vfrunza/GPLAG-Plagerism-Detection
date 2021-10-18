#include<stdio.h>
#include<stdlib.h>
int max(int matrica[100][100], int visina, int sirina)
{
    int brojac_svakog_clana[10000]={},i,j,max_element_matrice,max_broj_ponavljanja=1,vrati=0,brojac_svakog_negativnog_clana[10000]={},temp;
    max_element_matrice=matrica[0][0];
    for (i=0;i<visina;i++){
        for(j=0;j<sirina;j++){
            if (matrica[i][j]>=0)
            brojac_svakog_clana[matrica[i][j]]++;
            else {
                temp=abs(matrica[i][j]);
                brojac_svakog_negativnog_clana[temp]++;
            }
            if(matrica[i][j]>max_element_matrice) max_element_matrice=matrica[i][j];
            
        }
    }
    for (i=0;i<max_element_matrice;i++){
        if (brojac_svakog_clana[i]>max_broj_ponavljanja){ 
            if(brojac_svakog_negativnog_clana[i]>brojac_svakog_clana[i]){
            max_broj_ponavljanja=brojac_svakog_negativnog_clana[i];
            vrati=i*(-1);
            }
            else{
                max_broj_ponavljanja=brojac_svakog_clana[i];
                vrati=i;
            }
            
        }
        if (brojac_svakog_clana[i]==max_broj_ponavljanja){
            if (i<vrati){
            if (brojac_svakog_negativnog_clana[i]>brojac_svakog_clana[i]) {max_broj_ponavljanja=brojac_svakog_negativnog_clana[i];
            vrati=i*(-1);
            }
            else if(brojac_svakog_negativnog_clana[i]==brojac_svakog_clana[i]){
                vrati=-1*i;
            }
            else vrati=i;
            }
            
        }
    }
    return vrati;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
    int i,j,temp,k,l;
  
    for (i=0;i<visina;i++){
        for (j=0;j<sirina;j++){
            if (matrica[i][j]==n){
                for(k=0;k<visina;k++){
                    for (l=j;l<sirina-1;l++){
                        matrica[k][l]=matrica[k][l+1];
                    }
                }
                j--;
                sirina--;
            } 
        }
    }
    return sirina;
}
int main()
{
    int matrica[100][100],i,j,sirina,visina,broj_izbacivanja=0;
    printf("Unesite sirinu i visinu matrice:");
    scanf("%d %d",&sirina,&visina);
    for (i=0;i<visina;i++){
        printf("Unesite elemente %d. reda:",i+1);
        for(j=0;j<sirina;j++)
        scanf("%d",&matrica[i][j]);
    }
    sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
    broj_izbacivanja++;
 while (sirina!=1){
     printf("Nakon %d. izbacivanja matrica glasi:",broj_izbacivanja);
     for (i=0;i<visina;i++){
         for (j=0;j<sirina;j++){
             printf("   %d",matrica[i][j]);
         }
         printf("\n");
     }
     sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
     broj_izbacivanja++;
 }
 printf("Nakon %d. izbacivanja matrica glasi: ",broj_izbacivanja);
     for (i=0;i<visina;i++){
         for (j=0;j<sirina;j++){
             printf("   %d",matrica[i][j]);
         }
         printf("\n");
     }
     printf("Nakon %d. izbacivanja matrica je prazna!",broj_izbacivanja+1);
    return 0;
}