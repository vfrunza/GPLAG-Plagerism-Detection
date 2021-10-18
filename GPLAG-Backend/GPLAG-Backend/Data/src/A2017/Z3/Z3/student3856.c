#include <stdio.h>
#include <stdlib.h>
int izbaci_cifre(int niz1[],int vel1, int niz2[], int vel2)
{
	int i,j,broj,temp,cifra,b=1,razl=1,predznak=1;
	//provjeravamo je li niz cifara ispravan, da li se u nizu zaista nalaze iskljucivo cifre
	for(j=0; j<vel2; j++) {
		if(niz2[j]<0 || niz2[j]>9) {
			b=0;
			break;
		}
	}
	//provjeravamo da li se u nizu cifara neke cifre ponavljaju
	if(b==1) {
		for(j=0; j<vel2; j++) {
			for(i=0; i<vel2; i++) {
				if(i!=j && niz2[i]==niz2[j]) {


					b=0;
					break;
				}
			}
		}
	}

	if(b==0) return b;

//iz niza brojeva izbacujemo cifre koje se javljaju u nizu cifara
	for(i=0; i<vel1; i++) {
		predznak=1;
		if(niz1[i]<0) predznak=-1;
		broj=abs(niz1[i]);

		temp=0;
		while(broj!=0) {
			cifra=broj%10;
			broj=broj/10;
			for(j=0; j<vel2; j++) {
				//ako je cifra broja jednaka cifri iz niza cifara postavljamo log promjenjivu na 0 breakamo
				if(cifra==niz2[j]) {
					razl=0;
					break;

				}

			}
			//ako cifra broja nije jednaka cifri iz niza cifara 
			if(razl) temp=temp*10+cifra;
			razl=1;
		}
		if(temp==0) niz1[i]=0;
		else	{
			niz1[i]=0;
			//sad je temp naopako i treba nam niz[i] koji je jednak temp kada idem z desna na lijevo
			while(temp!=0) {
				niz1[i]=niz1[i]*10+temp%10;
				temp=temp/10;
			}
		}

		niz1[i]=predznak*niz1[i];
	}
	return b;
}
int main()
{

	return 0;
}
//nadijina verzija
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
