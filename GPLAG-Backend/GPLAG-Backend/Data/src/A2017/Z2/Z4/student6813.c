#include <stdio.h>
#define VELICINA 100
int main() {
int i,j,k,m,n,l,x;
int mat_a[VELICINA][VELICINA],mat_b[VELICINA][VELICINA],mat_c[VELICINA][VELICINA];
int brojac_a=0,brojac_b=0,brojac_c=0;
do {
printf("Unesite brojeve M i N: ");
    scanf("%d %d",&m,&n);
} while(m>100 || n>100);
printf("Unesite clanove matrice A: ");
for(i=0;i<m;i++)
for(j=0;j<n;j++){
    scanf("%d",&mat_a[i][j]);
}
printf("Unesite clanove matrice B: ");
for(i=0;i<m;i++)
for(j=0;j<n;j++){
    scanf("%d",&mat_b[i][j]);
}
printf("Unesite clanove matrice C: ");
for(i=0;i<m;i++)
for(j=0;j<n;j++){
    scanf("%d",&mat_c[i][j]);
}
for(i=0;i<m;i++)
for(j=0;j<n;j++){
    
    x=mat_a[i][j];
    
    for(k=0;k<m;k++)
    for(l=0;l<n;l++){

if(mat_a[k][l]==x){
    brojac_a++;
}
if(mat_b[k][l]==x){
    brojac_b++;
}
if(mat_c[k][l]==x){
    brojac_c++;
}

}
if(brojac_a!=brojac_b || brojac_a!=brojac_c || brojac_b!=brojac_c){
    printf("NE");
    return 0;
}
}
    printf("DA");


	return 0;
}
