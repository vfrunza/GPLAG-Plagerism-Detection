#include <stdio.h>
#define redovi 20
#define kolone 20
int main() {
		int i=0,j=0,n=0,tacka1=0,tacka2=0;
		char matrica[redovi][kolone];
		for(i=0;i<redovi;i++)
		{
			for(j=0;j<kolone;j++)
			{
				matrica[i][j]='g';
			}
		}
		do
		{
			printf("Unesite broj tacaka: ");
			scanf("%d",&n);
			if(n>10 || n<=0)
		{printf("Pogresan unos\n");}
		}while(n>10 || n<=0);
		
		
		
		for(i=0;i<n;i++)
		{
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d", &tacka1,&tacka2);
			
			while(tacka1<0 || tacka1>19 || tacka2<0 || tacka2>19)
			{
				printf("Pogresan unos\n");
				printf("Unesite %d. tacku: ",i+1);
				scanf("%d %d", &tacka1, &tacka2);
			}
			matrica[tacka2][tacka1]='*';
		}
		for(i=0;i<redovi;i++)
		{
			for(j=0;j<kolone;j++)
			{
				if(matrica[i][j]!='*')
				{printf(" ");}
				else
				{printf("%c",matrica[i][j]);}
			}
			printf("\n");
		}
	return 0;
}
