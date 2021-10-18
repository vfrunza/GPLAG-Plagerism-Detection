#include <stdio.h>
#define MAX 100
#define max 1000
int main() {
int i,j,A[MAX][MAX],B[MAX][MAX],C[MAX][MAX],m,brojaciA[max]={0},brojaciB[max]={0},brojaciC[max]={0},n,k;
do{
printf("Unesite brojeve M i N: ");
scanf("%d %d", &m, &n);}
while (m>100 || n>100);
printf("Unesite clanove matrice A: ");
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%d", &A[i][j]);
	}
}printf("Unesite clanove matrice B: ");
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%d", &B[i][j]);
	}
}printf("Unesite clanove matrice C: ");
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%d", &C[i][j]);
	}
}for(k=0;k<max;k++){
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
if(k==A[i][j])
	brojaciA[k]++;
	else continue;	}}
	if(i==m-1 && j==n-1)break;	}
	
for(k=0;k<max;k++){
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
if(k==B[i][j])
brojaciB[k]++;
	else continue;	}}
	if(i==m-1 && j==n-1)break;	}
	
	for(k=0;k<max;k++){
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
if(k==C[i][j])
	brojaciC[k]++;
	else continue;	}}	
	if(i==m-1 && j==n-1)break;}


for(i=0;i<max;i++){
	if(brojaciA[i]!=brojaciB[i] || brojaciA[i]!=brojaciC[i] || brojaciB[i]!=brojaciC[i]){
		printf("NE\n");break;
	} else if(brojaciA[i]==brojaciB[i] && brojaciA[i]==brojaciC[i] && brojaciB[i]==brojaciC[i] ){if(i==max-1)printf("DA\n");	else continue; }

}
	


	return 0;
}
