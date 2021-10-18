#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}


char* ubaci_broj(char* s, int br)
{

	int i, vel, vel2=0, a, b, cl=0, temp=br, k=0;
	char iuc[12];
	char *p=iuc, *r=s, *c, *plz=s;

	while(*s!='\0') {
		vel2++;
		s++;
	}
	vel2++;
	s=r;

	if(br<0) {
		br=-1*br;
		*p++='-';
		cl++;
	}

	do {
		cl++;
		p++;
		temp/=10;
	} while(temp!=0);
	*p--='\0';

	temp=br;
	do {
		*p--=temp%10+'0';
		temp/=10;
	} while(temp!=0);

	vel=cl;
	a=vel2;
	b=vel2;

	while(*s!='\0') {
		if(*s==' ' && s==r)
			while(*s==' ') {
				s++;
				k++;
			}

		while(*s!=' ') {
			if(*s=='\0') return plz;
			s++;
			k++;
		}
		c=s;
		do {
			c++;
			if(*c=='\0') return plz;
		} while(*c==' ');

		if(*(s+1)!=' ') {
			s++;
			k++;
			for(i=0; i<b-k+1; i++) {
				*(r+vel2+vel+1)=*(r+vel2);
				vel2--;
			}
			for(i=0; i<vel; i++) {
				*s=iuc[i];
				s++;
			}

			*s=' ';
			a=a-k;
			b=b-k;
			vel2=a;
		} else if(*(s+1)==' ') {
			s++;
			k++;
			for(i=0; i<b-k+1; i++) {
				*(r+vel2+vel)=*(r+vel2);
				vel2--;
			}
			for(i=0; i<vel; i++) {
				*s=iuc[i];
				s++;
			}
			b=b-k;
			a=a-k;
		}

		while(*s==' ') {
			s++;
			k++;
		}
		r=r+vel+k;

		s--;
		vel2=a;
		s++;
		k=0;

		c=s;
		do {
			c++;
			if(*c=='\0') return plz;
		} while(*c==' ');
	}

	return plz;
}

int main()
{
	char tekst[100];
	int br;
	printf("Unesite tekst: ");
	unesi(tekst, 100);
	printf("Unesite broj: ");
	scanf("%d", &br);

	printf("\"%s\"", ubaci_broj(tekst, br));
	return 0;
}





