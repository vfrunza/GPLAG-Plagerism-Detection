#include <stdio.h>
int daj_prost()
	{
	static int broj=1;
	int j, prost=1;
	
	for(;;)
	 {
	 	broj+=1;
	 	prost=1;
		for(j=2; j<broj;j++)
		  {
			if(broj%j==0) prost=0;
		  }
			if(prost==1)
	             return broj;
	 }
	}

int main() {
	int a,b;
	int n=0,i,suma=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d%d",&a,&b);
	if(a<=0)
	printf("A nije prirodan broj.\n");
	if(a>=b)
	printf("A nije manje od B.\n");
	
	   } while (a>=b || a<=0 || b<=0);
	
   	while(n<a)
	{
	   n=daj_prost();
	}
	
	for(i=a;i<b;i++)
	{
		
		if(n>a && n<b)
		suma+=n;
		n=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
