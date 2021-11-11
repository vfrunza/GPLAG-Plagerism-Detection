#include <stdio.h>

int suma(int n){
    if(n < 0) n = -n;
	int c, s=0;
	while(n!=0){	
		c = n % 10;
		n = n / 10;
		s = s + c;
	}
	 return s;
}

int fibonacci (int n) {
	int Fibonacci[1000] , vel = 2, i;
	Fibonacci[0] = 1;
	Fibonacci[1] = 1;
	if(n==1 || n == 2) return 1;
	for(i = 2; i < 100; i++) Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
		for(i = 0; i < 50; i++)
			if(Fibonacci[i] == n)return 1;	
		return 0;
}


void ubaci(int *niz, int vel){
	int i, j;
	for(i=0 ; i<vel ; i+=2) {
		j=vel;
		while(j!=i) { niz[j] = niz[j-1]; j--; }
		vel++;
		niz[i+1] = suma(niz[i]);
	}
}

int izbaci(int *niz, int vel){
	int i, j;
	for(i=0; i < vel; i++) {
	    if(niz[i] > 0){
		if(fibonacci(niz[i]) ) {
			for(j=i; j<vel - 1; j++){
				niz[j] = niz[j + 1];
			    }
			    vel--;
			    i--;
		    }
	    }
	}
	return vel;
}




int main() {
	int i, niz[1000],broj = 10;
	printf("Unesite niz od 10 brojeva: ");
		for(i=0 ; i<broj; i++){
			scanf("%d",&niz[i]);
		}
		ubaci(niz,broj);
		broj += broj;
		broj=izbaci(niz,broj);
		
		printf("Modificirani niz glasi: ");
			for(i=0 ; i<broj - 1; i++)
				printf("%d, ",niz[i]); 
			printf("%d.",niz[i]);
		
	return 0;
}
