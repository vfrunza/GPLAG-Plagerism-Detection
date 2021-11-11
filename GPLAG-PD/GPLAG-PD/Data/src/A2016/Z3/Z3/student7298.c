#include <stdio.h>

int main() {
	int matrica[201][201],m,n,i,j,k,c,br;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
		if(m>0 && m<201 && n>0 && n<201) break;
		else printf("Brojevi nisu u trazenom opsegu.\n");
	}while(1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d", &matrica[i][j]);
	for(i=0;i<m;i++)
		for(k=i;k<m-1;k++){
			br=n;
			for(j=0;j<n;j++){
				if(matrica[i][j]==matrica[k+1][j]) br--;
				else break;
			}
			if(br==0){
				for(c=k+1;c<m-1;c++)
					for(j=0;j<n;j++)
						matrica[c][j]=matrica[c+1][j];
				m--;
				k--;
			}
		}
	for(j=0;j<n;j++)
		for(k=j;k<n-1;k++){
			br=m;
			for(i=0;i<m;i++){
				if(matrica[i][j]==matrica[i][k+1]) br--;
				else break;
			}
			if(br==0){
				for(c=k+1;c<n-1;c++)
					for(i=0;i<m;i++)
						matrica[i][c]=matrica[i][c+1];
				n--;
				k--;
			}
		}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(matrica[i][j]>9 && matrica[i][j]<100) printf("   %d", matrica[i][j]);
			else if(matrica[i][j]>99 && matrica[i][j]<1000) printf("  %d", matrica[i][j]);
			else if(matrica[i][j]>-10 && matrica[i][j]<0) printf("   %d", matrica[i][j]);
			else if(matrica[i][j]>-100 && matrica[i][j]<-9) printf("  %d", matrica[i][j]);
			else if(matrica[i][j]>-1000 && matrica[i][j]<-99) printf(" %d", matrica[i][j]);
			else printf("    %d", matrica[i][j]);
	 	
	 	}printf("\n");
	}
	return 0;
}
