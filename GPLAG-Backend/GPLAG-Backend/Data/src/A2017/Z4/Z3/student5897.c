#include <stdio.h>
void najduzi_bp(char* s1, char* s2)
{
	char *p,*k,*p1,*k1,*t;
	int  brojac1=0, brojac2=0;
	while(!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))) {
		s1++;
	}
	p=s1;
	t=s1;
	s1++;
	while((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
		while(t!=s1) {
			if(*t==*s1) break;
			brojac1++;
			t++;
		}
		if(*t==*s1 && t!=s1) {
			k=s1;
			break;
		}
		s1++;
		t=p;
		k=s1;
	}
	while(*s1) {
		while(!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))) {
			s1++; if(*s1=='\0') break;
		}
		if(*s1=='\0') break;
		p1=s1;
		t=s1;
		s1++;
		while((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
			while(t!=s1) {
				if(*t==*s1) break;
				brojac2++;
				t++;
			}
			if(*t==*s1 && t!=s1) {
				k1=s1;
				break;
			}
			if(*s1=='\0') break;
			s1++;
			if(*s1=='\0') break;
			t=p1;
			k1=s1;
		}
		if(brojac2>brojac1) {
			p=p1;
			k=k1;
			brojac1=brojac2;
		}
	}
	while(p!=k){
		*s2=*p;
		s2++; p++;
	}
	s2++; *s2='\0';
}


int main()
{
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
