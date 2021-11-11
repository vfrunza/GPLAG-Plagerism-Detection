#include <stdio.h>

int main() {
	int niz[200][200];
	int i,j,m,n,k,p,q,pret;
	 do {
	printf("\nUnesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	if((m>200 || n>200 || m<1 || n<1))
	printf("Brojevi nisu u trazenom opsegu.");
	} while(m<1 || m>200 || n<1 || n>200); 
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
	 for(j=0;j<n;j++){
	 	scanf("%d", &niz[i][j]);
	 }
	 }
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			pret=1;
			for(k=0;k<n;k++)
			if(niz[i][k]!=niz[j][k])
			      pret=0;
			if(pret==1)
			{
				for(p=j;p<m-1;p++)
				  for(q=0;q<n;q++)
				    niz[p][q]=niz[p+1][q];
				m--;
				j--;
			}
		}
	}

for(i=0;i<n;i++)
 {
	for(j=i+1;j<n;j++)
	{
		pret=1;
		for(k=0;k<m;k++)
		if(niz[k][i] != niz[k][j])
		pret=0;
		if(pret==1)
		{
			for(p=j;p<n-1;p++) 
			for(q=0;q<m;q++) 
			niz[q][p]=niz[q][p+1];
			n--;
			j--; 
			
		}
	}
}
printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0;i<m;i++){
	for(j=0;j<n;j++)
	{
		printf("%5d", niz[i][j]);
	}
	printf("\n");
}


	return 0;
}
