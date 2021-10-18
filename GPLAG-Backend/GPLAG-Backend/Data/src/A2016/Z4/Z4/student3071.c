#include <stdio.h>
#include<math.h>
#define EPSILON 0.0001
#include<stddef.h>
#include<string.h>
int duzina_stringa(char *string){
	int duzina=0;
	while(*string!='\0'){
		duzina++;
		string++;
	}
	return duzina;
}

//Sigurnosna funkcija da utvrdi da li se zaista radi 
//o posljednjoj tacki
int brojac_zagrada(char *string){
	int duzina=0;
	while(*string!='\0'){
		if(*string=='(') duzina++;
		string++;
	}
	return duzina;
}

char *obuhvat( char *string, float x1, float y1, float x2, float y2 ){
	int brojac_lijevih=0, brojac_desnih=0, brojac_zareza=0;
	int koord,k=0;
	float sx1=0,sy1=0;
	char *pok;
	char *pok2;
	char *pok3;
	char *pok4;
	//Test ispravnosti stringa, ujedno test njegove sadrzine
	for(pok=string; *pok; pok++,k++){
		if(*pok==',' && *(pok+1)==')') return NULL;
		if(*pok=='(' && *(pok+1)==',') return NULL;
		if(*pok=='(' && *(pok+1)=='.') return NULL;
		if(*pok==',' && *(pok+1)=='.') return NULL;
		if(k!=0 && *pok=='(' && *(pok-1)!=',') return NULL;
		if(*pok=='(') brojac_lijevih++;
		else if (*pok==')') brojac_desnih++;
		else if (*pok==',') brojac_zareza++;
		else if (!(*pok<='9' && *pok>='0') && *pok!='.' && *pok!='-') return NULL;
	}
	if(brojac_desnih!=brojac_lijevih || brojac_zareza%2!=1) return NULL;
	pok=string;
	for(; *pok; pok++){
		//Sad racunamo tacke
    sx1=0;
    sy1=0;
	koord=0;
	int signum=1;
	k=0;
	for(pok2=pok+1; *pok2!=','; pok2++){
	//X, prva tacka
		if(*pok2=='-'){
			signum=-1;
			pok2++;
		}
		for(pok3=pok2; *pok3!='.' && *pok3!=','; pok3++){
			koord=koord*10;
			koord+=*pok3-48;
		}
		sx1=koord;
		koord=0;
		if(*pok3=='.'){
			pok3++;
			for(; *pok3!=','; pok3++){
				k++;
				koord=koord*10;
				koord+=*pok3-48;
			}
		}
		sx1=(sx1+koord/pow(10,k))*signum;
		pok2=pok3;
		break;
	}
	k=0;
	koord=0;
	pok2++;
	signum=1;
	//Y, prva tacka
	for(; *pok2!=','; pok2++){

		if(*pok2=='-'){
			signum=-1;
			pok2++;
		}
		for(pok3=pok2; *pok3!='.' && *pok3!=')'; pok3++){
			koord=koord*10;
			koord+=*pok3-48;
		}
		sy1=koord;
		koord=0;
		if(*pok3=='.'){
			pok3++;
			for(; *pok3!=')'; pok3++){
				k++;
				koord=koord*10;
				koord+=*pok3-48;
			}
		}
		sy1=(sy1+koord/pow(10,k))*signum;
		pok2=pok3;
		break;
	}
	//Logicka promjenjiva uz koju utvrdjujemo da li izbaciti clan ili ne
	int izbaci_iz_stringa=1;
	if(sx1<x1 && fabs(sx1-x1)>EPSILON) izbaci_iz_stringa=0;
	if(sx1>x2 && fabs(sx1-x2)>EPSILON) izbaci_iz_stringa=0;
	if(sy1<y1 && fabs(sy1-y1)>EPSILON) izbaci_iz_stringa=0;
	if(sy1>y2 && fabs(sy1-y2)>EPSILON) izbaci_iz_stringa=0;
	//Samo kopiranje ako sx1 i sy1 ne zadovoljavaju
	if(!izbaci_iz_stringa){
            //Ako je ona koja se izbacuje posljednja
            if(!*(pok2+1)){
            if(*(pok-1)==','){
                *(pok-1)='\0';
            } else if (*pok=='('){
                *pok='\0';
                       }
            return string;

            }
        pok3=pok2+2;
        pok4=pok;
        for(; *pok3; pok3++, pok4++){
            *pok4=*pok3;
        }
        *pok4='\0';
        //Sada se testira ispravnost posljednje, tj ako se treba izbaciti u prethodnoj naredbi
        //Bi doslo do krahiranja u daljem kodu, pa ispravnost testiramo preko brojaca zagrada
        //pod pretpostavkom da je string prosao test ispravnosti u zaglavlju funkcije
        if(!*(pok2+1) && brojac_zagrada(string)==1){
        	if(*(pok-1)==','){
        		*(pok-1)='\0';
        	} else if (*pok=='('){
        		*pok='\0';
        	}
        	return string;
        }
        
	} else {
        pok=pok2+2;
	}
	pok-=1;
	if(! *(pok2+1)) return string;


	}

	return string;
}

int main() {
	//printf("Zadaća 4, Zadatak 4");
	/* AT5: U zadatku pise da su parametri funkcije (redom): x1, y1, x2, y2 */
char s[] = "(1,7),(2,5),(1,6),(3,3)";
char pom[100];

strcpy(pom,s);
obuhvat(pom, 1, 3, 3, 7);
printf("%s ", pom);

strcpy(pom,s);
obuhvat(pom, 3, 3, 1, 7);
printf("'%s' ", pom);

strcpy(pom,s);
obuhvat(pom, 7, 3, 3, 1);
printf("'%s' ", pom);

strcpy(pom,s);
obuhvat(pom, 1, 5, 2, 6);
printf("%s ", pom);

strcpy(pom,s);
obuhvat(pom, 1, 6, 2, 5);
printf("'%s' ", pom);

strcpy(pom,s);
obuhvat(pom, 2, 5, 1, 6);
printf("'%s' ", pom);
	return 0;
}
