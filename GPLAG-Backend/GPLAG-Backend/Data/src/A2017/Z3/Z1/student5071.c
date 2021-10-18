#include <stdio.h>
int dva_od_tri(int A[], int a, int B[], int b, int C[], int c) {
    int brojac=0, i=0, j=0, k=0, T1=0, T2=0;
    for(i=0; i<a-1; i++)
    for(j=i+1; j<a ;j++)
    if(A[i]==A[j]){
        for(k=j;k<a-1;k++)
        A[k]=A[k+1];
        a--;
        j--;
    }
     for(i=0; i<b-1; i++)
    for(j=i+1; j<b ;j++)
    if(B[i]==B[j]){
        for(k=j;k<b-1;k++)
        B[k]=B[k+1];
        b--;
        j--;
    }
     for(i=0; i<c-1; i++)
    for(j=i+1; j<c ;j++)
    if(C[i]==C[j]){
        for(k=j;k<c-1;k++)
        C[k]=C[k+1];
        c--;
        j--;
    }
    for(i=0;i<a;i++){
        for(j=0; j<b; j++)
            if(A[i]==B[j]) {
                T1=1;
                break;
            }
        for(j=0; j<c; j++)
        if(A[i]==C[j]) {
            T2=1;
            break;
        }
        if((T1==1 && T2==1) || (T1==0 && T2==0)) {
            T1=0; T2=0;
        }
        else { 
            T1=0; T2=0;
            brojac++;
    }
    }
    for(i=0; i<b; i++){
        for(j=0; j<c; j++)
        if(B[i]==C[j]){
            T1=1;
            break;
        }
        for(j=0; j<a; j++)
        if(B[i]==A[j]){
            T2=1;
            break;
        }
        if(T1==1 && T2==0) {
            T1=0;
            brojac++;
        }
        else {
            T1=0; T2=0;
        }
    }
    return brojac;
}
int main() {
    return 0;
}