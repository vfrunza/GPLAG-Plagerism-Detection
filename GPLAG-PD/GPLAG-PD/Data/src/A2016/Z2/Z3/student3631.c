#include <stdio.h>

int main() {
int a,b,br,i,k,j;
char mat[20][20]={' '};
printf ("Unesite broj tacaka: ");
scanf ("%d", &br);
while (br<1 || br>10) {printf ("Pogresan unos\n");
printf ("Unesite broj tacaka: ");
scanf ("%d", &br); } 
for (k=0;k<br; k++)
{
    printf ("Unesite %d. tacku: ",k+1);
    scanf ("%d %d", &a, &b);
    while (a<0 || a>19 || b<0 || b>19)
    {printf ("Pogresan unos\n");
    printf ("Unesite %d. tacku: ",k+1); 
    scanf ("%d %d", &a, &b);}
    mat[a][b]='*';
}
for (i=0; i<20; i++) {
    for (j=0; j<20; j++)
    {
     if ( mat[j][i]=='*') {printf ("*");} 
     else { printf (" ");}
    }
printf ("\n");
}
	return 0;
}
