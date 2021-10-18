#include <stdio.h>

int provjeri(char *s) {
	int i=0, j, t=0;
	char mat[100][100];
	while(*s!=0) {
		if(*s=='<' && *(s+1)=='/') {
			if(t==0) return 0;
			s+=2;
			j=0;
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z') || (*s>='0' && *s<='9')) {
				if(*s!=mat[i-1][j] && *s+32!=mat[i-1][j] && *s-32!=mat[i-1][j]) return 0;
				j++;
				s++;
			}
			i--;
		}
		if(*s=='<') {
			t=1;
			j=0;
			s++;
			while(*s==' ') {
				mat[i][j]=*s;
				j++;
				s++;
			}
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z') || (*s>='0' && *s<='9')) {
				mat[i][j]=*s;
				j++;
				s++;
			}
			i++;
		}
		s++;
	}
	if(i!=0) return 0;
	return 1;
}

int main() {
/*	printf("Zadaća 4, Zadatak 4");*/
	char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
	char tekst2[] = "<b><a>proba</b></a>";
	printf("%d ", provjeri(tekst1));
	printf("%d ", provjeri(tekst2));
	return 0;
}
