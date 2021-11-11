#include <stdio.h>
#include <stdlib.h>

void ubaci(int* niz,int vel) {
    int i,novi_br,pom,ostatak;
    for(i=vel-1; i>0; i--) {
        niz[2*i]=niz[i];
    }
    for(i=0; i<2*vel; i+=2) {
        novi_br=0;
        pom=niz[i];
        while (pom!=0) {
        ostatak=abs(pom%10);
        novi_br+=ostatak;
        pom/=10;
         }
        niz[i+1]=novi_br;
    }     
    }


int izbaci(int* niz, int vel) {
    int fibonacijev[40],i,j,k;
    fibonacijev[0]=1;
    fibonacijev[1]=1;
    for(i=2; i<40; i++) {
    fibonacijev[i]=fibonacijev[i-1]+fibonacijev[i-2];
    }
    for(i=0; i<vel; i++) {
        for(j=0; j<40; j++) {
            if(niz[i]==fibonacijev[j]) {
                for(k=i; k<vel-1; k++) {
            niz[k]=niz[k+1];
                }
                vel--;
                i--;
                break;
            }
        }
    }
return vel;
}

int main() {
    int i,vel,niz[20];
    printf("Unesite niz od 10 brojeva: ");
        for(i=0; i<10; i++) {
            scanf("%d",&niz[i]);
        }
        vel=i;
        ubaci(niz,vel);
        vel=2*vel;
        vel=izbaci(niz,vel);
        
    printf("Modificirani niz glasi: ");
        for(i=0; i<vel; i++) {
            if (i==vel-1)
            printf("%d.", niz[i]);
            else
            printf("%d, ", niz[i]);
        }
        
        
	return 0;
}
