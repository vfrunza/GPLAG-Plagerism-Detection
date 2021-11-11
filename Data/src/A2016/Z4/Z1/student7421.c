#include <stdio.h>

char u_mala(char z){
	if(z >= 'A' && z <= 'Z')
		return z + 'a' - 'A';
	return z;
}

int poredi_rijeci (char *p_rijec, int p_duzina, char *d_rijec, int d_duzina){
	if(p_duzina != d_duzina)
		return 0;
	int i = 0;
	for(; i < p_duzina; ++i)
		if(u_mala(p_rijec[i]) != u_mala(d_rijec[i]))
			return 0;
	return 1;
}

int jel_slovo(char z){
	return (z >= 'a' && z <='z') || (z >= 'A' && z <='Z');
}

int nadji_najcescu(char *s){
	int i = 0, index = -1, max = -1;
	/* prolazim kroz string */
	for(; s[i] != '\0'; ++i){
		int kraj_rijeci_1 = 1;
		if(jel_slovo(s[i]) == 0)
			kraj_rijeci_1 = 1;
		else if(kraj_rijeci_1 == 1){
			kraj_rijeci_1 = 0;
			int pocetak_1 = i;
			/* idem na kraj rijeci */
			while(s[i] != '\0' && jel_slovo(s[i]) == 1)
				++i;
			int j = i, broj_ponavljanja_rijeci = 1;
			/* trazim sljedecu rijec  */
			for(; s[j] != '\0'; ++j){
				int kraj_rijeci_2 = 1;
				if(jel_slovo(s[j]) == 0)
				kraj_rijeci_2 = 1;
				/* naso rijec */
				else if(kraj_rijeci_2 == 1){
					kraj_rijeci_2 = 0;
					int pocetak_2 = j;
					/* idem na kraj rijeci */
					while(s[j] != '\0' && jel_slovo(s[j]))
						++j;
					if(poredi_rijeci(&s[pocetak_1], i - pocetak_1, &s[pocetak_2], j - pocetak_2))
						++broj_ponavljanja_rijeci;
				}
				if(s[j] == '\0')
					break;
			}
			
			if(broj_ponavljanja_rijeci > max){
				max = broj_ponavljanja_rijeci;
				index = pocetak_1;
			}
		}
		if(s[i] == '\0')
			break;
	}
	return max == -1 ? -1 : index;
}

char *izbaci_najcescu(char *s){
	if(*s == '\0')
		return s;
	int pocetak = nadji_najcescu(s);
	if(pocetak == -1)
		return s;
	int duzina_rijeci = 0, i = pocetak;
	while(s[i] != '\0' && jel_slovo(s[i])){
		++i;
		++duzina_rijeci;
	}
	for(; s[i] != '\0'; ++i){
		int kraj_rijeci_1 = 1;
		if(jel_slovo(s[i]) == 0)
			kraj_rijeci_1 = 1;
		else if(kraj_rijeci_1 == 1){
			kraj_rijeci_1 = 0;
			int pocetak_1 = i;
			/* idem na kraj rijeci */
			while(s[i] != '\0' && jel_slovo(s[i]))
				++i;
		
			if(poredi_rijeci(&s[pocetak], duzina_rijeci, &s[pocetak_1], i - pocetak_1)){
				int k = pocetak_1, l = i;
				i = k - 1;
				for(; s[l] != '\0'; ++l, ++k)
					s[k] = s[l];
				s[k] = '\0';
			}
		}
		if(s[i] == '\0')
			break;
	}
	int k = pocetak, l = pocetak + duzina_rijeci;
	for(; s[l] != '\0'; ++l, ++k)
		s[k] = s[l];
	s[k] = '\0';
	return s;
}

int main() {
	char niz [] = "ja";
	
	izbaci_najcescu(niz);
	return 0;
}
