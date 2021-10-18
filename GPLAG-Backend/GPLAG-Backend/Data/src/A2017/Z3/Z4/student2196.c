#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
    int el[10000], br[10000],i, j, max=0, maxbr, x=-1, t=1;
    for(i=0; i<visina*sirina; i++){
        br[i]=0;
    }
    for(i=0; i<visina; i++){
        for(j=0; j<sirina; j++){
            el[j+sirina*i]=matrica[i][j];
        }
    }
    for(i=0; i<visina*sirina; i++){
        x++;
        t=1;
        if(i>0){
            for(j=i-1; j>=0; j--){
                if(el[i]==el[j]){
                    t=0; 
                    break;
                }
            }
        }
        if(t==0) continue;
        else{
            for(j=i; j<visina*sirina; j++){
                if(el[i]==el[j]) br[x]++;
            }
        }
    }
    max=el[0];
    for(i=0; i<visina*sirina; i++){
        if(el[i]>max) max=el[i];
    }
    maxbr=br[0];
    for(i=0; i<visina*sirina; i++){
        if(br[i]>maxbr) maxbr=br[i];
    }
    for(i=0; i<visina*sirina; i++){
        if(br[i]==maxbr && el[i]<=max) max=el[i];
    }
    return max; 
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int max){
    int i, j, kol, t=1, k;
    for(j=0; j<sirina; j++){
        t=1;
        for(i=0; i<visina; i++){
            if(matrica[i][j]==max){
                kol=j; 
                t=0; 
                break;
            }
        }
        if(t==0){
            for(i=0; i<visina; i++){
                for(k=kol; k<sirina; k++){
                    matrica[i][k]=matrica[i][k+1];
                }
            }
            j--;
            sirina--;
        }
    }
    return sirina;
}

int main() {
    int a[100][100], i, j, v, s, p=0, n;
   do{
        printf("Unesite sirinu i visinu matrice: ");
        scanf("%d %d", &s, &v);
    } while(s<0 || s>100 || v<0 || v>100);
    for(i=0; i<v; i++){
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<s; j++){
            scanf("%d", &a[i][j]);
        }
    }
    while(s>0){
        p++;
        n=max(a,v,s);
        s=izbaci_kolone(a,v,s,n);
        if(s>0){
            printf("\nNakon %d. prolaza matrica glasi:\n", p);
            for(i=0; i<v; i++){
                for(j=0; j<s; j++){
                    printf("%5d", a[i][j]);
                }
                printf("\n");
            }
        }
        else  printf("\nNakon %d. prolaza matrica je prazna!", p);
        
    }
   
	return 0;
}
