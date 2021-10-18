#include <stdio.h>
int sadrzi_kopiju(int matrica[100][100],int visina,int sirina,int broj,int indeks)
{
	int i,j;
	for(i=0;i<visina;i++)
	{
       if(niz[i]==broj && i>indeks)
       return 0;
	}
	return 1;
}

int main() {
	int i,j,sirina,visina,matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina,&visina);
	
	for(i=0;i<visina;i++)
	{   printf("Unesite elemente %d. reda:",i+1);
		for(j=0;j<sirina;j++)
		{
			scanf("%d", &matrica[i][j]);
		}
	}

	return 0;
}
