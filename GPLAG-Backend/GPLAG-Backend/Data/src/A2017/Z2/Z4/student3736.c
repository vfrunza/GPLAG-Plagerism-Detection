#include <stdio.h>

int main() {

int M,N,i,j,k=0;
do {
printf("Unesite brojeve M i N: ");
scanf("%d %d", &M, &N);

}while(M<0 || M>100 || N<0 || N>100);
int A[100][100], B[100][100], C[100][100];
printf("Unesite clanove matrice A: ");
for(i = 0; i < M;i++) {
	for(j=0;j < N; j++) {
		scanf("%d", &A[i][j]);
	}
}
printf("Unesite clanove matrice B: ");
for(i = 0; i < M; i++) {
	for(j =0;j <N; j++) {
		scanf("%d", &B[i][j]);
	}
}
printf("Unesite clanove matrice C: ");
for(i=0; i < M; i++) {
	for(j = 0; j < N; j++) {
		scanf("%d", &C[i][j]);
	}
}
if(M==0 && N==0) { printf("DA"); return 0; }
int A1[10000], B1[10000], C1[10000];
for(i =0;i < M; i++) {
	for(j=0; j < N; j++) {
		A1[k] = A[i][j];
		k++;
	}
}
k=0;
for(i =0;i < M; i++) {
	for(j=0; j < N; j++) {
		B1[k] = B[i][j];
		k++;
	}
}
k=0;
for(i =0;i < M; i++) {
	for(j=0; j < N; j++) {
		C1[k] = C[i][j];
		k++;
	}
}
int min,temp;
for(i = 0; i < k; i++) {
	min = i;
	for(j=i+1; j < k; j++) {
		if(A1[j]<A1[min]) min = j;
	}
	temp = A1[i];
	A1[i] = A1[min];
	A1[min] = temp;
}
for(i = 0; i < k; i++) {
	min = i;
	for(j=i+1; j < k; j++) {
		if(B1[j] < B1[min]) min = j;
	}
	temp = B1[i];
	B1[i] = B1[min];
	B1[min] = temp;
}
for(i = 0; i < k; i++) {
	min = i;
	for(j = i+1; j < k; j++) {
		if(C1[j] < C1[min]) min = j;
	}
	temp = C1[i];
	C1[i] = C1[min];
	C1[min] = temp;
}
int tacno = 0, tacno2 = 0;
for(i = 0; i < k; i++) {
		if(A1[i] != B1[i]) { tacno = 0; break; }
	else tacno = 1;
}
for(i = 0; i < k; i++) {
	if(A1[i] != C1[i])  { tacno2 = 0; break; }
	else tacno2 = 1;
}
if(tacno == 1 && tacno2 == 1) { printf ("DA\n"); }
else printf("NE\n");
return 0;
}
