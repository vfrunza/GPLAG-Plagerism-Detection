#include <stdio.h>

char* obuhvat(char *tekst, int x1, int y1, int x2, int y2)
{
	char *s=tekst, *pt, *kt, *pi, *ci;
	float br=0, x, y, k=1, dec=10, ima_tacku=0, suma=0, treba=0;
	while(*s!=0)
	{
		br++; s++;
	}
	if(br==0)
		return tekst;
	s=tekst;
	while(*s!=0)
	{
		pt=s;
		while(*s!=')')
			s++;
		kt=s;
		pi=pt; ci=kt;
		ima_tacku=0; k=1; suma=0;
		while(*pt!=',')
		{
			if(*pt=='.')
				ima_tacku=1;
			else if(*pt=='-')
				k*=-1;
			else if(*pt>='0' && *pt<='9')
				{
					if(ima_tacku)
						suma=suma+(*pt-'0')/10.;
					else
					suma=suma*dec+*pt-'0';
				}
			else
				dec=10;
			pt++;
		}
		x=suma*k;
		ima_tacku=0; k=1; suma=0;
		while(*pt!=')')
		{
			if(*pt=='.')
				ima_tacku=1;
			else if(*pt=='-')
				k*=-1;
			else if(*pt>='0' && *pt<='9')
				{
					if(ima_tacku)
						suma=suma+(*pt-'0')/10.;
					else
					suma=suma*dec+*pt-'0';
				}
			else
				dec=10;
			pt++;
		}
		y=suma*k;
		treba=0;
		printf("%f, %f\n", x, y);
		if(x<x1 || x>x2 || y<y1 || y>y2)
			treba=1;
		if(treba)
		{
			ci+=2;
			while(*ci!='\0')
			{
				*pi=*ci;
				pi++; ci++;
			}
			*pi='\0';
		}
		s+=2;
	}
		
	return tekst;
}



int main() {
	char tekst[100]="(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
	printf("\n%s", obuhvat(tekst, -3, -3, 3, 3));
	return 0;
}
