#include <stdio.h>
int daj_prost()
{int i=2;
static int j=1;j++;
	if (j==2) return j;
	for (;i<j;i++)
	{
	if (j%i==0) {j++;i=2;}
	} return j; }

int main() {
	int a,b,suma=0,broj=0,i;
	printf("Unesite brojeve A i B: ");
	scanf("%d%d",&a,&b);
	while (a<=0 || a>=b || b<=0) {
		if (a<=0) {printf("A nije prirodan broj.\n");
				printf("Unesite brojeve A i B: ");
				scanf("%d%d",&a,&b);continue;}
		if (a>=b) {printf("A nije manje od B.\n");
				printf("Unesite brojeve A i B: ");
				scanf("%d%d",&a,&b);continue;}
		if (b<=0)  {printf("B nije prirodan broj.\n");
				printf("Unesite brojeve A i B: ");
				scanf("%d%d",&a,&b);}
	}
	
for (i=0;i<b;i++)
{	broj=daj_prost();
	if (broj>a && broj<b) suma=suma+broj;
	
}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
