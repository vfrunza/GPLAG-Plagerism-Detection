#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i, j, clanovi[1000], broj_ponavljanja=0, max_ponavljanja=0, clan;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			clanovi[i*sirina+j]=matrica[i][j];
		}
	}
	clan=clanovi[0];
	for(i=0; i<=(visina-1)*sirina+(sirina-1); i++) {
		broj_ponavljanja=0;
		for(j=i; j<=(visina-1)*sirina+(sirina-1); j++) {
			if(clanovi[i]==clanovi[j]) broj_ponavljanja++;
		}
		if(broj_ponavljanja>max_ponavljanja) {
			max_ponavljanja=broj_ponavljanja;
			clan=clanovi[i];
		} else if(broj_ponavljanja==max_ponavljanja && clanovi[i]<clan) clan=clanovi[i];
	}
	return clan;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, k, izbacivanje, kolona;
	for(i=0; i<sirina; i++) {
		izbacivanje=0;
		for(j=0; j<visina; j++) {
			if(matrica[j][i]==N) {
				izbacivanje=1;
				kolona=i;
				break;
			}
		}
		if(izbacivanje==1) {
			for(j=0; j<visina; j++)
				for(k=kolona; k<sirina-1; k++)
					matrica[j][k]=matrica[j][k+1];
			sirina--;
			i--;
		}
	}
	return sirina;
}

int main()
{
	int m[100][100], m_sirina, m_visina, i, j, prolaz=1, cifra;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &m_sirina,&m_visina);
	for(i=0; i<m_visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<m_sirina; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	do {
		cifra=max(m,m_visina,m_sirina);
		m_sirina=izbaci_kolone(m,m_visina,m_sirina,cifra);
		if(m_sirina==0) break;
		printf("\nNakon %d. prolaza matrica glasi:\n", prolaz);
		for(i=0; i<m_visina; i++) {
			for(j=0; j<m_sirina; j++) {
				printf("%5d", m[i][j]);
			}
			printf("\n");
		}
		prolaz++;
	} while(m_sirina>0);

	printf("\nNakon %d. prolaza matrica je prazna!",prolaz);

	return 0;
}
