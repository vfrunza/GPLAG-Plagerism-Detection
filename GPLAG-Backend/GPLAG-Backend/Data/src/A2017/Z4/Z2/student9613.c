#include <stdio.h>


int provjeri_duzine(char* s, int* niz, int vel)
{
	char* p=s;
	char* q=s;
	int razmak=1, broj_rijeci=0, br=0, i;


	/* Brojanje rijeci u stringu */

	while(*p!='\0') {
		if(*p<'A' || (*p>'Z' && *p<'a') || *p>'z')
			razmak=1;
		else if(razmak==1) {
			razmak=0;
			broj_rijeci++;
		}
		p++;
	}


	if(vel!=broj_rijeci)
		return 0;

	/* Za stringove koji ne pocinju slovom */

	if(*q<'A' || (*q>'Z' && *q<'a') || *q>'z') {
		i=-1;

		while(*q<'A' || (*q>'Z' && 	*q<'a') || *q>'z')
			q++;

		while(*q!='\0') {
			while(*q<'A' || (*q>'Z' && *q<'a') || *q>'z')
				q++;

			if((*(q-1)<'A' || (*(q-1)>'Z' && *(q-1)<'a') || *(q-1)>'z') && ((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')))
				i++;

			br=0;

			while((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) {
				br++;
				q++;
			}

			if(*q<'A' || (*q>'Z' && *q<'a') || *q>'z')
				q--;

			q++;

			if(i>=vel)
				return 1;

			if(br!=niz[i])
				return 0;
		}
		return 1;
	}

	/* Za stringove koji pocinju slovom */



	else {

		i=0;

		while(*q!='\0') {
			while(((*q<'A') || ((*q>'Z') && (*q<'a')) || (*q>'z')) && (*q!='\0'))
				q++;

			if(q!=s) {
				if(((*(q-1)<'A') || ((*(q-1)>'Z') && (*(q-1)<'a')) || (*(q-1)>'z')))
					i++;
			}

			br=0;

			while(((*q>='A') && (*q<='Z')) || ((*q>='a') && (*q<='z'))) {
				br++;
				q++;
			}

			if((*q<'A') || (*q>'Z' && *q<'a') || (*q>'z'))
				q--;

			q++;

			if(i>=vel)
				return 1;

			if(br!=niz[i])
				return 0;
		}
		return 1;
	}
}

int main()
{

	return 0;
}
