#include <stdio.h>

int main() {
int m=0, n=0, i=0, j=0, k=0, l=0, o=0, matrica[201][201], pomocna=0;
do{    printf("Unesite brojeve M i N: ");
       scanf("%d %d", &m, &n);
   	if(m>200 || n>200 || n<0 || m<0){printf("Brojevi nisu u trazenom opsegu.\n");}
}
while(m>200 || n>200 || n<0 || m<0);

printf("Unesite elemente matrice: ");
for(i=0; i<m; i++){
	for(j=0; j<n; j++){
		scanf("%d", &matrica[i][j]);
	}
}

for(i=0; i<m; i++){
	for(k=i+1; k<m; k++){
		for(j=0; j<n; j++){
			if (matrica[i][j]==matrica[k][j]) pomocna++;
		}
		
		if(pomocna==n){
			for(l=k; l<m-1; l++){
				for(o=0; o<n; o++){
					matrica[l][o]=matrica[l+1][o];
				}
			}
			k--;
			m--;
		}
		pomocna=0;
	}
}
	
for(i=0; i<n; i++){
	for(k=i+1; k<n; k++){
		for(j=0; j<m; j++){
			if(matrica[j][i]==matrica[j][k]) pomocna++;
		}
		if(pomocna==m){
			for(l=0; l<m; l++){
				for(o=k; o<n-1; o++){
					matrica[l][o]=matrica[l][o+1];
				}
			}
			k--;
			n--;
		}
			pomocna=0;
		}
	}


printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0; i<m; i++){
	for(j=0; j<n; j++){
		printf("%5d", matrica[i][j]);
	}
	printf("\n");
}
	return 0;
}
