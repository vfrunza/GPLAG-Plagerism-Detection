#include <stdio.h>

int main() {
	int matrica[100][100],m,n,i,j,k,l,p,c,r,s;
	p=0;
	s=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || m>200 || n<1 || n>200) 
		printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<1 || m>200 || n<1 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		scanf("%d",&matrica[i][j]);
	}
	
	for(i=0;i<m;i++){
		if(p==1)
		i--;
		for(k=i+1;k<m;k++){
			c=0;                                                  /*c=kolona, r=red*/
			while(c<n){
				if(matrica[i][c]==matrica[k][c]) p=1;
				else {
					p=0;
					break;
				}
				c++;
			}
			if(p==1){
				for(j=k;j<m-1;j++){
					for(l=0;l<n;l++) matrica[j][l]=matrica[j+1][l];
				}
			m--;
			k--;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(s==1)
		i--;
		for(k=i+1;k<n;k++){
			r=0;
			while(r<m){
				if(matrica[r][i]==matrica[r][k]) s=1;
				else{
					s=0;
					break;
				}
				r++;
			}
			if(s==1){
				for(j=k;j<n;j++){
					for(l=0;l<m;l++) 
					matrica[l][j]==matrica[l][j+1];
				}
				n--;
				k--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		printf("%5d",matrica[i][j]);
		printf("\n");
	}
	
	return 0;
}
