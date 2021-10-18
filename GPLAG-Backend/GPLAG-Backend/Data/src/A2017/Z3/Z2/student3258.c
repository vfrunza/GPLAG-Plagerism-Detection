#include <stdio.h>
#include <math.h>

void zaokruzi1 (float *niz, int v)
{
	int i; 
	float *p=niz;
	for (i=0; i<v; i++)
	{
		*p=round (*p*10)/10;
		p++;
	}
}

void preslozi (float niz[], int v, int N)
{
	int l2, i, broj2, broj3;
	float broj1;
	float *p=niz;
	float niz2[1000];
	l2=0;
	i=0;
	zaokruzi1(niz,v);
	
	while(i<v)
	{
		if(niz[i]<0)
			broj1=(-1)*niz[i];
		else 
			broj1=niz[i];
		
		broj3=broj1*10;
		broj2=broj3%10;
		broj3=broj1;
		
		do
		{
			broj2=broj2+broj3%10;
			broj3=broj3/10;
		}while(broj3>0);
		
		if(broj2<N)
		{
			niz2[l2]=niz[i];
			l2++;
		}
		else
		{
			*p=niz[i];
			p++;
		}
		i++;
	}
	
	if(l2>0) 
	{
		*p=niz[l2-1];
		for(i=0; i<l2; i++)
		{
			*p=niz2[i];
			p++;
		}
	}
}


int main() {
 int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	
return 0;
}