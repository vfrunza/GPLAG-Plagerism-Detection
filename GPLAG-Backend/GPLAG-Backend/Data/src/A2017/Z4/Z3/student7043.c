#include <stdio.h>
#include <string.h>

void najduzi_bp(char* s1, char* s2){
	int vrati_s1=0;
	int duz_max=0;
	char naj_duzi_string[20];
	char string[20];
	int i=0;
	int j=0;
	int duzina_stringa;
	while (*s1!='\0'){
            i=0;
            vrati_s1=0;
        while (((*s1<'A' || *s1>'Z') && (*s1<'a' || *s1>'z'))) s1++;
		while((*s1>='A' && *s1<='Z') ||(*s1>='a' && *s1<='z')){
			string[i]=*s1;
			i++;
			s1++;
		}
		string[i]='\0';
		duzina_stringa=strlen(string);
		i=0;
		j=i+1;
		while(string[i]!='\0'){
            while(string[j]!='\0'){
                if (string[i]==string[j] || string[i]==(string[j]+32) || string[i]==(string[j]-32)) {
                    string[j]='\0';
                    break;
                }
                j++;
            }
            i++;
            j=i+1;
		}
		vrati_s1=duzina_stringa-i;
		duzina_stringa=strlen(string);
		if (duzina_stringa>duz_max){
            duz_max=duzina_stringa;
            strcpy(naj_duzi_string,string);
		}
		s1=s1-vrati_s1;
	}
	strcpy(s2,naj_duzi_string);
}

int main() {
    {//AT3
        char niz[10];
        najduzi_bp ("Ovo jEv oVo aAaA", niz);
        printf ("Niz: '%s'", niz);
    }//Niz: 'jEv'
}
