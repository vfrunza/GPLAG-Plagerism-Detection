#include <stdio.h>

/* Da li se prije i poslije elementa *a javlja rijec */
int provjera(const char *t, char *a)
{
	int ima=1;
	char *x=a;
	char *y=a;

	if(a==t)
		return 0;

	while(x>=t) {
		if(*x!=' ') {
			ima=1;
			break;
		} else ima=0;
		x--;
	}

	if(ima==1) {
		ima=0;
		while(*y!='\0') {
			if(*y!=' ') {
				ima=1;
				break;
			}
			y++;
		}
	}

	if(ima) return 1;
	else return 0;
}

const char *ubaci_broj(char* tekst, int broj)
{
	const char*q=tekst;
	char*s=tekst, *poc=NULL, *kraj=NULL;
	char broj_string[12];
	char*sb = broj_string;
	int tmp=broj, broj_cifara=0,br_razmaka=0;

	/* Konvertovanje int u string */
	if (broj < 0) {
		broj = -broj;
		*sb++ = '-';
		broj_cifara++;
	}

	do {
		sb++;
		tmp /= 10;
		broj_cifara++;
	} while (tmp != 0);

	*sb-- = '\0';

	do {
		*sb-- = broj%10 + '0';
		broj /= 10;
	} while (broj != 0);
	/* -------------------------- */

	sb=broj_string;

	while (*s != '\0') {
		if (*s == ' ' || *s=='\t') {
			if(provjera(q,s)) {
				poc=s;
				kraj=s;
				while(*poc==' ' || *poc=='\t') {
					br_razmaka++;
					poc++;
				}

				while (*kraj != '\0')
					kraj++;
				while (kraj >= s) {
					if(br_razmaka==1)
						*(kraj+broj_cifara+1) = *kraj;
					else
						*(kraj+broj_cifara) = *kraj;
					kraj--;

				}

				while (*sb != '\0') {
					++s;
					*s = *sb;
					sb++;
				}

				if(*s!=' ') {
					s++;
					while(*s==' ' || *s=='\t') s++;
					s--;
				}

				sb=broj_string;
				br_razmaka=0;
			}

			else {
				while(*s==' ' || *s=='\t') s++;
				s--;
			}
		}
		s++;
	}

	return q;
}


int main()
{
	char a[150] = "  Animal		angeli   sumpti animum cau exigui sim 	figura    	duo i			ta.";
	printf("\"%s\"\n", ubaci_broj(a, 1));
	return 0;
}
