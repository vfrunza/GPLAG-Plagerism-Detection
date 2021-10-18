#include <stdio.h>

int broj_cif(int broj)
{

	int temp=broj;
	int br_cif=0;

	do {
		temp/=10;
		br_cif++;
	}	while (temp!=0);

	if(broj<0) return br_cif+1;

	return br_cif;
}

int broj_rijeci(char*s)
{
	int i=0;
	int br_rijeci=0;
	char* p =s;
	char* poc=s;


	while(*p!='\0') {

		if(*p!=' ')
			i++;

		else if(i>0) {
			br_rijeci++;
			i=0;

		}
		p++;
	}

	if(*poc=='\0') br_rijeci=0;

	else if(*(p-1)!=' ' && *poc!='\0') br_rijeci++;

	return br_rijeci;

}



char* ubaci_broj(char* tekst, int broj)
{

	char* pocetni=tekst;
	char* p=tekst;
	char* q=tekst;
	char* r=tekst;
	char* s=tekst;
	int br_R=0;
	int br_znak=broj_cif(broj);
	int temp=broj;
	int temp2;
	int cifra;
	int br_rijeci=broj_rijeci(tekst);
	int i=0;

	for(i=0; i<br_rijeci-1; i++) {

		while(*p!='\0') {


			if(*p!=' ') {
				q=p;
				while(*q!='\0') {

					if(*q==' ') {
						r=q;
						break;
					}
					q++;
				}

				while(*q!='\0') q++;

				break;
			}


			p++;
		}


		s=r;

		while(*s!='\0') {
			if(*s==' ') br_R++;
			else break;
			s++;
		}



		if(br_R==1) {
			while(q>r) {
				*(q+br_znak+1)=*q;
				q--;
			}
		}


		else {
			while(q>r) {
				*(q+br_znak)=*q;
				q--;
			}
		}

		q++;


		if(broj<0) {
			*q='-';
			temp=-temp;

		}

		temp2=temp;


		do {
			q++;
			temp/=10;
		} while(temp!=0);

		if (broj>=0) q--;

		if(br_R==1) {
			*(q+1)=' ';
		}



		temp=temp2;



		do {
			cifra=temp%10;

			*q=cifra+'0';
			q--;
			temp/=10;
		} while(temp!=0);

		if(br_R==1) s+=(br_znak+1);
		else s+=br_znak;

		p=s;
		br_R=0;
		q=p;
		r=p;
		temp=broj;

	}

	return pocetni;


}

int main()
{

	char tekst[100]="";
	int a=0;
	int b= broj_rijeci(tekst);
	ubaci_broj(tekst,a);
	printf("%s", tekst);
	printf("\n%d", b);

	return 0;
}
