#include <stdio.h>

int jel_prost(int broj)
{
	int i,b=0;
	for(i=2;i<broj;i++)
	{
		if(broj%i==0)
		{
			b=1;
			break;
		}
	}
	if(b!=1) return 1;
	return 0;
}

int daj_prost() {
	static int prost=0;
	int a;
    prost++;
	if(prost==1) prost++;
	
	if(jel_prost(prost)==1)
	{
		a=prost;
		return a;
	}

	
}

int main() {
	
	int a,b,suma=0,i;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a>0 && b>0 && a<b) break;
		else if(a<=0) printf("A nije prirodan broj.\n");
		else if(a>=b) printf("A nije manje od B.\n");
		
	}
	while(a<=0 || b<=0 || a>=b);

    for(i=0;i<2000;i++)
    { 
    	i=daj_prost();
    	if(i>a && i<b)
    	suma=suma+i;
        
    }
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
