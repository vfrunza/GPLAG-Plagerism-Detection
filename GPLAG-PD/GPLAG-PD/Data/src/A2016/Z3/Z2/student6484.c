#include <stdio.h>
#define A 10

void ubaci(int niz[], int vel) {
	
	int suma=0, temp;
	int i, j;
	
	for(i=2*vel-1; i>=0; i--) {
		for(j=i/2; j>=0; j--) {
			if(i%2==0) {
				niz[i]=niz[j];
				break;
			}
			else break;
		}
	}
	
	for(i=0; i<2*vel; i++) {
		if(i%2==1) {
			temp=niz[i-1];
			if(temp<0) temp=-temp;
			suma=0;
			for(;;) {
				if(temp/10==0) break;
				suma+=temp%10;
				temp/=10;
			}
			suma+=temp%10;
			niz[i]=suma;
		}
	}
}

int Fibonacci(int x) {
	int a=1, b=1, c;
	for(;;) {
		c=a+b;
		if(x==1) return 1;
		if(c<x) {
			c=a+b;
			a=b;
			b=c;
		}
		if(c==x) return 1;
		else if(c>x) return 0;
	}
}

int izbaci(int niz[], int vel) {
	int i,j;
	for(i=0; i<vel; i++) {
		if(niz[i]>0) {
			if (Fibonacci(niz[i])==1) {
				for(j=i; j<vel-1; j++) {
					niz[j]=niz[j+1];
				}
				i--;
				vel--;
			}
		}
		
	}
	return vel;
}

int main() {
	int i, niz[20], vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	vel=izbaci(niz,2*10);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++) {
		if(i!=vel-1)
		printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
	}
	return 0;
}
