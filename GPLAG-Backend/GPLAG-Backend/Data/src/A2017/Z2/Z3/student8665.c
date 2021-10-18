#include <stdio.h> 
#include <math.h> 
#define EPS 0.0000000001
int main()
{
	double a[250][250],b[250][250],c[250][250];
	int a1=0,a2=0,b1=0,b2=0,i=0,j=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&a1,&a2);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<a2; i++) {
		for(j=0; j<a1; j++) {
			scanf("%lf",&a[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&b1,&b2);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<b2; i++) {
		for(j=0; j<b1; j++) {
			scanf("%lf",&b[i][j]);
		}
	}
	if(b2!=a1 || b1!=a2) {
		printf("NE");
		return 0;
	}
	for(i=0; i<a2; i++) {
		for(j=0; j<a1; j++) {
			c[j][i]=a[a2-i-1][j];
		}
	}
	for(i=0; i<b2; i++) {
		for(j=0; j<b1; j++) {
			if(fabs(c[i][j]-b[i][j])>EPS*(fabs(c[i][j])+fabs(b[i][j]))) {
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	return 0;
}
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 0.000000000000001

int main()
{
	int m,n, a, b,i,j;
	double A[20][20], B[20][20], mat[20][20];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d", &a);
	scanf("%d", &b);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<a; i++) {
		for(j=0; j<b; j++) {
			scanf("%lf", &B[i][j]);
		}
	}
	if(m!=b || n!=a) {
		printf("NE");
		return 0;
	}

	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			mat[i][j]=A[n-1-i][j];
		}
	}
	if(m==b && n==a) {
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(fabs(mat[i][j]-B[i][j])>e*(fabs(mat[i][j])-fabs(B[i][j]))) {
				printf("NE");
					return 0;
				}
			}
		}
	}
	printf("DA");
	return 0;

	return 0;
}*/
