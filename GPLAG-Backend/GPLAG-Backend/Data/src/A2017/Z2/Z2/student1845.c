#include <stdio.h>
#include <math.h>
int main() {
    int vel,niz[100],niz1[10000],niz2[1000],t=0,i;
    printf("Unesite velicinu niza: ");
    scanf("%d", &vel);
    printf("Unesite clanove niza: ");
    for(i=0; i<vel; i++) {
    	scanf("%d", &niz[i]);
    }
    for(i=0; i<vel; i++) {
    int n=niz[i],c=0,k=1, novi=n, brc=1;
    while(novi!=0){
    	n/=10;
    	brc++;
    }
    k=pow(k,brc-1);
    while(n!=0) {
    	c=(n%10)*k;
    	k/=10;
    	n/=10;
    }
    niz[i]=c;
    while(c!=0) {
    	niz1[t]=c%10;
    	c/=10;
    	t++;
    }
    }
    for(i=0;i<vel;i++) printf("%d ", niz[i]);
    for(i=0;i<t;i++) printf("%d ", niz1[i]);
	return 0;
}
