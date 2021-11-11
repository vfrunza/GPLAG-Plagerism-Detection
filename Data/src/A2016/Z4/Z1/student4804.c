#include <stdio.h>

/*Funkcija za unos stringa*/
void unesi(char s[], int n)
{
	char znak;
	int i=0;
	znak=getchar();
	if(znak=='\n')
		znak=getchar();
	while(i<n-1 && znak!='\n') {
		s[i]=znak;
		i++;
		znak=getchar();
	}
	s[i]='\0';
}

char *rijec(char *d)
{
	char *p;
	p=d;

	while((*d>='A' && *d<='Z') || (*d>='a' && *d<='z')) {
		d++;
	}
	*d='\0';


	return p;
}

int duzina(char *s)
{
	int br=0;
	while(*s!='\0') {
		br++;
		s++;
	}
	return br;
}

int broj_ponavljanja(char *s,char *q)
{
	int razmak=1,br=0,jednaki,i;
	char *p,*r,*k,rj[500],*l;
	k=&rj[0];
	while(*s!='\0') {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
			razmak=1;
		else if (razmak==1) {
			razmak=0;
			p=s;
			l=k;	/* Pokazivac na pocetak niza*/
			for(i=0; i<500; i++)
				rj[i]='\0';
			while(*p!='\0') {
				*k=*p;
				if(*k>='A' && *k<='Z')
					*k=*k+('a'-'A');
				k++;
				p++;
			}
			r=q;
			k=l;
			k=rijec(k);
			jednaki=1;
			while(*k!='\0') {
				if(*r!=*k && *r!=*k-'a'-'A') {
					jednaki=0;
					break;
				}
				if(*r=='\0') {
					jednaki=0;
					break;
				}
				r++;
				k++;
			}
			if(jednaki==1)
				br++;
			k=l;
		}
		s++;
	}
	return br;
}

char *izbaci_najcescu(char *s)
{
	int razmak=1,maximum=0,br,i,izbaci=1,duz;
	char *p,*q,rj[500],*l,*k,max[500],*m,*g,*r,*h,*v,*z;
	q=s;
	m=&max[0];
	r=s;
	k=&rj[0];
	while(*s!='\0') {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
			razmak=1;
		else if (razmak==1) {
			razmak=0;
			p=s;
			l=k;
			for(i=0; i<500; i++)
				rj[i]='\0';

			while(*p!='\0') {
				*k=*p;
				if(*k>='A' && *k<='Z')
					*k=*k+('a'-'A');
				k++;
				p++;
			}
			k=l;
			k=rijec(k);
			br=broj_ponavljanja(q,k);	/*Trazenje rijeci koja se najvise ponavlja*/
			if(br>maximum) {
				maximum=br;
				g=m;
				for(i=0; i<500; i++)
					max[i]='\0';
				while(*k!='\0') {
					*m=*k;
					m++;
					k++;
				}
				k=l;
				m=g;
			}
		}
		s++;
	}
	razmak=1;
	while(*r!='\0') {
		if(!((*r>='A' && *r<='Z') || (*r>='a' && *r<='z')))
			razmak=1;
		else if (razmak==1) {
			razmak=0;
			izbaci=1;
			h=r;
			z=h;
			v=m;
			duz=duzina(m);
			m=v;
			/*Izbacivanje rijeci*/
			while((*r>='A' && *r<='Z') || (*r>='a' && *r<='z')) {

				if(*r!=*m && *r!=(*m-('a'-'A'))) {
					izbaci=0;
					break;
				}


				m++;
				r++;

				if(*m=='\0' && maximum!=1 && duz>1 &&(!((*r>='A' && *r<='Z') || (*r>='a' && *r<='z')))) {
					izbaci=0;
					break;
				}

			}
			r=h;
			m=v;
			while((*r>='A' && *r<='Z') || (*r>='a' && *r<='z')) {

				r++;

			}

			if(izbaci==1) {
				while(*r!='\0') {
					*h=*r;
					r++;
					h++;
				}
				*h='\0';
			}
			r=z;
			r--;
		}
		r++;
	}
	return q;
}


int main()
{
	char rec[500];
	unesi(rec,500);

	printf("%s",izbaci_najcescu(rec));

	return 0;
}
