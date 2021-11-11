#include <stdio.h>


void ubaci(int *niz, int brclan) {
	int i, t;
	

	for(i=brclan*2 - 1; i>=0; i--) {
		niz[i]=niz[i/2];
	}
	
	
	for(i=0; i<brclan*2; i++) {
	
		if(niz[i]>0) t=niz[i];
		else t=niz[i] * (-1);
		
		
		if(i%2!=0) {
			niz[i]=0;
			
			while(t!=0){
			niz[i]+=t%10;
			t/=10;
			}
		}
	}
}

int izbaci(int *niz, int brclan) {
	int i, j, fib[1000]={0}, k, t;

	fib[0]=1;
	fib[1]=2;
	for(i=2; i<1000; i++) {
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	t=brclan*2;
	

	for(i=0; i<t; i++) {
		for(j=0; j<1000; j++) {
			if(niz[i]==fib[j]) {
				for(k=i; k<t; k++) {
					niz[k]=niz[k+1];
				}
				
				niz[t-1]=1;
				t--;
				brclan--;
				i--;
			}
		}
	}
	return brclan;
}


int main() {
    int niz[21]={0}, i, t=20, brclan=10;

    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
     scanf("%d", &niz[i]);
        if (niz[i]%1!=0) i--;
    }

    ubaci(niz, brclan);
    izbaci(niz, brclan);
    printf("Modificirani niz glasi: %d", niz[0]);
    for(i=1; i<t; i++) {
    if(niz[i]!=1) printf(", %d", niz[i]);  }   printf(".");
	
	return 0;
}
