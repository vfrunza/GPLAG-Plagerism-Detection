#include <stdio.h>

int counter=0;

int words(const char sentence[])
{
    int counted = 0;

    const char* it = sentence;
    int inword = 0;

    do switch(*it) {
        case '\0': 
        case ' ': case '\t': case '\n': case '\r': // TODO others?
            if (inword) { inword = 0; counted++; }
            break;
        default: inword = 1;
    } while(*it++);

    return counted;
}

char *izbaci_najcescu(char *s){
	char *pocetak_stringa = s, *tmp = s;
	int broj_rijeci=1, i=1, broj_znakova=0, pamti_pocetak[100];
	int ponavljanje_rijeci[100], max_index, max, tmp_brojac=0;
	char *q, *pok;
	int br=0, istina=0;
	
	pamti_pocetak[0] = 0;
	
	if(*s==' '){
		while(!(*s>='a' && *s<='z')){
			s++;
		}
	}
	pocetak_stringa=s;
	
	if(counter==1){
		*pocetak_stringa='\0';
		return pocetak_stringa;
	}
	
	s++;
	while(*s!='\0'){
		tmp = s-1;
		if(*tmp==' ' && *s>='a' && *s<='z'){
			pamti_pocetak[i] = broj_znakova;
			i++; broj_rijeci++;
		}
		broj_znakova++; s++;
	}
	
	if(broj_rijeci==1){
		*pocetak_stringa='\0';
		return pocetak_stringa;
	}
	
	
	for(i=0; i<100; i++){
		ponavljanje_rijeci[i] = 1;
	}
	for(i=0; i<broj_rijeci-1; i++){
		s = pocetak_stringa + pamti_pocetak[i];
		q = pocetak_stringa + pamti_pocetak[i+1];
		tmp_brojac=0;
		while(*q!='\0'){
			istina=0;
			if(*s == *q){
				istina = 1;
				s++; q++;
				tmp_brojac++;
			}
			else{
				istina = 0;
				s = s - tmp_brojac;
				tmp_brojac = 0;
				q++;
			}
			if(istina == 1 && *s == ' '){
				s = s - tmp_brojac;
				tmp_brojac = 0;
				ponavljanje_rijeci[i]++;
			}
		}
	}
	
	max = ponavljanje_rijeci[i];
	for(i=0; i<broj_rijeci-1; i++){
		if(ponavljanje_rijeci[i] > max){
			max = ponavljanje_rijeci[i];
			max_index = i;
		}
	}
	
	tmp_brojac = 0, istina = 0;
	s = pocetak_stringa + pamti_pocetak[max_index];
	q = pocetak_stringa + pamti_pocetak[max_index+1];
	
	while(*q != '\0'){
		pok = q;
		if(*s == *q){
			istina=1;
			s++; q++;
			tmp_brojac++;
		}
		else{
			istina=0;
			s=s-tmp_brojac;
			tmp_brojac=0;
			q++;
		}
		if(istina==1 && *s==' '){
			pok++;
			q=q-tmp_brojac;
			s=s-tmp_brojac;
			while(*pok!='\0'){
				*q = *pok;
				q++; pok++;
				br++;
			}
			*q = '\0';
			q = q - br;
			tmp_brojac = 0;
		}
	}
	
	q=s;
	while(*s!=' '){
		s++;	
	}
	while(*s==' '){
		s++;
	}
	while(*s!='\0'){
		*q = *s;
		q++; s++;
	}
	*q = '\0';
	
	return pocetak_stringa;
}

int main() {
	char recenica[] = "Pet plus pet plus pet daje petnaest";
	counter=words(recenica);
	printf("%s", izbaci_najcescu(&recenica));
	return 0;
}