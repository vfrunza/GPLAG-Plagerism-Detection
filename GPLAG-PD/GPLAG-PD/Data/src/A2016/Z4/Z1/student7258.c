#include <stdio.h>


char* izbaci_najcescu(char *s) {
	char *p=s,*q;
	char *pocetak1, *kraj1, *pocetak2, *kraj2, *prva, *druga, *PocetakRijeci, *KrajRijeci;
	int brojac1=0,brojac2,logpr;
	while(*p!='\0') {
		if((*p>='A' && *p<='Z')||(*p>='a' && *p<='z') && (p==s || *(p-1)==' ')) {
			pocetak1=p;
			while ((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')) {
				p++;
			}
			if(*p=='\0' || *p==' ' || *p=='-') {
				kraj1=p;
				q=p;
				while(*q!='\0') {
					if ((*q>='A' && *q<='Z')||(*q>='a' && *q<='z') && (q==s || *(q-1)==' ')) {
						pocetak2=q;
						while((*q>='A' && *q<='Z')||(*q>='a' && *q<='z')) {
							q++;
						}
						if(*q=='\0' || *q==' ' || *q=='-') {
							kraj2=q;
							logpr=1;
							prva=pocetak1;
							druga=pocetak2;
							while(druga!=kraj2) {
								if(*prva!=*druga) logpr=0; 
								prva++;
								druga++;
							}
							if(logpr==1) {
								brojac1++;
							}
						}
					}
					q++;
				}
				brojac2=0;
				if(brojac1>brojac2) {
					brojac2=brojac1;
					PocetakRijeci=pocetak1;
					KrajRijeci=kraj1;
				}
			}
		}
		p++;
	}
	
	char *pr,*dr,*Pocetak,*Kraj;
	p=s;
	while(*p!='\0') {
		if((*p>='A' && *p<='Z')||(*p>='a' && *p<='z') && (p==s || *(p-1)==' ')) {
			Pocetak=p;
			while((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')) {
				p++;
			}
			if(*p==' ' || *p=='\0' || *p=='-') {
				Kraj=p;
				logpr=1;
				pr=Pocetak;
				dr=PocetakRijeci;
				while(pr!=Kraj) {
					if(*pr!=*dr) logpr=0; 
					pr++;
					dr++;
				}
				if(logpr==1) {
					while(KrajRijeci!='\0') {
						*PocetakRijeci=*(KrajRijeci+1);
						PocetakRijeci++;
						KrajRijeci++;
					}
					p=p-(KrajRijeci-PocetakRijeci);
				}
			}
		}	
		p++;
	}
	return s;
}
int main() {

	return 0;
}
