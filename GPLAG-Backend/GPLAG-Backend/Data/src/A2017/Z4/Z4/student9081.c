#include <stdio.h>
int provjeri (char* s)
{
	char matrica[100][100];
	char niz[200];
	int i=0,j=0,k;
	int vel=0;
	int isti=1;
	int pozicija;
	int cs;
	int tag=0;
	/*Provjera da li HTML kod sadrzi tagove jer jeHTML bez tagova je ispravan*/
	while (*s!='\0') {
		if (*s=='<' || *s=='>') {
			tag=1;
			break;
		}
		s++;
	}
	if (tag==0)
		return 1;
	while (*s!='\0') {
		/*Kad naidjemo na prvi otvoren tag,provjeravamo je li poslije njega nesto sto nije slovo ili broj*/
		/*Ako je to slucaj,tag je neispravan i f-ja vraca 0*/
		if (*s=='<') {
			s++;
			if (*s==' ' || *s=='>')
				return 0;
			/*Kad nadjemo prvi ispravan tag,stavljamo njegov naziv u jedan red matrice*/
			if (((*s>='A' && *s<='Z') || (*s>='a' && *s<='z') || (*s>='0' && *s<='9')) && *s!=' ') {
				while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z') || (*s>='0' && *s<='9')) {
					matrica[i][j]=*s;
					j++;
					s++;
				}
				matrica[i][j]='\0';
				/*Koristimo i pomocni niz,kad nadjemo ispravan tag koji zauzima i-ti red matrice,i-ti clan pomocnog niza stavljamo na 1*/
				niz[i]=1;
				j=0;
				i++;
				vel=i;
			}
			if (*s=='/') {
				/*Kad naidjemo na zavoren tag,slijedi ista provjera je li poslije njega nesto sto nije slovo ili cifra*/
				s++;
				if (*s==' ')
					return 0;
				if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z') || (*s>='0' && *s<='9')) {
					/*Ako je tag ispravan,nalazimo posljednju poziciju u pomocnom nizu na kojoj se nalazi vrijednost 1*/
					/*Ta pozcija nam govori koji red matrice treba da poredimo sa tagom*/
					/*Uvijek poredimo posljednji ubaceni red u matricu,ako je odgovarajuca vrijednost u pomocnom nizu 1*/
					int flag=0;
					/*Ako je velicina manja od jedan,znaci da nijedan tag nije ispravno otvoren,a dosli smo do zatvorenog taga,pa f-ja vraca 0*/
					if (vel<1)
						return 0;
					else if (vel>=1) {
						for (k=vel-1; k>=0; k--) {
							if (niz[k]==1) {
								pozicija=k;
								flag=1;
								break;
							}
						}
						if (flag==0)
							return 0;
						j=0;
						/*Poredimo red matrice sa tagom*/
						/*Ako su isti na odgovarajuce mjesto u nizu upisemo 0 umjesto 1*/
						while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z' ) || (*s>='0' && *s<='9')) {
							if (*s>='A' && *s<='Z')
								cs=32;
							else if (*s>='a' && *s<='z')
								cs=-32;
							if (matrica[pozicija][j]!=*s+cs && matrica[pozicija][j]!=*s) {
								isti=0;
								break;
							}
							j++;
							s++;
						}
						if (isti)
							niz[pozicija]=0;
					}
				}
				s--;
			}
		}
		j=0;
		isti=1;
		s++;
	}
	/*Prolazimo kroz pomocni niz,ako nadjemo vrijednost 1,znaci da neki tag nije ispravno zavoren*/
	/*U suprotnom,f-ja vraca 1*/
	for (i=0; i<vel; i++) {
		if (niz[i]==1)
			return 0;
	}
	return 1;
}

int main()
{
	return 0;
}
