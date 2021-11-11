#include <stdio.h>

int main() {
int i,j,n;
do{
printf ("Unesite broj n: ");
scanf ("%d", &n);
if (n<1 || n>50) { printf ("Pogresan unos\n"); }
} while(n<1 || n>50);

if (n==1) {printf ("***");}
 
else for (i=0;i<n;i++){
      for (j=0;j<(4*n-3);j++)
      { if ((i==j) || j==(2*n-2)+i || j==(4*n-4)-i || j==(((4*n-3)/2)-i))
      printf ("*");
      else { printf (" ");}
      }
      printf ("\n");
 }
 return 0;
 }
