#include <stdio.h>

int suma(int a)
{
	int suma=0;
	while(a!=0) {
		suma+=a%10;
		a/=10;
	}
	if(suma<0)
		suma*=-1;
	return suma;
}

void ubaci(int *niz, int vel)
{
	int i, j=0, broj, niz2[60];
	for(i=0; i<vel; i++) {
		niz2[j]=niz[i];
		j++;
		broj=niz[i];
		niz2[j]=suma(broj);
		j++;
	}
	for(i=0; i<2*vel; i++)
		niz[i]=niz2[i];
}

int izbaci(int *niz, int vel){
	int fib[300], i, j, k;
	fib[0]=1;
	fib[1]=1;
	for(i=2; i<300; i++)
		fib[i]=fib[i-1]+fib[i-2];
	for(i=0; i<vel; i++)
		for(j=1; j<300; j++)
			if(niz[i]==fib[j]) {
				for(k=i; k<vel-1; k++)
					niz[k]=niz[k+1];
				vel--;
				j--;
				i--;
				break;
			}
	}

int main() {
		int vel=10, niz[60], i=0;
		printf("Unesite niz od 10 brojeva: ");
		for(i=0; i<vel; i++)
			scanf("%d", &niz[i]);
		ubaci(niz, vel);
		vel*=2;
		vel=izbaci(niz, vel);
		printf("Modificirani niz glasi: ");
		for(i=0; i<vel; i++) {
			if(i<=vel-2) printf("%d, ", niz[i]);
			else printf("%d.", niz[i]);
		}

		return 0;
	}