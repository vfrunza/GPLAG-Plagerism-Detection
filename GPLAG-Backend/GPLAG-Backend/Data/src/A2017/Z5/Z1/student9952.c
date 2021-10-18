#include <stdio.h>

int mjeseci[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

struct Datum
{
	int dan, mjesec, godina;
};

struct Uposlenik
{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int slovo(char a);

int isto(char* a, char* b);

int razlika_dana(struct Datum d1, struct Datum d2);

int dovoljno_star(int kriterij, int test);

int nepotizam(struct Uposlenik direktor, struct Uposlenik kandidat);

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana);

int main()
{
	
struct Uposlenik direktor = {"Mujo Mujiic-Periic", {31,12,2017} };
struct Uposlenik kandidat ={"Pero Periic-Mujic",{1,1,2018}};
printf("%d",nepotizam(direktor,kandidat));
printf( "\n%d" , razlika_dana(direktor.datum_rodjenja,kandidat.datum_rodjenja))   ;


	return 0;
}

int razlika_dana(struct Datum d1, struct Datum d2)
{
	int i,broj=0;
	for(i=1; i<d1.godina; i++)
	{
		if((i%4==0 && i%100!=0)||i%400==0)broj+=366;
		else broj+=365;
	}
	for(i=1; i<d1.mjesec; i++)
	{
		broj+=mjeseci[i];
	}
	if(d1.mjesec>2&&((d1.godina%4==0 && d1.godina%100!=0) || d1.godina%400==0))broj++;
	broj+=d1.dan;

	int broj2=0;

	for(i=1; i<d2.godina; i++)
	{
		if((i%4==0 && i%100!=0) || i%400==0)broj2+=366;
		else broj2+=365;
	}
	for(i=1; i<d2.mjesec; i++)
	{
		broj2+=mjeseci[i];
	}
	if(d2.mjesec>2 && ((d2.godina%4==0 && d2.godina%100!=0) || d2.godina%400==0))
	{
		broj2++;
	}
	broj2+=d2.dan;

	return broj-broj2;

}

int dovoljno_star(int kriterij, int test)
{
	if(kriterij<0)
	{
		if(kriterij-test < 0) return 1;
		return 0;
	}
	else
	{
		if(test>kriterij)return 1;
		return 0;
	}
	return 0;
}

int nepotizam(struct Uposlenik direktor, struct Uposlenik kandidat)
{
	char prez_dir1[50]="";
	char prez_dir2[50]="";
	char prez_kan1[50]="";
	char prez_kan2[50]="";

	char* p;
	char* q;
	char* poc;
	p=direktor.ime_prezime;
	q=kandidat.ime_prezime;
	int dirprez=1;
	int kanprez=1;
	while(*p!='\0')
	{
		if( *p==' '&&slovo(*(p+1)) )
		{
	
			poc=p+1;
		}
		p++;
	}
	p=prez_dir1;
	while(*poc!='\0'&&*poc!='-'&&slovo(*poc))
	{
		*p=*poc;
		p++;
		poc++;
	}
	*p='\0';
	if(*poc=='-')
	{
		dirprez++;
		poc++;
		p=prez_dir2;
		while(*poc!='\0'&&slovo(*poc))
		{
			*p=*poc;
			p++;
			poc++;
		}
		*p='\0';
	}
	
	
	while(*q!='\0')
	{
		if(*q==' '&&slovo(*(q+1)))
		{
			
			poc=q+1;
		}
		q++;
	}
	q=prez_kan1;
	while(*poc!='\0'&&*poc!='-'&& slovo(*poc))
	{
		*q=*poc;
		q++;
		poc++;
	}
	*q='\0';
	if(*poc=='-')
	{
		kanprez++;
		poc++;
		q=prez_kan2;
		while(*poc!='\0'&&slovo(*poc))
		{
			*q=*poc;
			q++;
			poc++;
		}
		*q='\0';
	}

if(dirprez==1)
{
	if(kanprez==1)
	{
		if(isto(prez_dir1,prez_kan1)==0)return 1;
	}
	else if(kanprez==2)
	{
		if(isto(prez_dir1,prez_kan1)==0||isto(prez_dir1,prez_kan2)==0)return 1;
	}
}
else if(dirprez==2)
{
	if(kanprez==1)
	{
		if(isto(prez_dir1,prez_kan1)==0||isto(prez_dir2,prez_kan1)==0)return 1;
	}
	else if(kanprez==2)
	{
		if(isto(prez_dir1,prez_kan1)==0||isto(prez_dir1,prez_kan2)==0)return 1;
		if(isto(prez_dir1,prez_kan1)==0||isto(prez_dir2,prez_kan1)==0)return 1;
	}
}

	return 0;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i,j;
	for(i=0; i<vel; i++)
	{
		if(dovoljno_star(broj_dana,razlika_dana(direktor.datum_rodjenja,kandidati[i].datum_rodjenja))&&!nepotizam(direktor,kandidati[i]))
		{
			for(j=i; j<vel-1; j++)
			{
				kandidati[j]=kandidati[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int slovo(char a)
{
	if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))return 1;
	return 0;
}

int isto(char* a, char* b)
{
	while(*a!='\0'||*b!='\0')
	{
		if(*a!=*b)return 1;
		a++;b++;
	}
	return 0;
}