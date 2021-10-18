#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void ubaci (int niz[], int vel) {
	int i, j, k, parni, neparni, neko, neko1;
	int kopija[100], br[100]={0}, suma[100]={0}, n[100], kopija1[100], kopija2[100];
	for(i=0;i<2*vel;i++) {
		kopija[i]=fabs(niz[i]);
		kopija1[i]=niz[i];
		kopija2[i]=fabs(niz[i]);
	/*	petlja koja broji cifre*/
		for(j=0;j<100;j++) {
			kopija[i]=kopija[i]/10;
			if(kopija[i]>0) br[i]++;
		}
	/*	 petlja koja sabire cifre broja */
		for(k=0;k<br[i]+1;k++) {
			n[k]=kopija2[i]%10;
			suma[i]+=n[k];  /*broj koji se treba ubaciti */
			kopija2[i]=kopija2[i]/10;
			if(kopija2[i]<=0) break;
		}
		parni=i;
		neparni=i;
		if(i%2==0) {
			neko=parni/2;
			parni=parni-neko;
			niz[i]=kopija1[parni];
			
		}
		else if(i%2!=0) {
			neko1=(neparni-1)/2;
			niz[i]=suma[neko1];
		}
	}
}

int izbaci (int *niz, int vel) {
	int i, k, j, fibonacijev[1000];
	fibonacijev[0]=1; fibonacijev[1]=1;
	for(i=2;i<100;i++) {
		fibonacijev[i]=fibonacijev[i-1]+fibonacijev[i-2];
	}
	for(j=0;j<vel;j++) {
	     for(i=0;i<100;i++) {
			if(fibonacijev[i]==niz[j]) {
				for(k=j;k<vel-1;k++) {
					niz[k]=niz[k+1]; 
				}
				vel--;
				j--;
				break;
			}
		}
	}
	return vel;
}


int main() {
	int niz[100]={0}, i, velicina;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) {
		scanf("%d ", &niz[i]);
	}
	ubaci(niz,10);
	velicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<velicina;i++) {
		if(i<velicina-1)
		printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
	}
	return 0;
}

