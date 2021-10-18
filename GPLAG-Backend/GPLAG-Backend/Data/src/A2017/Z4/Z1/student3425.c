#include <stdio.h>
void unesi (char niz[], int velicina){	/*Funkcija za unos teksta*/
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char *ubaci_broj(char *s, int broj){
	
	char *pocetak=s,*p,*q,temp;
	int br_cifara=1, kopija;
	if(broj<0) kopija=broj*(-1);
	else kopija=broj;
	if(kopija==0) br_cifara++;
	while(kopija!=0){	/*Broj cifara nam govori koliko ce nas broj u stringu zauzeti polja*/
		kopija/=10;
		br_cifara++;
	}
	if(broj<0) br_cifara++;
	p=s;
	while(*s==' ') s++;
	while(*s!='\0'){
		if(*s==' '){
			char *k=s;
			while(*k!='\0'){	/*petlja pomocu koje osiguravam ne umetanje broja poslije zadnje rijeci*/
				if(*k!=' ') break;
				k++;
			}
			if(*k=='\0') return pocetak;
			if(*(s+1)==' '){ 
				s++;
				br_cifara--;
			}
			while(*p!='\0') p++;

				
			while(p!=s){
				*(p+br_cifara)=*p;
				p--;
			}
			p+=br_cifara;
			s=p;
			*p=' ';
			p--;
			if(broj<0) kopija=-broj;
			else kopija=broj;
			if(kopija==0){	/*Specijalan slucaj broja jer jedino za ovaj broj mi nece uci u petlju za ubacivanje brojeva u string*/
				*p='0';
				p--;
			}
			
			while(kopija!=0){
				*p=(kopija%10)+'0';
				p--;
				kopija/=10;
			}
			if(broj<0) *p='-';
			while(*(s+1)==' ') s++;
		}
		s++;
	}
	
	
return pocetak;
}

int main() {
	char tekst[300],*p;
	int broj,i;
	printf("Unesi tekst: ");
	unesi(tekst,100);
	printf("\nUnesi broj: ");
	scanf("%d",&broj);
	p=ubaci_broj(tekst,broj);
/*	printf("\nKrajnji string izgleda ovako: %s",tekst); */
/*	dodaj_broj_na_kraj(tekst,broj); */
	printf("Vas tekst izgleda ovako: ");
	for(i=0;i<300;i++){
		if(p[i]=='\0') break;
		printf("%c",p[i]);
	}
	
	return 0;
}
