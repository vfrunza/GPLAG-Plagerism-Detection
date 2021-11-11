#include <stdio.h>


int daj_prost()
{
	static int broj=2;
	int i;
	
	for(i=2;i<broj;i++)
	{
		if(broj%i==0)
		{
			broj++;
			i=2; continue;
		}
		
		if(i==broj) break;
	}
	return broj++;
}

int main() {
	
	int a,b,j,k,suma=0; do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a<= 0) printf("A nije prirodan broj.\n");
	if(a>=b) printf("A nije manje od B.\n");
	
	} while(a<=0 || b<=0 || a>=b);
	
	for(j=0;j<b;j++)
	{
		k=daj_prost();
		if(k>a && k<b) suma+=k;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
