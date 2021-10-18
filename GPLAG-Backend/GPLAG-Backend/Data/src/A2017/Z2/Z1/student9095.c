/*#include <iostream>
/#include <cmath>*/
#include <stdio.h>

/*using namespace std*/

int main()
{
	int broj, i, j;
	
	do
	{
	    printf("Unesite broj N: ");
	    scanf("%d", &broj);
	    
	    if(broj % 4 != 0 || broj < 8) printf("Neispravno N!");
	    printf("\n");
	    
	}while(broj % 4 != 0 || broj < 8);
	
	for(i = 0; i < broj / 2; i++)
	{
	    for(j = 0; j < broj; j++)
	    {
	        if(i == j) printf("\\");
	        else if(i + j == broj/2 - 1) printf("/");
	        else if((i == 0 || i == broj/2 - 1) && (j == broj/2  || j == broj - 1)) printf("+");
	        else if((i == 0 || i == broj/2 - 1) && j > broj/2  && j < broj - 1) printf("-");
	        else if((i > 0 || i < broj/2 - 1) && (j == broj/2 || j == broj - 1 )) printf("|");
	        else printf(" ");
	    }
	    
	    printf("\n");
	}
	
	
	for(i = 0; i < broj / 2; i++)
	{
	    for(j = 0; j < broj; j++)
	    {
	        if((i == 0 || i == broj / 2 - 1) && (j == 0 || j == broj / 2 - 1)) printf("+");
	        else if((i == 0 || i == broj / 2 - 1) && j > 0 && j < broj / 2 - 1 ) printf("-");
	        else if((i > 0 || i < broj / 2 - 1) && (j == 0 || j == broj / 2 - 1)) printf("|");
	        else if((i == broj / 4 || i == broj / 4 - 1) && (j == 3 * broj / 4 || j == 3 * broj / 4 - 1)) printf("+");
	        else if((i == broj / 4 || i == broj / 4 - 1) && (j < broj / 4 - 1 || j > broj / 4) && j > broj / 2 - 1) printf("-");
	        else if((i < broj / 4 - 1 || i > broj / 4) && (j == 3 * broj / 4 || j == 3 * broj / 4 - 1)) printf("|");
	        else printf(" ");
	    }
	    
	    printf("\n");
	}
	
	return 0;
}