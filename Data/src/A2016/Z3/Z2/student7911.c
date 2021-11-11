#include <stdio.h>
#include <stdlib.h>
void ubaci(int niz[], int n){
    int i, j, suma, novi;
    for(i=0; i<2*n; i+=2)
    {
        for(j=2*n-1; j>i+1; j--)
            niz[j]=niz[j-1];
        novi=abs(niz[i]);
        suma=0; 
        while(novi!=0)
        {
            suma+=novi%10;
            novi/=10;
        }
        niz[i+1]=suma;
    }
    
}

int izbaci(int niz[], int n){
    int i = 2, j;
    long int fibonacci[50]={1,2};
    while(i<50){
        fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
        i++;
    }
    
    for(i=0; i<n; i++){
        for(j=0; j<50; j++){
            if(niz[i]==fibonacci[j]){
                for(j=i; j<n-1; j++)
                    niz[j]=niz[j+1];
                
                i--;
                n--;
                break;
            }
        else if(niz[i]<fibonacci[j])
                break;
        }
    
    }
    return n;
}
int main(){
    int niz[20]={0}, i, n;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++){
        scanf("%d", &niz[i]);
    }
    ubaci(niz,10);
    n=izbaci(niz,20);
    
    printf("Modificirani niz glasi: ");
    for(i=0; i<n; i++){
        if(i<n-1) printf("%d, ",niz[i]);
        else printf("%d.",niz[i]);
    }
    return 0;
}