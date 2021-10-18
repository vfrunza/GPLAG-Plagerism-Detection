#include <stdio.h>

int main() {
int ma=0,na=0,mb=0,nb=0,i,j;


printf ("Unesite sirinu i visinu matrice A: ");
scanf ("%d", &na);
scanf ("%d", &ma);


int k=ma;



double A[100][100];
 printf ("Unesite clanove matrice A: ");
for (i=0; i<ma ; i++)
 for (j=0; j<na; j++)
 scanf ("%lf", &A[i][j]);
 

 printf ("Unesite sirinu i visinu matrice B: ");
 scanf ("%d", &nb);
scanf ("%d", &mb);

double B[100][100];
 printf ("Unesite clanove matrice B: ");
for (i=0; i<mb ; i++)
 for (j=0; j<nb; j++)
 scanf ("%lf", &B[i][j]);

int daNe=1;
if (ma !=nb || na != mb)
{printf ("NE"); 
 return 0;
}
for (i=0; i<ma ; i++) {
for (j=0; j<na ; j++) {
if (A[i][j]!=B[j][k-1-i])
{
	daNe=0;
}} }


 if (daNe==0)
{printf ("NE"); }
else
{printf ("DA"); }


return 0;

}
