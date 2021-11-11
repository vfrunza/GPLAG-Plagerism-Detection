#include <stdio.h>

int daj_prost()
{
	static int t=1; /*staticka promjenjiva kada nema parametra*/
	int prost=1,i=0;
	
	while (1)       /*prolazak kroz beskonacnu while petlju za trazenje prostih brojeva*/
	{
		t++;
	
	for(i=2;i<t;i++)         /*provjera da li je broj prost*/
	{
		if(t%i==0)
		{                          							/*za i=2;2<2 (nece uci u petlju)*/
		prost=0;											/*za 2<3  uslov zadovoljen 3/2=prost broj 3*/
			break;											/*za 2<4 uslov zadovoljen 4/2!=prost broj */	
		}                                                       /*za 2<5 uslov zadovoljen 5/2=prost broj 5*.. itd*/    
		else
		{
			prost=1;
		}
	}
	
	
	if(prost==1)
	{
		return t;
	}
	}
	
	
}

/*provjera da li je broj prirodan i da li je A manje od B*/
int main() {
	int a,b,suma_prostih=0,f=daj_prost();
	
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)
		{
			printf("A nije prirodan broj.\n");
		}
		else if (a>=b)
		{
			printf("A nije manje od B.\n");
		}
		
		
	} while(a>=b || a<=0 );
	
	while(f<b)
	{
		f=daj_prost();             /*vracanje funkcije*/
	
	if(f>a && f<b)
	{
		suma_prostih=suma_prostih+f;       /*racunanje sume prostih brojeva*/
	}}

printf("Suma prostih brojeva izmedju %d i %d je %d. ",a,b,suma_prostih);
	
	
return 0;	
}
