#include <stdio.h>

int provjeri (char* s1)
{


	char* p=s1;
	char* q=s1;
	char* r=s1;
	char* s=s1;
	char* t=s1;
	int tacno=1;
	int brojac1=0;
	int brojac2=0;
	int brojac3=0;


	while(*p!='\0') {

		if(*p=='<') brojac1++;
		if(*p=='>') brojac2++;
		p++;
	}



	if(brojac1!=brojac2 || brojac1%2!=0 || brojac2%2!=0) return 0; /*mora biti isti broj otvorenih i zatvorenih tagova*/


	if(brojac1==0 && brojac2==0) return 1;	/*nema tagova*/

	p=s1;

	while(*p!='\0') {

		q=p;

		if(*p=='<') q=p;

		if(*(q+1)=='/' && *q=='<')
			brojac3++;

		p++;
	}


	if(brojac3!=brojac1/2) return 0; /* svaki tag mora imati tacno jedan / (backslash) */

	q=s1;
	p=s1;

	while(*p!='\0') {

		while(!(*p=='<' && *(p+1)!='/') && *p!='\0') p++; /* p na pocetku taga */

		if(*p!='\0') {

			while(*s!='>') s++;

			if(*(s+1)!='\0') s++; /* s na  pocetku sljedeceg taga */

			if( (*(p+1)>='0'&& *(p+1)<='9') || (*(p+1)>='A'&& *(p+1)<='Z') || (*(p+1)>='a'&& *(p+1)<='z') ) {
				q=p+1;
				r=q;	       /* r na pocetku naziva taga */
				t=r;		   /* sacuvali smo pocetak...*/
			} else return 0;   /* tag mora pocinjati slovom ili cifrom */


			while ( (*q>='0'&& *q<='9') || (*q>='A'&& *q<='Z') || (*q>='a'&& *q<='z') ) q++; /* q na kraju naziva taga */


			while(*p!='\0' && (*(p+1)!='/' || *p!='<')) p++; /* p na pocetku kraja zatvorenog taga koji mora imati / (backslash) */


			if( *(p+2)!='\0' && ((*(p+2)>='0'&& *(p+2)<='9') || (*(p+2)>='A'&& *(p+2)<='Z') || (*(p+2)>='a'&& *(p+2)<='z'))  ) {
				p+=2;
			} else return 0; /* iza znaka "/" mora biti slovo ili cifra */


			while ( ((*p>='0'&& *p<='9') || (*p>='A'&& *p<='Z') || (*p>='a'&& *p<='z')) && r<q ) {

				if( *p-*r!=0 && *p-*r!=32 && *p-*r!=-32 ) { /* provjeravamo da li je to kraj taga na koji pokazuje r, ako nije...*/
					tacno=0;  /* ... pamtimo to...*/
					r=t;      /* ... i r vracamo na pocetak */
				} else tacno=1;


				if(tacno==0 && *p!='\0') {
					while(*p!='\0' &&  (*p!='<' || *(p+1)!='/')) p++; /* ako je netacno trazimo kraj sljedeceg taga */
					/*printf("%c\n", *p);*/
					if( *p!='\0' && (*(p+2)!='\0' && ((*(p+2)>='0'&& *(p+2)<='9') || (*(p+2)>='A'&& *(p+2)<='Z') || (*(p+2)>='a'&& *(p+2)<='z')) )  ) {
						p+=2;
					} else return 0;
				}

				if(tacno==1) {
					p++;
					r++;	/* Poredimo svaki znak*/
				}
			}


			if(tacno==1) {
				while(*p!='\0') {
					if(*p !='>') tacno=0;
					else {
						tacno=1;  /* kraj taga mora zavrsavati znakom ">" */
						break;
					}
					p++;
				}
			}

			if(tacno==0) return 0; /* ako ne, nije uredno zatvoren*/

			p=s; /* ponavljamo postupak za naredni tag ako je prethodni uredno zatvoren... */
		}

	}


	if(tacno) return 1;
	else return 0;

}

int main()
{

	printf ("Provjera 2: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a><span></span></span>"));

	return 0;
}
