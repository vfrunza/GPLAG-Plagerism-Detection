#include <stdio.h>

void obrisiPodstr (char *s, char *rijec, int prviPutPar);

int brojPonavljanja (char *s, char *rijec){
	//funkcija vraca broj ponavljanja rijeci u stringu
	int len = 0;
	char *pokLast = rijec;
	char *temp;
	char slovo, slovoA, slovoB;
	char *p = rijec;
	int isti = 1;
	int broj = 0;
	int space = 1;
	//odredjujemo duzinu rijeci, len
	while(*rijec != '\0'){
		if(*rijec < 'A' ||(*rijec > 'Z' && *rijec < 'a') || (*rijec >'z')){
			break;
		}
		len++;
		rijec++;
	}
	rijec = pokLast;
	while(*s != '\0'){
		slovo = *s;
		if(slovo <= 'Z' && slovo >= 'A')
			slovo += 'a' - 'A';
		if( slovo < 'a' || (slovo >'z')){
			space = 1;
		}
		else if(space){
			space = 0;
			//prolaze kroz sve rijeci
			temp = s;
			isti = 1;
			p = rijec;
			while(temp < s + len){
				slovoA = *temp;
				if(slovoA <= 'Z' && slovoA >= 'A')
				slovoA += 'a' - 'A';
				if(*temp == '\0'){
					isti = 0;
					break;
				}
				slovoB = *p;
				if(slovoB <= 'Z' && slovoB >= 'A')
				slovoB += 'a' - 'A';
				if(slovoA != slovoB){
					isti = 0;
				}
				
				if(temp == s+ len - 1){
					if(*(temp + 1) != '\0' && ((*(temp+1) >= 'A' && *(temp +1) <= 'Z' ) || (*(temp+1) >= 'a' && *(temp +1) <= 'z' )))
					isti = 0;
				}
				p++;
				temp++;
				
			}
			if(isti)
				broj++;
		}
	s++;			
	}
	
return broj;	
}
char *izbaci_najcescu(char *s){
	char *ret = s;
	int brojZnakova = 0;
	char *startMax;
	int num = 0;
	int space = 1;
	char slovo;
	
	while(*s++ != '\0'){
		brojZnakova++;
	}
	s = ret;
	//odredimo adresu najcesce rijeci
	while(*s != '\0'){
		slovo = *s;
		if(slovo <= 'Z' && slovo >= 'A')
			slovo += 'a' - 'A';
		if(slovo < 'A' ||(slovo > 'Z' && slovo < 'a') || (slovo >'z')){
			space = 1;
		}
		else if(space){
			//num++;
			space = 0;
			if(brojPonavljanja(ret, s) > num){
				num = brojPonavljanja(ret, s);
				startMax = s;
			}
				
		}
		s++;
	}
	//brisemo najcescu
	if(num != 0)
	obrisiPodstr(ret, startMax,1);
	
	return ret;
}
void obrisiPodstr (char *s, char *rijec, int prviPutPar){
	char *ret = s;
	int len = 0;
	char *pokLast = rijec;
	char *temp;
	char slovo, slovoA, slovoB;
	char *p = rijec;
	int isti = 1;
	int broj = 0;
	int space = 1;
	int brisanje;
	int prviPut;//rijec je snimljena na prvom mjestu u stringu pa je moramo zadnju obrisat
	//odredjujemo duzinu rijeci, len
	prviPut = prviPutPar;
	while(*rijec != '\0'){
		if(*rijec < 'A' ||(*rijec > 'Z' && *rijec < 'a') || (*rijec >'z')){
			break;
		}
		len++;
		rijec++;
	}
	rijec = pokLast;
	while(*s != '\0'){
		slovo = *s;
		if(slovo <= 'Z' && slovo >= 'A')
			slovo += 'a' - 'A';
		if( slovo < 'a' || (slovo >'z')){
			space = 1;
		}
		else if(space){
			space = 0;
			//prolaze kroz sve rijeci
			temp = s;
			isti = 1;
			p = rijec;
			while(temp < s + len){
				slovoA = *temp;
				if(slovoA <= 'Z' && slovoA >= 'A')
				slovoA += 'a' - 'A';
				if(*temp == '\0'){
					isti = 0;
					break;
				}
				slovoB = *p;
				if(slovoB <= 'Z' && slovoB >= 'A')
				slovoB += 'a' - 'A';
				if(slovoA != slovoB){
					isti = 0;
				}
				
				if(temp == s+ len - 1){
					if(*(temp + 1) != '\0' && ((*(temp+1) >= 'A' && *(temp +1) <= 'Z' ) || (*(temp+1) >= 'a' && *(temp +1) <= 'z' )))
					isti = 0;
				}
				p++;
				temp++;
				
			}
			if(isti){
				if(prviPut == 0){
					temp = s;
					brisanje = len;
					while(brisanje--){
						s= temp;
						while(*s != '\0'){
							*s = *(s+1);
							s++;
						}
					}
					s = temp;
					s--;
				}
				else
				prviPut = 0;
				
			}
				
		}
	s++;			
	}
	//funkcija sama sebe poziva da bi obrisala i prvo pojavljivanje rijeci
	if(prviPutPar)
	obrisiPodstr(ret, pokLast, 0);
}

int main() {

	return 0;
}
