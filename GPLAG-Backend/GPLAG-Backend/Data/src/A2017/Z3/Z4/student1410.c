#include <stdio.h>

int max(int matrica[100][100],int visina,int sirina)
{
	int br,brojac=0,temp,i,j,ponavljanje=0,q,m;
	int max=0;
	int prvi=matrica[0][0];
	for(i=0; i<visina; i++) {

		for(j=0; j<sirina; j++) {

			br=matrica[i][j];

			for(q=0; q<visina; q++)
				for(m=0; m<sirina; m++) {
					ponavljanje=matrica[q][m];
					if(br==ponavljanje)
						brojac++;
				}

			if(brojac>=max) {
				temp=prvi;
				prvi=br;
				if(brojac==max && br>temp)
					prvi=temp;

				max=brojac;



			}
			brojac=0;


		}
	}

	return prvi;

}
int izbaci_kolone (int matrica[100][100],int visina,int sirina,int N)
{
	int v,s,i,k,j,w;
	v=visina;
	s=sirina;

	for(i=0; i<v; i++)
		for(j=0; j<s; j++) {
			if(matrica[i][j]==N) {
				for(k=j; k<s; k++)
					for(w=0; w<v; w++)
						matrica[w][k]=matrica[w][k+1];
				s--;
			}
		}




	return s;

}
int main()
{
	int i,j,visina,sirina,mat[100][100],brojac_1=0,l,rez,z;
	int s;

	int r=1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++)
			scanf("%d",&mat[i][j]);
	}

	do {
		z=0;
		if(sirina>1)
			while(z<visina) {
				for(l=1; l<sirina; l++)
					if (mat[z][0]== mat[z][l])
						brojac_1++;

	s=sirina;
				if(brojac_1==s) {
					printf("\nNakon 1. prolaza matrica je prazna!");
					return 0;
				} else {
					brojac_1=0;
					z++;

				}

			}

		rez=max(mat,visina,sirina);
		sirina=izbaci_kolone(mat,visina,sirina,rez);

		if(sirina !=0) {

			printf("\nNakon %d. prolaza matrica glasi:\n",r);
			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					if(j==0 && mat[i][0]<10)
						printf("    ");
					else if(j==0 && mat[i][0]>=10)
						printf("   ");
					else if(j==0 && mat[i][0]>=100)
						printf("  ");


					if(j==sirina-1)
						printf("%-5d",mat[i][j]);
					if(j!=sirina-1)
						printf("%-5d",mat[i][j]);
				}
				printf("\n");
			}
		} else{
			printf("\nNakon %d. prolaza matrica je prazna!",r);
			return 0;
		}
		r+=1;
		} while(sirina!=0);




	return 0;
}
