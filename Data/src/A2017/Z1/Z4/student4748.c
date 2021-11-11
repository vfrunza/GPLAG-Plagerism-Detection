#include <stdio.h>

int main() {
	int R,K,SK,i,j;
		do{
	printf("Unesite broj redova: ");
	scanf("%d",&R);
	} while (R<=0 || R>10);
    do{
	printf("Unesite broj kolona: ");
	scanf("%d",&K);
    } while (K<=0 || K>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&SK);
	} while (SK<=0 || SK>10);

	for (i=0; i<(2*R+1); i++)
	{  if (i%2==0)
		{{
			for (j=0; j<(K*SK+K+1); j++)
		 {
			if(j%(SK+1)==0) 
		{
			printf("+");
		}
			else
			{
				printf("-");
			}
		 }
	  }
		printf("\n");}
		else
		{
			for (j=0; j<(K*SK+K+1); j++)
		     {
		     	if (j%(SK+1)==0)
		     	printf("|");
		     	else
		     	printf(" ");
		       }
		printf("\n");	
		}
	}
	return 0;
}
