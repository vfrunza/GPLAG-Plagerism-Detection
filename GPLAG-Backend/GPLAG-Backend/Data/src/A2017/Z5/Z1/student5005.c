#include <stdio.h>
#include <stdlib.h>

void unesi(char niz[], int velicina)
{
	char znak=getchar();
	int i;
	if (znak=='\n')
		znak=getchar();
	i=0;
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}

struct Datum
{
	int dan, mjesec, godina;
};

struct Uposlenik
{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int Slovo(char c)
{
	if ((c>='a' && c<='z') || (c>='A'&& c<='Z'))
		return 1;
	return 0;	
}

int ime_direktora(char *s)
{
	int razmak=1, broj_rijeci=0;
	while(*s!='\0')
	{
		if (*s==' ')
			razmak=1;
		else if(razmak==1)
		{
			broj_rijeci++;
			razmak=0;
		}
		s++;
	}
	return broj_rijeci;
}

int prezime_direktora(char *s)
{
	int broj=1;
	while(*s!='\0')
	{
		/*racunanje broja prezimena direktora*/
		if (*s=='-' && *(s-1)!=' ' && *(s+1)!=' ')
			broj=2;
		s++;	
	}
	return broj;
}

int ime_kandidata(char *s)
{
	int razmak=1, broj_rijeci=0;
	while(*s!='\0')
	{
		if (*s==' ')
			razmak=1;
		else if(razmak==1)
		{
			broj_rijeci++;
			razmak=0;
		}
		s++;
	}
	return broj_rijeci;
}

int prezime_kandidata(char *s)
{
	int broj=1;
	while(*s!='\0')
	{
		/*racunanje broja prezimena kandidata*/
		if (*s=='-' && *(s-1)!=' ' && *(s+1)!=' ')
			broj=2;
		s++;	
	}
	return broj;
}

int provjeri_prezime(char *s1, char *s2, int broj1, int broj2, int br_prez1, int br_prez2)
{
	int razmak=1, broj_rijeci=0, nadjeno=0, isti=1;
	char *p, *q, *poc1, *poc2;
	/*postavljanje pokazivaca na prvo slovo prezimena direktora*/
	while(*s1!='\0')
	{
		if (*s1==' ')
			razmak=1;
		else if(razmak==1)
		{
			razmak=0;
			broj_rijeci++;
			if (broj_rijeci==broj1)
			{
				p=s1;
				nadjeno=1;
			}
		}
		if (nadjeno==1)
			break;
		s1++;
	}
	/*postavljanje pokazivaca na prvo slovo prezimena uposlenika*/
	nadjeno=0;
	razmak=1;
	broj_rijeci=0;
	while(*s2!='\0')
	{
		if (*s2==' ')
			razmak=1;
		else if(razmak==1)
		{
			razmak=0;
			broj_rijeci++;
			if (broj_rijeci==broj2)
			{
				q=s2;
				nadjeno=1;
			}
		}
		if (nadjeno==1)
			break;
		s2++;
	}
	/*poredjenje dva prezimena*/
		poc1=p;
		poc2=q;
		while(*p!='\0')
		{
			if (*p==*q)
			{
				p++;
				q++;
				if ((*p=='-' || *p=='\0') && (*q=='-' || *q=='\0'))
					return 1;
				continue;
			}
			else if (*p!=*q && br_prez1==1 && br_prez2==1)
				return 0;
			else if (*p!=*q && br_prez1==2 && br_prez2==1)
			{
				while(Slovo(*p))
					p++;
				q=poc2;
				p++;
				while(*p!='\0' && *q!='\0')
				{
					if (*p!=*q)
					{
						isti=0;
						return 0;
					}
					p++;
					q++;
				}
				if (isti==1 && *q=='\0' && *p=='\0')
					return 1;
			}
			else if (*p!=*q && br_prez1==1 && br_prez2==2)
			{
				while(Slovo(*q))
					q++;
				q++;
				p=poc1;
				while(*p!='\0' && *q!='\0')
				{
					if (*p!=*q)
					{
						isti=0;
						return 0;
					}
					p++;
					q++;
				}
				if (isti==1 && *q=='\0' && *p=='\0')
					return 1;
			}
		}
	return 0;
}

int razlika_u_godinama(struct Uposlenik direktor, struct Uposlenik radnik)
{
	int razlika, i, prestupna_direktor=0, prestupna_korisnik=0, ud_dire=0, ud_rad=0;
	int niz_mjeseci[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int niz_mjeseci_prestupne[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if ((direktor.datum_rodjenja.godina %4 == 0 && direktor.datum_rodjenja.godina %100 !=0) || (direktor.datum_rodjenja.godina %400==0))
		prestupna_direktor=1;
		
	if ((radnik.datum_rodjenja.godina %4 == 0 && radnik.datum_rodjenja.godina %100 !=0) || (radnik.datum_rodjenja.godina %400 == 0))
			prestupna_korisnik=1;
	
	/*racunanje ukupno dana direktora*/
	for(i=direktor.datum_rodjenja.godina-1; i>=0; i--)
	{
		if ((i %4 == 0 && i %100 !=0) || ( i %400==0))
			ud_dire+=366;
		else
			ud_dire+=365;
	}
	for(i=direktor.datum_rodjenja.mjesec-2; i>=0; i--)
	{
		if (prestupna_direktor==1)
			ud_dire+=niz_mjeseci_prestupne[i];
		else
			ud_dire+=niz_mjeseci[i];
	}
	ud_dire+=direktor.datum_rodjenja.dan;
	
	/*racunanje ukupno dana korisnika*/
	for(i=radnik.datum_rodjenja.godina-1; i>=0; i--)
	{
		if ((i%4 == 0 && i%100!=0) || (i%400==0))
			ud_rad+=366;
		else
			ud_rad+=365;
	}
	for(i=radnik.datum_rodjenja.mjesec-2; i>=0; i--)
	{
		if (prestupna_korisnik==1)
			ud_rad+=niz_mjeseci_prestupne[i];
		else 
			ud_rad+=niz_mjeseci[i];
	}
	ud_rad+=radnik.datum_rodjenja.dan;
	
	razlika=ud_dire-ud_rad;
	return razlika;
	
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i, j, br1, br2, br_prez1, br_prez2, vraceno, razlika;

	br1=ime_direktora(direktor.ime_prezime);
	br_prez1=prezime_direktora(direktor.ime_prezime);

	for(i=0; i<vel; i++)
	{
		br2=ime_kandidata(kandidati[i].ime_prezime);
		br_prez2=prezime_kandidata(kandidati[i].ime_prezime);
		
		vraceno=provjeri_prezime(direktor.ime_prezime, kandidati[i].ime_prezime, br1, br2, br_prez1, br_prez2);
		
		if(vraceno==1)
			continue;
		
		razlika=razlika_u_godinama(direktor, kandidati[i]);
		/*izbacivanje iz niza*/
		if (razlika>broj_dana)
		{
			for(j=i; j<vel-1; j++)
				kandidati[j]=kandidati[j+1];
			vel--;
			i--;
		}
	}	
	
	return vel;
}


int main() {
	struct Uposlenik kandidati[100];
	struct Uposlenik direktor;
	int vraceno, i, broj, broj_dana, vel;
	
	printf("Unesite ime i prezime direktora: ");
	unesi(direktor.ime_prezime, 50);
	printf("Unesite datum rodjenja kandidata: ");
	scanf("%d %d %d", &direktor.datum_rodjenja.dan, &direktor.datum_rodjenja.mjesec, &direktor.datum_rodjenja.godina);
	printf("Unesite broj dana za razliku: ");
	scanf("%d",&broj_dana);

	for(i=0; i<100; i++)
	{
		printf("Unesite broj (-1 za kraj): ");
		scanf("%d", &broj);
		if (broj==-1)
			break;
		printf("Unesite ime i prezime kandidata: ");
		unesi(kandidati[i].ime_prezime, 50);
		printf("Unesite datum rodjenja kandidata: ");
		scanf("%d %d %d", &kandidati[i].datum_rodjenja.dan, &kandidati[i].datum_rodjenja.mjesec, &kandidati[i].datum_rodjenja.godina);
	}
	vel=i;
	printf("Velicina niza prije funkcije: %d", vel);
	vraceno=suzi_listu(kandidati, vel, direktor, broj_dana);
	printf("\nVelicina niza nakon funkcije: %d", vraceno);
	
	for(i=0; i<vraceno; i++)
		printf("%s %d.%d.%d\n", kandidati[i].ime_prezime, kandidati[i].datum_rodjenja.dan, kandidati[i].datum_rodjenja.mjesec, kandidati[i].datum_rodjenja.godina);

	return 0;
}




/* ispit sa prvog roka redovni 
#include <stdio.h>

int funckija (int niz[], int vel, int prazan_niz[]) {
int i,j=0, cifra, vel_pn=0,k,l,m,p;

for (i=0; i<vel; i++) {
	
	if (niz[i]==0) {
		prazan_niz[j]=0;
		j++;
	}
	
	while (niz[i]!=0) {
	cifra=niz[i]%10;
	prazan_niz[j]=cifra;
	j++;
	niz[i]/=10;
	}
	
}
vel_pn=j;

for (k=0; k<vel_pn; k++) {
	for (l=k+1; l<vel_pn; l++) {
		if  (prazan_niz[k]==prazan_niz[l]) {
			for (m=k; m<vel_pn-1; m++) 
			prazan_niz[m]=prazan_niz[m+1];
		vel_pn--;
		k--;
		}
	}
}
for (p=0; p<vel_pn; p++) {
	printf("%d, ",prazan_niz[p]);
}
}

     
     

int main() {
	int i,n,niz[100], prazan_niz[100]={0};
	printf("unesi n: ");
	scanf("%d",&n);
	
	for (i=0; i<n; i++) {
		scanf("%d",&niz[i]);
	}
	
	printf("poziv funkcije: %d", funkcija(niz,n,prazan_niz) );
	return 0;
}*/

