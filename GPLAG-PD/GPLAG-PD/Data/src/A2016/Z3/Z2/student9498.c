#include <stdio.h>

int suma(int n) {
    int x = 0;
    if (n<0)
    n=-n;
    while (n>0) {
        x+=n%10;
         n/=10;
    }
    return x;
}

int izbaci(int niz[],int vel) {
    int fibernaci[46]={1,1},i=0,j=0,k=0;
    for(i=2;i<46;i++) fibernaci[i] = fibernaci[i-1] + fibernaci[i-2];
    for(i=0;i<vel;i++){
        for(j=1;j<46;j++){
        if(niz[i]==fibernaci[j]){
                for(k=i;k<vel-1;k++)
                niz[k]=niz[k+1];
                vel--;
                i--;
                break;
            }
        }
    }

    return vel;
        }
        void ubaci(int niz[],int vel){
            int i;
            for(i=2*vel-2;i>0;i-=2)
            niz[i]=niz[i/2];
            niz[1]=suma(niz[0]);
        for(i=2*vel-1;i>2;i-=2) niz[i]=suma(niz[i-1]);
        }
        int main() {
            int niz[20],i,velicina=10;
            printf("Unesite niz od 10 brojeva: ");
            for(i=0;i<velicina;i++)scanf("%d",&niz[i]);
            ubaci(niz,velicina);
            velicina=izbaci(niz,2*velicina);
            printf("Modificirani niz glasi: ");
            for(i=0; i<velicina; i++) {
                if(i==velicina-1) printf("%d.",niz[i]);
                else printf("%d, ",niz[i]);
            }
            return 0;
        }