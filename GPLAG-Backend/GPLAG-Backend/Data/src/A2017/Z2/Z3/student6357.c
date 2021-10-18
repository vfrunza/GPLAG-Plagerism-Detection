#include <stdio.h>

int main() {
	int a,b,m,n,i,j,nizA[100][100],nizB[100][100],istina=1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&b,&a);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%d",&nizA[i][j]);
		}
	}printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&n,&m);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&nizB[i][j]);
		}
	}for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(a>n || b>m || n>a || m>b) istina=0;
			else {
				if(nizA[i][j]!=nizB[j][n-i-1]){
				 istina=0;
				 break;
		}
	}}}if(istina) printf("DA");
	else printf("NE");
	return 0;
}
