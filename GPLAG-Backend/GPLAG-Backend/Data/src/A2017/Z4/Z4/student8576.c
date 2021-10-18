#include <stdio.h>

int provjeri(char* p)
{
	char* pok = p;
	int brojac_otvorenih = 0;
	int brojac_zatvorenih = 0;
	int i=0, j=0;
	char tagovi[25][20];
	while(*p!='\0')
	{
		if(*p=='<' && *(p+1)!='/')
			brojac_otvorenih++;
		else if(*p=='<' && *(p+1)=='/')
			brojac_zatvorenih++;
		p++;
	}
	if(brojac_zatvorenih != brojac_otvorenih)
		return 0;
	if(brojac_otvorenih==0)
		return 1;
	p = pok;
	while(*p!='\0')
	{
		if(*p=='<' && *(p+1)!='/')
		{
			p++;
			if(*p==' ' || *p=='>')
				return 0;
			while(*p!='>' && *p!=' ')
			{
				char c = *p;
				if(c>='A' && c<='Z')
					c+=32 ;
				tagovi[i][j] = c;
				j++;
				p++;
			}
			tagovi[i][j] = '\0';
			i++;
			j=0;
		}
		else if(*p=='<' && *(p+1)=='/')
		{
			p++;
			p++;
			if(*p==' ' || *p=='>')
				return 0;
			while(*p!='>' && *p!=' ')
			{
				char c = *p;
				if(c>='A' && c<='Z')
					c+=32;
				if(c!=tagovi[i-1][j] || tagovi[i-1][j]=='\0')
					return 0;
				p++;
				j++;
			}
			i--;
			j=0;
		}
		p++;
	}
	return 1;
}

int main() {
	printf("%d", provjeri("<html><a></a></html>"));
	return 0;
}
