#include <stdio.h>

int main() {
	
	int br_red,br_kol,i,j,br_s,k;
	
	do
	{printf("Unesite broj redova: ");
	scanf("%d", &br_red);
	}
	while(br_red<=0||br_red>10);
	
	do
	{printf("Unesite broj kolona: ");
	scanf("%d", &br_kol);
	}
	while(br_kol<=0||br_kol>10);
	
	do
	{printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &br_s);
	}
	while(br_s<=0||br_s>10);
	
	for(i=0; i<br_red; i++)
	{
		for(j=0; j<br_kol; j++)
		{
			printf("+");
			for(k=0; k<br_s; k++) printf("-");
			if(j==br_kol-1) printf("+\n");
		}
		
		for(j=0; j<br_kol; j++)
		{
			printf("|");
			for(k=0; k<br_s; k++)
			printf(" ");
			if(j==br_kol-1)
			printf("|\n");
		}
	
		if(i==br_red-1)
		{
			for(j=0; j<br_kol; j++)
			{
				printf("+");
				for(k=0; k<br_s; k++) printf("-");
				if(j==br_kol-1) printf("+\n");
			}
		}
		
	}	
	return 0;
}


