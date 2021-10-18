#include <stdio.h>

int main() {
	int prva[100][100],druga[100][100],treca[100][100];
	int m,n,a,b,redA,redB=0,redC;
    do{printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);}
	while((m>=101) && (m>=101));
	printf("Unesite clanove matrice A: ");
	for(a=0;a<m;a++)
	 for(b=0;b<n;b++)
	{scanf("%d", &prva[a][b]);}
	for(a=0;a<m;a++)
	 for(b=0;b<n;b++)
     	{
     	redA+=prva[a][b];
		}
	printf("Unesite clanove matrice B: ");
	for(a=0;a<m;a++)
	for(b=0;b<n;b++)
	{scanf("%d", &druga[a][b]);}
	for(a=0;a<m;a++)
	 for(b=0;b<n;b++)
	 {	
	 	redB=redB + druga[a][b];
		}
	printf("Unesite clanove matrice C: ");
	for(a=0;a<m;a++)
	 for(b=0;b<n;b++)
	{scanf("%d", &treca[a][b]);}
	for(a=0;a<m;a++)
	 for(b=0;b<n;b++)
		{
		redC+=treca[a][b];
		 }

if((redA==redB) && (redB==redC) && (redA==redC)){printf("DA");}
else{printf("NE");}


	return 0;
}
