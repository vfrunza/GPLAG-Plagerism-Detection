#include <stdio.h>
#include <math.h>

int max(int matrica[100][100], int visina, int sirina){
    int brojpon[10000]={0};
    int brojponminusa[10000]={0};
    int maxpon=0, i, j;
    int brojkojisemaxpon;
    brojkojisemaxpon=matrica[0][0];
 //   for(i=0;i<10;i++){
 //       brojpon[i]=0;
 //   }
   // pom1=brojpon;
    for(i=0;i<visina;i++){
        for(j=0;j<sirina;j++){
            if(matrica[i][j]>=0) brojpon[matrica[i][j]]++;
            else brojponminusa[(matrica[i][j])*(-1)]++;
        }
    }
    
    for(i=0;i<10000;i++){
        if(brojpon[i]>maxpon){ maxpon=brojpon[i]; brojkojisemaxpon=i;}
        if(brojponminusa[i]>maxpon){ maxpon=brojponminusa[i]; brojkojisemaxpon=i*(-1);}
        if(brojpon[i]==maxpon)
            if(i<brojkojisemaxpon) brojkojisemaxpon=i;
        if(brojponminusa[i]==maxpon)
            if((i*(-1))<brojkojisemaxpon) brojkojisemaxpon=i*(-1);
    }
    
    return brojkojisemaxpon;   
    
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
    int *pok1=&matrica[0][0];
    int *pok=pok1;
    int i, j, m, n;
    
    for(i=0;i<visina;i++){
        for(j=0;j<sirina;j++){
            if(j==0) pok=&matrica[i][j];
            if(matrica[i][j]==N){
                for(m=0;m<visina;m++){
                    for(n=j;n<sirina-1;n++){
                        matrica[m][n]=matrica[m][n+1];
                    }
                }
               // while(pok<pok1+sirina-1){
                //    *pok=*(pok+1);
                //}
                sirina--;
                j--;
            }
        }
    }
    return sirina;
}
int main() {
//	printf("Zadaća 3, Zadatak 4");
    int matrica[100][100];
    int i, j, s, v, x, prolaz=1;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d%d", &s, &v);
    for(i=0;i<v;i++){
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0;j<s;j++){
            scanf("%d", &matrica[i][j]);
        }
    }
    x=izbaci_kolone(matrica,v,s,max(matrica,v,s));
    while(x>1){
        //printf("\nx je %d", x);
        //if(x==1){ printf("Nakon %d. prolaza matrica je prazna!", prolaz); break;}
        printf("\nNakon %d. prolaza matrica glasi:\n", prolaz);
        for(i=0;i<v;i++){
           for(j=0;j<x;j++){
                printf("%5d", matrica[i][j]);
        }
        printf("\n");
    }
    x=izbaci_kolone(matrica,v,x,max(matrica,v,x));
    prolaz++;
    }
    if(x==1){ //mora se razloziti u dva jer nakon jedinice dolazi veci broj pa da je samo >= onda bi odobravalo i za brojeve iza 1
        printf("\nNakon %d. prolaza matrica glasi:\n", prolaz);
        for(i=0;i<v;i++){
           for(j=0;j<x;j++){
                printf("%5d", matrica[i][j]);
        }
        printf("\n");
    }
    prolaz++;
    }
    printf("\nNakon %d. prolaza matrica je prazna!", prolaz);
    return 0;
}
    


