#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{

	int i,j,maxi,min,brojac=0,brojac2=0,temp;
	int nizbrojaca[100]= {0},maxn[100]= {0},niz[100]= {0};


	for(i=0; i<visina; i++) {

		for(j=0; j<sirina; j++) {
			niz[brojac]=matrica[i][j];
			brojac++;
		}
	}

	for(i=0; i<brojac; i++) {
		temp=niz[i];
		for(j=0; j<brojac; j++) {
			if(niz[j]==temp) nizbrojaca[i]++;
		}
	}

	maxi=nizbrojaca[0];
	for(i=0; i<brojac; i++) {
		if(nizbrojaca[i]>maxi) {
			maxi=nizbrojaca[i];
		}
	}

	for(i=0; i<brojac; i++) {
		if(nizbrojaca[i]==maxi) {
			maxn[brojac2]=niz[i];
			brojac2++;
		}
	}

	min=maxn[0];
	for(i=0; i<brojac2; i++) {
		if(maxn[i]<min) min=maxn[i];
	}

	return min;

}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{

	int i,j,k,l;

	for(i=0; i<visina; i++) {

		for(j=0; j<sirina; j++) {

			if (matrica[i][j]==N) {

				for(k=j; k<sirina; k++)

					for(l=0; l<visina; l++)
						matrica[l][k]=matrica[l][k+1];

				sirina--;
				j--;
			}
		}
	}
	return sirina;
}



int main()
{

	int s,v,i,j,maxel,brojac=0;
	int mat[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &s, &v);


	for(i=0; i<v; i++) {

		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<s; j++) {
			scanf("%d", &mat[i][j]);

		}
	}

	printf("\n");

	do {
		maxel=max(mat,v,s);
		s=izbaci_kolone(mat,v,s,maxel);
		brojac++;

		if(s==0) printf("Nakon %d. prolaza matrica je prazna!\n", brojac);
		else printf("Nakon %d. prolaza matrica glasi:\n", brojac);

		for(i=0; i<v; i++) {

			for(j=0; j<s; j++)
				printf("%5d", mat[i][j]);
			printf("\n");
		}

		printf("\n");

	} while(s!=0);

	return 0;
}
