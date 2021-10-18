#include <stdio.h>
#include <string.h>

int slovo(char c);

int dva_slova(char a, char b);

int duzi(char* s2, int duzina, char* p1, char* p2);

void najduzi_bp(char* s1, char* s2);

int main()
{
	char s1[1000]=" aBA";
	char s2[1000]="";
	najduzi_bp(s1,s2);
	printf(" \n|%s| ",s2);
	return 0;
}

int slovo(char c)
{
	if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))return 1;
	return 0;
}

int dva_slova(char a, char b)
{
	if( (a-b=='a'-'A'||a-b=='A'-'a'||a-b==0)&&slovo(a)&&slovo(b))return 1;
	return 0;
}

int duzi(char* s2, int duzina, char* p1, char* p2)
{
	char* p=p1;
	int i=0;
	int t=0;/* nema duplikata*/

	while(p<p2)
	{
		p++;
		for(i=1; (p-i)>=p1 ; i++)
		{
			if(dva_slova(*(p-i),*p)) {t=1 ; break;}
		///	printf("\n |%c|%c|",*(p-i),*p);
		}
		if(t)break;
	}
	if(p-p1>duzina)
	{
		for(i=0; i<p-p1; i++)
		{
			*(s2+i)=*(p1+i);
		}
		*(s2+(p-p1))='\0';

		return p-p1;
	}
	else return duzina;

}

void najduzi_bp(char* s1,char* s2)
{
	int duzina=0;
	char *p1,*p2;
	p1=s1;
	p2=s1;

	while(*p1!='\0')
	{
		while( !slovo(*p1) && *p1!='\0')p1++;
		/*naisli smo na prvo slovo*/
		p2=p1;
		p2++;
		while(slovo(*p2) && *p2!='\0')p2++;
		/*ovdje smo naisli na prvo neslovo poslije rijeci*/
		while(p1<p2)
		{
			duzina=duzi(s2,duzina,p1,p2);
			p1++;
		}
		p1=p2;
	}

}



