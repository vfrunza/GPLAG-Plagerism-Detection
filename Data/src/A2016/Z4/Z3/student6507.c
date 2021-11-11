#include <stdio.h>

int broj_rijeci_u_stringu(char* tekst){
	char* p=tekst;
	int broj=0;
	while(*p != '\0'){
		if(p==tekst) broj++;
		if(*(p+1)==' ' && *p!=' ') broj++;
		if(*p!= ' ' && *(p+1)=='\0') broj++;
		p++;
	}
	return broj;
}

int len(char* s){
	char*p=s;
	int duz=0;
	while(*p != '\0'){
		duz++;
		p++;
	}
	return duz;
}
/*pronalazak rijeci u nizu*/
char* StrStr(char* tekst, char* rijec){
	char* p=tekst;
	char* pocetak=tekst;
	char* q=rijec;
	while(*p != '\0'){
		q=rijec;
	 if(*p==*q && (p==tekst || *(p-1)==' ')){
			pocetak=p;
			while(*p==*q){
				if(*p=='\0') return pocetak; /*ako dodje do kraja recenice, znaci da je pronadjena rijec*/
				p++;
				q++;
			}
			if((*p=='\0' || *p==' ') && *q=='\0') return pocetak;
		}
		p++;
	}
	return NULL;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char** r=rijeci;
	char** z=zamjene;
	char* x=tekst;
	char* kraj;
	char* p;
	int i, duzina, k, brojac=0;
	for(i=0; i<broj_rijeci; i++){
			x=StrStr(tekst,*(r+i));
			if(x){
			brojac++;
			if(brojac==broj_rijeci_u_stringu(tekst)) return tekst;/*Ovime sprjecavamo beskonacno provjeravanje*/
			kraj=x;
			duzina=len(*(z+i))-len(*(r+i));
			if(duzina<0){
				for(k=0; k<(-duzina); k++){
					kraj=x;
					while(*kraj != '\0'){
					*kraj=*(kraj+1);
					if(*kraj=='\0') continue;
					kraj++;
					}
				}
				p=*(zamjene+i);
				while(*p!='\0') *x++=*p++;
				x--;
				i--;
			}
			else{
				while(*kraj != '\0'){
					kraj++;
				}
			
				while(kraj>x){
					*(kraj+duzina)=*kraj;
					kraj--;
				}
				p=*(zamjene+i);
				while(*p!='\0') *x++=*p++;
				x--;
				i--;
			
				}
			}
		}
	return tekst;
}

int main() {
	char* rijeci[2]={"dobro"};
	char* zamjene[2]={"dobro"};
	char tekst[100]="dobro dobro";
    char *p=zamjena_rijeci(tekst,rijeci, zamjene, 1);
	printf("%s", p);
	return 0;
}
