#include <stdio.h>

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char *p=tekst, *p2, *p3;
	int duzina=0, i, i2, j, postoji_rijec, jednake, rvel, vel, vel2, brpomjeranja=0;
	
	while (*p!='\0') {
		duzina++;
		p++;
	}
	p=tekst;
	
	while (*p != '\0') {
		 //trazenje rijeci koju treba zamijeniti
		if(( p==tekst || *(p-1)==' ') && *p!=' ') {
			postoji_rijec=0;
			for( i = 0; i < broj_rijeci; i++) {
				jednake=1;
				j=0;
				rvel=0;
				p2=p;
				
				while (*p2 != '\0' && *p2 !=' ' && rijeci[i][j]!= '\0') {
					if( *p2!=rijeci[i][j]) jednake =0;
					p2++;
					j++;
					rvel++;
				}
				if(rijeci[i][j] != '\0' || (rijeci[i][j]=='\0' && *p2 != '\0' && *p2 != ' '))
					jednake=0;
					
				if(jednake) {
					i2=i;
					postoji_rijec=1;
					vel=rvel;
				}
					
			}
			
		if(postoji_rijec) {
			//zamjena rijeci koje imaju isti indeks
			p2=p;
			j=0;
			vel2=0;
			while(zamjene[i2][j]!='\0') {
				vel2++;
				j++;
			}
			//u slucaju da je rijec koju mjenjamo kraca od zamjenske pomjeramo tekst
			if(vel2>=vel) {
				for(i=vel; i<vel2; i++){
					p3=tekst + duzina + 1 + brpomjeranja;
					brpomjeranja++;
					while (p3>p2) {
						*p3=*(p3-1);
						p3--;
					}
				}
			}
			//u slucaju da je suprotna situacija
			else {
				for( i=vel2; i<vel; i++) {
					p3=p2;
					brpomjeranja--;
					while(p3 < tekst+duzina) {
						*p3=*(p3+1);
						p3++;
					}
					duzina--;
				}
			}
			j=0;
			
			//zamjena rijeci
			while (zamjene[i2][j] != '\0') {
				*p2=zamjene[i2][j];
				p2++;
				j++;
			}
			
		}
		}
		p++;
		
	}
	return tekst;
}
int main() {
	
	char* rijeci[2] = { "beli", "sneg"};
	char* zamjene[2] = { "bijeli", "snijeg"};
	char tekst[10000]= "beli sneg je pokrio beli breg";
	
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	
	return 0;
}
