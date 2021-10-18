#include <stdio.h>

struct Datum { int dan, mjesec, godina };
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	struct Datum cuttoff;
	int year,day,month,leap,neg;
	day = direktor.datum_rodjenja.dan;
	month = direktor.datum_rodjenja.mjesec;
	year = direktor.datum_rodjenja.godina;
	if (broj_dana < 0){
		neg = 1;
		broj_dana = -1 * broj_dana;
	} else {
		neg = 0;
	}
    if(year%4 == 0)
    {
        if( year%100 == 0)
        {
           
            if ( year%400 == 0)
                leap = 1;
            else
               leap = 0;
        }
        else
           leap = 1;
    }
    else{
        leap = 0;
    }
    if(leap == 1){
    	if ((broj_dana + day > 31) && neg == 1){
    		if(month == 12){
    			cuttoff.godina = year  + 1;
    			cuttoff.mjesec = 1;
    			cuttoff.dan = broj_dana - (31 - day);
    		} else if (month == 2){
    			cuttoff.godina = year;
    			cuttoff.mjesec = 3;
    			cuttoff.dan = broj_dana - (29 - day);
    		} else if (month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    			cuttoff.godina = year;
    			cuttoff.mjesec = month + 1;
    			cuttoff.dan = broj_dana - (31 - day);
    		} else if (month == 4 || month == 6 || month == 9 || month == 11){
    			cuttoff.godina = year;
    			cuttoff.mjesec = month - 1;
    			cuttoff.dan = broj_dana - (30 - day);
    		}
    	} else if (broj_dana > day && neg == 0){
    		if(month == 1){
    			cuttoff.godina = year - 1;
    			cuttoff.mjesec = 12;
    			cuttoff.dan = 31 - (broj_dana - day);
    		} else if (month == 2){
    			cuttoff.godina = year;
    			cuttoff.mjesec = 1;
    			cuttoff.dan = 29 - (broj_dana - day);
    		} else if (month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    			cuttoff.godina = year;
    			cuttoff.mjesec = month - 1;
    			cuttoff.dan = 31 - (broj_dana - day);
    		} else if (month == 4 || month == 6 || month == 9 || month == 11){
    			cuttoff.godina = year;
    			cuttoff.mjesec = month - 1;
    			cuttoff.dan = 30 - (broj_dana - day);
    		}
    	}
    }
      
}
int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
(broj_dana > day && neg == 0){
    		if(month == 1){
    			cuttoff.godina = year - 1;
    			cuttoff.mjesec = 12;
    			cuttoff.dan = 31 - (broj_dana - day);
    		} else if (month == 2){
    			cuttoff.godina = year;
    			cuttoff.mjesec = 1;
    			cuttoff.dan = 29 - (broj_dana - day);
    		} else if (month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    			cuttoff.godina = year;
    			cuttoff.mjesec = month - 1;
    			cuttoff.dan = 31 - (broj_dana - day);
    		} else if (month == 4 || month == 6 || month == 9 || month == 11){
    			cuttoff.godina = year;
    			cuttoff.mjesec = month - 1;
    			cuttoff.dan = 30 - (broj_dana - day);
    		}
    	}