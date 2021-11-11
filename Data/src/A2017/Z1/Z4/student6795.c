// program uradio u code::bloks, jer c9 nije bio u funkciji, pa kopirao
#include <stdio.h>

int main() {
	int r,k,sjk;
	int i,j,z;

	do
	{
		printf("Unesite broj redova: ");
		scanf("%i",&r);
	} while(r<=0 || r>10);
	
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%i",&k);
	} while(k<=0 || k>10);
	
	do
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%i",&sjk);
	} while(sjk<=0 || sjk>10);


	for(i=0;i<r;i++)
    {
//----------------------------------------------
        for(j=0; j<k; j++)
        {
            printf("+");
            for(z=0;z<sjk;z++)
            {
                printf("-");
            }
        }
    printf("+");
    printf("\n");
    int y,x;
    for(y=0;y<k;y++)
    {
        printf("|");
        for (x=0;x<sjk;x++)
        {
            printf(" ");
        }
    }
    printf("|");
    printf("\n");
    }

 int zadnji,zzadnji;
 for(zadnji = 0; zadnji < k; zadnji++)
 {
     printf("+");
     for (zzadnji = 0;zzadnji < sjk; zzadnji++)
     {
         printf("-");
     }
 }
printf("+");
	return 0;
}