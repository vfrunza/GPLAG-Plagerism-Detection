#include <stdio.h>

void najduzi_bp(char *s1, char *s2)
{
	int brojac = 0;
	int max=0;
	int kraj;
	char *temp;
	char *temp_2;
	int dodaj1=0, dodaj2=0;
	int i;
	
	temp=s1;
	while (*s1!='\0') {
		if ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))
			break;
		s1++;
	}
	if (*s1=='\0') {
		*s2='\0';
		return;
	} else
		s1=temp;
	
	while (*s1!='\0') {
		if ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
			brojac=0;
			kraj=0;
			temp=s1;
			while ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
				dodaj1=0;
				dodaj2=0;
				brojac++;
				s1++;
				temp_2=s1;
				for (i = 0; i < brojac; i++) {
					if (*s1>='A' && *s1<='Z')
						dodaj1='a'-'A';
					if (*(temp_2-1)>='A' && *(temp_2-1)<='Z')
						dodaj2='a'-'A';
					else
						dodaj2=0;
					if (*s1+dodaj1==*(--temp_2)+dodaj2) {
						kraj=1;
						break;
					}
				}
				if (kraj)
					break;
			}
			if (brojac>max) {
				max=brojac;
				for (i = 0; i < max; i++) {
					*s2++=*(temp+i);
				}
				*s2='\0';
				s2-=max;
			}
			s1=temp;
		}
		s1++;
	}
}

int main()
{
	char s1 []="Ovo je neki primjer teksta";
	char s2 [100];
	najduzi_bp(s1,s2);
	printf("%s\n",s2);
	
	return 0;
}