#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

int broj,broj2 = 0,i = 1,stotice,desetice;

printf("Unesite broj: ");

scanf("%d", &broj);

if(broj < 0) broj = abs(broj);

else if(broj < 10 && broj > 0) broj = 0;

while(broj > 10)
{
	desetice = (broj % 10);
	
	broj /= 10;
	
	stotice = (broj % 10);
	
	broj /=10;
	
	broj2 = broj2 + abs(desetice-stotice)*i;
	
	broj = broj * 10 + stotice;
	
	i*=10;
}
printf("%d", broj2);

return 0;
}