#include <stdio.h>

/*suma cifara nekog broj*/
int suma_cifara(int broj) {
	int cifra,suma=0;
	if (broj<0)
		broj=-broj;
	while (broj>0) {
		cifra=broj%10;
		suma+=cifra;
		broj/=10;
	}
	return suma;
}

/*u niz ubacuje broj koji predstavlja sumu cifara prethodnog clana*/
void ubaci(int* niz,int vel) {
	int *i,j,temp,vel2;
	vel2=vel;
	/*premjesta elemete koje smo unijeli*/
	for (i=niz+2*vel-1; i>niz; i--) {
		if (i==niz+vel-1) {
			temp=*(niz+2*vel-2);
			*(niz+2*vel-2)=*(niz+vel-1);
			*(niz+vel-1)=temp;
			vel--;
		}
	}
	/*sumu cifara clana niza postavlja na prazno mjesto do clana niza*/
	for(j=0; j<vel2; j++) {
		*(niz+2*j+1)=suma_cifara(*(niz+2*j));
	}
}

/*izbacuje iz niza sve clanove koji su Fibonaccijevi brojevi*/
int izbaci(int *niz,int vel) {
	int *i,*k,j,temp,fibonaci1,fibonaci2,fibonaci3;
	/*prolazi kroz clanove niza*/
	for (i=niz; i<niz+vel; i++) {
		fibonaci1=0;
		fibonaci2=1;
			/*racuna Fibonaccijeve brojeve*/
			for (j=0; j<10000; j++) {
				fibonaci3=fibonaci1+fibonaci2;
				/*poredi clanove niza i Fibonaccijeve brojeve*/
				if (*i==fibonaci3) {
					/*izbacuje clanove niza koji su Fibonaccijevi brojevi*/
					for(k=i; k<niz+vel-1; k++){
						temp=*k;
						*k=*(k+1);
						*(k+1)=temp;
					}
					vel--;
					i--;
					break;
				}
			fibonaci1=fibonaci2;
			fibonaci2=fibonaci3;
			}
	}
	return vel;
}

int main() {
	int *j,i,niz[20],velicina;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
    
	ubaci(niz,10);
	velicina=izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	if (velicina==1) {
		printf("%d.", *niz);
	} else {
		for (j=niz; j<niz+velicina; j++) {
			if (j==niz+velicina-1)
				printf("%d.", *j);
			else
				printf("%d, ", *j);
		}
	}
		
	return 0;
}
