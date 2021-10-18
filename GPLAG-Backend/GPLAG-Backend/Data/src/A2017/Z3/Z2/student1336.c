#include <stdio.h>
#include <math.h>


void zaokruzi1 (float *niz, int br) {
	int i;
	float *p=niz;
	for (i=0; i<br; i++) {
		*p = round (*p*10)/10;
		 p++;
	}
}


void preslozi (float *niz, int v, int d)
{
	/* Varijable a,b,c su koristene samo za racunanje*/
	float *p=niz;
	int duzina1, duzina2, i, b, c;
	float a;
	float n1[100], n2[100];
	zaokruzi1(niz,v);
	duzina1=0; duzina2=0;
	
	for(i=0; i<v; i++)
	{
		a=fabs(niz[i]);
		c=a*10;
		b=c%10;
		c=a;
		
		do
		{
			b=b+c%10;
			c=c/10;
		}while(c>0);
		
		if(b>=d) 
		{
			n1[duzina1]=niz[i]; 
			duzina1++;
		}
		else 
		{
			n2[duzina2]=niz[i];
			duzina2++;
		}
	}
	
	for(i=0; i<duzina1; i++)
	{
		*p=n1[i]; p++;
	}

	for(i=0; i<duzina2; i++)
	{
		*p=n2[i]; p++;
	}
}



int main() {
	int i;
	float niz[] = { 3.2, -4.301, -123.1999, 1.1, 0.9 };

	zaokruzi1 (niz, 5);
	preslozi(niz, 5, 8);
	
	printf("Niz glasi: ");
		for (i=0; i<5; i++)
    		printf("%g ", niz[i]);

	return 0;
}
