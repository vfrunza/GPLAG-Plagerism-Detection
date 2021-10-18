#include <stdio.h>

int main() {
	int sa,sb,va,vb,A[100][100] = {{0}, {0}},B[100][100]={{0}, {0}},D[100][100]= {{0}, {0}},T[100][100]= {{0}, {0}},i,j,a,b,t,k,z;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sa, &va);
	printf("Unesite clanove matrice A: ");
	t = 1;
	for(i=0;i<va;i++){
		for(j=0;j<sa;j++) {
			scanf ("%d",&a);
			A[i][j] = a;
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sb, &vb);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<vb;i++){
		for(j=0;j<sb;j++) {
			scanf ("%d",&b);
			B[i][j] = b;
		}
	}
if ((sa == sb && va != vb) || (sa != sb && va == vb) || (sa == sb && va==vb && sa != va && vb != sb) ) {
	t = 0;
} else {
if (sa == va && sb == vb) {
	for(i=0;i<va;i++){
		for(j=0;j<sa;j++) {
			D[i][j] = A[j][i];
		}
	}

	for(i=0;i<va;i++){
		for(j=0, k= va - 1;j<k;j++,k--) {
			T[i][j] = D[i][k];
			D[i][k] = D[i][j];
			D[i][j] = T[i][j];
			
		}
	}
} else {
	for(i=0;i<sa;i++){
			z = 0;
		for(j=va-1;j>=0;j--) {
			D[i][z] = A[j][i];
			z++;
		}
	}
}
}
	for(i=0;i<va;i++){
		for(j=0;j<sa;j++) {
			if (B[i][j] != D[i][j]){
				t = 0;
		}
	}
	}
	if (t == 1) {
		printf("DA");
	} else {
		printf("NE");
	}
	return 0;
}
