#include <stdio.h>

int main() {
	int i,j,a,b,c,d,A[10][10],B[10][10],pom,max=0,jednake;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&a,&b);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a;i++) {
		for(j=0;j<b;j++) {
			scanf("%d",&A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&c,&d);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<c;i++) {
		for(j=0;j<d;j++) {
			scanf("%d",&B[i][j]);
		}
	}
	if(a!=c && b!=d) { printf("NE"); return 0;}
    
	jednake=1;
    	for(i=0;i<a;i++) {
		for(j=0;j<b;j++) {
			if(A[j][i]!=B[i][j]) 
			jednake=0;
			
		}
	}
	if(jednake==1) printf("DA");
	else printf("NE");
	return 0;
}
