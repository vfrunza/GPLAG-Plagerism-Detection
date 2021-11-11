#include<stdio.h>
int dajZbir(int x){
    int zbir=0;
    if(x<0)
         x*=-1;
    while(x!=0){
        zbir+=x%10;
        x/=10;
    }
    return zbir;
}

void ubaci(int niz[], int duzina){
    int i=0;
    while(i<duzina){
        int j;
        for(j=duzina;j>i+1;j--){
            niz[j]=niz[j-1];
        }
        niz[j]=dajZbir(niz[i]);
        duzina++;
        i+=2;
    }
}

int JeLiFib(int a){
    int suma;
    int x,y,i;
    for(i=0;;i++){
        if(i==0){
            x=0;
            y=1;
            suma=x+y;
        }
        else{
            x=y;
            y=suma;
            suma=x+y;
        }
        if(suma==a) return 1;
        else if(suma!=a && suma>a) return 0;
    }
}

int izbaci(int niz[], int duzina){
    int i=0;
    while(i<duzina){
        if(JeLiFib(niz[i])){
            int j;
            for(j=i;j<duzina-1;j++){
                niz[j]=niz[j+1];
            }
            duzina --;
            i--;
        }
        i++;
    }
    return duzina;
}


int main() {
    int niz[20];
    int x,i;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz, 10);
    x=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0; i<x; i++) {
        if(i!=x-1)
            printf("%d, ", niz[i]);
        else
            printf("%d.", niz[i]);
    }
    return 0;
    }




