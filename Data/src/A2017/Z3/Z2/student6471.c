#include <stdio.h>
#include <math.h>

int zbir_decimala(float f)
{
    int i, rez;
    
    rez = 0;
    f = fabs(f) * 10;
    for (i = 0; i < 25; i++)
    {
       rez += f - trunc(f / 10) * 10;
       f = trunc(f / 10);
    }

    return rez;
}

void zaokruzi1(float niz[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		niz[i] = round(niz[i] * 10) / 10;
}

void preslozi(float niz[], int n, int k)
{
    int i, j;
    float tniz[100];
    
    if (k < 1 || n <= 0)
    	return;
    
	zaokruzi1(niz, n);
	
	j = 0;
	for (i = 0; i < n; i++)
	    if (zbir_decimala(niz[i]) >= k)
	    {
	        tniz[j] = niz[i];
	        j++;
	    }
	for (i = 0; i < n; i++)
	    if (zbir_decimala(niz[i]) < k)
	    {
	        tniz[j] = niz[i];
	        j++;
	    }
	
	for (i = 0; i < n; i++)
	    niz[i] = tniz[i];
}

int main() {
    int i;
    float niz[] = { -1.0, -0.1, -0.19999, -4.449999, -4.45001 };
    zaokruzi1(niz,5);
    preslozi(niz, 0, 8);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
}