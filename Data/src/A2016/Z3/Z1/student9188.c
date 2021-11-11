#include <stdio.h>


int daj_prost()
{
	static int n=1;
	int i;
	
   	int prost=0;
   	
   	while(1==1)
   	{
   		n++;
   		prost=1;
   		for(i=2;i<n;i++)
   			if(n%i==0) prost=0;
   		if(prost==1) break;
   	}
	
	return n;
}

int main() {
	
	int i;
	int a,b;
	int suma=0;
	int temp;
	
	do
	{
		printf("Unesite brojeve A i B: ");
	    scanf("%d %d",&a,&b);
	    if(a<1) printf("A nije prirodan broj.\n");
	    else if(a>=b) printf("A nije manje od B.\n");
	    else if(b<1)printf("B nije prirodan broj.\n");
	}while((a<1 || b<1) || a>=b);
 
   while(1==1)
   {
   	
   	 temp=daj_prost();
   	 if(temp>a && temp<b){ suma+=temp; }
   	 if(temp>b)break;
   }
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
