#include <stdio.h>
#include <math.h>

int saberi(int n){
	n=fabs(n);
	int i, brojac=0, suma=0, broj;
	broj=n;
	while(broj!=0){
		broj/=10;
		brojac++;
	}
	for(i=0; i<brojac; i++){
		suma+=n%10;
		n/=10;
	}
	return suma;
}

void ubaci(int *niz, int vel){
	int i, j, vel1;
	vel1=vel;
	vel*=2;
	for(i=0; i<vel; i++){
		if(i%2!=0){
			for(j=vel1; j>i; j--){
				*(niz+j)=*(niz+j-1);
				}
				vel1++;
				if(i!=0) *(niz+j)=saberi(*(niz+i-1));
		}
	}
}

int fibonacci(int n){
	int i, suma, zadnji, predzadnji, fib;
	zadnji=1; predzadnji=0; fib=0;
	for(i=1; i<=n; i++){
		suma=zadnji+predzadnji;
		predzadnji=zadnji;
		zadnji=suma;
		if(zadnji==n){
			fib=1;
			break;
		}
	}
	if(fib==1) return 1;
	return 0;
}

int izbaci(int *niz, int vel){
	int i, fib, j;
	for(i=0; i<vel; i++){
		fib=fibonacci(niz[i]);
		if(fib==1){
			for(j=i; j<vel-1; j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
	
}

int main() {
	int niz [100], i, vel1, vel;
	vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<vel; i++){
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz, vel);
	vel1=izbaci(niz, 2*vel);
	
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel1; i++){
		if(i==vel1-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]); }
    return 0;
}

