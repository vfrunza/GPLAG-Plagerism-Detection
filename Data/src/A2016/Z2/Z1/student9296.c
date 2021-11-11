#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	int n, zadnja, dzadnja, nbroj=0, i=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);	
	
	if(n<0) 
	{
		n = n*(-1);
	}
	
	while(n>=10)
	{
		zadnja = n%10;
		
		dzadnja = (n/10)%10;
		
		nbroj = abs(zadnja-dzadnja)*pow(10, i) + nbroj;
		
		i++;
		
		n=n/10;
		
	}
	
	printf("%d", nbroj);

	
	return 0;
}
