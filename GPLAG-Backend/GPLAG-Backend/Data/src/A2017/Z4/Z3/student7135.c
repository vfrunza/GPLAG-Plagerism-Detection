#include <stdio.h>
void najduzi_bp(char* s1, char* s2)
{
	char* p=s1;
	char* p1=s1;
	char* p2=s1;
	int brojac=1;
	int ponavlja=0;
	int max_slova=0,max_pozicija=0,i=0,k=0,j;
	while(*s1!='\0') {
		brojac=1;
		while(((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) && *s1!='\0') {
			if(brojac==1) {
				p1=s1;
				k=i;
			};
			ponavlja=0;
			if(p1!=s1) {
				p2=p1;
				ponavlja=0;
				while(s1>p2) {
					if(*p2==*s1 || (*p2==*s1-32 && (*p2<='Z' && *s1>='a')) || (*p2==*s1+32 && (*p2>='a' && *s1<='Z'))) {
						ponavlja=1;
						break;
					}
					p2++;
				}
			}
			if(ponavlja==1 || !((*(s1+1)>='a' && *(s1+1)<='z') || (*(s1+1)>='A' && *(s1+1)<='Z'))) {
				if(ponavlja==1) brojac--;
				if((brojac)>max_slova) {
					max_slova=brojac;
					max_pozicija=k;
				}
				break;
			}
			s1++;
			i++;
			brojac++;
		}
		if(ponavlja==1) {
			s1-=(brojac);
			i-=(brojac);
		}
		s1++;
		i++;
	}
	*(s2+max_slova)='\0';
	for(j=0; j<max_slova; j++) {
		*s2=*(p+j+max_pozicija);
		s2++;
	}
}
int main()
{
	char niz[10];
	najduzi_bp ("Ovo jev ovo aaaa", niz);
	printf ("Niz: '%s'", niz);
	return 0;
}
