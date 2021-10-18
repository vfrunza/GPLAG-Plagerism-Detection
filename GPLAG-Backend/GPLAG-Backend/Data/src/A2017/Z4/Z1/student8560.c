#include<stdio.h>
char* ubaci_broj (char* tekst, int broj) {
	int br_mjesta=0,tmp,i,c,obr=0,obrnuti;
	char *s,*p,*kraj,*raz,*ss,*pomjeri;
	s=tekst;
	tmp=broj;
	if(broj<0) {
		br_mjesta++;
		tmp*=-1;
	}
	while(tmp!=0) {
		c=tmp%10;
		obr=obr*10+c;
		br_mjesta++;
		tmp/=10;
	} 
	obrnuti=obr;
	br_mjesta++;
	while(*s!='\0') {
		obr=obrnuti;
		if(*s!=' ') {
			while(*s!=' ' && *s!='\0') s++;
			if(*s=='\0') break;
			if(*s==' ') {
				s++;
				kraj=s;
				if(*kraj==' ') {
					while(*kraj==' ') kraj++;
				}
				if(*kraj=='\0') break;
			}
			p=s;
			while(*s!='\0') s++;
			ss=(s+br_mjesta);
			while(ss>=(p+br_mjesta)) {
				*ss=*s;
				s--;
				ss--;
			}
			i=br_mjesta;
			if(broj<0) {
					*p='-';
					p++;
					i--;
			}
			while(i!=1) {
				c=obr%10;
				*p=(c+'0');
				p++;
				i--;
				obr/=10;
			}
			*p=' ';
			s=p;
			raz=s;
			raz++;
			if(*raz==' ') {
				pomjeri=(raz+1);
				while(*pomjeri!='\0') {
					*raz=*pomjeri;
					raz++;
					pomjeri++;
				}
				*raz='\0';
			}
		}
		s++;
		if(*s=='\0') break;
	}
	return tekst;
}
int main() {
	int broj;
	char pjesma[]="   Deset mladja  ";
	printf("Unesite broj: ");
	scanf("%d",&broj);
	printf("%s",ubaci_broj(pjesma,broj));
	return 0;
}
