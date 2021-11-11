#include <stdio.h>   
#include <math.h>
int fibonacci(int a) {                       /*nije koristena*/
 	int i, rez, zadnji=1, predzadnji=0;
 	for(i=0; i<=a; ++i) {
 		rez=zadnji + predzadnji;
 		predzadnji = zadnji;
 		zadnji = rez;
 	}
 	return 0;
}
void ubaci(int niz[], int velicina){
	int i, j, sljedeci, a;
		for(i=0; i<velicina; i++) {
			a=fabs(niz[i]);
			sljedeci=0;
			while(a>0) {
				sljedeci+=a%10;
				a/=10;
			}
			for(j=velicina; j>i; j--){
				niz[j]=niz[j-1];
			}
			niz[i+1]=sljedeci;
			velicina++;
			i++;
		}
	}

int izbaci(int niz[], int velicina) {
	int Fibonacci[34]={1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465 };
	int* p=niz, i, j, k;
	while(p<niz+velicina) {
		for(i=0; i<velicina; i++) {
			for(j=0; j<34; j++) {
				if(niz[i]==Fibonacci[j]) {
					for(k=i; k<velicina-1; k++) {
						niz[k]=niz[k+1];
					}
					velicina--;
					i--;
					break;
				}
			}
		}
		p++;
	}
	return velicina;
}
int main() {
	int niz[20], i, velicina=10, vel, velicina1=20;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<velicina; i++) 
		scanf("%d", &niz[i]);
	ubaci(niz, velicina);
	izbaci(niz,velicina1);
	vel=izbaci(niz, velicina1);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++) {
		if(i==vel-1)
			printf("%d.", niz[i]);
		else
			printf("%d, ", niz[i]);
	}
	return 0;
}
