#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
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

int aps(int n)
{
	/* vraca apsolutnu vrijednost parametra*/
	if(n<0)
		n-=2*n;
	return n;
}

int cifra(int n)
{
	/*vraca broj cifara parametra*/
	int i,br=n;
	for(i=0; br!=0; i++)
		br/=10;
	if(n<0)
		i++;
	return i;
}

char* ubaci_broj(char *tekst,int broj)
{
	int i=0,j,razmak,duz,n;
	int m=cifra(broj);
	/*pomjera poziciju do prvog znaka razlicitog od razmaka za string koji pocinje sa razmakom*/
	if(*tekst==' ') {
		while(*(tekst+i)==' ')
			i++;
	}
	do {
		if(*(tekst+i)==' ') {
			/*provjerava da li se nalazi nakon pozicije znak razlicit od razmaka*/
			for(j=i; *(tekst+j)!='\0'; j++)
				if(*(tekst+j)!=' ')
					break;
					/*ako ne, prekida dalju manipulaciju stringa*/
			if(*(tekst+j)=='\0')
				break;
			i++;
			duz=duzina(tekst);
			razmak=0;
			/*ako je samo jedan razmak izmedju znakova, dodaje se jedan razmak*/ 
			if(*(tekst+i)!=' ')
				razmak=1;
				/*pomjeranje znakova za broj cifara udesno*/
			for(j=duz+m+razmak; j>i+m-1-razmak; j--)
				*(tekst+j)=*(tekst+j-m-razmak);
			if(razmak==1)
				*(tekst+i)=' ';
			n=aps(broj);
			for(j=i+m-1; j>=i; j--) {
				/*ako je broj negativan dodaje mu se znak minus*/
				if(n==0) {
					*(tekst+j)='-';
					break;
				}
				*(tekst+j)=(n%10)+'0';
				n/=10;
			}
			i+=m;
			while(*(tekst+i)==' ')
				i++;
		}
	} while(*(tekst+(++i))!='\0');
	return tekst;
}

int main()
{
	char s[1000];
	int n;
	unesi(s,1000);
	scanf("%d",&n);
	printf("%s",ubaci_broj(s,n));
	return 0;
}
