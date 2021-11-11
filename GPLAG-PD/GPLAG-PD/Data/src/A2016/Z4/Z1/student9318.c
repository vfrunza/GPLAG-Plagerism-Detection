#include <stdio.h>

char *izbaci_najcescu(char *s){
		int br = 0,br1,ima;
		char *pocetak = NULL;
		char *p = NULL, *q = NULL , *a = NULL , niz[100] = "", izbaci[100] = "", A, B;
		pocetak = s;
		while(*s != '\0'){
				if((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z') ){
					p = niz;
					while(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z')*p++ = *s++;   *p = '\0';
					s--;
					/*prolazimo kroz citav string da izbrojimo iste rijeci */
					br1 = 0;
					a = pocetak;
					while(*a != '\0'){
							if( (*a >= 'a' && *a <= 'z') || (*a >= 'A' && *a <= 'Z')){
								q = a;
								p = niz;
								ima = 1;
								while(*p != '\0'){
									A = *p;
									B = *a;
									if(A >= 'a' && A <= 'z') A -= 32;
									if(B >= 'a' && B <= 'z') B -= 32;
									if(A != B)ima = 0;
									if(ima == 0)break;
									a++;   p++;
								}
								if(ima){
									if( (pocetak ==  q || *(q - 1) == ' ' || 
									  !( (*(q - 1) >= 'a' && *(q - 1) <= 'z') || (*(q - 1) >= 'A' && *(q - 1) <= 'Z')))
									&& (*a == ' ' || *a == '\0' || !((*a >= 'a' && *a <= 'z') || (*a >= 'A' && *a <= 'Z')) ))  br1++;
								}
							}
							if(*a != '\0')a++;
					}
					if(br1 > br){
						br = br1;
						p = niz;
						a = izbaci;
						while(*p != '\0')*a++ = *p++; 	*a = '\0';
					}
				}
			s++;
		}
	/*izbacivanje najcesce rijeci */
	a = pocetak;
	while(*a != '\0'){
							if( (*a >= 'a' && *a <= 'z') || (*a >= 'A' && *a <= 'Z')){
								q = a;
								p = izbaci;
								ima = 1;
								while(*p != '\0'){
										A = *p;
										B = *a;
									if(A >= 'a' && A <= 'z') A -= 32;
									if(B >= 'a' && B <= 'z') B -= 32;
									if(A != B)ima = 0;
							if(ima == 0)break;
									a++; p++;
								}
								if(ima){
							if( (pocetak ==  q || *(q - 1) == ' ' || 
									  !( (*(q - 1) >= 'a' && *(q - 1) <= 'z') || (*(q - 1) >= 'A' && *(q - 1) <= 'Z')))
									&& (*a == ' ' || *a == '\0' || !((*a >= 'a' && *a <= 'z') || (*a >= 'A' && *a <= 'Z')) )){
								
									p = q;
									while(*a != '\0'){
										*p++ = *a++;	}
									*p = '\0';
									a = q;
									a--;
									}
								}
						}
				a++;
			}
	return pocetak;
}


int main() {
	char t[] = "Danas je lijep dan";
printf("'%s'", izbaci_najcescu(t));
return 0;
}