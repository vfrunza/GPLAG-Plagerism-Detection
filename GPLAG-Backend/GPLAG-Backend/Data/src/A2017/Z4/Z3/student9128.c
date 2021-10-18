#include <stdio.h>
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

void najduzi_bp(char* s, char* s1) {
	int duzina, max_duzina=0;
	char* temp, *pom, *pom2=s1, *kraj, *help;
	char pomocno_slovo1, pomocno_slovo2;
	while(*s!=0) {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
			s++;
			continue;
		}
		else {
			temp=s+1;
			pom=s;
			help=s;
			kraj=s;
			while((*kraj>='A' && *kraj<='Z') || (*kraj>='a' && *kraj<='z')) kraj++;
			
			while(((*help>='A' && *help<='Z') || (*help>='a' && *help<='z')) && help<kraj) {
				while(((*temp>='A' && *temp<='Z') || (*temp>='a' && *temp<='z')) && temp<kraj) {
					if(*temp>='a') pomocno_slovo1=*temp-32;
					else pomocno_slovo1=*temp;
					if(*help>='a') pomocno_slovo2=*help-32;
					else pomocno_slovo2=*help;
					if(pomocno_slovo1==pomocno_slovo2) {
						kraj=temp;
					}
					temp++;
				}
				help++;
				temp=help+1;
			}
			
			duzina=(temp-s)/sizeof(char);
			if(duzina>max_duzina) {
				s1=pom2;
				while(pom!=kraj) {
					*s1=*pom;
					s1++;
					pom++;
				}
				*s1=0;
				max_duzina=duzina;
			}
		}
		s++;
	}
}
int main() {
	char s[100], s1[100];
	printf("Unesi string: \n");
	unesi(s, 100);
	najduzi_bp(s, s1);
	printf("%s", s1);
	return 0;
}
