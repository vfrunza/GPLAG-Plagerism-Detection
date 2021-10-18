#include <stdio.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int main()
{
	struct Datum datum;
	int x, i;
	int mjeseci_god[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int mjeseci_pres[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

	printf("Unesite dan: ");
	scanf("%d", &datum.dan);
	printf("Unesite mjesec: ");
	scanf("%d", &datum.mjesec);

	printf("Unesite godinu: ");
	scanf("%d", &datum.godina);
	printf("Unesite broj dana: ");
	scanf("%d", &x);

	//Smanjujemo uneseni broj x za godine,a godine povecavamo
	while(x>=366) {
		if((datum.godina%4==0 && datum.godina%100!=0) || (datum.godina%400==0)) {
			x-=366;
			datum.godina++;
		} else {
			x-=365;
			datum.godina++;
		}
	}
	if(x==365) {
		datum.godina++;
	} else {
		//Oduzimamo od x-a onoliko dana koliko nam treba da nadopunimo na puni mjesec, ako je x manji od te dopune onda dodajemo danima x i prekidamo
		if((datum.godina%4==0 && datum.godina%100!=0) || (datum.godina%400==0)) {
			if(x>mjeseci_pres[datum.mjesec-1]-datum.dan) {
				x-=mjeseci_pres[datum.mjesec-1]-datum.dan;
				if(datum.mjesec==12) {
					datum.mjesec=1;	
					datum.godina++;
				} 
				else datum.mjesec++;
			} else {
				datum.dan+=x;
				x=0;
			}
		} else {
			if(x>mjeseci_god[datum.mjesec-1]-datum.dan) {
				x-=mjeseci_god[datum.mjesec-1]-datum.dan;
				if(datum.mjesec==12) {
					datum.mjesec=1;
					datum.godina++;
				}
				else datum.mjesec++;
			} else {
				datum.dan+=x;
				x=0;
			}
		}

		//Dani nam sada pocinju od prvog dana u mjesecu pa od x-a oduzimamo puni broj dana u mjesecu sve dok je to moguce; mjesece povecavamo dok ne dodemo do 12.
		for(i=datum.mjesec-1; i<=12; i++) {
			if((datum.godina%4==0 && datum.godina%100!=0) || (datum.godina%400==0)) {
				if(x>=mjeseci_pres[i]) {
					x-=mjeseci_pres[i];
					datum.mjesec++;
				} else break;
			} else {
				if(x>=mjeseci_god[i]) {
					x-=mjeseci_god[i];
					datum.mjesec++;
				} else break;
			}
		}

		//Moze nam se desiti da dodemo do kraja godine ali nam je x i dalje !=0 pa ponavljamo postupak jos jednom pocevsi od nove godine
		if(x>=31) {
			datum.godina++;
			datum.mjesec=1;
			for(i=0; i<=12; i++) {
				if((datum.godina%4==0 && datum.godina%100!=0) || (datum.godina%400==0)) {
					if(x>=mjeseci_pres[i]) {
						x-=mjeseci_pres[i];
						datum.mjesec++;
					} else break;
				} else {
					if(x>=mjeseci_god[i]) {
						x-=mjeseci_god[i];
						datum.mjesec++;
					} else break;
				}
			}
		}

		//Sada nam x moze biti manje od majmanjeg broja dana u mjesecu za tu godinu pa taj ostatak postaje datum.dan
		if(x==0 && datum.dan!=mjeseci_god[datum.mjesec-1]) {
			if((datum.godina%4==0 && datum.godina%100!=0) || (datum.godina%400==0)) datum.dan=mjeseci_pres[datum.mjesec-1];
			else datum.dan=mjeseci_god[datum.mjesec-1];//-2?????????????
		} else {
			datum.dan=x;
		}
	}

	printf("Novi datum: %d.%d.%d.", datum.dan, datum.mjesec, datum.godina);


	return 0;
}
