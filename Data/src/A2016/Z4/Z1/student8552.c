#include <stdio.h>

char* izbaci_najcescu (char* s) {
	char* rijeci[20];
	char *poc=s,*p,*q,*r;
	int i,j,vel=0,br_rijeci=0,br[20]={0},max,index;
	while (*s!='\0') {
		while ((*s<'A' || *s>'z' || (*s>'Z' && *s<'a')) && *s!='\0')
			s++;
		if (*s=='\0') break;
		rijeci[br_rijeci]=s;
		br_rijeci++;
		while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			s++;
		if (*s=='\0') break;
	}
	s=poc;
	if (br_rijeci!=0) {
		br[0]=1;
		vel++;
		for (i=1; i<br_rijeci; i++) {
			for (j=0; j<i; j++) {
				p=rijeci[i];
				q=rijeci[j];
				while ((*p==*q || *p==*q+32 || *p+32==*q) && ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && ((*q>='A' && *q<='Z') || (*q>='a' && *q<='z'))) {
					p++;
					q++;
				}
				if ((*p<'A' || *p>'z' || (*p>'Z' && *p<'a')) && (*q<'A' || *q>'z' || (*q>'Z' && *q<'a'))) {
					br[j]++;
					break;
				}
				else if (j==i-1) {
					br[i]++;
					vel++;
				}
			}
		}
		max=br[0];
		index=0;
		for (i=1; i<br_rijeci; i++) {
			if (br[i]>max) {
				max=br[i];
				index=i;
			}
		}
		if (max==1) 
			s=rijeci[index];
		else if (max!=1)
			s=rijeci[index+1];
		while (*s!='\0') {
			if (max==1) {
				p=rijeci[index];
				s=p;
				while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
					s++;
				while (*s!='\0')
					*p++=*s++;
				*p='\0';
				if (*p=='\0') break;
			}
			else if (max!=1) {
				p=rijeci[index];
				q=s;
				while ((*p==*s || *p==*s+32 || *p+32==*s) && ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
					p++;
					s++;
				}
				if ((*p<'A' || *p>'z' || (*p>'Z' && *p<'a')) && (*s<'A' || *s>'z' || (*s>'Z' && *s<'a')) && (*(q-1)<'A' || *(q-1)>'z' || (*(q-1)>'Z' && *(q-1)<'a'))) {
					r=q;
					while (*s!='\0')
						*q++=*s++;
					*q='\0';
					s=r;
				}
			}
			if (*s=='\0') break;
			s++;
		}
		p=rijeci[index];
		s=p;
		while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			s++;
		while (*s!='\0')
			*p++=*s++;
		*p='\0';
	}
	return poc;
}

int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
