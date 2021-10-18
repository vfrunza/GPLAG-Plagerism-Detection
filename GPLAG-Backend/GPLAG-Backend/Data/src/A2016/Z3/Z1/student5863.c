#include<stdio.h>
#include<stdlib.h>

int daj_prost()
{
	static int x=1;
	int i,p=0;
	
	x++;
	for(i=2;i<x;i++)
	{
		if(x%i==0)break;
	}
	if(x==i) 
	{
	 p=i;
	 
	}
	
	return p;
}


int main()
{
 int a,b,i,z,suma;
 
 suma=0;
 do{
 printf("Unesite brojeve A i B: ");
 scanf("%d %d",&a,&b);
 if(a>=b) printf("A nije manje od B.\n");
 if(a<=0) printf("A nije prirodan broj.\n");
 
 }
 while(a<=0 || b<=0 || a>=b);
 
 
 for(i=a;i<10000;i++)
 
 {
 	z=daj_prost();
 	
 	
 	if(z>a && z<b)
 	{
 		suma+=z;
 		
 	}
 }
 printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
 return 0;
 }