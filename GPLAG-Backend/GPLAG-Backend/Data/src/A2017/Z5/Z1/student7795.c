#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YEAR_DAYS	365
#define NAMESIZE	50


/* structure types */
int dan[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Datum { int dan, mjesec, godina; };
struct Uposlenik {
	char ime_prezime[NAMESIZE];
	struct Datum datum_rodjenja;
};

/* count leap years */
int leaps(struct Datum date) {
	int year = date.godina;
	if(date.mjesec <= 2)
		year--;
	return (year/4 + year/400 - year/100);
}

/* return days passed since the Birth of Christ */
long int _passed(struct Datum date) {
	int i = 0;
	
	long int days = date.godina * YEAR_DAYS + date.dan + leaps(date);
	for(i = 0; i < date.mjesec-1; i++)
		days += dan[i];
	
	return days;
}

/* days between dates */
int _pDays(long int days, const struct Datum date) {
	return (days - _passed(date));
}

/* count letters */
int countLetter(const char* string) {
	int _num = 0;
	while(*string != '\0') {
		if(*string == ' ')
			_num++;
		string++;
	}
	return _num;
}

/* function to return surname */
void _surname(char* input, char* string, int type) {
	/* break first one into parts and add into other */
	int _spaces = countLetter(input);
	int _pos = -_spaces;
	char ime_prezime[NAMESIZE];
	char *token;
	
	strncpy(ime_prezime, input, NAMESIZE);
	token = strtok(ime_prezime, " -");
	
	while(token != NULL) {
		_pos++;
		
		if(type == _pos-1) {
			strncpy(string, token, NAMESIZE);
			return;
		}
		token = strtok(NULL, " -");
	}
	*string = '\0';
	string = 0;
}

/* check if same surnames */
int checkSur(char* sur1, char* sur2, char* _temp) {
	if((strcmp(_temp, sur1) == 0) && strlen(_temp) > 0)
		return 1;
	if((strcmp(_temp, sur2) == 0) && strlen(_temp) > 0)
		return 1;
	return 0;
}


/* function to shrink array */
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	/* initial */
	long int _dirDays = _passed(direktor.datum_rodjenja);
	char _dir1[NAMESIZE], _usr1[NAMESIZE];
	char _dir2[NAMESIZE], _usr2[NAMESIZE];
	int i = 0, j = 0, _rod = 0;
	
	/* give me all surnames of the director */
	_surname(direktor.ime_prezime, _dir1, 0);
	_surname(direktor.ime_prezime, _dir2, 1);
	
	/* go through array */
	while(i < vel) {
		if(_pDays(_dirDays, kandidati[i].datum_rodjenja) > broj_dana) {
			/* give me surnames of candidates */
			_surname(kandidati[i].ime_prezime, _usr1, 0);
			_surname(kandidati[i].ime_prezime, _usr2, 1);
			
			/* check if familiy */ 
			_rod = checkSur(_dir1, _dir2, _usr1) || checkSur(_dir1, _dir2, _usr2); 
			
			if(!_rod) {
				for(j = i; j < vel-1; j++)
					kandidati[j] = kandidati[j+1];
				vel--;
				i--;
			}
		}
		i++;
	}
	return vel;
}

int main() {
	return 0;
}