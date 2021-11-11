#include <stdio.h>


int daj_prost()
{
	static int n=1;
	int prost=1;
	int i;
	
	while(1==1)
	{   
		prost=1;
		n++;
		for(i=2;i<n;i++)
			if(n%i==0) prost=0;
		if(prost==1) break;
	}
	return n;
}


int main() {
	int a,b;
	int temp,suma=0;
	
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<1) printf("A nije prirodan broj.\n");
		else if(a>=b)printf("A nije manje od B.\n");
		else if(b<1)printf("B nije prirodan broj.\n");
	}while(a<1 || b<1 || a>=b );
	
	
	while(1==1)
	{
		temp=daj_prost();
		if(temp>a && temp<b) suma+=temp;
		if(temp>b)break;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
