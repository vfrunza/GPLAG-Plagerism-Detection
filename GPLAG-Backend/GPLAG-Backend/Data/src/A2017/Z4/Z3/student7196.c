#include <stdio.h>

void najduzi_bp(char* s1, char* s2) {
	char* poc1=s1;
	char* poc2=s1;
	char* pamti=s2;
	char* pamti_s1=s1;
	char* klizeci=s1;
	int duz_podstringa1=0, max_duz_podstringa1=0, duz_podstringa2=0, max_duz_podstringa2=0;
	int pomocna=0;
	int br_prolaza=0;
	
	while (*s1) {
		while (!(*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z')) {
			s1++;
		}
		poc1=s1;
		
		/*Trazenje podstringa na prvi nacin, zbog cinjenice da najduzi podstring moze biti omedjen i slovima slijeva ili zdesna*/
		br_prolaza=0;
		while (*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z') {
			s1++;
			klizeci=poc1;
			while (klizeci<s1) {
				if (*s1==*klizeci || *s1==*klizeci+32 || *s1==*klizeci-32) {
					if (br_prolaza==0) {
						poc1=s1=klizeci+1;
						pomocna=10;
						br_prolaza=1;
						break;
					}
					else {
						pomocna=5;
						break;
					}
				}
				klizeci++;
			}
			if (pomocna==10) {
				pomocna=0;
				continue;
			}
			if (pomocna==5) {
				pomocna=0;
				break;
			}
		}
		duz_podstringa1=s1-poc1;
		s1--;
		if (duz_podstringa1>max_duz_podstringa1) {
			max_duz_podstringa1=duz_podstringa1;
			klizeci=poc1;
			pamti=s2;
			while (klizeci<=s1) {
				*s2++=*klizeci++;
			}
			*s2=0;
			s2=pamti;
		}
		s1++;
	}
	
	s1=pamti_s1;
	pamti=s2;
	pomocna=0;
	
	/*Trazenje podstringa na drugi nacin*/
	while (*s1) {
		while (!(*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z')) {
			s1++;
		}
		poc2=s1;
		while (*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z') {
			s1++;
			klizeci=poc2;
			while (klizeci<s1) {
				if (*s1==*klizeci || *s1==*klizeci+32 || *s1==*klizeci-32) {
					pomocna=5;
					break;
				}
				klizeci++;
			}
			if (pomocna==5) {
				pomocna=0;
				break;
			}
		}
		duz_podstringa2=s1-poc2;
		s1--;
		if (duz_podstringa2>max_duz_podstringa2) {
			max_duz_podstringa2=duz_podstringa2;
			if (max_duz_podstringa2>max_duz_podstringa1 || (max_duz_podstringa2==max_duz_podstringa1 && poc2<poc1)) {
				klizeci=poc2;
				pamti=s2;
				while (klizeci<=s1) {
					*s2++=*klizeci++;
				}
				*s2=0;
				s2=pamti;
			}
		}
		s1++;
	}
}

int main() {
	return 0;
}
