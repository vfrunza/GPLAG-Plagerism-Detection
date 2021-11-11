#include <stdio.h>
#include <stdlib.h>
int suma (int x){
	int s=0,l;
	l=abs(x);
	while (l!=0){
		s+=(l%10);
		l=l/10;
	}
	return s;
}

int fibonacci (int x){
	int g=0, a, b, c;
		if (x==1){
			g = 1;
		} else {
			a=0;
			b=1;
			c=a+b;
				while (c<x){
					a=b;
					b=c;
					c=a+b;
				}
			if (c==x){
				g = 1;
			} else {
				g = 0;
			}
		}
	return g;
}

void ubaci (int *p,int A){
	int i, e=1;
	for (i=2*A-1; i>0; i--){
		if (i%2!=0){
			*(p+i)=suma (*(p+A-e));
		} else {
			*(p+i)= *(p+A-e);
			e++;
		}
	}
}

int izbaci (int *p, int A){
	int i,j,n=A;
	
		for (i=0; i<n; i++){
				if (fibonacci(*(p+i))==1){
					for (j=i; j<n-1; j++){
						*(p+j)=*(p+j+1);
					}
					n--;
					i--;
				}
		}
	return n;
	
}




int main() {
	
	int niz[100]={0},i,A=10;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for (i=0; i<A; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz,A);
	A=A*2;
	A = izbaci(niz,A);
	
    printf("Modificirani niz glasi: ");
		for (i=0; i<A; i++){
			if (i==A-1){
				printf("%d.", niz[i]);
			} else {
		printf("%d, ", niz[i]);
		}
	}
	return 0;
}