#include <stdio.h>

int Isti(char *prvi,char *drugi){
	while(*prvi!='>' && *prvi!=' ' && *drugi!='>'){
		if(*prvi!=*drugi) return 0;
		prvi++;
		drugi++;
		if(*prvi=='\0' || *drugi=='\0') return 0;
	}
	if((*prvi=='>' || *prvi==' ') &&( *drugi=='>')) return 1;
	else return 0;
}

char *pomocna(char *s,char *otvoren,int *prekidac){
	while(*s!='\0'){
		if(*s=='<'){
			s++;
			if(*s=='/'){
				s++;
				if(Isti(otvoren,s)==0) *prekidac=1;
				else return s;
			}
			else{
				s=pomocna(s,s,prekidac);
			}
		}
		s++;
	}
	return s;
}

int provjeri(char *s)
{
	char* salji=s;
	int prekid=0;
	while(*s!='\0'){
		if(*s=='<'){
			s++;
			if(*s!='/'){
				salji=s;
				s=pomocna(s,salji,&prekid);
				if(prekid==1) return 0;
			}
			else return 0; // da je prva odma bila zatvorena a nijedna nije otvorena
		}
		s++;
	}
	return 1;
}


int main(){
	printf("%d",provjeri("<div id=""tekst""><h2>Naslov</h2><p>Ovo je <b>četvrti</b> i <i>posljednji</i> zadatak iz <a href=""zadaca4"">zadaće 4</a></p></div>"));
	return 0;
}