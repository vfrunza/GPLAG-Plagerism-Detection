#include <stdio.h>
char* kodiraj(char* tekst, char* sifranik){
	char *vrati,*s,*pomocni,*p,*q;
	int brojac[200]={0},max=0,i,NULA=0,NEMA,broja=0,br=0,K;
	p=tekst;
	vrati=sifranik;
	q=sifranik;
	while(*p!='\0'){
		K=*p;
		brojac[K]++;
		p++;
	}
	for(i=0;i<98;i++){
		*sifranik=32;
		sifranik++;
	}
	*sifranik='\0';
	s=vrati;
	max=brojac[0];
	for(;;){
		for(i=0;i<127;i++){
			if(brojac[i]>max){
			max=brojac[i];
			*s=i;
			}
		}
		for(i=0;i<127;i++)
			if(max==brojac[i])
				if(brojac[i]<max){
					max=brojac[i];
					*s=i;
				}
		for(i=0;i<127;i++)
			if(max==brojac[i]){
				brojac[i]=0;
				break;
			}
		broja++;
		/*Provjeravamo da li je citav niz brojac[] postavljen na nulu*/
		NULA=1;
		for(i=0;i<127;i++)
			if(brojac[i]!=0)
				NULA=0;
		s++;
		if(NULA)
			break;
		if(*s=='\0')
			break;
		max=0;
	}
	
	*s='\0';
	for(i=32;i<127;i++){
		NEMA=1;
		sifranik=vrati;
		while(br<=broja){
			if(*sifranik==i)	
				NEMA=0;
			sifranik++;
			br++;
		}
		br=0;
		if(NEMA){
			*s=i;
			s++;
		}
	}
	*s='\0';
	br=0;
	vrati=tekst;
	pomocni=q;
	/*Kodiramo string "tekst"*/
	while(*tekst!='\0'){
		q=pomocni;
		while(*q!=*tekst){
			br++;
			q++;
			if(*q=='\0')
				break;
		}
	*tekst=126-br;
	tekst++;
	br=0;
	}
	return vrati;
}
char *dekodiraj(char* tekst,char* sifranik){
	char*t,*s,*vrati;
	int i;
	vrati=tekst;
	t=tekst;
	s=sifranik;
	i=126;
	while(*t!='\0'){
		for(i=126;i>=0;i--){	
			if(*t==i){
				*t=*s;
				break;
			}
			s++;
			if(*s=='\0')
				break;
		}
		s=sifranik;
		t++;
	}
	return vrati;
}
void unesi(char niz[], int velicina){
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int main(){
    char tekst[80];
    char sifranik[100];
    printf("Unesi : ");
    unesi(tekst,80);
	kodiraj(tekst,sifranik);
	dekodiraj(tekst,sifranik);
    printf("%s",tekst);
	return 0;
}