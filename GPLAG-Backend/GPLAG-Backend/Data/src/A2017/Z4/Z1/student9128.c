#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* ubaci_broj (char* s, int broj) {
	char* povratni=s, *temp, *pom, *kraj;
	int duzina=0, isti_broj=broj, slovo=1, broj_rijeci=0, i=0, razmak=1, post_razmak=0, negativan=0, broj_razmaka=1;
	
	//post_razmak - poslije koje rijeci se nalazimo u stringu
	
	if(isti_broj<0) {
		isti_broj*=-1;
		negativan=1;
		duzina++;
	}
	while(isti_broj!=0) {
		isti_broj/=10;
		duzina++;
	}
	if(broj<0) isti_broj=broj*(-1);
	else isti_broj=broj;
	while(*s==' ') s++;

	pom=s;
	while(*pom!=0) {
		if(*pom==' ') razmak=1;
		else if(razmak==1) {
			razmak=0;
			broj_rijeci++;
		}
		pom++;
	}
	
	while(*s!=0) {
		if(*s!=' ') slovo=1;
		else if (slovo==1) {
			post_razmak++;
			if(post_razmak>=broj_rijeci) {
				break;
			}
			if(*(++s)!=' ') {
				slovo=0;
				temp=s;
				s--;
				while(*temp!=0) {
					temp++;
				}
				while(temp!=s) {
					*(temp+duzina+1)=*temp;
					temp--;
				}
				while(i<duzina+2) {
					*temp++=' ';
					i++;
				}
				s=temp-1;
				i=0;
				temp-=2;
				while(i<duzina) {
					*temp=(isti_broj%10)+'0';
					isti_broj/=10;
					if(i==duzina-1 && negativan==1) *temp='-';
					temp--;
					i++;
				}
				i=0;
				if(negativan) isti_broj=broj*(-1);
				else isti_broj=broj;
			} 
			else if(*(s)==' ') {
				slovo=0;
				s--;
				temp=s+1;
				while(*temp==' ') {
					broj_razmaka++;
					temp++;
				}
				while(*temp!=0) temp++;
				while(temp!=s) {
					*(temp+duzina)=*temp;
					temp--;
				}
				while(i<duzina+broj_razmaka) {
					*temp++=' ';
					i++;
				}
				s=temp-1;
				i=0;
				temp-=broj_razmaka;
				while(i<duzina) {
					*temp=(isti_broj%10)+'0';
					isti_broj/=10;
					if(i==duzina-1 && negativan==1) *temp='-';
					temp--;
					i++;
				}
				i=0;
				broj_razmaka=0;
				if(negativan) isti_broj=broj*(-1);
				else isti_broj=broj;
			}
		}
		s++;
	}
	
	return povratni;
}

int main() {
	char s[1000];
	int broj;
	printf("Unesi string: \n");
	unesi(s, 1000);
	printf("Unesi broj: \n");
	scanf("%d", &broj);
	printf("Sad string glasi: \n");
	printf("%s", ubaci_broj(s, broj));
	return 0;
}
