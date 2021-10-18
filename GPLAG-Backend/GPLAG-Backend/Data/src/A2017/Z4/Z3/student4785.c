#include <stdio.h>

void najduzi_bp(char *s1, char *s2)
{
	char *p=s1;
	char *pocetak;
	int max=0,d=1;
	while(*s1!='\0') {

		/* stavlja pokazivac p na pocetak rijeci */
		if(!((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))) {
			p=s1+1;
		} else {
			char *neslovo=s1;

			/* stavlja pokazivac neslovo na kraj rijeci */
			while(*neslovo!='\0') {
				if(!((*neslovo>='A' && *neslovo<='Z') || (*neslovo>='a' && *neslovo<='z'))) break;
				neslovo++;
			}

			while(p<neslovo) {
				char *min=neslovo;
				char *r=p;
				while(r<neslovo) {
					char *q=r+1;
					char temp=*r;
					if(temp>='A' && temp<='Z') temp+='a'-'A';
					while(q<neslovo) {
						char temp2=*q;
						if(temp2>='A' && temp2<='Z') temp2+='a'-'A';
						if(temp==temp2) {
							/* pamti poziciju najranijeg ponavljanja slova*/
							if(q<min) {
								min=q;
							}
							break;
						}
						q++;
					}
					r++;
				}

				d=0;
				while(min>p) {
					d++;
					min--;
				}
				/* pamti se pozicija najduzeg niza */
				if(d>max) {
					max=d;
					pocetak=p;
				}
				p++;
			}
			s1=neslovo-1;
		}
		s1++;
	}

	while(max) {
		*s2++=*pocetak++;
		max--;
	}
	*s2='\0';

}

int main()
{
	return 0;
}
