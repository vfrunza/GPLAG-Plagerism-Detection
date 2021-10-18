#include <stdio.h>
#include <stdbool.h>

int duzina(char* s1){
	int duz;
	while (*s1!='\0'){
		duz++;
	}
	return duz;
}

bool da_li_je_slovo(char znak){
	if((znak>='A' && znak<='Z') || (znak>='a' && znak<='z')) return true;
	return false;
}

bool provjeri_prisutnost(char* za_provjeru, char slovo){
	while(*za_provjeru!='\0'){
		if(*za_provjeru==slovo || *za_provjeru==(slovo-32) || *za_provjeru==(slovo+32)) return false;
		else za_provjeru++;
	}
	return true;
}

void najduzi_bp(char* s1, char* s2){
	char maksimalni[100]="";
	char* maks_point=maksimalni;
	char privremeni[100]="";
	int duzina_maksimalnog=0;
	int brojac=0;
	int i;
	
	while (*s1!='\0'){
		if(brojac == 0 && da_li_je_slovo(*s1)){
			privremeni[brojac]=*s1;
			brojac++;
			privremeni[brojac]='\0';
			s1++;
		}
		else if(!da_li_je_slovo(*s1) || !provjeri_prisutnost(privremeni, *s1)){
			if(!provjeri_prisutnost(privremeni, *s1)){
				if(provjeri_prisutnost(privremeni,(s1+1)) && da_li_je_slovo(*(s1+1))){
					privremeni[brojac]=*s1;
					brojac++;
					privremeni[brojac]='\0';
					for(i=0;i<brojac-1;i++){
						privremeni[i]=privremeni[i+1];
					}
					privremeni[brojac]='\0';
					brojac--;
					s1++;
					continue;
				}
			}
			if(brojac>duzina_maksimalnog){
				for(i=0;i<brojac;i++){
					maksimalni[i]=privremeni[i];
				}
				maksimalni[brojac]='\0';
				duzina_maksimalnog=brojac;
			}
			brojac=0;
			privremeni[brojac]='\0';
			s1++;
		}
		else if(da_li_je_slovo(*s1) && provjeri_prisutnost(privremeni,*s1) ){
			privremeni[brojac]=*s1;
			brojac++;
			privremeni[brojac]='\0';
			s1++;
		}
	}
	if(*s1=='\0' && brojac>duzina_maksimalnog){
		for(i=0;i<brojac;i++){
			maksimalni[i]=privremeni[i];
		}
		maksimalni[brojac]='\0';
	}
	while(*maks_point!='\0'){
		*s2=*maks_point;
		s2++;
		maks_point++;
	}
	*s2='\0';
}

int main() {
	return 0;
}
