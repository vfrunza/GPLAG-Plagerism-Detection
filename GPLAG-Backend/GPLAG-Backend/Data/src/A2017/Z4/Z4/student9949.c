#include <stdio.h>

int provjeri(char *s)
{
	int k1=0, k2=0, i, j;
	char niz_otvorenih[1000];
	char niz_zatvorenih[1000];
	char *p=niz_otvorenih;
	char *q=niz_zatvorenih;
	while(*s!='\0') {
		if(*s=='<' && *(s+1)!='/') {
			s++;
			if(*s=='\0') break;
			while(*s!=' ' || *s!='>') {
				if(*s>='A' && *s<='Z') {
					*p=*s+32;
				} else {
					*p=*s;
				}
				p++;
				s++;
				k1++;
				if(*s=='\0') break;
			}
			*p=' ';
			p++;
			k1++;
		} else if(*s=='<' && *(s+1)=='/') {
			s+=2;
			if(*s=='\0') break;
			while(*s!=' ' || *s!='>') {
				if(*s>='A' && *s<='Z') {
					*q=*s+32;
				} else {
					*q=*s;
				}
				q++;
				s++;
				k2++;
				if(*s=='\0') break;
			}
			*q=' ';
			q++;
			k2++;
		} else {
			s++;
		}
		if(*s=='\0') break;
	}
	if(k1!=k2) return 0;
	for(i=k1; i>0; i--) {
		for(j=0; j<k2; j++) {
			if(p[i]!=q[j]) {
				return 0;
			} else {
				if(j==k2-1) return 1;
				i--;
			}
		}
	}
	return 1;

}

int main()
{
	return 0;
}
