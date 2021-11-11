#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define m 20
#define n 200
void ubaci (int*B, int b){
int i, *p=B, b1, *a=B, suma=0, br;
b1=(b)-1;
for(i=b1; i>0; i--){
    *(p+(2*i))=*(p+i);
}
p=B;
for(i=1; i<2*b; i+=2){
    br=*a;
    suma=0;
    while(br!=0){
        suma+=(br)%10;
        br=br/10;
    }
    *(p+i)=(abs)(suma);
    a+=2;
}
}
int fib(int x){
    int f[n], i;
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(i=3; i<n; i++){
        f[i]=f[i-1]+f[i-2];
    }
    for(i=0; i<n; i++){
        if(x==f[i]) return 1;
    }
    return 0;
}
int izbaci(int*B, int b){
    int*p=B, i, j, *a;
    for(i=0; i<b; i++){
        a=p;
        if(fib(*p) == 1){
            for(j=i; j<b-1; j++){
                *a=*(a+1);
                a++;
            }
            *p--;
            b--;
            i--;
        }
       *p++; 
    }
    return b;
}

int main(){
    int B[m];
    int i, b=0, br;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++){
        scanf("%d", &B[i]);
        b++;
    }
    ubaci(B, b);
    b=b*2;
    br=izbaci(B, b);
    printf("Modificirani niz glasi: ");
    for(i=0; i<br; i++){
        if(i==br-1) printf("%d.", B[i]);
        else printf("%d, ", B[i]);
    }
    return 0;
}
