#include <stdio.h>
int main() {

int i,j,niz[10],niz1[10],k,n,mat[20][20];
printf("Unesite broj tacaka: ");
scanf("%d",&n);
while(n<=0 || n>10)
{ printf("Pogresan unos\n");
printf("Unesite broj tacaka: ");
scanf("%d",&n); }
for(i=0;i<20;i++){
    for(j=0;j<20;j++)
        mat[i][j]=0;}
        
for(k=0;k<n;k++){
   { printf("Unesite %d. tacku: ", k+1);
    scanf("%d %d", &niz[k], &niz1[k]);}
    if((niz[k]>=20) || (niz1[k]>=20) || (niz[k]<0) || (niz1[k]<0)){
        printf("Pogresan unos\n");
        k--;}}
        
for(k=0;k<n;k++)
{ for(i=0;i<20;i++)
{ for(j=0;j<20;j++)
if(i==niz1[k] && j==niz[k])
mat[i][j]=1; }}
for(i=0;i<20;i++){
    for(j=0;j<20;j++){
        if(mat[i][j]==1) 
        printf("*");
        else if(mat[i][j]==0) printf(" ");}
        printf("\n");
    }

	return 0;
}
