#include <stdio.h>

int main() {
	float a[100][100],b[100][100],c[100][100];
	int m1,m2,n1,n2,i,j;
	int rezultat = 1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m1,&n1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<n1;i++){
		for(j=0;j<m1;j++) scanf("%f",&a[i][j]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&m2,&n2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<n2;i++){
		for(j=0;j<m2;j++) scanf("%f",&b[i][j]);
	}
	if(m1==n2 && n1==m2){
		for(i=0;i<n2;i++){
			for(j=0;j<m2;j++){
				c[i][j]=a[n1-j-1][i];
			}
		}
		for(i=0;i<m1;i++){
			for(j=0;j<n1;j++){
				if(c[i][j]!=b[i][j]){
					rezultat = 0;
					break;
				}
			}
		}
		if(rezultat) printf("DA\n");
		else printf("NE\n");
	}
	else printf("NE\n");
	return 0;
}
