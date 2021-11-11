#include <stdio.h>
#define M 100
#define N 100
int main() {
	int A[M][N], B[M][N], C[M][N], nizA[M*N], nizB[M*N], nizC[M*N];
	int i, j, m, n, k, t, p, min=0, temp, tacnost;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while(m>100 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &C[i][j]);
		}
	}
	/*pisanje matrice A kao niz*/
	k=0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			nizA[k++]=A[i][j];
		}
	}
	
	/*sortiranje niza A od manjeg ka vecem*/
	for (i=0; i<m*n; i++) {
		min=i;
		for (j=i+1; j<m*n; j++) {
			if (nizA[j] < nizA[min])
			min = j;
		}
		temp = nizA[i];
		nizA[i] = nizA[min];
		nizA[min] = temp;
 	}
	
	/*pisanje matrice B kao niz*/
	t=0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			nizB[t++]=B[i][j];
		}
	}
	
	/*sortiranje niza B od manjeg ka vecem*/
	for (i=0; i<m*n; i++) {
		min=i;
		for (j=i+1; j<m*n; j++) {
			if (nizB[j] < nizB[min])
			min = j;
		}
		temp = nizB[i];
		nizB[i] = nizB[min];
		nizB[min] = temp;
 	}
 	
 	/*pisanje matrice C kao niz*/
	p=0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			nizC[p++]=C[i][j];
		}
	}
	
	/*sortiranje niza C od manjeg ka vecem*/
	for (i=0; i<m*n; i++) {
		min=i;
		for (j=i+1; j<m*n; j++) {
			if (nizC[j] < nizC[min])
			min = j;
		}
		temp = nizC[i];
		nizC[i] = nizC[min];
		nizC[min] = temp;
 	}
 	
 	tacnost=1;
 	for (i=0; i<m*n; i++) {
 		if((nizA[i]!=nizB[i]) || (nizA[i]!=nizC[i])){
 			tacnost=0;
 		}
 	}
 	
 	if(tacnost){
 		printf("DA");
 	}
 	else{
 		printf("NE");
 	}
	return 0;
}
