#include <stdio.h>
#include <math.h>
//pomocna fja za izbacivanje cifara iz broja koristeci histogram za brojeve od 0-9
int izbaci(int x, int*hist)
{
	int rez1=0, cifra, rez2=0, predznak=0;

	while(x) {
		if(x < 0) {
			x = fabs(x);
			predznak = 1;
		}
		cifra = x%10;
		x /= 10;
		if (hist[cifra] != 1)
			rez1 = rez1*10 + cifra;
	}
	//posto smo dobili broj, ali s obrnutim redoslijedom cifara, moramo mu vratiti cifre u redoslijed u kakvom su bile u pocetnom broju
	while(rez1) {
		rez2 = rez2*10 + (rez1%10);
		rez1 /= 10;
	}
	if(predznak) return -rez2;
	else return rez2;

}

int izbaci_cifre(int*M, int m, int*N, int n)
{
	int hist[10] = {0};
	int i,j;
	for(i = 0; i < n; i++) {
		if(N[i]<0 || N[i]>9)
			return 0;
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < 10; j++) {
			if(N[i] == j) hist[j]++;
		}
	}
	//ukoliko se cifre u drugom nizu ponavljaju, histogram ce sadrzati i brojeve vece od 0 i 1
	for(i = 0; i < 10; i++) {
		if(hist[i] > 1)
			return 0;
	}
	for(i = 0; i < m; i++) {
		M[i] = izbaci(M[i], hist);
	}
	return 1;
}

int main()
{
	int M[100], N[100], m, n, i;

	scanf("%d %d", &m, &n);

	for(i = 0; i < m; i++) {
		scanf("%d", &M[i]);
	}
	for(i=0; i < n; i++) {
		scanf("%d", &N[i]);
	}

	izbaci_cifre(M, m, N, n);

	for(i = 0; i < m; i++) {
		printf("%d", M[i]);
	}


	return 0;
}
