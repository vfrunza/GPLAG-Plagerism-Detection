#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
    int i, j, k, l, ponavljanja, ponavljanja_max=0, broj_max=-1;
    
    for(i=0; i<visina; i++)
        for(j=0; j<sirina; j++)
        {
            ponavljanja = 0;
            
            for(k=i; k<visina; k++)
                for(l=0; l<sirina; l++)
                    if(matrica[k][l] == matrica[i][j]) ponavljanja++;
                    
            if(ponavljanja > ponavljanja_max)
            {
                ponavljanja_max = ponavljanja;
                broj_max = matrica[i][j];
            }
            else if(ponavljanja == ponavljanja_max)
                if(matrica[i][j] < broj_max) broj_max = matrica[i][j];
        }
        
    return broj_max;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
    int i, j, k, l, pom;
    
    for(j=0; j<sirina; j++)
        for(i=0; i<visina; i++)
            if(matrica[i][j] == N)
            {
                for(k=j+1; k<sirina; k++)
                    for(l=0; l<visina; l++)
                    {
                        pom = matrica[l][k];
                        matrica[l][k] = matrica[l][k-1];
                        matrica[l][k-1] = pom;
                    }
                    
                sirina--;
                j--;
                break;
            }
    
    return sirina;
}

int main() {
	
	int i, j, visina, sirina, matrica[100][100], br=0;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	
	for(i=0; i<visina; i++)
	{
	    printf("Unesite elemente %d. reda: ", i+1);
	    for(j=0; j<sirina; j++)
	        scanf("%d", &matrica[i][j]);
	}
	
	while(sirina > 0)
	{
	    sirina = izbaci_kolone(matrica,visina,sirina, max(matrica,visina,sirina));
	    
	    if(sirina != 0) printf("\nNakon %d. prolaza matrica glasi:\n", ++br);
	    else printf("\nNakon %d. prolaza matrica je prazna!", ++br);
	    
	    for(i=0; i<visina; i++)
	    {
	        for(j=0; j<sirina; j++)
	            if(matrica[i][j] < 10) printf("    %d", matrica[i][j]);
	            else printf("   %d", matrica[i][j]);
	        printf("\n");
	    }
	}
	
	return 0;
}
