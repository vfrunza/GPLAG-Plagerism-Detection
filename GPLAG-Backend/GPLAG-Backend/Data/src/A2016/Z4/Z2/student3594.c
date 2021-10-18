#include <stdio.h>

char* kodiraj (char *s, char *q){
	
	char *p, *r;
	int i, j, pom;
	char pom2;
	char slova [95];
	char brojaci [95];
	
	for(i=0; i<95; i++){
		slova[i] = 32 + i;
		brojaci[i] = 0;
	}
	
	p = s;
	while(*p != '\0'){
		if(*p >= 32 && *p<=126){
			brojaci[*p-32]++;
		}
		p++;
	}
	
	for(i=0; i<95; i++){
		for(j=i; j<95; j++){
			if(brojaci[j] > brojaci[i] || (brojaci[j] == brojaci[i] && slova[j] < slova[i])){
				pom = brojaci[i];
				brojaci[i] = brojaci[j];
				brojaci[j] = pom;
				pom2 = slova[i];
				slova[i] = slova [j];
				slova[j] = pom2;
			}
		}
	}
	
	r=q;
	for(i=0; i<95; i++){
		*r = slova[i];
		r++;
	}
	*r = '\0';
	p=s;
	while(*p != '\0'){
		i=0;
		while(i<95){
			if(*p == slova [i]){
			break;	
			} 
			i++;
		}
		*p = 126-i;
		p++;
	}
	return s;
}

char* dekodiraj(char *s, char *q){
	char *p = s;
	while(*p != '\0'){
		*p = q[126-*p];
		p++;
	}
	return s;
}




int main() {

	return 0;
}
