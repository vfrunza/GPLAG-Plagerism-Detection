#include <stdio.h>

int prost(int n)
{
	int i; 
	
	if ( n==0 ) return 0;
	
	for ( i = 2 ; i < n ; i++)
	{
		if (n%i==0)
			return 0;
	}
	return 1;
}



int daj_prost()
{
	static int broj=1;
	int i ;
	for( i = broj+1; i < 2147483646 ; i++)
	{
		if(prost(i))
		{
			broj=i;
			break;
		}
	}
	return broj;

}

int main() {
	int a,b,suma=0;
	int prosti=0;
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		
		if(a<=0) 
		{
			printf("A nije prirodan broj.\n");
		} else if (a>=b)
		{
			printf("A nije manje od B.\n");
		} else 
		{
			while(prosti<=a){
				prosti=daj_prost();
			}
			
			while(prosti<b)
			{
				
				suma+=prosti;
			prosti=daj_prost();
		
			}
		
			
				
			
			printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
		break;
			
		}
		
	} while ( a>0 || a<b || a>b);
	return 0;
}