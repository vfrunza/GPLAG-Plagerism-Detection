#include <stdio.h>

int main() {
	int i , j , br_red , br_kol , sirina;
	
	do {
	printf("Unesite broj redova: ");
	scanf("%d", &br_red);
	} while (br_red>10 || br_red<=0);
	
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &br_kol);
	} while (br_kol>10 || br_kol<=0);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	} while (sirina>10 || sirina<=0);
	
	for(i=0; i<2*br_red+1; i++)
	{
		
     for(j=0; j<(sirina+1)*br_kol+1; j++)
     {
	
         if(i%2==0)
         {
		
	        if(j==0 || j==(sirina+1)*br_kol || j%(sirina+1)==0)
	        { 
		    printf("+");
		    
	
	} 
	else
	{
	     	printf("-");
	}
	
	}
	else
	{
		if(j==0 || j==(sirina+1)*br_kol || j%(sirina+1)==0)
		{
			printf("|");
		}
		else
		{
			printf(" ");
	  	}
  
   	}
  
  }
  printf("\n");
  }
  return 0;
}
