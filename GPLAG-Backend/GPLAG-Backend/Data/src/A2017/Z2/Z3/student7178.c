#include <stdio.h>
#include <math.h>
# define visina 100
# define sirina 100


int main() {
	int i,j, mat1[visina][sirina], mat2[visina][sirina],n,m,k,r,jednak;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &m, &n);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<n; i++){
		for(j=0; j<m;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &k, &r);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<r; i++){
		for(j=0; j<k;j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	
	if(n==r && m==k || n==k && r==m) {
		jednak=1;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(!(fabs(mat1[i][j]-mat2[j][n-1-i])<0.000001)){
					jednak=0;
					break;
				}
			}
		}
		
if (jednak)printf("DA");
else printf("NE");
		}
	else printf ("NE");

	return 0;
}
