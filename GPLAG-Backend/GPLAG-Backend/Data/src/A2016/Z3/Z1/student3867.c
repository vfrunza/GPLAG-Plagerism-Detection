#include <stdio.h>

int daj_prost()
{
	static int i=1;
/*static jer treba svaki put kada pozovem daj_prost() da daje sljedeci prost, inace bi uvijek isao od i*/
	int dodatak,j;
	if(i==1)
	{
		i++;
		return 2;
	}
	dodatak=1;
	i++;
/*provjerava da li je i prost broj*/
	do
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				dodatak=0;
				break;
			}
			else dodatak=1;
		}
		i++;
	}while(dodatak==0);
	i--;
	return i;
}

int main()
{
	int a,b,i,nesto,suma=0;
	do
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a>=b)
			printf("A nije manje od B.\n");
		if(a<1)
			printf("A nije prirodan broj.\n");
	}while((a>=b)||(a<1));
/*sabiranje prostih brojeva izmedju unesenih a i b*/
    for(i=a+1;i<b;i++)
	{
		nesto=daj_prost();
/*dva if-a za provjeru intervala*/
		if(nesto<=a)
		{
			i--;
			continue;
		}
		if(nesto>=b)
			break;
		suma=suma+nesto;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}