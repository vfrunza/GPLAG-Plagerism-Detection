#include <stdio.h>
#include <math.h>

int check(int*veliki,int*mali,int i,int k) {
    int j;
    for(j=0;j<k;j++) {
        if(veliki[i]==mali[j]) return 1;
    }
    return 0;
}

int fib (int x) {
    int g=x,a=0,b=1,c,znak=1;
    while(2) {
        c=a+b;
        if(g==c) break;
        else if (g<c) {
            znak=0;
            break;
        }
        else {
            a=b;
            b=c;
        }
    }
    return znak;
}

int zbir (int x) {
    int i,x1,suma=0;
    if(x<=0) x=fabs(x);
        for(i=1;i<=x;i*=10) {
            x1=(x/i)%10;
            suma+=x1;
        }
    return suma;
}

void ubaci (int* niz, int vel) {
    int prvi[20000],k=0;
    int drugi[20000];
    int*p=niz;
    int*q=drugi;
    int*r=prvi;
    while(p<niz+vel) {
        *q=*p;
        q++;
        p++;
    }
    p=niz;
    while(p<niz+vel) {
        *r=zbir(*p);
        r++;
        p++;
    }
    p=niz;
    q=drugi;
    r=prvi;
    while(p<niz+2*vel) {
        if(k%2==1){
            *p=*r;
            r++;
        }
        else if(k%2==0){
            *p=*q ;
            q++;
        }
        p++;
        k++;
    }
}

int izbaci (int* niz, int vel ) {
    int k=0,i,j;
    int kicked[10000];
    int*q=niz;
    
    while(q<niz+vel) {
            if(fib(*q)==1) {
                kicked[k]=*q;
                k++;
            }
        q++;
    }
    q=niz;
    for(i=0;i<vel;i++) {
        if(check(niz,kicked,i,k)==1) {
            for(j=i;j<vel-1;j++) {
                *(q+j)=*(q+j+1);
            }
            vel--;
            i--;
        }
    }
    return vel;
}

int main() {
    int niz[100];
    int i,k;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++) {
        scanf("%d", &niz[i]);
    }
    ubaci(niz,10);
    k=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0;i<k;i++) {
        if(i==k-1) printf("%d.", niz[k-1]);
        else printf("%d, ", niz[i]);
    }
    return 0;
}
