#include <stdio.h>
#include <stdbool.h>

int obrni_broj(int x)
{
	int y=0;
	
	while(x > 0)
	{
		y *= 10;
		y += x%10;
		x /= 10;
	}
	
	return y;
}

int izbaci_cifre(int brojevi[], int vel_br, int cifre[], int vel_cif)
{
	int i, j, x, y, koef;
	bool izbaci;
	
	for(i=0; i<vel_cif; i++)
	{
		if(cifre[i] < 0 || cifre[i] > 9) return 0;
		for(j=i+1; j<vel_cif; j++)
			if(cifre[j] == cifre[i]) return 0;
	}
	
	for(i=0; i<vel_br; i++)
	{
		if(brojevi[i] < 0) koef=-1;
		else koef = 1;
		
		x = brojevi[i]*koef;
		y = 0;
		
		while(x > 0)
		{
			izbaci = false;
			for(j=0; j<vel_cif; j++)
				if(cifre[j] == x%10)
				{
					izbaci = true;
					break;
				}
			
			if(!izbaci)
			{
				y *= 10;
				y += x%10;
			}
			
			x /= 10;
		}
		
		brojevi[i] = obrni_broj(y)*koef;
	}
	
	return 1;
}

int main() {
	
	int brojevi[] = {321,5,73};
	int cifre[] = {2,7,5};
	int i;
	
	if(izbaci_cifre(brojevi,3,cifre,3) == 1)
		for(i=0; i<3; i++)
			printf("%d ", brojevi[i]);
	
	return 0;
}
