#include <stdio.h>
#include <math.h>

int max(int matrica[100][100], int visina, int sirina){
    int i, j, a, b, c, h, br1[10000]={0}, br2[10000]={0};
    for(i=0; i<visina; i++)
    for(j=0; j<sirina; j++){
        if(matrica[i][j]>=0)
        br1[matrica[i][j]]++;
        else if(matrica[i][j]<0){
            matrica[i][j]=fabs(matrica[i][j]);
            br2[matrica[i][j]]++;
        }
    }
     a=matrica[0][0];
    for(i=0; i<visina; i++)
    for(j=0; j<sirina; j++)
    if(fabs(matrica[i][j])>a) 
    a=fabs(matrica[i][j]);
    
    b=br1[0]; j=h=0; c=br2[0];
    for(i=1; i<=a; i++){
    if(br1[i]>b){ b=br1[i]; j=i;}
    else if(br1[i]==b){
        if(i>j) b=br1[j];
        else{ b=br1[i]; j=i;}
    }
    if(br2[i]>c){ c=br2[i]; h=i;}
    else if(br2[i]==c){
    if(i>h){ c=br2[i]; h=i;}
    else c=br2[h];
    }
}
if(b>c) return j;
else return (-1)*h;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
    int i, j, h1, h2;
    
    for(i=0; i<visina; i++)
    for(j=0; j<sirina; j++)
    if(matrica[i][j]==N){
        for(h1=0; h1<visina; h1++)
        for(h2=j; h2<sirina-1; h2++)
        matrica[h1][h2]=matrica[h1][h2+1];
        sirina--; i--; break;
    }    
    return sirina;
}

int main(){
    int matrica[100][100]={{0},{0}}, i, j, sirina, visina, a, h;
 
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d %d", &sirina, &visina);
    
    for(i=0; i<visina; i++){
        printf("Unesite elemente %d. reda: ", 1+i);
    for(j=0; j<sirina; j++)
        scanf("%d ", &matrica[i][j]);
    }
    a=sirina;
    for(i=0; i<a; i++){
        sirina=izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
        if(sirina!=0){
        printf("\nNakon %d. prolaza matrica glasi:\n", i+1);
        for(j=0; j<visina; j++){
        for(h=0; h<sirina; h++)
            printf("%5d", matrica[j][h]);
            printf("\n");
        }}
        else{ printf("\nNakon %d. prolaza matrica je prazna!", i+1); break;}
    }
    return 0;
    }


