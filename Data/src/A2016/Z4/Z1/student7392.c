#include <stdio.h>

/* IZBACUJE DUZINA KARAKTERA POCEVSI OD NEKOG */ 

void izbaci(char *pocetak, int duzina){
	while(*(pocetak+duzina)){
		*pocetak=*(pocetak+duzina);
		pocetak++;
	}
	*pocetak=*(pocetak+duzina);
}

/* VRACA APSOLUTNU VRIJEDNOST INT BROJA */

int apsolutna(int a){
	if(a<0)return -a; 
	return a;
}

/* VRACA POINTER NA PRVI KARAKTER ZADNJEG PONAVLJANJA RIJECI */

char* nadjiZadnju(char *s, char *testna_rijec, int duzina_testne){
	int duzina=0;
	int is_new=1;
	int i;
	char *a=testna_rijec;
	char *temp=s;
	/* ITERACIJA KROZ TEKST I PREPOZNAVANJE PONAVLJANJA RIJECI UZ ZANEMARIVANJE CAPS LOCKA */
	while(*s){
		if((*s<='z' && *s>='a')||(*s<='Z' && *s>='A')){
			if(is_new==1){
				temp=s;
				duzina=1;
				is_new=0;
			} else duzina++;
		} else {
			if(duzina==duzina_testne){
				for(i=0;i<duzina_testne;i++){
					if(apsolutna(*(temp+i)-*(testna_rijec+i))!=32 && apsolutna(*(temp+i)-*(testna_rijec+i))!=0)break;
				}
				if(i==duzina_testne){
					a=temp;
				}
			}
			is_new=1;
			duzina=0;
		}
		s++;
	}
	if(duzina==duzina_testne){
		for(i=0;i<duzina_testne;i++){
			if(apsolutna(*(temp+i)-*(testna_rijec+i))!=32 && apsolutna(*(temp+i)-*(testna_rijec+i))!=0)break;
		}
		if(i==duzina_testne){
			a=temp;
		}
	}
	return a;
}

/* VRACA BROJ PONAVLJANJA RIJECI U TEKSTU I BRISE RIJECI IZ TEKSTA IDENTICNE TESTNOJ RIJECI UKOLIKO JE VRIJEDNOST treba_brisati=1 */

int koliko_puta(char *s, char *testna_rijec, int duzina_testne, int treba_brisati){
	char *temp=s;
	int duzina=0;
	int is_new=1;
	int i;
	int iste=0;
	/* ITERIRANJE KROZ TEKST I BROJANJE PONAVLJANJA (+BRISANJE) */
	while(*s){
		if((*s<='z' && *s>='a')||(*s<='Z' && *s>='A')){
			if(is_new==1){
				temp=s;
				duzina=1;
				is_new=0;
			} else duzina++;
		} else {
			if(duzina==duzina_testne){
				for(i=0;i<duzina_testne;i++){
					if(apsolutna(*(temp+i)-*(testna_rijec+i))!=32 && apsolutna(*(temp+i)-*(testna_rijec+i))!=0)break;
				}
				if(i==duzina_testne){
					iste++;
					if(treba_brisati){
						if(testna_rijec==temp){
							izbaci(temp, duzina_testne);
							return 0;
						}
						izbaci(temp, duzina_testne);
						testna_rijec=testna_rijec-duzina_testne;
						s=temp;
					}
				}
			}
			is_new=1;
			duzina=0;
		}
		s++;
	}
	if(duzina==duzina_testne){
		for(i=0;i<duzina_testne;i++){
			if(apsolutna(*(temp+i)-*(testna_rijec+i))!=32 && apsolutna(*(temp+i)-*(testna_rijec+i))!=0)break;
		}
		if(i==duzina_testne){
			iste++;
			if(treba_brisati){
				izbaci(temp, duzina_testne);
			}
		}
	}
	return iste;
}

/* PROVJERAVA KOJU RIJEC TREBA IZBACITI I VRACA POINTER NA PRVI KARAKTER TEKSTA */

char* izbaci_najcescu(char *s){
	char *pocetak=s;
	char *max_pointer=s;
	char *temp=s;
	int max_ponavljanja=-1;
	int max_duzina=-1;
	int duzina;
	int is_new=1;
	int koliko;
	/* ITERIRANJE KROZ TEKST + PAMCENJE POINTERA NA PRVI KARAKTER RIJECI KOJA SE NAJVISE PUTA PONAVLJA I NJENE DUZINE */
	while(*s){
		if((*s<='z' && *s>='a')||(*s<='Z' && *s>='A')){
			if(is_new==1){
				temp=s;
				duzina=1;
				is_new=0;
			} else duzina++;
		} else {
			if(is_new==0){
				koliko=koliko_puta(pocetak, temp, duzina, 0);
				if(koliko>max_ponavljanja){
					max_ponavljanja=koliko;
					max_pointer=temp;
					max_duzina=duzina;
				}
				is_new=1;
				duzina=0;
			}
		}
		s++;
	}
	if(is_new==0){
		koliko=koliko_puta(pocetak, temp, duzina, 0);
		if(koliko>max_ponavljanja){
			max_ponavljanja=koliko;
			max_pointer=temp;
			max_duzina=duzina;
		}
	}
	max_pointer=nadjiZadnju(pocetak, max_pointer, max_duzina);
	if(max_ponavljanja!=-1){
		koliko_puta(pocetak, max_pointer, max_duzina, 1);
	}
	return pocetak;
}

int main() {
	char t[]="Pet678678678786pet pte pte pte pte 1";
	printf("'%s'", izbaci_najcescu(t));
	return 0;
}
