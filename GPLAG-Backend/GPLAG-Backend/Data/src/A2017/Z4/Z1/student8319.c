#include <stdio.h>
#include<stdbool.h>

void broj_cifri(int x, int *y)
{
	if(x < 0) x *= -1;
	
	while(x > 0)
	{
		x /= 10;
		(*y)++;	
	}
}

char* ubaci_broj(char* tekst, int broj)
{
	char *p = tekst, *q, *r, pom1, pom2, znak;
	int br, i, broj2, br_znakova = 0;
	bool a, neg = false;
	
	broj_cifri(broj, &br_znakova);
	
	if(broj < 0)
	{
		neg = true;
		broj *= -1;
		br_znakova++;
	}
	
	while(*p == ' ' && *p != '\0') p++;
	
	while(*p != '\0')
	{
		if(*p == ' ')
		{
			r = p;
			while(*r == ' ' && *r != '\0') r++;
			if(*r == '\0') break;
			
			if(*(p+1) != ' ')
			{
				a = true;
				br = br_znakova+1;
			}
			else
			{
				a = false;
				br = br_znakova;
			}
			
			for(i=0; i<br; i++)
			{
				p++;
				pom1 = *p;
				q = p+1;
				
				while(*q != '\0')
				{
					pom2 = *q;
					*q++ = pom1;
					pom1 = pom2;
				}
				
				*q++ = pom1;
				*q = '\0';
			}
			
			if(a) *p-- = ' ';
			
			r = p;
			broj2 = broj;
			
			while(broj2 > 0)
			{
				znak = (broj2%10)+48;
				*r-- = znak;
				broj2 /= 10;
			}
			
			if(neg) *r = '-';
			
			while(*(p+1) == ' ') p++;
		}
		
		p++;
	}
	
	return tekst;
}

int main() {
	
	char tekst[] = "     Danas  je     lijep   i   suncan   dan.";
	
	printf("%s", ubaci_broj(tekst, -23));
	
	return 0;
}