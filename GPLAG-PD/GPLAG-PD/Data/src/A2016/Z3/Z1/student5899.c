#include <stdio.h>
int daj_prost()
{
	static int s=1;
	int prost=1,i;
	while(1)
	{
		
		s++;
		for(i=2;i<s;i++) 			/*i=2 2<2 nece uci u petlju ali ispisuje  2
									i=2 2<3
									3/2 prost   3
									i=2 2<4
									4/2  nije prost	0
									i=2 2<5
									5/2 prost		5*/
		{
			if(s%i==0)
			{
				prost=0;
				break;		/*glupa*/
			}
			else
			{
				prost=1;
			}
			
		}
		if(prost==1) 
		{
			return s;
		}
	
	}
}

	
	
	

int main() 
{
	int a,b,suma=0,k=daj_prost();

		do
		{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)
		{
			printf("A nije prirodan broj.\n");
		}
		if(a>=b)
		{
			printf("A nije manje od B.\n");
		} 
		}
		while(a>=b || a<=0);
		
		while(k<b)
		{
			k=daj_prost();
			if(k>a && k<b)
			{
				suma=suma+k;
			}
		}
		
		printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);

	return 0;
}
