#include <stdio.h>
#include <math.h>
int main() {
	int m=0,n=0,i;
	int A[101];
	int C[101];
	int B[101];
	int a[100001] = {0};
	int b[100001] = {0};
	int c[100001] = {0};
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}while(m > 100 || m < 0 || n > 100 || n < 0 );
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < m*n; i++){
		scanf("%d", &A[i]);
	}
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < m*n; i++){
		scanf("%d", &B[i]);
	}printf("Unesite clanove matrice C: ");
	for(i = 0; i < m*n; i++){
		scanf("%d", &C[i]);
	}
	
	for(i = 0; i < m*n; i++){
		if(A[i] > 0){
			a[A[i]] = a[A[i]] + A[i];
		}else{
			a[A[i]] = a[-1*(A[i])] + (A[i]);
		}
	}
	for(i = 0; i < m*n; i++){
		if(B[i] > 0){
			b[B[i]] = b[B[i]] + B[i];
		}else{
			b[B[i]] = b[-1*(B[i])] + B[i];
		}
	}
	for(i = 0; i < m*n; i++){
		if(C[i] > 0){
			c[C[i]] = c[C[i]] + C[i];
		}else{
			c[C[i]] = c[-1*(C[i])] + C[i];
		}
	}
	for(i = 0; i < 10001; i++){
		if(a[i] == b[i] && b[i] == c[i] && c[i] == a[i]){
			
		}else{
			break;
		}
		/*printf("%d", a[i]);
		printf("%d", b[i]);
		printf("%d", c[i]);*/
	}
	if(i == 10001){
		printf("DA");
	}else{
		printf("NE");
	}
	return 0;
}
