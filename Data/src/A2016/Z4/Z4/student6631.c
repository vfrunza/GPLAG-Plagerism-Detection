#include <stdio.h>
#include <math.h>
#define e 0.0001

int provjeraPismenosti(char* nizTacaka, int* i){                                /* provjeraPismenost i provjeraDrgua rade u paru */
	if(nizTacaka[*i] == '-') (*i)++;                                            /* ova funkcija provjerava ono sto se nalazi izmedju zagrade i zareza */
	if(nizTacaka[*i] >= '0' && nizTacaka[*i] <='9'){
		while( nizTacaka[*i] >= '0' && nizTacaka[*i] <='9')(*i)++;				
	}
	else return 0;
	if(nizTacaka[*i] == '.'){ 
		(*i)++;
		while( nizTacaka[*i] >= '0' && nizTacaka[*i] <='9')(*i)++;
	}
	return 1;
}

int provjeraDruga(char* nizTacaka){                                             /* ova funkcija provjerava da li je format unosa ispravan */
	int x = 0, zarez;
	while (nizTacaka[x] != '\0'){
		zarez=0;
		if(nizTacaka[x++] != '(') return 0;
		if(!provjeraPismenosti(nizTacaka, &x)) return 0;
		if(nizTacaka[x++] != ',')return 0;
		if(!provjeraPismenosti(nizTacaka, &x)) return 0;
		if(nizTacaka[x++] != ')') return 0;
		if(nizTacaka[x] != ','){
			
			if(nizTacaka[x] != '\0') return 0;
			else break;
			}
		x++;
		if(nizTacaka[x] == '\0') return 0;
		}
		
return 1;
}

int opsegCheck(float max, float min, char* nizTacaka){                          /* provjera opsega */
	int i=0;
	int multi =1;
	int signum= 1;
	float dec = 0.1;
	float broj=0;
	
	while(nizTacaka[i+1] != '.' && nizTacaka[i+1] != ',' && nizTacaka[i+1] != ')') i++;  /*preskakanje karaktera != broj */
	while( nizTacaka[i] >= 48 && nizTacaka[i] <=57){
		broj= broj+ ((nizTacaka[i] - 48)*multi);								/* ovim cemo dobiti trazeni broj */
		i--;
		multi= multi*10;
	}
	
	if(nizTacaka[i]=='-') signum=-1;                                             /* uzeli smo u obzir - kao predznak */
	while(nizTacaka[i] != '.' && nizTacaka[i] != ',' && nizTacaka[i] != ')') i++;
	if(nizTacaka[i]=='.'){
		i++;
		while(nizTacaka[i]>= 48 && nizTacaka[i]<= 57 ){
			broj= broj+ ((nizTacaka[i]-48)*dec);
			dec = dec/10;
			i++;
		}
	}
	broj= broj*signum;
	if((broj-min>e || fabs(broj-min)<e) && (fabs(broj-max)<e || max - broj >e)) return 1;
	else return 0;
}

void koordinata(char* nizTacaka, int i){                                        /* funckija sluzi za izbacivanje koordiante */
	char* pocetnaVrijednost = nizTacaka;
	int duzina=0;
	int brojac=i;
	int brojac2=0;
	
	while(nizTacaka[brojac++]!= ')'){
		duzina++;
	}
	
	brojac=duzina;
	
	if(nizTacaka[i+brojac+1]!= '\0'){
		duzina++;
	}
	else if(i!=0){
		i--;
		duzina++;
	}
	nizTacaka = nizTacaka + i;
	while(duzina >= 0){
		brojac2=0;
		while(nizTacaka[brojac2]!='\0'){
			nizTacaka[brojac2]=nizTacaka[brojac2+1];
			brojac2++;
		}
		duzina--;
	}
	nizTacaka=pocetnaVrijednost;                                                /* cuvali smo pocetnu vrijednost da nizTacaka */ 
}	                                                                            /* bude jednak onom, prije izvrsavanja fje */
	

char* obuhvat(char* nizTacaka, float minX, float minY, float maxX, float maxY){ /* trazena funkcija u zadatku */
	int i=0;
	if (nizTacaka[0]=='\0') return nizTacaka;
	if(!provjeraDruga(nizTacaka)){ return NULL;
	}
	
	while(nizTacaka[i]!='\0'){
	if(nizTacaka[i]=='\0') break;
	if(i!=0) i++;
	if(!opsegCheck(maxX, minX, nizTacaka+i)){
		while(nizTacaka[i]!= '(') i--;
		koordinata(nizTacaka, i);
		continue;
	}
	
	if(nizTacaka[i]=='\0') break;
	while(nizTacaka[i++]!=',');
	if(!opsegCheck(maxY, minY, nizTacaka+i)){
		while(nizTacaka[i]!= '(') i--;
		koordinata(nizTacaka, i);
		continue;
	}
	
	if(nizTacaka[i]=='\0') break;
	while(nizTacaka[i]!=')' && nizTacaka[i]!='\0') i++;
	i++;
}
	return nizTacaka;
}


int main() {
	return 0;
}
