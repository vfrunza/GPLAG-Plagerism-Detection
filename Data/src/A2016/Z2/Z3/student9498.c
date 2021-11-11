#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int mat[20][20]={0}, n=0, x=0, y=0, i=0, j=0;
    do
    {
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    if(n < 1 || n > 10)
    printf("Pogresan unos\n");
}
while(n < 1 || n > 10);
for(i = 0; i < n; i++)
{ 
    printf("Unesite %d. tacku: ", i+1);
scanf("%d %d", &x, &y);
if(x < 0 || x > 19 || y < 0 || y > 19)
{
printf("Pogresan unos\n");
i--;
continue;
}
mat[y][x] = 1;
}
for(i = 0; i < 20; i++)
{
for (j = 0; j < 20; j++)
{
    if (mat[i][j] == 1)
    printf("*");
    else
    printf(" ");
}
printf("\n");
}
return 0;
}