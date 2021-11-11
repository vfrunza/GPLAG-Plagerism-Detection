#include <stdio.h>
#include <math.h>

int suma_cifara(int n){
	if(n < 0)
		n *= -1;
	int suma = 0;
	for(; n != 0; n/=10)
		suma += n % 10;
	return suma;
}

void ubaci_broj_u_niz(int *niz, int velicina, int broj, int mjesto){
	int i = velicina;
	for(; i >= mjesto; --i)
		niz[i] = niz[i - 1];
	niz[mjesto] = broj;
}

void ubaci(int *niz, int velicina){
	int i = 0, s_velcina = velicina;
	for(; i < s_velcina * 2; i += 2, ++velicina)
		ubaci_broj_u_niz(niz, velicina, suma_cifara(niz[i]), i + 1);
}

int izbaci_iz_niza(int *niz, int velicina, int broj){
	int i = 0, j = 0;
	for(; i < velicina; ++i)
		if(niz[i] == broj){
			for(j = i + 1; j < velicina; ++j)
				niz[j - 1] = niz[j];
			--i;
			--velicina;
		}
	return velicina;
}


int jel_fibonnacijev(int n){
	int a = 1, b = 1;
	if(n == a || n == b)
		return 1;
	int c = a + b;
	while(c <= n){
		if(c == n)
			return 1;
		a = b;
		b = c;
		c = a + b;
	}
	return 0;
}

int izbaci(int *niz, int velicina){
	int i = 0;
	for(; i < velicina; ++i)
		if(jel_fibonnacijev(niz[i]) == 1){
			velicina = izbaci_iz_niza(niz, velicina, niz[i]);
			--i;
		}
	return velicina;
}

int main() {
	int niz[20], i=0;
	printf("Unesite niz od 10 brojeva: ");
	for(; i < 10; ++i)
		scanf("%d", &niz[i]);
	ubaci(niz, 10);
	int n_duzina = izbaci(niz, 20);
	
	printf("Modificirani niz glasi: ");
	for(i = 0; i < n_duzina - 1; ++i)
		printf("%d, ", niz[i]);
	printf("%d.", niz[i]);
	return 0;
}
