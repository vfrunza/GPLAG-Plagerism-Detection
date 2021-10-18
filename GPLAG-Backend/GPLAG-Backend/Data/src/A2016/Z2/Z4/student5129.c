#include <stdio.h>

int main() {
	/* m i n su dimenzije matrice "mat" */
	double m, n, mat[100][100]={0};
	/* loop je tu da C9 bude zabavno iskustvo drugim kolegama, "i" i "j" su brojaci */
	int loop=1, i, j, rezultat=-1, temp;
	
	
	/* Infinite loop da svi ostali imaju kvalitetno C9 iskustvo */
	do {
		/* Input dimenzijaja matrice */
		printf("Unesite M i N: ");
		scanf("%lf %lf", &m, &n);
		
		/* Provjera uslova - cijeli brojevi u intervalu od 0 do 100 */
		if ((int) m/1 < m || (int) n/1 < n) {
			printf("Pogresan unos!");
		} else if (m<1 || m>100 || n<1 || n>100) {
			printf("Pogresan unos!\n");
		} else break;
	} while (loop);
	
	/* Unos clanova matrice */
	printf("Unesite elemente matrice: ");
	
	for (i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	
	temp=n;
	/* Ispitivanje uslova */
	for (i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			/* Specijalni slucaj kada matrica ima samo jednu vrstu */
			if (m==1) {
				rezultat = 1;
				break;
			}
			
			/* Osnovni uslov za oba tipa specijalnih matrica */
			if (i<m-1 && j<n-1) { 
				if (mat[i][j] != mat[i+1][j+1]) {
					rezultat = 0;
					break;
				}
			}
			
			/* Uslov za cirkularnu matricu */
			if (mat[1][0]==mat[0][temp]) {
				rezultat = 1;
				break;
			}
		}
		/* Prekid ako je rezultat pronađen */
		if (rezultat != -1) break;
	}
	
	/* Provjera koji su uslovi zadovoljeni i adekvatni ispis */
	if (rezultat == 0) printf("Matrica nije ni cirkularna ni Teplicova");
	else if (rezultat == 1) printf("Matrica je cirkularna");
	else printf("Matrica je Teplicova");
	
	return 0;
}