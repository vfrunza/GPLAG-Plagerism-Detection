#include <stdio.h>
int podstring(char* s, char* poc, char* kraj)
{
	//broj ponavljanja rijeci
	char* s1=s;
	char* s2=poc;
	int brojac=1;
	while(*s1 != '\0') {
		s2=poc;
		while((*s1 == *s2 || *s1-32 == *s2 || *s1+32 == *s2) && s2<kraj) {
			s1++;
			s2++;
		}
		if(*s1 == '\0')
			return brojac;
		if(s2==kraj && !((*s1 >= 'A' && *s1 <= 'Z') || (*s1 >= 'a' && *s1 <='z')))
			brojac++;
		s1++;
	}
	return brojac-1;
}

char* izbaci_najcescu(char* s)
{
	char* reset=s;
	char* p = s;
	char* poc;
	char* kraj;
	int br_ponavljanja;
	int rijec;
	int max=0;
	char* pmax;
	char* kmax;
	char* q;
	int  r, i=0, duzina;
	//trazi rijec koja se najcesce ponavlja
	while(*p != '\0') {
		rijec=0;
		if((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <='z')) {
			poc=p;
			kraj=poc;
			while((*kraj >= 'A' && *kraj <= 'Z') || (*kraj >= 'a' && *kraj <='z'))
				kraj++;
			rijec=1;
			p=kraj-1;
		}//ako pronadje rijec, poziva funkciju podstring da prebroji njeno ponavljanje, pamti adresu rijeci koja se najcesce ponavlja
		if(rijec==1) {
			br_ponavljanja=podstring(s, poc, kraj);
			if(br_ponavljanja > max) {
				max=br_ponavljanja;
				pmax=poc;
				kmax=kraj;
			}
		}
		p++;
	}
//izbacivanje
	if(max==0)
		return s;

	p=reset;
	q=pmax;
	r=kmax;
	
	if(kmax-pmax == 1) {
		poc=kmax;
		kraj=kmax;
	} else {
		poc=kmax-1;
		kraj=kmax-1;
	}

	//izbacuje sve rijeci koje su jednake onoj koja se najcesce ponavlja, osim te rijeci kada se prvi put pojavi
	while(*poc != '\0') {
		pmax=q;
		if((*poc==*pmax || *poc+32 == *pmax || *poc-32 == *pmax) && !((*(poc-1) >= 'A' && *(poc-1) <= 'Z') || (*(poc-1) >='a' && *(poc-1) <= 'z'))) {
			kraj=poc;
			while((*kraj==*pmax || *kraj-32 == *pmax || *kraj+32 == *pmax) && pmax<kmax) {
				kraj++;
				pmax++;
			}
			if((*(kraj-1)==*(kmax-1) || *(kraj-1)+32 == *(kmax-1) || *(kraj-1)-32 == *(kmax-1)) && !(*(kraj) >= 'A' && *(kraj) <= 'Z' || (*(kraj) >= 'a' && *(kraj) <='z'))) {
				while(*poc++ = *kraj++);
				poc=kmax-1;
			}
		}
		poc++;
	}
	//izbacivanje te rijeci kada se prvi put pojavi
	while(*pmax++ = *kmax++);

	return s;
}


int main()
{



	return 0;
}
