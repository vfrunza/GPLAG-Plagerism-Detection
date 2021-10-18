#include <stdio.h>
#include <math.h>

int main() 
{
	/*printf("Zadaća 2, Zadatak 1");*/
	int s = 0, e = 0, m = 0, r = 0, a = 0, E = 0;
	
	printf("Unesite broj: ");
	scanf("%d", &s);
		
	if(s >= -9 && s <= 9)
	{
		printf("0");
		return 1;
	}
		
	else if(s < 0)
		s = fabs(s);
		
	e = s;
		
	while(e != 0)
	{
		e /= 10;
		m++;
	}
	
	while(r < m - 1)
	{
		a = s % 10 - ((s % 100 - s % 10) / 10);
		
		if(a < 0)
			a = fabs(a);
			
		E += (a * pow(10, r));
		s /= 10;
		r++;
	}
	
	printf("%d", E);
	
	return 0;
}
