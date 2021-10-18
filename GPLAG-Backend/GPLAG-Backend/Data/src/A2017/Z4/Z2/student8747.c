#include <stdio.h>
#include <ctype.h>
int PrebrojRijeci(char* s)
{
	char* p=s;
	char* q=s;
	int BrojRazmaka=1;
	while(*p!='\0') {
		if((*p<65 || *p>90) && (*p<97 || *p>122) && *p==' ' || *p=='-') {
			q=p;
			while((*q<65 || *q>90) && (*q<97 || *q>122) && *q==' '  || *q=='-') {
				q++;
			}
			p=q;
			BrojRazmaka++;
		}

		else p++;
	}
	
	return BrojRazmaka;
}

int provjeri_duzine(char* Recenica, int* NizBrojeva, int x)
{
	char* p=Recenica;
	int* q=NizBrojeva;
	char* r=Recenica;
	char* test=Recenica;
	int BrojacSlova=0;
	int Brojrijeci=PrebrojRijeci(test);
	if(Brojrijeci!=x && Brojrijeci>1) {
		return 0;
	} else if(Brojrijeci==1) {
		Brojrijeci=x;
	}
	char*k=Recenica;
	while(*k!='\0') {
		k++;
	}
	while(*p!='\0') {
		if((*p>=65 && *p<=90) || (*p>=97 && *p<=122) ) {
			r=p;
			while((*r>=65 && *r<=90) || (*r>=97 && *r<=122)) {
				BrojacSlova++;
				r++;
			}
			if(*q!=BrojacSlova) {
				return 0;
			} else {
				q++;
				p=r;
			}
			BrojacSlova=0;
			Brojrijeci--;

		}
		if(Brojrijeci==0  && *p!='\0' &&  ((*p>=65 && *p<=90) || (*p>=97 && *p<=122))) {
			return 0;
		}
		if(*r!='\0') {
			p++;
		}
	}
	return 1;

}
int main()
{
	char tekst[] = "Space... The final frontier... These are the voyages of the starship Enterprise. Its five-year mission: to explore strange new worlds, to seek out new life and new civilizations, to boldly go where no man has gone before!";
	int niz[] = {5, 3, 5, 8, 5, 3, 3, 7, 2, 3, 8, 10, 3, 4, 4, 7, 2, 7, 7, 3, 6, 2, 4, 3, 3, 4, 3, 3, 13, 2, 6, 2, 5, 2, 3, 3, 4, 6};
	int niz2[] = {1,2,3,4,5}; /* reda radi */

	provjeri_duzine(tekst, niz, 4);
	printf("%d ", provjeri_duzine(tekst, niz, 38));
	printf("%d ", provjeri_duzine(tekst, niz2, 5));

	return 0;
}
