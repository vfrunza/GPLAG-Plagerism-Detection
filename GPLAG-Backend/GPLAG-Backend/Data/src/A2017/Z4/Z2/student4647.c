#include <stdio.h>

int provjeri_duzine(char* s,int* niz, int vel){
	int br_slova=0,br_rijeci=0;
	char *p=s;
	while(*s!='\0'){
if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z') && (s==p || *(s-1)==' ')) {
	br_slova=0;
	 while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
			br_slova++;
			s++;
		}
		if((*s<'A' || *s>='z')|| (*s>'Z' && *s<'a')|| *s=='\0')
		{
			br_rijeci++;
			if(br_rijeci>vel)
			return 0;
		}
		if(niz[br_rijeci-1]!=br_slova)
		return 0;
	}
	else s++;
}
if(vel>br_rijeci)    return 0;
return 1;
}

 
int main() { 
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
