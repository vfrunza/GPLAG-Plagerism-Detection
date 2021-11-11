#include<stdio.h>
int pomocna(int broj,int niz[],int vel){
    int *p=niz;
    int a=0;
    while(p<niz+vel){
        if(*p==broj){
            a=1;
            break;
        }
        p++;
    }
    return a;
}
int izbaci_cifre(int niz1[],int vel1,int niz2[],int vel2){
    int *p=niz1;
    int *q=niz2;
    int k=1,i,j,m,novibroj=0,true=1,negativan=0;
    
    while(q<vel2+niz2){
        if(*q<0 || *q>9) true=0;
        q++;
    }
    q=niz2;
    for(i=0;i<vel2;i++){
        for(j=i+1;j<vel2;j++){
            if(niz2[i]==niz2[j]) true=0;
        }
    }
    
    while(p<niz1+vel1){
        if(*p<0){
            negativan=1;
            *p=(*p)*(-1);
        }
        while(*p!=0){
            i=(*p)%10;
            m=pomocna(i,niz2,vel2);
            if(m){
                *p/=10;
            }else{
                novibroj+=i*k;
                k*=10;
                *p/=10;
            }
        }
        if(negativan==1){
            novibroj=novibroj*-1;
        }
        negativan=0;
        *p=novibroj;
        p++;
        k=1;
        novibroj=0;
    }
    return true;
}
int main(){
   return 0;
}