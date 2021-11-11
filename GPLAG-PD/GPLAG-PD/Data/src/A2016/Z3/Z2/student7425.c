#include <stdio.h>

int suma(int n) {
	if(n<0) n=-n;
	int a=0;
	while(n!=0) {
		a+=(n%10);
		n/=10;
	}
	return a;
}

int fibonacci(int n) {
	int x=1,y=1,z;
	if(n==x || n==y) return 1;
	z=x+y;
	while(z<=n) {
		if(z==n) return 1;
		x=y;
		y=z;
		z=x+y;
	}
	return 0;
}

void ubaci(int niz[], int vel) {
	int i;
	int niz1[100];
	for(i=0;i<vel;i++)
		niz1[i]=niz[i];
	for(i=0;i<vel;i++) {
		
			niz[2*i]=niz1[i];
		if(i%2==1) niz[i]=0;
		}
	for(i=1;i<2*vel;i+=2) {
		niz[i]=suma(niz[i-1]);
	}
}	

int izbaci(int niz[], int vel) {
	int i,j;
	for(i=0;i<vel;i++) {
		if(fibonacci(niz[i])==1) {
			for(j=i;j<vel-1;j++) 
				niz[j]=niz[j+1];
			i--;
			vel--;
		}
	}
	return vel;
}


int main() {
	int niz[20];
	int i,vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
		scanf("%d", &niz[i]);
	ubaci(niz, 10);
	vel=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++) {
		if(i!=vel-1) printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
	}
	return 0;
}
