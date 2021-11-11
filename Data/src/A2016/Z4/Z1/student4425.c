#include <stdio.h>

char* izbaci_najcescu (char* s) {
	char* vrati = s;
	
	int duzina_stringa=0, counter, brojac, max=0, len, ostatak, i, izbaci, flag;
	char* kick;
	char* pok;
	char* kickk;
	char pomocni[100];
	
	while (*s != '\0') {
		if (!(*s>='A' && *s<='Z') || !(*s>='a' && *s<='z')) {
			s = vrati;
			*s = '\0';
			return vrati;
		}
		duzina_stringa++; //možda zatreba
		s++;
	} s=vrati;
	
	while (*s != '\0') {
		counter = 0; brojac = 0;
		
		if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			
			kick = s;
			while (((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
				brojac++;
				s++;
			}
			
			counter++; //uzeli smo jednu riječ, i njen count je automatski 1, idemo vidjeti ima li ih još?
			while (*s != '\0') {
				sth2:
				if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
					flag=0;
					pok=s;
					for (i = 0; i<brojac; i++) {
						if ((*(s+brojac)>='A' && *(s+brojac)<='Z') || (*(s+brojac)>='A' && *(s+brojac)<='Z')) {
							s++;
							goto sth2;
						}
						if (*(kick+i) == *(s+i)) flag=1;
						else flag=0;
					}
					if (flag==1) counter++;
				}
				
				if (counter > max) {
					max = counter;
					kickk = kick;
					len = brojac;
				}
				
				s++;
			}
			
		}
		s++;
	}
	
	i=0;
	while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
		*kickk = pomocni[i];
		i++;
		kick++;
	} pomocni[i] = '\0';
	kick = pomocni[0];
	
	printf ("%s", pomocni);
	
	brojac = len;
	while (*s != '\0') {
		sth:
		if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			if ((*(s+brojac)>='A' && *(s+brojac)<='Z')|| (*(s+brojac)>='A' && *(s+brojac)<='Z')) {
					while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) s++;
					goto sth;
			}
			
			for (i=0; i<len; i++) {
				if(*(kick+i) == *(s+i)) izbaci = 1;
			}
			
			if (izbaci == 1) {
				
				pok = s;
				while (*pok!='\0') {
					ostatak++;
					pok++;
				} 
				
				for (i=0; i<=ostatak;i++) {
					*s = *(s+len);
					s++;
				}
			}
			
			s=pok;
		}
		
		s++;
	}
	
	return vrati;
}

int main() {
	return 0;
}