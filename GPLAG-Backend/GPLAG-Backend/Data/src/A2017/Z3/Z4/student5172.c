#include <stdio.h>

/* izbacujem kolonu zadanu parametrom @param kolona */
void izbaci_kolonu(int mat [100][100], int br_redova, int br_kolona, int kolona)
{
	int i = kolona, next = kolona + 1;
	for(; next < br_kolona; ++next, ++i)
	{
		int j = 0;
		for(; j < br_redova; ++j)
			mat[j][i] = mat[j][next];
	}
		
}

int izbaci_kolone(int mat[100][100], int br_redova, int br_kolona, int val)
{
	if(br_kolona == 0 || br_redova == 0)
		return br_kolona;
	/* prolazim kroz matricu i trazim koje kolone treba izbaciti */
	int i = 0;
	for(; i < br_kolona; ++i)
	{
		int j = 0;
		for(; j < br_redova; ++j)
			/* naso sam element brisem kolonu */
			if(mat[j][i] == val)
			{
				izbaci_kolonu(mat, br_redova, br_kolona, i);
				/* izbrisao kolonu smanjjem velcinu za 1 */
				--br_kolona;
				--i;
				break;
			}
	}
	return br_kolona;
}

/* funkcija koja prebrojava ponavljanje @param val unutar @param mat */
int count(int mat[100][100], int br_redova, int br_kolona, int val)
{
	int brojac = 0;
	int i = 0;
	for(; i < br_redova; ++i)
	{
		int j = 0;
		for(; j < br_kolona; ++j)
			if(mat[i][j] == val)
				++brojac;
	}
	return brojac;
}

int max(int mat[100][100], int br_redova, int br_kolona)
{
	if(br_redova == 0 || br_kolona == 0)
		return br_kolona;
		
	int ref_r = 0, ref_k = 0;
	int ref_ponavlja = count(mat, br_redova, br_kolona, mat[0][0]);
	int i = 0;
	
	for(; i < br_redova; ++i)
	{
		int j = 0;
		for(; j < br_kolona; ++j)
			if(mat[i][j] != mat[ref_r][ref_k])
			{
				int nova_pon = count(mat, br_redova, br_kolona, mat[i][j]);
				if(nova_pon == ref_ponavlja && mat[i][j] < mat[ref_r][ref_k])
				{
					ref_r = i;
					ref_k = j;
				}
				else if(nova_pon > ref_ponavlja)
				{
				 	ref_ponavlja =	nova_pon;
				 	ref_r = i;
					ref_k = j;
				}
			}
	}
	return mat[ref_r][ref_k];
}


int main() 
{
	int mat[100][100];
	int sirina, visina;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d", &sirina);
	scanf("%d", &visina);
	int i = 0;
	for(; i < visina; ++i){
		printf("Unesite elemente %d. reda: ", i + 1);
		int j = 0;
		for(;j < sirina; ++j)
			scanf("%d", &mat[i][j]);
	}
	printf("\n");
	i = 1;
	int br_k = sirina;
	for(;;++i)
	{
		int br = max(mat, visina, br_k);
		br_k = izbaci_kolone(mat, visina, br_k, br);
		
		if(br_k == 0)
		{
			printf("Nakon %d. prolaza matrica je prazna!", i);
			return 0;
		}
		
		printf("Nakon %d. prolaza matrica glasi:\n", i);
		
		int j = 0;
		for(; j < visina; ++j)
		{
			int k = 0;
			for(; k < br_k; ++k)
				printf("%5d", mat[j][k]);
			printf("\n");
		}
		printf("\n");
		
	}
	return 0;
}
