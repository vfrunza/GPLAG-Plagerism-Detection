#include <stdio.h>
#include <stdlib.h>

int cifre(int i) {
    int suma=0;
    if(i!=0) {
    do {
      i=abs(i);
      suma=suma+(i%10);
      i=i/10;
    }while(i!=0);
}
return suma;
}

int fibonaci(int a) {
    int temp;
    int temp1=1, temp2=1;
    if(a==1) {
        return 1;
    }
    do {
        temp=temp1+temp2;
        if(temp==a) return 1;
        if(temp>a) return 0;
        temp1=temp2;
        temp2=temp;
    }while(1);
}

void ubaci(int *niz, int duzina) {
    int i;
    int a=0;
    int niz1[20];
    int niz2[20];
    
    for(i=0; i<duzina; i++) {
        niz1[i]=cifre(niz[i]);
    }
    for(i=0; i<duzina*2; i+=2){
        niz2[i]=niz[a];
        niz2[i+1]=niz1[a];
        a++;
        if(a==duzina) {
            break;
        }
    }
    for(i=0; i<duzina*2; i++) {
        niz[i]=niz2[i];
    }
}

int izbaci(int *niz, int duzina) {
        int a, b;
        int c;
        
        for(a=0; a<duzina; a++) {
            c=fibonaci(niz[a]);
            if(c) {
                for(b=a; b<duzina-1; b++) {
                    niz[b]=niz[b+1];
                }
                duzina--;
                a--;
            }
        }
        return duzina;
}


int main() {
    int niz[20];
    int i;
    int temp;
    
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
        scanf("%d", &niz[i]);
    }
    
    ubaci(niz, 10);
    temp=izbaci(niz, 20);
    
    printf("Modificirani niz glasi: ");
    printf("%d", niz[0]);
    for(i=1; i<temp; i++) {
        printf(", %d", niz[i]);
    }
    
    printf(".");
    return 0;
}