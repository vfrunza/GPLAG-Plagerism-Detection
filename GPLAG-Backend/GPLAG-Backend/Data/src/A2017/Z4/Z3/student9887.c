#include <stdio.h>

void najduzi_bp(char* s1, char*s2)
{

	char *pocetak, *q;
	int i=0, nova_duzina=0, isti=0, max_duzina=0;

	while(*s1!='\0') {
		if((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) {
			q=s1;
			nova_duzina=0;
			isti=0;
			while((*q>='a' && *q<='z') || (*q>='A' && *q<='Z')) {
				i=0;
				while(i<nova_duzina){
					if(*q==*(s1+i) || *q==*(s1+i)+32) isti=1;
					else if(*q>='a' && (*q==*(s1+i) || *q==*(s1+i)-32)) isti=1;
					i++;
				}
				if(isti) break;
				nova_duzina++;
				if(nova_duzina>max_duzina) {
					pocetak=s1;
					max_duzina=nova_duzina;
				}
				q++;
			}
		}
		s1++;
	}
	while(max_duzina!=0) {
		*s2++=*pocetak++;
		max_duzina--;
	}
	*s2='\0';
	return;
}

int main()
{

	return 0;
}
