#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,t=0,k;
	int brojac=0;
	int maksimalan,brpon;
	int niz[10000];
	for(i=0;i<visina;i++)
	for(j=0;j<sirina;j++)
	{
		niz[t]=matrica[i][j];
		t++;
	}
	maksimalan=matrica[0][0];
	brpon=1;
	for(k=0;k<t;k++)
	{
	brojac=0;
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			if(niz[k]==matrica[i][j])
			brojac++;
		}
	}
	if(brojac>brpon || (brojac==brpon && niz[k]<=maksimalan))
	{
		maksimalan=niz[k];
		brpon=brojac;
	}
	}
	return maksimalan;
}
int main() {
	int matrica[100][100]={{1,2,3,4},{-1,-1,-1,-2},{3,2,4,7}};
	printf(" %d",max(matrica,3,4));
	return 0;
}
