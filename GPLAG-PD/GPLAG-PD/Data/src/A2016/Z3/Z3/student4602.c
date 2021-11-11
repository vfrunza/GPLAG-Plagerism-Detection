#include <stdio.h>

int main() {
	int matrica[200][200];
	int r,k;
	int i,j,k1,pomocna=1,q,h;
do{
		printf("Unesite brojeve M i N: ");
		scanf("%d" "%d" ,&r,&k);
		if(r>200||r<=0||k<=0||k>200)printf("Brojevi nisu u trazenom opsegu.\n");
		
	}	while(r<=0||r>200||k<=0||k>200);
	printf("Unesite elemente matrice: ");
for(i=0;i<r;i++){
	for(j=0;j<k;j++){
		scanf("%d",&matrica[i][j]);
	}
}
for(i=0;i<r;i++){
	for(j=i+1;j<r;j++){pomocna=1;
	for(k1=0;k1<k;k1++){
		if(matrica[i][k1]!=matrica[j][k1])pomocna=0;}
		if(pomocna==1){
		for(q=j;q<r-1;q++)
		for(h=0;h<k;h++)matrica[q][h]=matrica[q+1][h];
		r--;
		j--;
		
			
		}
	}
		
	}
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			pomocna=1;
			for(k1=0;k1<r;k1++){if(matrica[k1][i]!=matrica[k1][j])pomocna=0;}
				if(pomocna==1){
		for(q=0;q<r;q++)
		for(h=j;h<k-1;h++)matrica[q][h]=matrica[q][h+1];
		k--;
		j--;
		
			
		}
		}
	}
printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<r;i++){
	for(j=0;j<k;j++){
		printf("%5d",matrica[i][j]);
	}printf("\n");
}
	return 0;
}
