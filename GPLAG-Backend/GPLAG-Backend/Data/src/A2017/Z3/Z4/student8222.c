#include <stdio.h>
int max(int matrica[100][100],int visina,int sirina)
{
	int i,j,maximum,,niz[10000];
	for (i=0;i<visina;i++) {
		for (j=0;j<sirina;j++) {
			for (m=0;m<visina+sirina;m++)
			{
				niz[m]=matrica[i][j];
			}
		}
	}
	int i,najveci=0,tmp=0,indeks,drugi=0;
    for (i=0; i<vel; i++) {
        if (niz[i]>=najveci) najveci=niz[i];
    }
    for (i=vel-1;i>=0;i--)
    {
        if (niz[i]>=drugi && niz[i]!=najveci)
        {
            drugi=niz[i];
            indeks=i;
            tmp=1;
        }
    }
    if (najveci==0 || tmp==0) indeks=-1;
	return maximum;
}
int main() {
	int i,j,n,m,M[100][100];
	printf("Unesite visinu i sirinu matrice: ");
	scanf("%d %d",&n,&m);
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			printf("Unesite elemente %d. reda: ",j);
			scanf("%d",&M[i][j]);
		}
	}
	return 0;
}
