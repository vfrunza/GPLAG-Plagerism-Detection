#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int main()
{

 int redoviA,koloneA,redoviB,koloneB,i,j;
 printf("Unesite sirinu i visinu matrice A: ");
 scanf("%d",&redoviA);
 scanf("%d",&koloneA);
 int matricaA[100][100],pomocni[100][100];
 printf("Unesite clanove matrice A: ");
 for(i=0;i<redoviA;i++)
 {
     for(j=0;j<koloneA;j++)
     {

         scanf("%d",&matricaA[i][j]);
     }
 }
 printf("Unesite sirinu i visinu matrice B: ");
 scanf("%d",&redoviB);
 scanf("%d",&koloneB);
 int matricaB[100][100];
printf("Unesite clanove matrice B: ");
 for(i=0;i<redoviB;i++)
 {
     for(j=0;j<koloneB;j++)
     {
         scanf("%d",&matricaB[i][j]);
     }
 }
 int r=0,k=0;
 for(i=0;i<redoviA;i++)
 {
     k=0;
     for(j=koloneA-1;j>=0;j--)
     {
        pomocni[r][k]=matricaA[j][i];
        k++;
     }
     r++;

 }
bool t=false;
for(i=0;i<r;i++)
{
    for(j=0;j<k;j++)
    {
     if(pomocni[i][j]!=matricaB[i][j])
     {

        t=true;
        break;
     }

    }
}
if(t==true) printf("NE\n");
else printf("DA\n");
    return 0;
}
