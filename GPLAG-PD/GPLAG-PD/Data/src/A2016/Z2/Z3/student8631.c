#include<stdio.h>
#define vel 20
int main()
{
    int b[vel],  c[vel], n, i,j, k, max1, max2;
    int mat[vel][vel]={0};
    do{
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);

 if (n<=0 || n>10) printf("Pogresan unos\n"); } while(n<=0 || n>10);
    for (i=0; i<n; i++) {printf("Unesite %d. tacku: ", i+1);
    scanf("%d", &b[i]); scanf("%d", &c[i]);
    if(b[i]<0 || b[i]>=vel || c[i]<0 || c[i]>=vel) { printf("Pogresan unos\n");
    i--; continue;}}
    max1=b[0]; max2=c[0];
    for (i=0; i<n; i++)
    {  if(c[i]>max2) max2=c[i];
    if(b[i]>max1) max1=b[i];
        
         
   }
    
    for (k=0; k<n; k++)
    {for (i=0; i<vel; i++)
    {for (j=0; j<vel; j++)
    {if (i==c[k] && j==b[k]) mat[i][j]=1;}}}
    for (i=0; i<=max2; i++)
    {for (j=0; j<=max1; j++)
    {if ( mat[i][j]==1) 
 printf("*");
        else printf(" ");
        }
        
    printf("\n");
    }
    return 0; }