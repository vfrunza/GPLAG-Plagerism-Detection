#include <stdio.h>
#include <math.h>
int fibonaccijev_broj(int n) {
    int niz[100000]={1,1},i,fib=0;
    for(i=2; i<100000; ++i)
        niz[i]=niz[i-1]+niz[i-2];
    for(i=1; i<100000; ++i) {
        if(niz[i]==n) {
            fib=1;
            break;
        }
    }
    return fib;
}
int sumica(int a) {
    int sumica=0;
    double b;
    for(;;) {
        b=a;
        sumica+=a%10;
        b/=10;
        a=(int)b;
        if(fabs(b)<1) 
            break;
    }
    sumica=fabs(sumica);
    return sumica;
}
void ubaci(int a[], int p) {
    int i,j=0,niz[100];
    for(i=0; i<p; ++i) {
        niz[i]=a[i];
    }
    for(i=0; i<p*2; i++) {
        a[i]=0;
    }
    for(i=0; i<p*2; ++i) {
        if(i%2==0)
            a[i]=niz[j];
        else {
            a[i]=sumica(niz[j]);
            j++;
        }
    }
}
int izbaci(int niz[], int n) {
    int i,j,p=n;
    for(i=0; i<n; ++i) {
        if(fibonaccijev_broj(niz[i])==1) {
            if(p==1) {
                p=0;
                break;
            }
            else {
                for(j=i; j<n-1; ++j) {
                    niz[j]=niz[j+1];
                }
                p--;
                i--;
                n--;
            }
        }
    }
    return p;
}
int main() {
    int n,i,niz[20];
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; ++i) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz,10);
    n=izbaci(niz,20);
    if(n>0) {
        printf("Modificirani niz glasi: ");
        for(i=0; i<n-1; ++i) {
            printf("%d, ", niz[i]);
        }
        printf("%d.", niz[n-1]);
    }    
    return 0;
}