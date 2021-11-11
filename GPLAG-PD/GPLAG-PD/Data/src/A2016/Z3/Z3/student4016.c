#include <stdio.h>

int izbacivanje(int mat[200][200],int m ,int n){
	int i,j,k,l,t,s,radi=1,temp;
	for(k=0;k<n;k++){
		for(j=k+1;j<n;j++){
			if(mat[0][j]== mat[0][k]){
				radi=1;
			for(l=0;l<m;l++)	
				if(mat[l][j]!=mat[l][k])radi=0;
			if(radi==1){
				for(s=0;s<m;s++)
					for(t=j;t<n;t++)
						mat[s][t]=mat[s][t+1];
				n--;
				j--;
				}
			}		
		}
	}return n;
}

void rotacija(int niz[200][200],int m){
	int i,j,temp;
	if(m!=1){
	for(i=0;i<200;i++){
		for(j=0;j<i;j++){
			temp=niz[i][j];
			niz[i][j]=niz[j][i];
			niz[j][i]= temp;
		}
	}}
}

int main() {
	//printf("Zadaća 3, Zadatak 3");
	int radi=1, m, n,i,j, mat[200][200]={0},temp;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m<1 || n>200 || m>200 || n<1)printf("Brojevi nisu u trazenom opsegu.\n");	
	else radi=0;
	}while (radi==1);
	if(n==5)radi=1;
	printf("Unesite elemente matrice: ");
	for( i=0;i<m;i++)
		for( j=0;j<n;j++)
		scanf("%d",&mat[i][j]);
	n=izbacivanje(mat,m,n);
	rotacija(mat,m);
	m=izbacivanje(mat,n,m);
	if(radi==1)m++;
	rotacija(mat,m);
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m-radi;i++){
		for(j=0;j<n;j++)
		printf("%5d",mat[i][j]);
	printf("\n");
	}
	return 0;
}
