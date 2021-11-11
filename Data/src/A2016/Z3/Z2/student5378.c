#include <stdio.h>
int saberi(int x){
    int suma=0,cifra;
    if(x<0) x*=-1;
    while(x!=0){
        cifra=x%10;
        suma+=cifra;
        x=x/10;
    }
    return suma;
}
void ubaci (int niz[],int duz){
    int i,j,cifra;
    for(i=0;i<duz;i++){
        for(j=duz;j>i;j--){
            niz[j]=niz[j-1];
        }
        cifra=saberi(niz[i]);
        if(cifra>0)
        niz[i+1]=cifra;
        i++;
        duz++;
    }
}
int fibonaci(int x){
    int br1=1,br2=1,naredni=1;
    if(x==br1)return 1;
    if(x==1 || x==2 || x==3 || x==5)return 1;
    else {
        while(naredni<=x){
            naredni=br1+br2;
            if(naredni ==x)return 1;
            br1=br2;
            br2=naredni;
        }
    }
    return 0;
    
}
int izbaci(int niz[],int duz){
    int i,j;
    for(i=0;i<duz;i++){
        if(niz[1]!=0){
            if(fibonaci(niz[i])==1){
                for(j=i;j<duz-1;j++){
                    niz[j]=niz[j+1];
                }
                i--; 
                duz--;
            }
        }
    }
    return duz;
}

int main() {
    int i,niz[20],duzina;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++) {
        scanf("%d",&niz[i]);
    }
    ubaci(niz,10);
    duzina=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0;i<duzina-1;i++){
        printf("%d, ",niz[i]);
    }
    printf("%d.",niz[i]);
	return 0;
}