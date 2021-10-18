#include <stdio.h>
void najduzi_bp(char *s1,char *s2)
{
	char *p,*q,*r=s2,temp1,temp2;
	char pomocni[26];
	int logicka,razmak=1,duzina=0,maxduzina=0,i;
	/* prolazak kroz string*/
	while(*s1!='\0') {
		if(*s1<'A'||(*s1>'Z'&& *s1<'a')||*s1>'z') {
			s1++;
			razmak=1;
		} else if (razmak==1) {
			p=s1;
			i=0;
			/* Trazenje podstringa*/
			while((*p>='A'&& *p<='Z')||(*p>='a'&&*p<='z')) {
				logicka=0;
				q=p-1;
				/*Provjera da se ne ponavlja niti jedan znak*/
				if(*p>='A'&& *p<='Z')
					temp1=*p+'a'-'A';
				else
					temp1=*p;
				while(q>=s1) {
					if(*q>='A'&& *q<='Z')
						temp2=*q+'a'-'A';
					else
						temp2=*q;
					if(temp1==temp2) {
						logicka=1;
						break;
					}
					q--;
				}
				if(logicka==0)
					pomocni[i++]=*p;
				else {
					break;
				}
				p++;
			}
			duzina=i;
			/*ako je veci od prehodnog prepisi ga*/
			if(duzina>maxduzina) {
				s2=r;
				for (i = 0; i < duzina; i++) {
					*(s2+i)=pomocni[i];

				}
				*(s2+i)='\0';
				maxduzina=duzina;
			}
			s1++;
		} else s1++;
	}
	/*ako nema slova u stringu*/
	if(maxduzina==0)
		*s2='\0';
}

int main()
{
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
