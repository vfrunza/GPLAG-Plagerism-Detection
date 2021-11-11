#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BROJ_EL 100000
void ubaci(int* p, int x){
	x = x * 2;
	int i=0, j, m, suma=0, apsolutno;
	m=(x/2)-1;
	for(j=2; 1<=m ; j+=2){
		i++;
		p[x-j]=p[(x/2)-i];
		m--;
	}
	for(i=0; i<x; i+=2){
		apsolutno = (abs) (p[i]);
		for(j= apsolutno; 1<=j; j/=10){
			m = j % 10;
			suma += m;
		}
		p[i+1] = suma;
		suma=0;
	}
	
}
void Fibonaccijevi(long long* p, int x){
	int i;
	p[0]=1;
	p[1]=1;
	for(i=2; i<x; i++){
		p[i]=p[i-1] + p[i-2];
	}
}
int izbaci(int* niz, int x){
	int i, j, k=0;
	long long p[BROJ_EL];
	Fibonaccijevi(p, BROJ_EL);
	for(i=0; i<x; i++){
		for(j=0; j<BROJ_EL; j++){
			if(niz[i]==p[j]){
				for(k=i; k<x-1; k++){
					niz[k]=niz[k+1];
				}
				x--;
				i--;
				break;
			}
		}
	}
	return x;
}
int main() {
	int i, x=10, niz[BROJ_EL], m;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<x; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, x);
	x*=2;
	m=izbaci(niz, x);
	printf("Modificirani niz glasi: ");
	for(i=0; i<m; i++){
		if(i!=m-1){
			printf("%d, ", niz[i]);
		}else{
			printf("%d.", niz[i]);
		}
	}
	return 0;
}
