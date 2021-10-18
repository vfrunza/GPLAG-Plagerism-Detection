#include <stdio.h>

int main() {
	int m, n, i, j, k, l, da=1;
	int a[101][101], b[101][101], c[101][101];
	int brojaci_a[101][101]={{0}}, brojaci_b[101][101]={{0}}, brojaci_c[101][101]={{0}};
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	}while (m>100 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &b[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &c[i][j]);
		}
	}
	
	/*upisivanje u matricu brojaci od a*/
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			for(k=0; k<101; k++){
				for(l=0; l<101; l++){
				if(a[i][j]==(n*k + l)) brojaci_a[k][l]++;	
				}
			}
		}
	}
	
	/*upisivanje u matricu brojaci od b*/
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			for(k=0; k<101; k++){
				for(l=0; l<101; l++){
				if(b[i][j]==(n*k + l)) brojaci_b[k][l]++;	
				}
			}
		}
	}
	
	/*upisivanje u matricu brojaci od c*/
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			for(k=0; k<101; k++){
				for(l=0; l<101; l++){
				if(c[i][j]==(n*k + l)) brojaci_c[k][l]++;	
				}
			}
		}
	}
	
	/*provjera*/
	for(i=0; i<101; i++){
		for(j=0; j<101; j++){
			if(brojaci_a[i][j]!=brojaci_b[i][j] || brojaci_b[i][j]!=brojaci_c[i][j]){
				da=0; break;
			}
		}
	}
	
	if(da) printf("DA");
	else printf("NE");
	return 0;
}
