#include <stdio.h>

int main() {
int n,k,x[20],y[20],i,j,br=0;
char mat[20][20];
for(i=0;i<=19;i++)
{
for(j=0;j<=19;j++)
{
mat[i][j]=' ';
}
}
printf("Unesite broj tacaka: ");
scanf("%d",&n);
while(n<=0 || n>10)
{
printf("Pogresan unos \n");
printf("Unesite broj tacaka: ");
scanf("%d",&n);
if(n<=0 || n>10)
{
continue;
}
else
{
break;
}
}
for(k=0;k<n;k++)
{
while(br<n)
{
printf("Unesite %d. tacku: ",br+1);
scanf("%d %d",&x[k],&y[k]);
while(x[k]<0 || x[k]>19 || y[k]<0 || y[k]>19)
{
printf("Pogresan unos\n");
printf("Unesite %d. tacku: ",br+1);
scanf("%d %d",&x[k],&y[k]);
if (x[k]<0 || x[k]>19 || y[k]<0 || y[k]>19)
{
continue;
}
else
{
break;
}
}
br++;
mat[y[k]][x[k]]='*';
}
}
for(i=0;i<20;i++)
{
for(j=0;j<20;j++)
{
printf("%c",mat[i][j]);
}
printf("\n");
}
return 0;
}





