#include <stdio.h>
#include <math.h>
#include <string.h>
#define EPS 0.0001

void izbaciKordinatu(char* pocetak, char* kraj){
	while(*kraj != '\0'){
		*pocetak = *kraj;
		pocetak++;
		kraj++;
	}
	*pocetak = *kraj;
}
int jeBroj(char karakter){
	if(karakter>='0' && karakter <='9') return 1;
	return 0;
}
int unutar(float x, float y, float x1, float y1, float x2, float y2){
	float rangex = x2 - x1, rangey = y2 - y1;
	float xmid = (x1 + x2)/2, ymid = (y1 + y2)/2;
	if( x1 - x > EPS || y1 - y > EPS || x - x2 >EPS || y -y2 > EPS) return 0;
	else return 1;
	//if(fabs(xmid - x) <= (rangex + EPS) && fabs(ymid - y) <= (rangey + EPS)) return 1;
	//else return 0;
}

char* obuhvat(char* kordinate, float x1, float y1, float x2, float y2){
	char* pocetak,*kraj;
	if(*kordinate == '\0') return kordinate;
	char* pok = kordinate;
	while(*pok != '\0'){
		pocetak = pok;
		if(*pok != '(') return NULL;
		pok++;
		int znakPrveKorinate = 1;
		float prvaKordinata = 0;
		int brojCifra = 1;
		if(*pok == '-'){
			znakPrveKorinate = -1;
			pok++;
		}
		if(jeBroj(*pok) == 0) return NULL;
		while(jeBroj(*pok)){
			prvaKordinata = prvaKordinata*10 + (*pok - '0');
			pok++;
		}
		if(*pok == '.'){
			pok++;
			int decimal = 1;
			while(jeBroj(*pok)){
				prvaKordinata += ((float)(*pok - '0'))/decimal;
				decimal*=10;
				pok++;
			}
		}
		if(*pok != ',') return NULL;
		pok++;
		int znakDrugeKorinate = 1;
		float drugaKordinata = 0;
		if(*pok == '-'){
			znakDrugeKorinate = -1;
			pok++;
		}
		if(jeBroj(*pok) == 0) return NULL;
		while(jeBroj(*pok)){
			drugaKordinata = drugaKordinata*10 + (*pok - '0');
			pok++;
		}
		if(*pok == '.'){
			pok++;
			int decimal = 1;
			while(jeBroj(*pok)){
				prvaKordinata += ((float)(*pok - '0'))/decimal;
				decimal*=10;
				pok++;
			}
		}
		if(*pok!=')') return NULL;
		pok++;
		prvaKordinata*=znakPrveKorinate;
		drugaKordinata*=znakDrugeKorinate;
	//	printf("%f %f\n",prvaKordinata,drugaKordinata);
		if(*pok != '\0' && *pok!=',' ) return NULL;
		else if(*pok !='\0' && *pok == ',' && pok[1] == '\0') return NULL;
		else if(*pok !='\0' && *pok == ',')
			pok++;
		kraj = pok;
		if(!unutar(prvaKordinata,drugaKordinata,x1,y1,x2,y2)){
			izbaciKordinatu(pocetak,kraj);
			pok = pocetak;
	//		printf("%s\n",kordinate);
		} 

	}
	if(*(pok -1) ==',') pok[-1] = '\0';
	return kordinate;
}


int main() {
	char s[] = "(1,7),(2,5),(1,6),(3,3)";
	char pom[100];

	strcpy(pom,s);
	obuhvat(pom, 1, 3, 3, 7);
	printf("%s\n", pom);
	//izbaciKordinatu(pom+6,pom+12);
	printf("Ocekivano (1,7),(2,5),(1,6),(3,3)\n");
	//printf("%s\n", pom);
	
	return 0;
}
