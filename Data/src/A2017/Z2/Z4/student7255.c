#include <stdio.h>

int main() {
	
	int m,n;
	int uslov;
	int a[100][100], b[100][100], c[100][100];
	int i, j, k, l, broj_upisanih = 0, brojac, granica = 0;
	int poredbeni;
	int prosla_b, prosla_c;
	
	int niz[100000];
	int upisani[100000];
	
	for (i = 0; i < 100000; i++)
		{
			niz[i] = 0;
			upisani[i] = 0;
		}
	
	
	do
	{
		uslov = 1;
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		
		if (m < 0 || m > 100)
			uslov = 0;
		if (n < 0 || n > 100)
			uslov = 0;
	} while(uslov == 0);
	
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
			
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &b[i][j]);
			
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
	
	
	for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				{
					poredbeni = a[i][j];
					brojac = 0;
					for (k = 0; k < m; k++)
						{
							for (l = 0; l < n; l++)
								{
									if (poredbeni == a[k][l])
										brojac++;
								}
						}
					
					uslov = 1;
					for (k = 0; k < granica; k = k+2)
						{
							if (niz[k] == poredbeni)
								uslov = 0;
						}
						
					if (uslov == 1)
						{
							niz[granica] = poredbeni;
							granica++;
							niz[granica] = brojac;
							granica++;
						}
				}
		}
		
		
	prosla_b = 1;
	for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				{
					poredbeni = b[i][j];
					brojac = 0;
					for (k = 0; k < m; k++)
						{
							for (l = 0; l < n; l++)
								{
									if (poredbeni == b[k][l])
										brojac++;
								}
						}
					
					uslov = 1;
					for (k = 0; k < broj_upisanih; k++)
						{
							if (poredbeni == upisani[k])
								uslov = 0;	
						}
						
					if (uslov == 1)
						{
							upisani[broj_upisanih] = poredbeni;
							broj_upisanih++;
							l = 0;
							for(k = 0; k < granica; k = k+2)
								{
									if (niz[k] == poredbeni)
										l = niz[k+1];
								}
								
							if (brojac != l)
								prosla_b = 0;
						}
				}
		}
	
	
	
	for (i = 0; i < 100000; i++)
		upisani[i] = 0;
	broj_upisanih = 0;
	
		
	prosla_c= 1;
	for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				{
					poredbeni = c[i][j];
					brojac = 0;
					for (k = 0; k < m; k++)
						{
							for (l = 0; l < n; l++)
								{
									if (poredbeni == c[k][l])
										brojac++;
								}
						}
					
					uslov = 1;
					for (k = 0; k < broj_upisanih; k++)
						{
							if (poredbeni == upisani[k])
								uslov = 0;	
						}
						
					if (uslov == 1)
						{
							upisani[broj_upisanih] = poredbeni;
							broj_upisanih++;
							l = 0;
							for(k = 0; k < granica; k = k+2)
								{
									if (niz[k] == poredbeni)
										l = niz[k+1];
								}
								
							if (brojac != l)
								prosla_c = 0;
						}
				}
		}
		
	if (prosla_b == 1 && prosla_c == 1)
		printf("DA");
	else
		printf("NE");
		
	
	
	
	
	return 0;
}
