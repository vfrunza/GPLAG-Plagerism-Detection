#include <stdio.h>

int prost(int X)
{
	int i;
	
	if (X < 2)
		return 0;
		
	for(i = 2; i < X; i++)
		if(X % i == 0)
			return 0;
			
	return 1;
}

int daj_prost()
{
	static int i = 2;
	
	for( ; ; )
	{
		if(prost(i) == 1)
		{
			return i++;
		}
		
		else
			i++;
	}
	
}

int main() 
{
	/*printf("Zadaća 3, Zadatak 1");*/
	
	int A, B, suma = 0, broj = 0;
	
	greska:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	
	if(A <= 0)
	{
		printf("A nije prirodan broj.\n");
		goto greska;
	}
		
	if(A >= B)
	{
		printf("A nije manje od B.\n");
		goto greska;
	}
	
	while(broj < A)
		broj = daj_prost();
	
	if(broj > A && broj < B)
			suma += broj;
		
	while(broj >= A)
		{
			broj = daj_prost();
			
			if(broj < B)
				suma += broj;
				
			else if(broj >= B)
				break;
		}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
		
	return 0;
}
