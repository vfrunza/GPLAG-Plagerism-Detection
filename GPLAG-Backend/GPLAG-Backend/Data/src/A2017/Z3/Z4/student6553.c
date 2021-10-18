#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	int vrijednosti[100], ponavljanja[100]= {0},i,j,s=1,p,maksi,uspjeh;
	vrijednosti[0]=matrica[0][0];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			uspjeh=0;
			for(p=0; p<s; p++) {
				if(matrica[i][j]==vrijednosti[p]) {
					ponavljanja[p]++;
					uspjeh=1;
					break;
				}

			}
			if(!uspjeh) {
				vrijednosti[s]=matrica[i][j];
				ponavljanja[s]++;
				s++;
			}

		}

	}
	maksi=0;
	for(i=0; i<s; i++) {
		if(ponavljanja[i]>ponavljanja[maksi] || (ponavljanja[i]==ponavljanja[maksi] && vrijednosti[i]<vrijednosti[maksi])) maksi=i;
	}
	return vrijednosti[maksi];
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina, int N)
{
	int j,i,p;

	for(j=0; j<sirina; j++) {
		for(i=0; i<visina; i++) {

			if(matrica[i][j]==N) {
				i=0;
				p=j;
				do {
					matrica[i][p]=matrica[i][p+1];
					i++;
					if(i==visina) {
						i=0;
						p++;
					}
				} while(p<sirina-1);
				sirina--;
				j--;
				i=visina;
			}
		}
	}

	return sirina;
}

void ispisi_matricu(int matrica[100][100],int visina,int sirina)
{
	int i,j;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}


int main()
{
	int i,j,matrica[100][100],visina,sirina,c;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");
	c=sirina;

	for(j=0; j<sirina; j++) {

		c=izbaci_kolone(matrica,visina,c,max(matrica,visina,c));
		if(c) {
			printf("Nakon %d. prolaza matrica glasi:\n",j+1);
			ispisi_matricu(matrica,visina,c);

		} else {
			printf("Nakon %d. prolaza matrica je prazna!", j+1);
			j=sirina;
		}
	}
	return 0;
}
