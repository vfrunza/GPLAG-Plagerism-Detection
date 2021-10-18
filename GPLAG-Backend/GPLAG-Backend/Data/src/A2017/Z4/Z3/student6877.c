#include <stdio.h>

	void najduzi_bp(char* s1, char* s2){
		char *p, *q, *poc, *kraj, *r;
		int duzina, max=0;
		char *pocmax, *krajmax;
		char *pom=s2;
		
		while(*s1!='\0'){
			duzina=0;
			if((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')){
				p=s1;
				poc=s1;
				
				while(*p!=' ' && *p!='\0'){
					if((*p<'a' && *p>'Z')|| (*p>'z') || (*p<'A')) break;
					p++;
				}
				
				kraj=p;
				p=poc;
				q=kraj;
				
				while(p!=q){
					r=p;
					while(r!=q){
						r++;
						if(*p==*r || *p==*r+'a'-'A' || *p==*r+'A'-'a'){
							q=r;
						}
						
						
					}
					p++;
				}
				
				kraj=q;
				p=poc;
				
				while(p!=q){
					duzina++;
					p++;
				}
				
				if(duzina>max){
					max=duzina;
					pocmax=poc;
					krajmax=kraj;
				}
				
				
			}
			s1++;
		}
		
		while(pocmax!=krajmax){
			*pom=*pocmax;
			pom++;
			pocmax++;
		}
		*pom='\0';
		
	}		
		
	

int main() {
	
	char niz[10];
    najduzi_bp ("abcde etankera cdefg", niz);
    printf ("Niz: '%s'", niz);

	return 0;
}
