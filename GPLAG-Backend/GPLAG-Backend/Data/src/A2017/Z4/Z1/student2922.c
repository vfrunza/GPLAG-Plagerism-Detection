#include <stdio.h>

char* ubaci_broj (char* tekst, int broj)
{
	int i=0,T=0,duzina=0,brojac=0,br=0,j,T1=0;
	int temp1=broj;
	/*rastavljanje broja na cifre*/
	if(temp1>=0) {
		while(temp1>0) {
			br++;
			temp1/=10;
		}
		while(*tekst!='\0') {
			for(j=0; j<80; j++) {
				if(*tekst=='\0') break; /*kada dođe do kraja stringa prekida se*/
				if(*tekst!=' ') { /*trazenje razmaka*/
					T1=1;
					break;
				}
				tekst++;
			}
			duzina=j;
			for(j=0; j<duzina; j++)
				tekst--;
			duzina=0;
			if(*tekst==' ' && T==1 && brojac!=0 && T1==1) {
				int temp=broj;
				tekst++;
				brojac++;
				for(i=0; i<br; i++) {
					for(j=0; j<1000; j++) {
						if(*tekst=='\0') break;
						tekst++;
					}
					duzina=j;
					/*pomjeranje stringa pri ubacivanju broja*/
					for(j=0; j<duzina+1; j++) {
						*(tekst+1)=*tekst;
						tekst--;
					}
					tekst++;
					duzina=0;
				}
				for(j=0; j<br-1; j++)
					tekst++;
				for(j=0; j<br; j++) {
					*tekst=(temp%10+'0'); /*ubacivanje broja*/
					brojac++;
					tekst--;
					temp/=10;
				}
				/*ispitivanje da li je razmak poslije ubacenog broja ili ne, ako nije treba ga ubaciti*/
				for(j=0; j<br+1; j++)
					tekst++;
				if(*tekst!=' ') {
					for(j=0; j<1000; j++) {
						if(*tekst=='\0') break;
						tekst++;
					}
					duzina=j;
					/*za ubacivanje razmaka potrebno je presloziti string, kao kod ubacivanja broja*/
					for(j=0; j<duzina+1; j++) {
						*(tekst+1)=*tekst;
						tekst--;
					}
					tekst++;
					*tekst=' ';
					brojac++;
					duzina=0;
				} else tekst--;
				T=0;
				T1=0;
			} else if(*tekst!=' ') {
				brojac++;
				T=1;
				T1=0;
			} else {
				brojac++;
				T1=0;
			}
			tekst++;
		}
		for(j=0; j<brojac; j++)
			tekst--;
		return tekst;
	} else {
		/*druga polovina programa, radi na isti nacin kao prva, samo sluzi za ubacivanje negativnih brojeva (minus je dodatak)*/
		while(temp1<0) {
			br++;
			temp1/=10;
		}
		while(*tekst!='\0') {
			for(j=0; j<1000; j++) {
				if(*tekst=='\0') break;
				if(*tekst!=' ') {
					T1=1;
					break;
				}
				tekst++;
			}
			duzina=j;
			for(j=0; j<duzina; j++)
				tekst--;
			duzina=0;
			if(*tekst==' ' && T==1 && brojac!=0 && T1==1) {
				int temp=broj;
				tekst++;
				brojac++;
				for(i=0; i<1000; i++) {
					if(*tekst=='\0') break;
					tekst++;
				}
				duzina=i;
				for(i=0; i<duzina+1; i++) {
					*(tekst+1)=*tekst;
					tekst--;
				}
				tekst++;
				*tekst='-';
				brojac++;
				duzina=0;
				tekst++;
				for(j=0; j<br; j++) {
					for(i=0; i<1000; i++) {
						if(*tekst=='\0') break;
						tekst++;
					}
					duzina=i;
					for(i=0; i<duzina+1; i++) {
						*(tekst+1)=*tekst;
						tekst--;
					}
					tekst++;
					duzina=0;
				}
				for(i=0; i<br-1; i++)
					tekst++;
				for(i=0; i<br; i++) {
					if(temp%10>=0) *tekst=(temp%10+'0');
					else *tekst=((-1)*temp%10+'0');
					brojac++;
					tekst--;
					temp/=10;
				}
				for(i=0; i<br+1; i++)
					tekst++;
				if(*tekst!=' ') {
					for(i=0; i<1000; i++) {
						if(*tekst=='\0') break;
						tekst++;
					}
					duzina=i;
					for(i=0; i<duzina+1; i++) {
						*(tekst+1)=*tekst;
						tekst--;
					}
					tekst++;
					*tekst=' ';
					brojac++;
					duzina=0;
				} else tekst--;
				T=0;
				T1=0;
			} else if(*tekst!=' ') {
				T=1;
				T1=0;
				brojac++;
			} else {
				brojac++;
				T1=0;
			}
			tekst++;
		}
		for(i=0; i<brojac; i++)
			tekst--;
		return tekst;
	}
}

int main()
{
	return 0;
}