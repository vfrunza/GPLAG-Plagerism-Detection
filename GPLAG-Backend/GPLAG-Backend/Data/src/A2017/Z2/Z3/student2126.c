#include <stdio.h>
#define eps 0.00001
int main() {
int i, j, sa, va, sb, vb;
double mata[100][100]={{0}}, matb[100][100]={{0}}, temp;
printf ("Unesite sirinu i visinu matrice A: ");
scanf ("%d%d", &sa, &va);
printf ("Unesite clanove matrice A: ");
for (i=0; i<sa; i++) {
	for (j=0; j<va; j++) 
	scanf ("%lf", &mata[i][j]);
}

printf ("Unesite sirinu i visinu matrice B: ");
scanf ("%d%d", &sb, &vb);

printf ("Unesite clanove matrice B: ");
for (i=0; i<sb; i++) {
	for (j=0; j<vb; j++) 
	scanf ("%lf", &matb[i][j]);
}

for (i = 0; i < sa; i++)
    {
        for (j = i + 1; j <va; j++)
        {
            temp = mata[i][j];
            mata[i][j] = mata[j][i];
            mata[j][i] = temp;
        }
    }
 
    for (i = 0; i < sa; i++)
    {
        for (j = 0; j < va / 2; j++)
        {
            temp = mata[i][j];
            mata[i][j] = mata[i][va - 1 - j];
            mata[i][va - 1 - j] = temp;
        }
    }    

for (i=0; i<sa; i++) {
	for (j=0; j<va; j++) 
	if (mata[i][j]-matb[i][j]>eps) { 
		printf ("NE");
		return 0;
}
	
}
printf ("DA");

	
	return 0;
}
