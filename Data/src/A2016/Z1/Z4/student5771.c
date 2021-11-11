#include <stdio.h>

int main() {
int i,n,m,p,l,j,k,o,r,s,u,z,v,b;
printf("Unesite broj n:");
do{
scanf("%d", &n);
if(n<=0 || n>50)
    { 
printf(" Pogresan unos"); 
printf("\nUnesite broj n:");
    }
    } while(n<=0 || n>50);
if(n>=1 && n<=50)
{
 m=1;
 p=2*n-3;
 l=n;
 k=1;
 r=2*(n-1)-3;
 u=1;
 v=2*(n-1)-3;
 b=n;
 printf(" "); for(i=1; i<=m; i++){ printf("*");} for(i=1; i<=p; i++){ printf(" ");} printf("*"); 
 for(i=1; i<=p; i++) { printf(" ");} printf("*"); printf("\n");
 for(i=1; i<=n-2; i++)
    {
 for(j=1; j<=k; j++) { printf(" "); }k++;printf("*");
  for(o=1; o<=r; o++){printf(" ");} r=r-2; printf("*");
  for(s=1; s<=u; s++){ printf(" ");}u=u+2; printf("*");
  for(z=1; z<=v; z++){printf(" ");} v=v-2; printf("*");
 printf("\n");
     }
 if(b>1) {for(i=1; i<l; i++){printf(" ");} printf("*"); 
 for(i=1; i<=p; i++){ printf(" ");} printf("*"); }
    }
 return 0;
}
