#include <stdio.h>

/* trazi vrijednost koja se ponavlja najvise puta u matrici, te ako je broj ponavljanja nekih razlicitih vrijednosti isti onda uzima onu manju */
int max(int matrica[100][100], int visina, int sirina)
{
	int i, j, duzina_niza, niz[10000], max_brojac, vrijednost, brojac, jednako, *p, *q;

	duzina_niza=0;
	p=niz;

	/* matricu pretvara u niz */
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			*p=*(matrica[i]+j);
			p++;
			duzina_niza++;
		}
	}

	p=niz;
	/* stavimo da je najveci broj ponavljanja neke vrijednosti na nulu i za vrijednost uzmemo prvi element niza */
	max_brojac=0;
	vrijednost=*p;
	/* broji koliko se puta vrijednost ponavlja u nizu */
	while(p<niz+duzina_niza) {
		q=niz;
		jednako=0;

		/* provjeravamo da li se prije vrijednosti na koju pokazuje pokazivac ponavlja negdje prije u nizu */
		while(q<p) {
			if(*q==*p) {
				jednako=1;
			}
			q++;
		}

		/* ako se vrijednost ne pojavljuje negdje prije u nizu onda broji koliko se puta ta vrijednost pojavljuje u nizu */
		if(!jednako) {
			q=p;
			brojac=0;
			while(q<niz+duzina_niza) {
				if(*q==*p) {
					brojac++;
				}
				q++;
			}

			/* ako je broj ponavljanja veci od prethodno odredenog najveceg broja ponavljanja onda
			odredi da je ta vrijednost koja se vise puta ponavlja ona sa najvecim brojem ponavljanja */
			if(brojac>max_brojac) {
				max_brojac=brojac;
				vrijednost=*p;

				/* ako je broj ponavljanja vrijednosti isti kao i prethodno odreden najveci broj ponavljanja onda za vrijednos koja se najvise puta ponavlja uzme onu manju */
			} else if(brojac==max_brojac) {
				if(*p<vrijednost) {
					vrijednost=*p;
					max_brojac=brojac;
				}
			}
		}
		p++;
	}

	return vrijednost;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int (*pokazivac)[100]=matrica, i, j, i1, j1, temp, *p;
	p=&sirina;

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {

			/* ako je vrijednost u elementu jednaka N onda pomjeri svaku kolonu nakon one u kojoj se elemnt nalazi za jedno mjesto unazad */
			if(*(pokazivac[i]+j)==N) {
				for(i1=0; i1<visina; i1++) {
					for(j1=j; j1<sirina-1; j1++) {
						temp=*(pokazivac[i1]+j1);
						*(pokazivac[i1]+j1)=*(pokazivac[i1]+j1+1);
						*(pokazivac[i1]+j1+1)=temp;
					}
				}

				/* sirinu smanji za 1 jer je izbacio jednu kolonu */
				(*p)--;
				/* j umanjujemoza jedan jer nova kolona koju smo postavili na mjesto one koju smo izbacili moze sadrzati element koji trebamo izbaciti */
				j--;
			}
		}
	}
	return *p;
}

int main()
{
	int sirina, visina, matrica[100][100], i, j, k, kolona;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);

	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}

	k=0;

	/* izbacuje kolone sve dok matrica ne ostane prazna to jeste dok sirina matrice ne postane 0 */
	while(sirina!=0) {
		kolona=izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));

		if(kolona==0) {
			printf("\nNakon %d. prolaza matrica je prazna!", k+1);
			break;
		} else {
			printf("\nNakon %d. prolaza matrica glasi:", k+1);
			printf("\n");
			for(i=0; i<visina; i++) {
				for(j=0; j<kolona; j++) {
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
		}

		sirina=kolona;
		k++;
	}

	return 0;
}
