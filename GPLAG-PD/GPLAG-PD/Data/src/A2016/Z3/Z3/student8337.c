#include <stdio.h>
#define BROJ_EL 200

int main() {
	int m, n, i, j, mat[BROJ_EL][BROJ_EL], nr1[BROJ_EL], nk1[BROJ_EL], k, h, f, a=0, z=0, q;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d", &m);
		scanf("%d", &n);
		if(m>BROJ_EL || n>BROJ_EL || m<1 || n<1){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}while(m>BROJ_EL || n>BROJ_EL || m<1 || n<1);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: ");
	
	for(i=0; i<m; i++){
		for(k=i; k<m; k++){
			for(h=0; h<n; h++){
				if(k==i){
					nr1[h]=mat[i][h];
				}else if(nr1[h]==mat[k][h]){
					a++;
					if(a==n){
						a=0;
						for(j=k; j<m; j++){
							for(f=0; f<n; f++){
								mat[j][f]=mat[j+1][f];
							}
						}
						m--;
						k--;
					}
				}else{
					a=0;
					break;
				}
			}
		}
	}
	
	for(i=0; i<n; i++){ 
		for(q=1; q<n; q++){
			nk1[q]=0;
		}
			for(j=0; j<m; j++){
				z=0;
				for(h=i; h<n; h++){
					if(h==i){
						a=mat[j][i];
					}else if(a==mat[j][h]){
						nk1[h]++;
						if(nk1[h]==m){
							for(k=0; k<m; k++){
								for(f=h; f<n; f++){
									mat[k][f]=mat[k][f+1];
								}
							}
							n--;
							nk1[h]=0;
							h--;
						}
					}else{
						z++;
					}
				}
				if(z==n-i-1) break;
			}
	}
	
	for(i=0; i<m; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%5d", mat[i][j]);
		}
	}
	return 0;
}
