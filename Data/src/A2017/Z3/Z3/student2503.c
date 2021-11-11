#include <stdio.h>
#include <math.h>

int izbaci_cifre(int brojevi [] , int b, int cifre[], int c) {
    int i=0, j=0, x=0, pomocni[10]={0}, p=0, k=0, T=0;
    
    for(i=0; i<c; i++)
    if(cifre[i]<0 || cifre[i]>9) return 0;
    
    for(i=0; i<c-1; i++)
    for(j=i+1; j<c; j++)
    if(cifre[i]==cifre[j]) return 0;
    
    for(i=0; i<c; i++)
    for(j=0; j<b; j++) {
        if(brojevi[j]<0) T=1; 
        x=fabs(brojevi[j]);
        while(x!=0){
            if(x%10!=cifre[i]) { pomocni[p]=x%10; p++; }
            x/=10;
        }
        if(p==0) brojevi[j]=0;
        else {
            brojevi[j]=0;
           for(k=p-1;k>=0;k--) 
           brojevi[j]+=pomocni[k]*pow(10,k);
           if(T) brojevi[j]*=(-1);
        }
        p=0;
        T=0;
    }
    return 1;
}
int main() {
    return 0;
}