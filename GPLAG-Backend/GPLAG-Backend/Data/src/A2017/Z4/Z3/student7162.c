#include <stdio.h>

void najduzi_bp(char *s1, char *s2) {
	int niz[127] = {0};
	char *pt, *kt, *pm=s1, *km=s1;
	char *poc=s1;
	int maxduz=0, i=0, vr;
	
	while (s1!='\0') {
		
		poc=s1;
		pt=poc;
	
		while (*poc !='\0' && *poc!=' ' && ((*poc >= 'A' && *poc <= 'Z') || (*poc >= 'a' && *poc <= 'z'))) {
			if(niz[*poc]==0) {
				if(*poc >= 'A' && *poc <= 'Z') {
					vr = *poc+('a' - 'A');
					niz[vr]++;
				}
				else niz[*poc]++;
				poc++;
			}
			else break;
		}
		kt = poc;
	
		if (kt-pt>maxduz) {
			maxduz = kt-pt;
			pm=pt;
			km=kt;
		}
	
		for (i=0;i<127;i++){
			niz[i] = 0;
			s1++;
		}
		if (*s1==' ') s1++;
	}
	
	while (pm!=km) {
		*s2=*pm;
		pm++;
		s2++;
	}
	*s2='\0';
}

int main() {
	char niz[100];
	najduzi_bp ("Ovo je neki primjer", niz);
	printf ("Niz: '%s' ", niz);
	return 0;
}	