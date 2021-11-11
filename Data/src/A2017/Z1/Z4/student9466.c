#include <stdio.h>

int main() {

int k; /* k predstavlja kolone */
int sirinaK; /* sirinaK predstavlja sirinu kolone */
int r; /*r predstavlja redove */
int brojR,brojK, sirinaKa; /* brojR je broj redove, brojK je broj kolona, sirinaKa je sirina kolona */

do{
	
printf("Unesite broj redova: ");
scanf("%d", &brojR);
} 
while(brojR > 10 || brojR <=0 );
do{
	printf("Unesite broj kolona: ");
	scanf("%d", &brojK);
}
	while(brojK > 10 || brojK <= 0);
	
	do{ 
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirinaKa);
	}
	while(sirinaKa > 10 || sirinaKa <=0);
	for(r = 0; r <= brojR -1 ; r++)
	{
		printf("+");
		for(k = 0; k <= brojK-1; k++)
		{
			for(sirinaK = 0; sirinaK <= sirinaKa -1 ; sirinaK++)
			{ 
				printf("-"); 
				
			}
				printf("+"); 
			
		}
				printf("\n");
				
				printf("|");
				
				for(k = 0; k <= brojK - 1; k++)
				{
                for(sirinaK = 0; sirinaK <= sirinaKa-1; sirinaK++)
                {
                	printf(" "); 
                	
                }
                	
                	printf("|");
				}
				 printf("\n");
	}
	
	printf("+");
	for(k = 0; k <= brojK-1; k++)
	{
		for(sirinaK = 0; sirinaK <= sirinaKa-1; sirinaK++)
		{ 
			printf ("-"); 
			
		}
			printf("+"); 
		
	}
			
			return 0; 
}
	
                	
	