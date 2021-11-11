#include <stdio.h>
#include <math.h>

int provjera(int cifre[], int vel){
    int i, j;
    for(i=0; i<vel; i++){
        if(cifre[i]<0 || cifre[i]>9) return 0;
        for(j=i+1; j<vel; j++){
            if(cifre[i]==cifre[j]) return 0;
        }
    }
    
    return 1;
}

int obrni(int x){
    int novi=0;
    while(x!=0){
        novi=novi*10 + x%10;
        x/=10;
    }
    return novi;
}
int izbaci_cifre(int niz[], int velniz, int cifre[], int velcifre){
    int i, j, novi, temp, cifra, test=0;
    if(provjera(cifre, velcifre)==0) return 0;
    else {
        for(i=0; i<velniz; i++){
            novi=0;
            temp=fabs(niz[i]);
            while(temp!=0){
                cifra=temp%10;
                for(j=0; j<velcifre; j++){
                    test=0;
                    if(cifre[j]==cifra){
                        test++;
                        break;
                    }
                }
                 if(test>0){
                        temp/=10;
                        continue;
                    }
                    else{
                        novi=novi*10 + cifra;
                     temp/=10;
                    } 
            }
            if(niz[i]<0) niz[i]=-obrni(novi);
            else niz[i]=obrni(novi);
        }
        return 1;
    }
}
int main(){
    
    return 0;
}