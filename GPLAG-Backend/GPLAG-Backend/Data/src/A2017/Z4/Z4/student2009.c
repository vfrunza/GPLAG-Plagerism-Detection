#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 150

int slovo_broj(char x)
{
	if((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>=49 && x<=57))
		return 1;

	else return 0;
}

int isti(char *x, char *y)
{
	char *a=x,*b=y;

	while(*a!='\0')
		if(*a++!=*b++)
			return 0;

	return 1;
}

int validan(char*x)
{
	char *p=NULL, *k=NULL, *s=NULL;
	char tag1[n]= {'\0'}, tag2[n]= {'\0'}, tag3[n+1]= {'\0'};
	char *a=NULL,*b=NULL,*c=NULL;

	while(*x!='\0') {

		if(*x=='<') {
			if(*(x+1)=='/') return 0;

			p=x;
			k=(x+1);

        re:
			a=tag1;
			b=tag2;
			c=tag3;
			*a++='<';
			*c++='<';
			*c++='/';
			while(*k!='<' && *k!='\0') {
				*a++=*k;
				*c++=*k++;
			}
			*a='\0';
			*c='\0';

			c=strstr(x,tag3);
			if(c==NULL) return 0;

			else {
				k++;
				s=k;
				*b++='<';
				while(*k!='<' && *k!='\0') {
					if(*k!='/')
						*b++=*k;
					k++;
				}

				if(*s=='/' && !isti(tag1,tag2))
					return 0;

				else if (*s!='/') {
					p=s-1;
					k=s;
					goto re;
				}

				else {
					while(*k!='\0')
						*p++=*k++;

					*p='\0';
					x--;
				}
			}
		}
		x++;
	}

	if(*x=='\0')
	return 1;
	else return 0;
}

int provjeri(char *s)
{
	char *a=NULL,*b=NULL,*c=NULL;
	char *html;
	int brojac=1, valid=0;
	html=(char *)malloc(n*sizeof(char));

	c=html;
	*c='\0';

	while(*s!='<' && *s!='\0') s++;
	if(*s=='<' && *(s+1)=='/') {
		free(html);
		return 0;
	}
	a=s;
	while(*a!='\0') {
		if(*a=='<') {
			if(*(a+1)=='>' || *(a+1)==' ' || *(a+1)=='<' || *(a+1)=='\0') {
				free(html);
				return 0;
			}
			b=a;
			do {
				*c=*b;
				if((*b)>='A' && (*b)<='Z')
					*c=*c+32;
				c++;
				b++;
				brojac++;
				if(*b=='/' && *(b-1)=='<') {
					*c++=*b++;
					brojac++;
				}
			} while(slovo_broj(*b));

			if(*b=='\0') {
				free(html);
				return 0;
			}

			if(*b==' ' || *b=='>')
				valid=1;
			else valid=0;  /* Poslije naziva elementa mora biti razmak+vrijednosti ili >, u suprotnom tag nije validan? */

			if(valid==1) {
				*c++='>';
				*c='\0';
				html=(char*)realloc(html,(n+brojac)*sizeof(char));
				c=html+brojac;
				brojac++;
				if(*b==' ') {
					while(*b!='>' && *b!='\0') {
						b++;
						if(*b=='<') {    /* Tag unutar tag-a ? */
							free(html);
							return 0;
						}
					}
				}
				a=b;
			} else {
				free(html);
				return 0;
			}
		}
		a++;
	}

	if(*html=='\0') {
		free(html);
		return 1;
	}

	else if(validan(html)) {
		free(html);
		return 1;
	}

	else {
		free(html);
		return 0;
	}
}

int main()
{
	char *t1 = "<JedanBasJaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaakoDugHTMLTagKojiJeStavljenOvdjeRadiHardKodiranja>"
					"ovo je cisto stavljeno da vidimo je li napravljena matrica gdje je duzina hardkodirana"
					"</JedanBasJaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaakoDugHTMLTagKojiJeStavljenOvdjeRadiHardKodiranja>";
	char *t2 = "<Taaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaag>"
					"tag."
					"<Taaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaagg>";
	printf ("Provjera 1: %d\nProvjera 2: %d", provjeri(t2), provjeri(t1));
	
	return 0;
}
