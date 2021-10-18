#include <stdio.h>

int main()
{
	printf("Unesite matricu: \n");
	int mat[100][100];
	int i,j;
	int vel_redova[1000] = {0};
	int niz_suma[1000] = {0};
	int visina=0;
	int x;

	for(i=0; i<100; i++) {
		for(j=0; j<100; j++) {
			scanf("%i",&mat[i][j]);
			if (mat[0][0] == -1) {
				printf("Nakon izbacivanja matrica glasi: \n");
				return 0;
			}
			if (i==1 && mat[1][0] == -1) {
				printf("Nakon izbacivanja matrica glasi: \n");
				return 0;
			} else if(mat[i][j] == -1 && j != 0) { /* AKO JE NEKI CLAN MATRICE -1 */
				for(x=0; x<j; x++) {
					niz_suma[i]+=mat[i][x];
				}
				vel_redova[i] = j;
				visina++;
				goto sljedeci;
			}/* KRAJ TOG ISPITIVANJA */
			else if(mat[i][0] == -1 && j==0) goto kraj;

		}
sljedeci:
		;
	}
kraj:
	;
	int max = -1;
	int broj;
	float sredina;

	for(i=0; i<visina; i++) {
		sredina = (float)(niz_suma[i]/vel_redova[i]);
		if(sredina == max) goto preskoci;
		if(sredina>max) max = sredina;
		broj = i;
preskoci:
		;
	}
//	printf("MINI TEST %i %i \n", max, broj); //MOJ MINI TEST
	for(i=broj-1; i<visina; i++) {
		for(j=0; j<vel_redova[i+1]; j++) {
			//for(x=i;x<vel_redova[];x++);
			mat[i][j] = mat[i+1][j];
		}
		vel_redova[i] = vel_redova[i+1];
	}
	visina--;
	printf("Nakon izbacivanja matrica glasi: \n");
	for(i=0; i<visina; i++) {
		for(j=0; j<vel_redova[i]; j++) {
			printf("%i",mat[i][j]);
			if(j!=vel_redova+1) printf(" ");
		}

		printf("\n");

	}



	return 0;
}
