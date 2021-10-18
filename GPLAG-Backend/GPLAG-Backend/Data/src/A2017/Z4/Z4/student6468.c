#include <stdio.h>

int provjeri(char* html) {
	char usedTags[1000][20];
	char* tmp;
	char *tmp2;
	int currentTag = 0;
	int i=0;
	char upperCaseTmp;

	while(*html != '\0') {
		if(*html == '<') {
			tmp = html + 1;
			
			while(*tmp != ' ' && *tmp != '\0' && *tmp != '>') {
				tmp++;
			}
				
			if(*(html + 1) == '/') {
				tmp2 = html + 2;
				i = 0;
				
				if(*tmp2 == ' ')
					return 0;
				
				while(tmp2 != tmp) {
					upperCaseTmp = *tmp2;
					if(upperCaseTmp >= 'A' && upperCaseTmp<='Z')
						upperCaseTmp += 32;
						
					if(usedTags[currentTag - 1][i] != upperCaseTmp)
						return 0;
						
					tmp2++;
					i++;
				}
				
				currentTag--;
			}
			else if((*(html+1) >= 'a' && *(html+1) <= 'z') || (*(html+1) >= 'A' && *(html+1)<= 'Z')) {
				tmp2 = html + 1;
				i = 0;
				
				if(tmp2 == tmp) {
					upperCaseTmp = *tmp2;
					
					if(upperCaseTmp >= 'A' && upperCaseTmp<='Z')
						upperCaseTmp += 32;
						
					usedTags[currentTag][0] = upperCaseTmp;
					usedTags[currentTag][1] = '\0';
				}
				else {
					while(tmp2 != tmp) {
						upperCaseTmp = *tmp2;
						
						if(upperCaseTmp >= 'A' && upperCaseTmp <= 'Z')
							upperCaseTmp += 32;
					
						usedTags[currentTag][i] = upperCaseTmp;
						tmp2++;
						i++;
					}
				}
				
				currentTag++;
			}
		}
		
		html++;
	}
	
	return currentTag == 0;
}

int main() {
	printf ("Provjera 1: %d\n", provjeri("<a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A>"));
	printf ("Provjera 2: %d\n", provjeri("<P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A></P>"));
	printf ("Provjera 3: %d\n", provjeri("<DiV><P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A></P><dIv>"));
	printf ("Provjera 3: %d\n", provjeri("<DiV><P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A></P></dIv>"));
	printf ("Provjera 4: %d\n", provjeri("<h1><P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</B></P></h1>"));
	printf ("Provjera 5: %d\n", provjeri("<a></a></a>jedan jako specijalan slucaj"));


	return 0;
}
