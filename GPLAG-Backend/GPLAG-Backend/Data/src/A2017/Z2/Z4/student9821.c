#include <stdio.h>

int main() {
	int mata[100][100];
	int matb[100][100];
	int matc[100][100];
	int niza[1000];
	int nizb[1000];
	int nizc[1000];
	int n,b=0,a=0,c=0,temp,ab=0,bc=0,m,i,j;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	}while(n<0||n>100||m<0||m>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mata[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matb[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matc[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			niza[a]=mata[i][j];
			a++;
		}
	}
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			nizb[b]=matb[i][j];
			b++;
		}
	}
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			nizc[c]=matc[i][j];
			c++;
		}
	}

	    for (i = 0; i < a; i++)
    {
        for (j = 0; j < (a - i - 1); j++)
        {
            if (niza[j] > niza[j + 1])
            {
                temp = niza[j];
                niza[j] = niza[j + 1];
                niza[j + 1] = temp;
            }
        }
    }

        for (i = 0; i < b; i++)
    {
        for (j = 0; j < (b - i - 1); j++)
        {
            if (nizb[j] > nizb[j + 1])
            {
                temp = nizb[j];
                nizb[j] = nizb[j + 1];
                nizb[j + 1] = temp;
            }
        }
    }

        for (i = 0; i < c; i++)
    {
        for (j = 0; j < (c - i - 1); j++)
        {
            if (nizc[j] > nizc[j + 1])
            {
                temp = nizc[j];
                nizc[j] = nizc[j + 1];
                nizc[j + 1] = temp;
            }
        }
    }
    for(i=0;i<a;i++){
    	if(niza[i]==nizb[i]) ab++;
    }
	 for(i=0;i<a;i++){
    	if(nizb[i]==nizc[i]) bc++;
    }
    if(ab==bc&&a==bc&&b==bc){
    	printf("DA\n");
    }else{
    	printf("NE\n");
    	
    }
    
	
	
	
	 	return 0;
}

/* Potrebno je napisati program koji omogućuje unos tri matrice cjelobrojnih elemenata A, B i C čije su dimenzije jednake: MxN,
a M i N su najviše 100. Najprije se unose brojevi M i N (pomoću do-while petlje osigurati da su ti brojevi u traženom opsegu). 
Zatim se provjerava da li su matrice B i C sastavljene od istih elemenata kao matrica A, pri čemu se ti elementi 
trebaju ponavljati isti broj puta. Ako je uslov zadatka ispunjen program treba na ekranu ispisati DA, u suprotnom treba 
ispisati NE.

Unesite brojeve M i N: 101 101
	Unesite brojeve M i N: 2 2
	Unesite clanove matrice A: 1 2 1 2
	Unesite clanove matrice B: 2 1 2 2
	Unesite clanove matrice C: 2 1 2 1
	NE
*/