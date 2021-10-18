#include <stdio.h>

int provjeri(char *s)
{
	char tagovi[10000];
	char* pocetak=tagovi;
	char* t=tagovi;
	int broj_tagova=0;
	*t=' ';

	while(*s!='\0') {
		if (*s=='<' && *(s+1)!='/') {
			char *p=s+1;
			char* kraj=s+1;
			int kraj_taga=0;
			if(!((*(s+1)>='A' && *(s+1)<='Z') || (*(s+1)>='a' && *(s+1)<='z'))) return 0;
			/*trazenje kraja taga*/
			while(*kraj!='\0') {
				if(*kraj=='<') return 0;
				else if(*kraj=='>') {
					kraj_taga=1;
					break;
				}
				kraj++;
			}
			if(kraj_taga==0) return 0;
			s++;
			t++;
			broj_tagova++;
			while(*p!='\0') {
				if (*p==' ' || *p=='>') break;
				p++;
			}
			/*stavljanje naziva taga u string*/
			while(s<p) {
				char temp=*s;
				if(temp>='A'&& temp<='Z') temp+='a' - 'A';
				*t++=temp;
				s++;
			}
			*t=' ';
		}

		else if(*s=='<' && *(s+1)=='/') {
			char* p=s+2;
			char* kraj=s+2;
			char* razmak=t;
			char* tag=t-1;
			int kraj_taga=0;
			if(!((*(s+2)>='A' && *(s+2)<='Z') || (*(s+2)>='a' && *(s+2)<='z'))) return 0;
			s+=2;
			while(*p!='\0') {
				if(*p==' ' || *p=='>') break;
				p++;
			}
			kraj=p;
			/*trazenje kraja taga*/
			while(*kraj!='\0') {
				if(*kraj!='>' && *kraj!=' ') return 0;
				else if(*kraj=='>') {
					kraj_taga=1;
					break;
				}
				kraj++;
			}
			if(kraj_taga==0) return 0;
			/*ako nema otvorenih tagova*/
			if(broj_tagova==0) 	return 0;

			while(tag>=pocetak) {
				if (*tag==' ') {
					razmak=tag;
					break;
				}
				tag--;
			}
			tag++;
			while(tag<t) {
				char temp=*s;
				if(temp>='A' && temp<='Z') temp+='a'-'A';
				if(s==p) return 0;
				if(*tag!=temp) return 0;
				tag++;
				s++;
			}
			if (s!=p) return 0;
			t=razmak;
			*(t+1)='\0';
			s=kraj;
			broj_tagova--;
		}
		s++;
	}
	if(broj_tagova!=0) return 0;
	return 1;
}

int main()
{
	return 0;
}