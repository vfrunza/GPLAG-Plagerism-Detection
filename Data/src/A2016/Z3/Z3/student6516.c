#include <stdio.h>
#include <stdlib.h>

int main() {
int mat[200][200];
	int i,j,k,p,q,m,n;

do { printf("Unesite brojeve M i N: ");
 scanf("%d %d",&m,&n);
if(m<=0 || m>=200 || n<=0 || n>=200) 
 printf("Brojevi nisu u trazenom opsegu.\n");}
while(m<=0 || m>=200 || n<=0 || n>=200);
 printf("Unesite elemente matrice: ");
 
for(i=0;i<m;i++){
for(j=0;j<n;j++){
 scanf("%d", &mat[i][j]);} }
 printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
for(i=0;i<m;i++){
for(j=i+1;j<m;j++){
int jednaki=1;
for(k=0;k<n;k++){
if(mat[i][k]!=mat[j][k]){
jednaki=0;
break;
}}
if(jednaki==1){
for(p=j+1;p<m;p++){
for(q=0;q<n;q++){
mat[p-1][q]=mat[p][q];}}
    m--;
    j--;
}}}
/*for(i=0;i<m;i++){
for(j=0;j<n;j++){
 printf("%d", mat[i][j]);
}
printf("\n");}*/
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
int jednaki=1;
for(k=0;k<m;k++){
if(mat[k][i]!=mat[k][j]){
jednaki=0;
break;
}}
if(jednaki==1){
for(p=j+1;p<n;p++){
for(q=0;q<m;q++){
mat[q][p-1]=mat[q][p];}}
    n--;
    j--;
 
}}}
 printf("\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
 printf("%5d", mat[i][j]);}
 printf("\n");
}
return 0;
}

