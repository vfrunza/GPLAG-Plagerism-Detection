#include <stdio.h>  

void najduzi_bp(char* s, char* s2)
{
	int brojac=0;
	int brojac2=0;
	int prekini=0;
	int max=0,broj=0;
	int i;
	char *p;
	char *s1;
	s1=s;
	char *neki;
	while(*s1!='\0')
	{
		if(*s1>='A' && *s1<='Z') *s1='a';
		broj=1;
		p=s1;
		p++;
		if((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z'))
		{
			while(1)
			{
				if(*p>='A' && *p<='Z') *p+=32;
				prekini=0;
				neki=s1;
				
				while(neki<p)
				{
					if(*neki==*p) { prekini=1; }
					neki++;
				}
				if(!(*p>='a' && *p<='z') ||(*p>='A' && *p<='Z')) prekini=1;
				if(prekini)
				{
					for(i=0;i<broj;i++) printf("%c",*(s1+i));
					printf("\n");
					if(broj>max) max=broj;
					break;
				}
				else
				{
					broj++;
					p++;
					
				}
			}
		}
		s1++;
	}
	
}
int main() {
	char niz[10];
	najduzi_bp("Ovo jev ovo aaaa",niz);
	//printf("%s",niz);
	return 0;
}
