#include <stdio.h>

int slovo (char s) {
	if ((s>='A' && s<='Z') || (s>='a' && s<='z')) return 1;
	return 0;
}

int veliko (char s) {
	if (s>='A' && s<='Z') return 1;
	return 0;
}

void najduzi_bp (char *s1, char*s2) {
	
	char *p = s1;
	char *q1 = s1;
	char *q2 = s1;
	char *poc = s1;
	char *kraj = s1;
	int br[100] = {0}, i=0, n=0, max=0;
	
	while (*s1!='\0') {
		p = s1;
		q1 = p;
		
		while (slovo(*p)==1 && *p!='\0' && *p!=' ') {
			if (br[*p] == 0) {
				if (veliko(*p)==1) {
					n = *p + 32;
					br[n]++;
				}
				else br[*p]++;
				p++;
			}
			else break;
		}
	
		q2 = p;
		if (q2 - q1 > max) {
			max = q2 - q1;
			poc = q1;
			kraj = q2;
		}
		
		for (i=0; i<100; i++) {
			br[i] = 0;
		}
	
		s1++;
	
		if (*s1 == ' ') s1++;
	}
		
	while (poc!=kraj) {
		*s2 = *poc;
		poc++;
		s2++;
	}
	*s2='\0';
}
	

int main() {
	return 0;
}
