#include<stdio.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int uporedi(char *s1, char *s2){
	int broj=0;
	while(*s1==*s2){
		if(*s1=='\0' && *s2=='\0'){
			broj=1; break;
		}
		s1++; s2++;
	}
	return broj;
}

int duzina (char *s){
	int duz=0;
	while(*s!='\0'){
		duz++;
		s++;
	}
	return duz;
}

int slovo (char s) {
	if((s>='A' && s<='Z') || (s>='a' && s<='z')) return 1;
	return 0;
}

char *zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *pocetak=tekst;
	char pomocni_niz[100];
	int i=0;
	while(i!=broj_rijeci){
		tekst=pocetak;
		char *pomocna_rijec=rijeci[i];
	//	char *q=pomocni_niz;
		while(*tekst!='\0'){
			char *q=pomocni_niz;
			while(*tekst==' ') tekst++;
			char *pocetak_rijeci=tekst;
			while(*tekst!=' ' && *tekst!='\0') *q++=*tekst++;
			*q='\0';
		//	q=pomocni_niz;
			if(uporedi(pomocna_rijec,pomocni_niz)){
				int vel=duzina(pomocni_niz)-duzina(zamjene[i]);
				if(vel<0){
					char *pom=tekst;
					while(*pom!='\0') pom++;
					while(pom!=pocetak_rijeci+duzina(pomocni_niz)-1)
						*(pom-vel)=*pom--;
				}
				
				if(vel>0){
					char *pom=tekst-vel;
					while(*(pom+vel)!='\0') *pom++=*(pom+vel);
					*pom='\0';
					//tekst-=vel;
				}
				
				char *niz=zamjene[i];
				while(*niz!='\0') *pocetak_rijeci++=*niz++;
			}
		}
		i++;
	}
	return pocetak;
}



int main(){
	char* rijeci[2] = {"testiranje", "test"};
char* zamjene[2] = {"zamjena", "swap"};
char tekst[] = "test testiranje test";
printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}






















