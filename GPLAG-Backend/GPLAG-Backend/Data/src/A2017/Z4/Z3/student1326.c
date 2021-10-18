#include <stdio.h>

void najduzi_bp(char *s1, char *s2){
	char *p=s;
	char *p_pom=s;
	char *t=s;
	int brojac=0;
	
	
	while(*s1!='\0'){
		while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')){
			for(*p_pom=t-1; *p_pom<=p; p_pom++){
				if(*p!=*p_pom)
			brojac++;
			}
			p++;
			t=p;
			p_pom=t;
		}
		
		s++;
	}
	
}

int main() {
	char string1[]="Ovo je neki primjer teksta";
	char string2[100]="";
	printf("%s", najduzi_bp(string1,string2));
	return 0;
}
