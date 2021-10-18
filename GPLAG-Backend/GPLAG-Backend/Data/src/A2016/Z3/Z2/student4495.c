#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void ubaci (int* niz, int vel) {
	
	int* clan;
	
	clan=niz;
	while (clan < niz + vel) {
		
		//Suma cifara clana niza
		
		int suma_c=0;
		int clan_niza=abs(*clan);
		
		while (clan_niza != 0) {
			suma_c=suma_c+(clan_niza%10);
			clan_niza=clan_niza/10;
		}
		
		//Pomjeranje clanova niza za jedno mjesto
		
		int* temp_p;
		temp_p=niz+vel;
		while (temp_p > clan) {
			*temp_p=*(temp_p-1);
			temp_p--;
		}
		
		//Ubacivanje novog clana niza
		
		*(clan+1)=suma_c;
		
		clan=clan+2;
		vel++;
			
		
	}
	
}

int fibonacci (int br) {
	
	int niz[1000];
	niz[0]=1;
	niz[1]=1;
	
	if (br == 1)
		return 1;
		
	int* p1=niz;
	int* p2=niz+1;
	int* p3=niz+2;
	
	while (1) {
		*p3=*p2+*p1;
		if (*p3 == br)
			return 1;
		if (*p3>br)
			return 0;
			
		p1++;
		p2++;
		p3++;
	}
}

int izbaci (int* p, int vel) {
	
	int* niz = p;
	int br;
	int* temp_p;
	while (niz < p+vel) {
		br=*niz;
		br=fibonacci(br);
	if (br == 1) {
		for (temp_p=niz; temp_p<p+vel-1; temp_p++) {
			*temp_p=*(temp_p+1);
		}
		vel--;
		niz--;
	}
		niz++;
	
}
	return vel;
}

int main() {
	int niz[100], i, izbaceni;
	 
	printf("Unesite niz od 10 brojeva: ");
	for (i = 0; i < 10; i++) {
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz, 10);
	izbaceni=izbaci(niz, 20);
	
	printf("Modificirani niz glasi: ");
	for (i = 0; i < izbaceni; i++) {
		if (i < izbaceni -1) 
			printf("%d, ", niz[i]);
		else 
			printf("%d.", niz[i]);
	}
	return 0;
}
