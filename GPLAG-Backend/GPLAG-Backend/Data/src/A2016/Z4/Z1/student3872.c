#include <stdio.h>
#include<ctype.h>
#define broj_el 100
char rijeci[1000];
void unos(char niz[], int velicina)
{
	char znak=getchar();
	int i;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
}



int duzina(char *s)
{
	int brojac=0;
	while(*s!='\0')
	
	{ brojac++; s++;}
	return brojac;
}
char *vlastiti_strcpy(char *s)
{
	char novi[100];
	char *pok=novi;
	while(*s!='\0')
	{
		*s=*pok;
		s++;
		pok++;
	}
	pok='\0';
	return pok;
}

void izbaci(char *s, char temp)
{ int velicina=0;
	while(temp!='\0')
	{
		velicina++;
		temp++;
	}
	
	char *p=s;
	char *q=s;
	while(*p!='\0')
	{
		char *pok=temp;
		char *pok1=p;
		while(((*pok1==*pok) || (*pok1==*pok-32) || (*pok1==*pok+32)) && *pok!='\0')
		{
			pok++;
			pok1++;
		
		if(p==s)
		{
			if(*pok=='\0' && !(*pok1>='A' && *pok1<='Z') && !(*pok1>='a' && *pok1<='z'))
			q=p;
			while(*(q+velicina)!='\0')
			{
				*q=*(q+velicina);
				q++;
			}
			*q=*(q+velicina);
		}
		else if(*pok=='\0' && (!(*pok1>='A' && *pok1<='Z') && !(*pok1>='a' && *pok1<='z')) && !(*(p-1)>='A' && *(p-1)<='Z') && !(*(p-1)>='a' && *(p-2)<'z'))
		{
			q=p;
			while(*(q+velicina)!='\0')
			{
				*q=*(q+velicina);
				q++;
			}
			*q=*(q+velicina);
		}
	}
	p++;
}
}
char *izbaci_najcescu(char *s)
{
	int velicina=0;
	while(*s!='\0')
	
	{
		velicina++;
		s++;}
	
	char *p=s;
	char *pok=s,*pok1=s,*pok2=s, *pok3=s, *pok4;
char *pok5;	int i=0, m=0, duzina1=0, max=0;
	char text[1000];
	char max_rijec[1000];

	if(velicina==0)
	{
		return p;
	}
	while(*s!='\0')
	{
		pok=s;
		while(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
		{
			if(*s=='\0')
			break;
			s++;
		}
		if(*s=='\0')
		{
			if(pok==p)
			
				return p;
				break;
			}
			pok1=s;
			pok2=s;
			while(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
			{
				if(*s=='\0')
				break;
				s++;
			}
			if(pok2==p && *s=='\0')
			{
				izbaci(p,p);
				return p;
			}
			if(*s=='\0')
			break;
			while(i<s-pok2)
			{
				*(text+i)=*pok2;
				pok2++;
			duzina1++;
			i++;
			}
			text[i]='\0';
			pok3=p;
			while(*pok3!='\0')
			{
				pok4=pok3;
		pok5=text;
		while(((*pok4==*pok5) || (*pok4==*pok5-32) || (*pok4==*pok5+32)) && *pok5!='\0')
		{
			pok4++;
			pok5++;
			if(pok3==p)
			{
				if(*pok5=='\0' && !(*pok4>='A' && *pok4<='Z') && (*pok4>='a' && *pok4<='z'))
				m++;
			}
			else if(*pok5=='\0' && (!(*pok4>='A' && *pok4<='Z') && !(*pok4>='a' && *pok4<='z')) && !(*(pok3-1)>='A' && *(pok3-1) && *(pok3-1)>='a' && *(pok3-1)<='z'))
			m++;
		}
		pok3++;
			}
			if(m>max)
			{
				max=m;
				for(i=0;i<duzina1;i++)
				{
					max_rijec[i]=text[i];
				}
				max_rijec[i]='\0';
			}
			if(*s=='\0')
			break;
			s++;
		}
		izbaci(p, max_rijec);
		return p;
	}



int main() {
	char text[10000];
	
	printf("Unesite neki text: ");
	unos(text,10000);
	printf("%s", izbaci_najcescu(text));
	return 0;
}
