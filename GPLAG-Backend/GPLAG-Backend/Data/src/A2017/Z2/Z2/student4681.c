#include <stdio.h>

int main() {
    int A[100]={0}, B[100],C[100], i,j, vel, kol=0, in=0,nu, size,count=0,qw=0;
    
    printf("Unesite velicinu niza: ");
    scanf("%d", &vel);
    printf("Unesite clanove niza: ");
    for(i=0;i<vel;i++) {
        scanf("%d", &A[i]);
    }
    for(i=vel-1;i>=0;i--){
        nu = A[i];
        while(nu>0) {
            size = nu%10;
         //   printf("%d ", size);
          //  printf("%d\n", count);
            C[count] = size;
            nu/=10;
            count++;
        }
        
    }
    nu=0;
    for(i=count-1;i>=0;i--) {
        A[nu] = C[i];
     //  printf("%d ", A[nu]);
        nu++;
    }
    printf("Finalni niz glasi:\n");
    for(i=0;i<nu;i++) {
        if(!qw) {
        for(j=0;j<nu;j++) {
            if(A[i]==A[i+j]){
               kol++;
               if(nu==kol || nu==i+j) {
                  if(nu==i+j) {
                      kol--;
                  } else  if(nu==kol) {
                   qw=1;
                  }
                   B[in]=A[i];
                   B[in+1] = kol;
                   in+=2;
                   i+=kol-1;
                   kol=0;
                   break;
               }
            } else if (A[i] != A[i+j]) {
                B[in]=A[i];
                B[in+1]=kol;
                in+=2;
                i+=kol-1;
                kol=0;
                break;
            }
        }
        } else {
            break;
        }
    }
    for(i=0;i<in;i++) {
        printf("%d ", B[i]);
    }
    return 0;
}