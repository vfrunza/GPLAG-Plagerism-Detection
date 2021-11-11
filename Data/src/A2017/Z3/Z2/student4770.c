#include<stdio.h>
void zaokruzi1(float* niz,int vel){
    float *p=niz;
    while (p<niz+vel) {
        if(*p>=0){
        *p *=10;
        *p =(int)(*p+0.5);
        *p++ /=10;
    }else{
        *p *=10;
        *p =(int)(*p-0.5);
        *p++ /=10;
        }
    }
}
int suma(int broj){
    int suma=0;
    while(broj!=0){
        suma+=broj%10;
        broj/=10;
    }
    return suma;
}
void preslozi(float *niz, int vel, int k){
    float *p=niz;
    int a=0,temp=0,sum=0;
    float *q=niz;
    float *m=niz; float *l=niz;
    zaokruzi1(niz,vel);
    while(p<niz+vel){
        *p *=10;
        p++;
    }
    p=niz;
    while(p<niz+vel){
        if(*p<0) a=*p*(-1);
        else a=*p;
        sum=suma(a);
        if(sum>=k){
           temp=*p;
            m=p;
            while(m>q){
                *m=*(m-1);
                m--;
            }
            *l=temp;
            l++;
            q=l;
        }
        sum=0;
        p++;
    }
    p=niz;
    while(p<niz+vel){
        *p /=10;
        p++;
    }
}
int main(){
    return 0;
}