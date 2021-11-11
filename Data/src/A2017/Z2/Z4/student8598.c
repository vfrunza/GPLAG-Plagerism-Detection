#include <stdio.h>
#define M 100
#define N 100

int main() {
	int m,n,A[M][N],C[M][N],B[M][N],i,j,element,k,x,jest=0,brojac1=0,brojac2=0,brojac3=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);}
	while(m>100 || n>100);;
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++){
	for(j=0; j<n; j++){
	scanf("%d", &A[i][j]);}}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++){
	for(j=0; j<n; j++){
	scanf("%d", &B[i][j]);}}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++){
	for(j=0; j<n; j++){
	scanf("%d", &C[i][j]);}}
	for(i=0; i<m; i++){
	for(j=0; j<n; j++){
	element=A[i][j];
	for(k=0; k<m; k++){
	for(x=0; x<n; x++){
	if(element==A[k][x]) brojac1++;
	if(element==B[k][x]) brojac2++;
	if(element==C[k][x]) brojac3++;
	}}
	if(brojac1!=brojac2 || brojac2!=brojac3){
	printf("NE\n");
	brojac1=0;
	brojac2=0;
	brojac3=0;
	return 0; }}}
	printf("DA\n");
	return 0;
}
