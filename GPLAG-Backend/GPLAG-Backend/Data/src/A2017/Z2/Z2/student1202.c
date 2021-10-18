#include <stdio.h>

int main() {
	int n, niz[100] = {0}, i, j, k, niz2[1000] = {0}, zadnja = -1, br1 = 0, br2 = 0, tmp[100] = {0}, a = 0;
	do {
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	} while(n < 1);
	printf("Unesite clanove niza: ");
	for (i = 0; i < n; i++)
	{
	    scanf("%d", &niz[i]);
	    if (niz[i] < 0)
	        i--;
	}
	    
	    
	for (i = 0; i < n; i++)
	{
		a = niz[i];
		for (j = 0; a > 0; j++)
			a /= 10;
	    if (j == 0)
	        j = 1;
		for (k = j - 1; k >= 0; k--)
		{
			tmp[k] = niz[i] % 10;
			niz[i] /= 10;
	    }
	    for (k = 0; k < j; k++)
	    {
	        if (tmp[k] == zadnja)
	            br1++;
	        else
	        {
	        	niz2[++br2] = br1;
	        	niz2[++br2] = zadnja = tmp[k];
	            br1 = 1;
	        }
	    }
	}
    niz2[++br2] = br1;
	printf("Finalni niz glasi:\n");
	for (i = 2; i < br2 + 1; i++)
	    printf("%d ", niz2[i]);
	return 0;
}