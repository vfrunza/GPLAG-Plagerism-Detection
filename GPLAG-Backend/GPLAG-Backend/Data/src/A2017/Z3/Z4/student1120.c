#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int max=0, indeks_i=0, indeks_j=0,i,j,k,l,clan=0,trenutno;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			trenutno=0; //broj pojavljivanja trenutnog clana
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) {
					if(matrica[k][l]==matrica[i][j]) trenutno++;
					if(trenutno>max || (trenutno==max && matrica[i][j]<matrica[indeks_i][indeks_j])) { //drugi dio uslova: ako se vise clanova ponavlja jednak(najveci) broj puta, vraca se najmanji od tih clanova
						max=trenutno;
						indeks_i=i;	//cuvamo indekse clana sa maksimalnim brojem pojavljivanja
						indeks_j=j;
						clan=matrica[i][j];
					}
				}
			}
		}

	}
	return clan;
}





int izbaci_kolone(int mat[100][100], int visina, int sirina, int n)
{
	int i,j,k,l,postoji,kolone=sirina; //broj kolona koje ostanu nakon izbacivanja svakako ne moze biti veci od sirine zadate matrice
	for(j=0; j<sirina; j++) {
		for(i=0; i<visina; i++) {
			postoji=0;
			if(mat[i][j]==n) postoji=1;
			if(postoji) {		//"izbacujemo" sve kolone u kojima se javlja clan n uz ocuvanje redoslijeda
				for(k=j; k<sirina-1; k++) {
					for(l=0; l<visina; l++) {
						mat[l][k]=mat[l][k+1];
					}
				}
				sirina--;
				kolone--;
				j--;		//ponovo posmatrajmo kolonu koja je dosla na mjesto izbacene jer mozda i nju treba izbaciti
			}
		}
	}


	return kolone;
}

int main()
{
	int vis,sir,mat[100][100]= {0},i,j,rez=0,br=0,kolone=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sir, &vis);
	for(i=0; i<vis; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sir; j++) {

			scanf("%d", &mat[i][j]);
		}

	}
	while(1) { //posto ne znamo koliko ce se puta ova petlja izvrsiti pa smo  koristili beskonacnu
		rez=max(mat,vis,sir);
		kolone=izbaci_kolone(mat,vis,sir,rez);
		sir=kolone; //nakon poziva funkcije izbaci_kolone mijenja se i sirina matrice pa je i u main funkciji moramo promijeniti
		br++;
		if(kolone==0) {
			printf("\nNakon %d. prolaza matrica je prazna!", br);
			break;
		} else {
			printf("\nNakon %d. prolaza matrica glasi:\n", br);
			for(i=0; i<vis; i++) {
				for(j=0; j<kolone; j++) {
					printf("%5d", mat[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
