#include <stdio.h>
#include <stdlib.h>
#define eps 0.000001;

float* zaokruzi1(float* niz, int velicina){
    int i, broj;
    for(i=0; i<velicina; i++){
        if(niz[i]>0){
            broj=niz[i]*10+0.5;
            niz[i]=(float)broj/10;
        }
        else{
            broj=niz[i]*10-0.5;
            niz[i]=(float)broj/10;
        }
    }
    return niz;
}

float* preslozi(float* niz, int velicina, int k){
    float broj, temp;
    float suma=0;
    int pomocni, cifra, i, j, index=0;
    zaokruzi1(niz, velicina);
    for(i=0; i<velicina; i++){
        broj=niz[i];
        broj*=10;
        pomocni=broj;
        while(1){
            if(pomocni==0) break;
            cifra=abs(pomocni%10);
            suma+=cifra;
            pomocni=pomocni/10;
        }
        temp=niz[i];
        if(suma>=k){
            for(j=i; j>index; j--){
                niz[j]=niz[j-1];
            }
            niz[index]=temp;
            index++;
        }
        suma=0;
    }
    return niz;
}

int main() {
int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}