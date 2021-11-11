#include <stdio.h>

int Suma(int n) {
if(n<0) n*=-1;
int suma=0;
int cifra;
	while(n!=0) {
		cifra=n%10;
		suma+=cifra;
		n/=10;
	}
return suma;	
}


void ubaci(int *niz, int vel) {
	int i,j;
	
	for(i=1; i<vel; i++) {
		if(i%2!=0) {
			vel++;
			for(j=vel; j!=i; j--)
				niz[j]=niz[j-1];
		
		niz[i]=Suma(niz[i-1]);	
		}
		
	}
	niz[vel]=Suma(niz[vel-1]);
}

int Fibo(int n) {
	int a=1,b=1,c;
	int i;
	
	if(n==1) return 1;
	
	while(a+b<=n)
	{   
		if(a+b==n ) return 1;
		c=a;
		a=b;
		b=c+b;
	}
	
	
	return 0;
}
int izbaci(int *niz, int vel) {
	int i,j;
	
	for(i=0; i<vel; i++) {
		if(Fibo(niz[i])==1) {
			for(j=i; j<vel-1; j++) 
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	
int i;
int niz[100];
int vel=20;

printf("Unesite niz od 10 brojeva: ");
for(i=0; i<10; i++) {
	scanf("%d", &niz[i]);
	}
  
  
  ubaci(niz,10);

  vel=izbaci(niz,vel);

  
  printf("Modificirani niz glasi: ");
  
	for(i=0;i<vel;i++){
		if(i==vel-1) printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	
	return 0;
}
