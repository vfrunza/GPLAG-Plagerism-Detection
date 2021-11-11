#include <stdio.h>
#include<stdlib.h>
#define VELICINA 10
#define velicina_2 20
void ubaci (int *niz, int velicina)
{
	int i, k;
	int b1;
	int b2;
	int b3 = 0;
	for(k = velicina - 1; k >= 0; k--){
		niz[2*k] = niz[k];
	}
	for(i = 0; i < 2 * velicina; i = i + 2){
		b1 = abs (niz[i]);
		if (b1 < 10) 
		b3 = b1;
		else {
			do{
			b2 = b1  % 10;
			b3 = b3 + b2;
			b1 = b1 / 10;
			}
			while(b1 != 0);
		}
		niz[i + 1] = b3;
		b3 = 0;
	}
}
int izbaci(int *niz, int velicina)
{
	int i;
	int k;
	int x = 1;
	int y = 1;
	int z;
	int u;
	for(i = 0; i < velicina; i++){
		x = 1;
		y = 1;
		for(k = 1; k < 10000; k++){
			if (k == 1)
			z = 1;
			else {
				z = x + y;
				x = y;
				y = z;
			}
			if(niz[i] == z){
				for(u = i; u < velicina - 1; u++){
					niz[u] = niz[u+1];
				
				}
				velicina -- ; 
				i --; 
				break;
			}
		}
	}
	return velicina;
}
int main(){
	int niz[2 * VELICINA];
	int i;
	int u;
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < VELICINA; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, VELICINA);
	u = izbaci(niz, velicina_2);
	printf("Modificirani niz glasi: ");
	for(i = 0; i < u; i++){
		if (i == u - 1){
			printf("%d.", niz[i]);
		}else {
			printf("%d, ", niz[i]);
		}
	}
	return 0;
}