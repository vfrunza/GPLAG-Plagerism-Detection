#include <stdio.h>
#include <stdlib.h>

int main() {
	int mat[200][200], i,j,k,m,n,p,l,jednakiredovi,jednakekolone;
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&m,&n);
	do { if (m<1 || n<1|| m>200 || n>200){
		printf("Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: ");
		scanf("%d%d", &m, &n);
	}}
	while (m<1 || n<1 || m>200 || n>200);
	
/*Unos elemenata matrice*/
	
    printf("Unesite elemente matrice: ");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &mat[i][j]);
		}
	}

/*for(i=0;i<m;i++){
	for (j=0;j<n;j++){
		printf("%5d", mat[i][j]);
	}
	printf("\n");}*/	


/*Poredi elemente po redovima*/
for(i=0;i<m;i++){
	for(j=i+1;j<m;j++){
		jednakiredovi=1;
		for (k=0;k<n;k++){
			if (mat[i][k]!=mat[j][k]){
				jednakiredovi=0;
				break;
			}
		}
/*izbacivanje redova koji su isti*/	
/* P=i je red koji se treba izbaciti, a l su kolone*/
	if (jednakiredovi==1){
	for (p=j+1;p<m;p++){
		for(l=0;l<n;l++){
			mat[p-1][l]=mat[p][l];}}
			m--;
			j--;
	}
}}
/*for(i=0;i<m;i++){
	for (j=0;j<n;j++){
		printf("%5d", mat[i][j]);
	}
	printf("\n");} */

/*poredenje elemenata po kolonama*/
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		jednakekolone=1;
		for (k=0;k<m;k++){
			if (mat[k][i]!=mat[k][j]){
				jednakekolone=0;
				break;
			}
		}
/*izbacivanje kolona koje su iste*/	

	if (jednakekolone==1){
	for (p=j+1;p<n;p++){
		for(l=0;l<m;l++){
			mat[l][p-1]=mat[l][p];
		}}
		n--;
		j--;
		
	}
}}


/*ispis nove matrice*/

printf("Nakon izbacivanja redova/kolona matrica glasi: ");
printf("\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
 printf("%5d", mat[i][j]);}
 printf("\n");
}
return 0;}





	
	