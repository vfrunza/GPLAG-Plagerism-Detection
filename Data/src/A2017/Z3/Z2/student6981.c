#include <stdio.h>
#include <math.h>

void zaokruzi1 (float *p, int d)
{
	int i;
	for(i=0;i<d;i++)
	{
		*(p+i)=((int)round(*(p+i)*10))/10.;
	}
}

int suma_clanova (float broj)
{
	int br=(int)round(fabs(broj)*10);
	int s=0;
	
	do
	{
	s+=br%10;
	br=br/10;
	}while(br!=0);
	
	return s;
}
void preslozi (float *p, int d, int k)
{
	int i,j,suma,pozicija=0;
	float temp;
	
	zaokruzi1(p,d);
	
	for(i=0;i<d;i++)
	{
		
		suma=suma_clanova(*(p+i));
		
		if(suma>=k)
		{
			temp=*(p+i);
			
			for(j=i;j>pozicija;j--)
			{
				*(p+j)=*(p+j-1);
			}
			
			*(p+pozicija)=temp;
			pozicija++;
		}
		
		
	}
}

int main() {
	
	int k=14;
	int i;
	
	float niz[5]={13.1, 15.749999, 15.75, 9.222, 78.1};
	
	preslozi(niz,5,k);
	
	printf("Niz glasi: ");
	for(i=0;i<5;i++)
    {
    	printf("%g ", niz[i]);
    }

	
	return 0;
}
