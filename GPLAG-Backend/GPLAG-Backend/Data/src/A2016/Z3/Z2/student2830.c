#include <stdio.h>
#include <stdlib.h>
void ubaci(int p[], int vel){
    int i=0,suma=0,h[10]={0},d[20]={0},n[20]={0},a,k=1,o=0;
    o=0;
    for(i=0; i<vel; i++) {
        h[i]=p[i];
        n[o]=h[i];
        o+=2;
    }  
   
   
    k=1;
    for(i=0; i<vel; i++) {
        while(h[i] != 0) {
            if(h[i] < 0) {
                h[i]*=-1;
            }
            a=h[i]%10;
            suma+=a;
            h[i]/=10;
        }
        d[k]=suma;
        k+=2;
        suma=0;
    }
 
    for(i=0; i<2*vel; i++) {
        if(i%2 == 1){
            p[i]=d[i];
        }else if(i%2 == 0) {
            p[i]=n[i];
        }
    }
 
  
}
int izbaci(int*p, int vel) {
    int rez[20],j=0,z=0,k=0,i;
    long long int fib[50];
    int *pok;
    pok=p;
    fib[0]=1;
    fib[1]=1;
    for(i=2; i<50; i++) {
        fib[i]=fib[i-2]+fib[i-1];
    }
  
    while(pok < p+vel) {
        rez[j]=*pok;
        j++;
        pok++;
    }
for(i=0; i<vel; i++) {
    for(j=0; j<50; j++) {
        if(rez[i]==fib[j]) {
            k=1;
            break;
        }
    }
    if(k == 1) {
        for(z=i; z<vel-1; z++) {
            rez[z]=rez[z+1];
        }
        i--;
        vel--;
        k=0;
    }
}
    for(i=0; i<vel; i++) {
        p[i]=rez[i];
    }
    return vel;
    
}
int main() {
    int niz[20],i,y,vel,x;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
        scanf("%d", &niz[i]);
    }
    vel=10;
	ubaci(niz,10);
	x=2*vel;
	y=izbaci(niz,x);
	printf("Modificirani niz glasi: ");
	for(i=0; i<y; i++) {
	    if(i<y-1) {
	    printf("%d, ",niz[i]);
	    }
	    else printf("%d.",niz[i]);
	}
	return 0;
    
}

    
  
