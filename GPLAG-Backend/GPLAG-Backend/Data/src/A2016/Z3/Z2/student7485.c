#include <stdio.h>
#include <stdlib.h>

void ubaci(int *niz, int br_clanova){
	int i,broj_cifara,pomocna,n;
	for (i=br_clanova-1;i>0;i--){
		niz[2*i]=niz[i];
	}
	for (i=0;i<2*br_clanova;i+=2){
		broj_cifara=0;
		pomocna=abs(niz[i]);
		while(pomocna>0){
			broj_cifara+=pomocna%10;
			pomocna/=10;
		}
		niz[i+1]=broj_cifara;
	}
	
}

int izbaci(int *niz, int br_clanova){
	int fibonaci[46],i,j,k;
	
	fibonaci[0]=1;
	fibonaci[1]=1;
	
	for (i=2;i<46;i++){
		fibonaci[i]=fibonaci[i-1]+fibonaci[i-2];
	}
	for(j=0;j<46;j++){
	for(i=0;i<br_clanova;i++){
		
			if (fibonaci[j]==niz[i]){
				for (k=i;k<br_clanova-1;k++){
					niz[k]=niz[k+1];
				}
			br_clanova--;
			i--;
			}
			}
		}
	return br_clanova;
	}
	



int main(){
	int niz[20],i,n;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	ubaci (niz,10);
	n=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++){
		if(i<n-1)
		printf("%d, ", niz[i]);
		else 
		printf("%d.", niz[i]);
	}
	
	
	return 0;
}