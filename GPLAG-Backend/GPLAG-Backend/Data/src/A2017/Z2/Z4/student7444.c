#include <stdio.h>

int main() {
	int A[100] = {0}, B[100] = {0}, C[100] = {0},D[2][100] = {{0}}, i,j,k,in=0, count=0,m,n,qw=0;

	do{printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}while(!(m<=100) && !(n<=100));
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m*n;i++) {
		scanf("%d", &A[i]);
	
	}

	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m*n;i++) {
		scanf("%d", &B[i]);
	
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m*n;i++) {
		scanf("%d", &C[i]);
	
	}

	for(i=0;i<m*n;i++) {
		for(k=0;k<i;k++) {
			if(A[k]==A[i] && i!=0) {
				qw=1;
				break;
			} else {
				qw=0;
			}
		}
		if(!qw) {
		for(j=0;j<m*n;j++) {
			if(A[i]==B[j]) {
				count++;
			}
		}
		D[0][in] = A[i];
		D[0][in+1] = count;
		in+=2;
		count=0;
	}
	}
	
	in=0;
qw=0;
for(i=0;i<m*n;i++) {
		for(k=0;k<i;k++) {
			if(C[k]==C[i] && i!=0) {
				qw=1;
				break;
			} else {
				qw=0;
			}
		}
		if(!qw) {
		for(j=0;j<m*n;j++) {
			if(C[i]==A[j]) {
				count++;
			}
		}
		D[2][in] = C[i];
		D[2][in+1] = count;
		in+=2;
		count=0;
	}
	}

	in=0;
qw=0;
	for(i=0;i<m*n;i++) {
		for(k=0;k<i;k++) {
			if(B[k]==B[i] && i!=0) {
				qw=1;
				break;
			} else {
				qw=0;
			}
		}
		if(!qw) {
		for(j=0;j<m*n;j++) {
			if(B[i]==C[j]) {
				count++;
			}
		}
		D[1][in] = B[i];
		D[1][in+1] = count;
		in+=2;
		count=0;
	}
	}

		for(i=0;i<in;i++) {
			if(qw) {
		for(k=0;k<in;k++) {
			if(D[0][k]!=D[1][i] && i!=0 && D[2][k]!=D[1][i]) {
				qw=0;
				break;
			} else if (D[0][k]==D[1][i] && D[2][k]==D[1][i]) {
				qw=1;
			}
		}
			}
}
	if(qw) {
		printf("DA");
	} else {
		printf("NE");
	}
	return 0;
}
