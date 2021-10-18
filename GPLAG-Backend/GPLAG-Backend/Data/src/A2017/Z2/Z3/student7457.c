#include <stdio.h>

int main() {

int a, A, b, B, i=0, j=0, matricaA[100][100], matricaB [100][100], TA[100][100] ;

printf ("Unesite sirinu i visinu matrice A: ");
scanf ("%d %d", &a, &A);



printf ("Unesite clanove matrice A: ");
for (i=0; i<A; i++)
{
	for (j=0; j<a; j++)
    {
        scanf ("%d", &matricaA[i][j]);
    }
}




printf ("Unesite sirinu i visinu matrice B: ");
scanf ("%d %d", &b, &B);



printf ("Unesite clanove matrice B: ");
for (i=0; i<B; i++)
{
	for (j=0; j<b; j++)
	{
        scanf ("%d", &matricaB[i][j]);
	}
}

/*Transponovanje i rotiranje*/

if ((B!=a) || (b!=A))
{
printf ("NE\n");
return 0;
}
else 
{
    for (i=0; i<a; i++)
    {
        for (j=0; j<A; j++)
        {
        TA[i][j]=matricaA[j][i];
        }
    }
    for (i=0; i<a; i++)
    {
        for (j=0; j<A; j++)
        {
        if (TA[i][A - 1 - j] != matricaB[i][j])
        {
            printf ("NE\n");
            return 0;
        }
        }
    }
}
    printf ("DA\n");
    
    
return 0;
}