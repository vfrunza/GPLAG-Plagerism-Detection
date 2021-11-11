#include <stdio.h>
void unesi(char niz[], int velicina)
{
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
void Broj(char *pok, char *kpok, float *x, float *y)
{
	char *s=pok;
	int negativni;
	double a,b;
	*x=0, *y=0;
	while(s!=kpok)
	{
		s++;
		negativni=0;
		if(*s=='-') {
			negativni=1;
			s++;
		}
		while(*s>='0' && *s<='9')
		{
			*x=*x*10+(*s-'0');
			s++;
		}
		if(*s=='.')
		{
			s++;
			a=0;
			while(*s>='0' && *s<='9')
			{
				a=a*10+(*s-'0');
				s++;
			}
			while(a>=1)
			a=a/10;
			*x+=a;
		}
		if(negativni) *x=*x*(-1);
		if(*s==',') s++;
		negativni=0;
		if(*s=='-') {
			negativni=1; s++;}
			while(*s>='0' && *s<='9')
			{
				*y=*y*10+(*s-'0');
				s++;
			}
			if(*s=='.')
			{
				s++;
				b=0;
				while(*s>='0' && *s<='9')
				{
					b=b*10+(*s-'0');
					s++;
				}
				while (b>=1) 
					b=b/10;
					*y+=b;
					
				}
				if(negativni) *y=*y*(-1);
			}
		}
		
		char *obuhvat(char *s, float x1, float y1, float x2, float y2)
		{
			char *p=s;
			char *pok, *kpok;
			char *izbaci;
			float x,y;
			while(*s!='\0')
			{
				if(*s=='(')
				{
					pok=s;
					while(*s!=')') s++;
					kpok=s;
					Broj(pok, kpok,&x,&y);
					if(x<x1 || x>x2 || y<y1 || y>y2)
					{
						s++;
						while(*s==',') s++;
						izbaci=s;
						while(*izbaci!='\0')
						{*pok++=*izbaci++;
					}
					*pok='\0';
					s=s-(izbaci-pok);
				}
			}
			else s++;
		}
		if(s!=p) s--;
		if(*s==',') *s='\0';
		return p;
		}
int main() {
	char text[100];
	printf("Unesite neki text: ");
	unesi(text, 100);
	char *novi=text;
	novi=obuhvat(text, -10, -10, 5, 5);
	printf("%s\n", text);
	printf("%s\n", novi);
	return 0;
}
