#include <stdio.h>

int max(int [100][100],int,int);
int izbaci_kolone(int [100][100],int,int,int);

int main()
{
	int i,j;
	int mat[100][100];
	int m,n,x=1;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&n,&m);

	for(i=0; i<m; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<n; j++)
			scanf("%d",&mat[i][j]);
	}

	printf("\n");

	while(n!=0) {
		n=izbaci_kolone(mat,m,n,max(mat,m,n));

		if(n==0) {
			printf("Nakon %d. prolaza matrica je prazna!\n",x);
			break;
		}

		printf("Nakon %d. prolaza matrica glasi:\n",x);
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++)
				printf("%5d",mat[i][j]);
			printf("\n");
		}

		printf("\n");
		x++;
	}

	return 0;
}

int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,k,l;
	int element=0,brojac=0,temp_element,temp_brojac;

	/* Trazenje elementa  sa najvecim brojem ponavljanja ('max')*/
	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			temp_element=matrica[j][i];
			temp_brojac=0;
			for(k=0; k<visina; k++)
				for(l=0; l<sirina; l++)
					if(matrica[k][l]==temp_element)
						temp_brojac++;

			if(temp_brojac>=brojac) {
				if(temp_brojac==brojac) /* Ako se dva elementa ponavljaju isti broj puta, uzima se manji */
					element=element>temp_element?temp_element:element;
				else
					element=temp_element;
				brojac=temp_brojac;
			}
		}
	}

	return element;
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N)
{
	int i,j,k,l;

	for(i=0; i<visina; i++)
		for(j=0; j<sirina; j++)
			if(matrica[i][j]==N) {
				for(l=j; l<sirina-1; l++)
					for(k=i; k<visina; k++)
						matrica[k][l]=matrica[k][l+1];
				sirina--;
				j--;
			}

	return sirina;
}