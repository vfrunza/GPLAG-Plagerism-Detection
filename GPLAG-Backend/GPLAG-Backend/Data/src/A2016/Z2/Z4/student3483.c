#include <stdio.h>

int main() {
	int i, j, m, n, tep, cir;
	double A[100][100];
	tep=1;
	cir=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(m<1 || m>100 || n<1 || n>100)
			printf("Pogresan unos!\n");
	}
	while(m<1 || m>100 || n<1 || n>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%lf", &A[i][j]);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(i!=m-1 && j!=n-1){
				if(A[i][j]!=A[i+1][j+1])
					tep=0;
				if(j!=n-2)
                	if(A[i][j+1]!=A[i+1][j+2])
                		tep=0;
			}
		}
		for(j=0; j<n; j++){
			if(i!=m-1){
				if(A[i][n-1]!=A[i+1][0])
					cir=0;
				if(i!=m-1 && j!=n-1)
					if(A[i][j]!=A[i+1][j+1])
						cir=0;
			}
		}
	}
	if(cir==1)
	printf("Matrica je cirkularna");
	else if(tep==1)
		printf("Matrica je Teplicova");
	else if(cir==0 && tep==0)
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
