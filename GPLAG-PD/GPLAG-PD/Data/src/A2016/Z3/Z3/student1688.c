#include<stdio.h>
int main() {
	int matrica[500][500],i,j,m,n,k,l,t,moze;
	/* Osiguravamo da su brojevi u trazenom opsegu */
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
		if(m<=0 || m>200 || n<=0 || n>200)
		printf("Brojevi nisu u trazenom opsegu. \n");
	}while(m<=0 || m>200 || n<=0 || n>200);
	
	/* Unosimo elemnte mtrice */
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&matrica[i][j]);
	
	i=0;
	/* Fiksirali smo prvi red matrice i poredili ga sa ostalim redovima */
	while(i<m){
		k=i+1;
		while(k<m){
			/* Pretpostavili smo da su svi elemnti isti i trazili prvi koji se razlikuje */
			moze=1;
			for(j=0;j<n;j++){
				if(matrica[k][j]!=matrica[i][j])
				moze=0;
			}
			/* Izbacivanje reda koji se ponavlja iz matrice pri ocuvanju redoslijeda */
			if(moze){
				for(l=k;l<m-1;l++)
				for(t=0;t<n;t++)
				matrica[l][t]=matrica[l+1][t];
				m--;
				k--;
			}
			k++;
		}
		i++;
	}
	i=0;
	/* Fiksirali smo prvu kolonu matrice i poredili je sa ostalim kolonama */
	while(i<n){
		k=i+1;
		while(k<n){
			/* Pretpostavili smo da su svi elementi isti i trazili prvi koji se razlikuje */
			moze=1;
			for(j=0;j<m;j++){
				if(matrica[j][k]!=matrica[j][i])
				moze=0;
			}
			/*Izbacivanje kolone koja se ponavlja iz matrice pri ocuvanju redoslijeda */
			if(moze){
				for(t=0;t<m;t++)
				for(l=k;l<n-1;l++)
				matrica[t][l]=matrica[t][l+1];
				n--;
				k--;
			}
			k++;
		}
		i++;
	}
	/* Nakon izbacivanja redova i kolona koje se ponavljaju matrica glasi */
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		printf("%5d",matrica[i][j]);
	}
	printf("\n");
	
}
return 0;
} 