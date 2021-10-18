#include <stdio.h>

int JelSlovo(char x){
	if(x>='a' && x<='z') return 1;
	if(x>='A' && x<='Z') return 1;
	return 0;
}

int ZnakJednak(char prvi,char drugi){
	if(prvi<drugi && prvi+32==drugi) return 1;
	else if(prvi>drugi && prvi-32==drugi) return 1;
	else if(prvi==drugi) return 1;
	else return 0;
}

void najduzi_bp(char* s1,char* s2)
{
	char *izvlaka;
	char *pok; // seta da vidi jel se ponovio znak
	int i;
	int max=0; // za trazenje maximuma
	int brojac=0;
	while(*s1==' ') s1++;
	izvlaka=s1;
	if(*s1=='\0'){*s2='\0'; return;}
	while(*s1!='\0'){
		pok=s1-brojac;
		while(pok!=s1) {if(ZnakJednak(*pok,*s1)) break;pok++;} // pok radi svoj dio
		if(JelSlovo(*s1)==0 || pok!=s1){ // dosao je do necega sto nije slovo ILI nasao je da se ovaj znak ponovio znaci prekini 
			if(brojac>max){ // ako je nadjen veci podniz apdejtuj 
				max=brojac;
				izvlaka=s1-brojac;
			}
		
			if(pok!=s1) s1=s1-brojac;
			brojac=0; // resetuje brojac za drugi podniz
		}
		else brojac++; // ako nije nasao znak da nastavi dalje
		s1++;
	}
	
	if(brojac>max){
		max=brojac;
		izvlaka=s1-brojac;
	}
	for(i=0;i<max;i++) *s2++=*izvlaka++;
	*s2='\0';
}

int main(){
	char rec[200]={"   ermi!n  "};
	char rijec[200];
	najduzi_bp(rec,rijec);
	printf("%s",rijec);
	return 0;
}