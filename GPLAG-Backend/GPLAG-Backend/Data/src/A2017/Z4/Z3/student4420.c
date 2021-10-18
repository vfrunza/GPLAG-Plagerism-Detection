#include <stdio.h>
		char velika ( char a) {
			if ( a>='a' && a<='z' ) return a-32;
			else return a;
			return a;
		}

	void najduzi_bp(char *s1, char *s2) {
		int brojac=0;
		int kontrola=0;
		char *max1;
		char *s4;
		char *s5,*s6;
		char *help1,*help2;
		int max=0,brojac2=0;
		char *s3;
		s3 = s1;
		while( *s3 != '\0') {
			while (*s3 != '\0' && !(*s3 >='a' && *s3 <='z' || *s3>='A' && *s3<='Z')) {
				s3++;
			}
			brojac=1;
			s5 = s3;
			if(*s3 != '\0')
				s4 = s3+1;
			else break;
			while(*s4 != '\0' &&(*s4 >= 'a' && *s4 <= 'z' || *s4 >= 'A' && *s4 <= 'Z')) {
				s5 = s3;
				kontrola = 0;
				while(s5 < s4){
					if(velika(*s4) == velika (*s5)){
						kontrola = 1;
						break;
					}
					s5++;
				}
				if(kontrola) break;
				s4++;
			}
			s5 = s3;
				brojac=1;
				s3 = s5;
				brojac = s4 - s5;
				s5 = s3;
			s6=s4;
			if(brojac>max) {
				help1 = s5;
				help2 = s6;
				max = brojac;
			}
			//s3=s4;
			if ( *s3 == '\0') continue;
			s3++;
		}
		max1=s2;
		while ( help1 < help2) {
			*s2 = *help1;
			help1++;
			s2++;
		}
		*s2 = '\0';
		s2=max1;	
	}
		
		

int main() {
char niz[10];
        najduzi_bp ("abcde etankera cdefg", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}
