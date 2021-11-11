#include <stdio.h>
#include <math.h>

    int izbaciti_iz_niza(int *niz, int vel, int x){
        int i,l;
        for(i=0;i<vel;i++){
            if(niz[i]==x){
                for(l=i;l<vel-1;l++) niz[l]=niz[l+1];
                vel--;
                i--;
            }
        }
        
        return vel;
    }

    int izbaciti(int x, int *cifre, int vel){
        int minus=0;
        int i;
        int k=0;
        int pomniz[10];
        if(x<0) {
            minus=1;
            x=-x;
        }
        if(x==0) return 0;
        
        while(x!=0){
            pomniz[k]=x%10;
            x/=10;
            k++;
        }
        
        for(i=0;i<vel;i++){
            k=izbaciti_iz_niza(pomniz,k,cifre[i]);
        }
        
        for(i=k-1;i>=0;i--){
            x+=pomniz[i]*pow(10,i);
        }
        
        
        if(minus) return -x;
        
        return x;
    }


    int izbaci_cifre(int *brojevi, int vel1, int *cifre, int vel2){
        int i,j;
        
        for(i=0;i<vel2;i++){
            if(cifre[i]<0 || cifre[i]>9) return 0;
            for(j=i+1;j<vel2;j++){
                if(cifre[i]==cifre[j]) return 0;
            }
        }
        
        for(i=0;i<vel1;i++){
            
            brojevi[i]=izbaciti(brojevi[i],cifre,vel2);
        }
        
        return 1;
        
        
    }
int main() {
int brojevi[] = {3};
int cifre[] = {3,5,1,2,4};

izbaci_cifre(brojevi, 0, cifre, 5);
printf("%d ", brojevi[0]);
  return 0;
}
