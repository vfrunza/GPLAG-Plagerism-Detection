#include <stdio.h>
void sortiraj(int *niz,int *sort,int *index)
{
	int i,j;
	int temp;

		for(i=0;i<127;i++)
		{
			for(j=i;j<127;j
			{
				if(niz[i]<niz[j])
				{
					temp=niz[i];
					niz[i]=niz[j];
					niz[j]=temp;

					temp=index[i];
					index[i]=index[j];
					index[j]=temp;
				}
				else if(niz[i]==niz[j] && index[i]>index[j])
				{
					temp=index[i];
					index[i]=index[j];
					index[j]=temp;
				}
			}
		}


}
void Pretvori(char *s,char *sifrarnik)
{
	char *p=s,*kljuc=sifrarnik;
	int br;
		while(*p!='\0')
		{	br=0;
			kljuc=sifrarnik;

			while(*kljuc!='\0')
			{
				if(*p==*kljuc++){*p=126-br;break;}
				br++;
			}
			p++;
		}

}
char *kodiraj(char *s,char *sifrarnik)
{

	char *p=s,*pok=sifrarnik;
	int i;
	int niz[127];
	int sort[127];
	int index[127];

		for(i=0;i<127;i++)
		{
			if(i<32){ niz[i]=-1; index[i]=-1;}
			else{niz[i]=0;index[i]=i;}
		}
		while(*p!='\0')
		{
			niz[*p+0]++;
			p++;
        }

		for(i=0;i<127;i++)
			sort[i]=niz[i];

		sortiraj(niz,sort,index);

		for(i=0;i<127;i++)
		{
			if(index[i]!=-1)
			{
				*pok=index[i];
				pok++;
			}
		}
		Pretvori(s,sifrarnik);

	return s;
}
char* dekodiraj(char *s,char *sifrarnik)
{

	char *p=s;

		while(*p!='\0')
		{
			*p=sifrarnik[126-*p];
			p++;
		}
	return s;

}
int main() {

	char tekst[] = "U ovom testu cemo testirati samo kodiranje";
    char sifrarnik[100] = "";
    kodiraj(tekst, sifrarnik);
    printf("%s\n", tekst);
    dekodiraj(tekst, sifrarnik);
    printf ("%s\n", tekst);
    printf("%s\n", sifrarnik);

	return 0;
}
