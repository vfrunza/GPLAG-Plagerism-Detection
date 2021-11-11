#include <stdio.h>
void unesi(char* s, int velicina){
	char znak = getchar();
	int i;
	if(znak == '\n') znak=getchar();
	i=0;
	while(i<velicina && znak != '\n'){
		*s = znak;
		znak = getchar();
		i++;
		s++;
	}
	*s = '\0';
}


int rijec(char* s){
	if((*s != ' ' && *s != '\0')){
		return 1;
	}else{
		return 0;
	}
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* s=tekst;
	char* p;
	char* kraj;
	char* niz;
	char* q;
	char* niz1[20000];
	char* niz2[20000];
	int neslovo=1, broj=0, i, promjeni[10000], broj1=0, duzina=0, prom=0, j=0, temp, max;
	
	while(*s != '\0'){
		if(!(rijec(s))){
			neslovo = 1;
		}else if(neslovo == 1){
			neslovo = 0;
		    niz1[broj] = s;
		    kraj=s;
		    while(*kraj != '\0' && rijec(kraj)){
		    	kraj++;
		    }
		    niz2[broj] = kraj;
			broj++;
		}
		s++;
	}
	prom=0;
	for(i=0; i<broj_rijeci; i++){
		niz=rijeci[i];
		duzina=0;
		while(*niz != '\0'){
			duzina++;
			niz++;
		}
		for(j=0; j<broj; j++){
			kraj = niz1[j];
			niz = rijeci[i];
			broj1=0;
			while(*kraj != '\0' && *kraj != *niz2[j] && *niz != '\0'){
				if(*niz == *kraj){
					broj1++;
				}else{
					break;
				}
				niz++;
				kraj++;
			}
			if(broj1 == duzina && !(rijec(kraj)) && *niz == '\0'){
				promjeni[prom] = j;
				prom++;
			}
		}
		
	}
	for(i=0; i<prom; i++){
		max=i;
		for(j=i+1; j<prom; j++){
			if(promjeni[j]>promjeni[max]){
				max=j;
			}
		}
		temp = promjeni[i];
		promjeni[i]=promjeni[max];
		promjeni[max]=temp;
	}
	
	for(i=0; i<prom; i++){
		p = niz1[promjeni[i]];
		kraj = niz2[promjeni[i]]-1;
		for(j=0; j<broj_rijeci; j++){
			niz=rijeci[j];
			duzina=0;
			while(*niz != '\0'){
				duzina++;
				niz++;
			}
			s=zamjene[j];
			broj=0;
			while(*s != '\0'){
				broj++;
				s++;
			}
			p=niz1[promjeni[i]];
			s=zamjene[j];
			niz=rijeci[j];
			broj1=0;
			while(*p != '\0' && *niz != '\0' && *p != *(kraj+1)){
				if(*p == *niz){
					broj1++;	
				}else{
					broj1=0;
					break;
				}
				p++;
				niz++;
			}
			p = niz1[promjeni[i]];
			niz=rijeci[j];
			q=p;
			while(*q != '\0'){
				q++;
			}
			if(duzina==broj1 && broj > duzina){
				while(q>kraj){
					*(q+broj-duzina)=*q;
					q--;
				}
				while(*s != '\0'){
					*p = *s;
					p++;
					s++;
				}
				break;
			}else if(duzina==broj1 && broj<duzina){
				kraj = niz2[promjeni[i]];
				q=kraj-(duzina-broj);
				while(*q++ = *kraj++);
				
				while(*s != '\0'){
					*p = *s;
					p++;
					s++;
				}
				break;
			}else if(duzina == broj1 && broj==duzina){
				while( *s != '\0'){
					*p=*s;
					p++;
					s++;
				}
				break;
			}
		    
		}
	}
	
	return tekst;
}

int main() {
	
	char tekst[200];
	char* rijeci[3] = {"test"};
	char* zamjene[3] = {"zamjena"};
	printf("Unesite tekst: ");
	unesi(tekst, 100);
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));

	return 0;
}
