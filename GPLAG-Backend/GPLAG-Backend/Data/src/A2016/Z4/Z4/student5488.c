#include <stdio.h>


/*void Pretvori(float pretvorix[], float pretvoriy[], char izdvojeno[]){
	int br_tacaka=0;
	int br_nakon=0;
	int br_min=0;
	int i;
	char* na_izdvojeno=izdvojeno
	float broj=0; float brojj=0;
	
	while (*na_izdvojeno!=',') {
		br_nakon++; na_izdvojeno++;
	}
	na_izdvojeno=izdvojeno;
	while(*na_izdvojeno!='\0'){
		if(*na_izdvojeno=='.') br_tacaka++;
		if(*na_izdvojeno=='-') br_min++;
		na_izdvojeno++;
		}
		
		if(br_min==0 && br_tacaka=0 ){
			while(*na_izdvojeno!=','){
				i=br_nakon;
				broj+=(*na_izdvojeno-48)*pow(10,i);
				i--;
				na_izdvojeno++;
			}
			*pretvorix=broj;
			/*treba dovrsiti pretvaranja sa zarezima i bez njih u float i poslije odvojiti fju za ovu tacku nakon!*/
		/*	
		}
}
*/
char* obuhvat(char string[],double x1,double y1,double x2,double y2){
	char* prodji_kroz_string=string;
	char* heh= NULL; 
	int br;
	char izdvoji[300];
	float pretvorix[300];
	float pretvoriy[300];
	/*Provjeravamo da li ima neki nedozvoljen znak u stringu*/
	while(*prodji_kroz_string!='\0'){
		if(*prodji_kroz_string!='(' && *prodji_kroz_string!=')' && *prodji_kroz_string!='.' && *prodji_kroz_string!=',' && *prodji_kroz_string!='-'&& *prodji_kroz_string>57 && *prodji_kroz_string<48) return heh;
	prodji_kroz_string++;
	}
	
	prodji_kroz_string=string;
	heh=izdvoji;
	while(*prodji_kroz_string!='\0'){
		heh=izdvoji;
		if(*prodji_kroz_string=='('){
			prodji_kroz_string++;
			br=0;
			while(*prodji_kroz_string!=')'){
				br++;
				*heh=*prodji_kroz_string;
				heh++;
				prodji_kroz_string++;
				
			}
			*heh='\0';
		}
		prodji_kroz_string++;
/*		Pretvori(pretvorix,pretvoriy,izdvojeno);
		if(pretvorix[0]<)// ovdje sa epsilonom...treba i niz koji preslikava one sve sto pripadaju pravougaoniku..
*/		
	}
	return string;
}
int main() {
/*	printf("Zadaća 4, Zadatak 4");*/
	return 0;
}
