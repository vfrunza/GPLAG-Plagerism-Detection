#include <stdio.h>
 

 
void izbacivanje(char* str1ng, int vel) {
	while(*(str1ng+vel)) {
		*str1ng=*(str1ng+vel);
		str1ng++;
	}
	*str1ng=*(str1ng+vel);
}
 
char* izbaci_najcescu(char* string) {
 
	char *max = string, *p = string, *pocetak, *kraj, *temp, *sljedeciPocetak, *sljedeciKraj, *temp1, *p2, *p3;
	int vel1, BrojRijeci=0, vel2, jednaka, vel3, maxBrojRijeci=0, maxVelicina=0, znak;
	char znak1,znak2;
 
 
	if (*p == '\0') return string;
	while(*p != '\0') {
		while((*p < 'A' || (*p > 'Z' && *p < 'a') || *p > 'z') && *(p+1) != '\0') p++;
			if(*p != '\0') {
				//Odredivanje prvog i posljednjeg slova trenutne rijeci
				pocetak = p;
				kraj = p;
				vel1 = 1;
				while(((*(kraj+1) >= 'A' && *(kraj+1) <= 'Z') || (*(kraj+1) >= 'a' && *(kraj+1) <= 'z')) && *(kraj+1) != '\0') {
					vel1++;
					kraj++;
				}
				BrojRijeci=1;
				temp=kraj+1;
 
				while (*temp != '\0') {
					
					sljedeciPocetak=temp;
 
					while ((*sljedeciPocetak < 'A' || (*sljedeciPocetak > 'Z' && *sljedeciPocetak < 'a') || *sljedeciPocetak > 'z') && *(sljedeciPocetak+1) != '\0') sljedeciPocetak++;
					sljedeciKraj = sljedeciPocetak;
					vel2=1;
 
					while(((*(sljedeciKraj+1) >= 'A' && *(sljedeciKraj+1) <= 'Z') || (*(sljedeciKraj+1) >= 'a' && *(sljedeciKraj+1) <= 'z')) && *(sljedeciKraj+1) != '\0') {
						vel2++;
						sljedeciKraj++;					
					}					
					jednaka=1; vel3=0;
 
					temp1=pocetak;
 
					if (vel1 != vel2 ) jednaka=0;
					else 
					while (vel3 < vel2) {
 
						if(*temp1 >= 'A' && *temp1 <= 'Z') znak1=(*temp1) + ('a' - 'A');
						else znak1=*temp1;
 
						if(*sljedeciPocetak >= 'A' && *sljedeciPocetak <= 'Z') znak2=(*sljedeciPocetak) + ('a' - 'A');
						else znak2=*sljedeciPocetak;
 
						if(znak1 != znak2) jednaka=0;
 
						temp1++; sljedeciPocetak++; vel3++;
 
					}
 
					if(jednaka) BrojRijeci++;
					temp=sljedeciKraj+1;
 
				}
 
				if(BrojRijeci>maxBrojRijeci ) {
				maxBrojRijeci=BrojRijeci;
				max=kraj;
				maxVelicina=vel1;
				}
			}
			p=kraj+1;
	}

	p=temp-1;
	while (p>=string) {
		znak=0;
		if((*(p+1) < 'A' || (*(p+1)>'Z' && *(p+1)<'a') || *(p+1)>'z') || *(p+1)=='\0') znak=1;
 
		if(*p>='A' && *p<='Z') znak1=(*p)+('a'-'A'); 
		else znak1=*p;
 
		if(*max >= 'A' && *max <='Z') znak2=(*max)+('a'-'A'); else znak2=*max;
 
 
 
		if(znak1==znak2 && znak){
			p3=p;
			p2=max;
			vel2=0;
			jednaka=1;
 
			while(p3>=string && (( *p3>='A' && *p3  <= 'Z') || (*p3>= 'a' && *p3 <= 'z'))) {
				if(p2>=string) {
					if(*p2>='A' && *p2<= 'Z') znak1=(*p2)+('a'-'A'); 
					else znak1=*p2;
					if(*p2>='A' && *p2<= 'Z') znak2=(*p2)+('a'-'A'); 
					else znak2=*p2;
					if(znak1!=znak2) jednaka=0;
 
				}
				vel2++;
				p3--;
				p2--;
			}
			p3++;
			if(maxVelicina!=vel2) jednaka=0;
			if(jednaka==1) {
				izbacivanje(p3,vel2);
			}
		}
		p--;
	}
	return string;
}
 
int main() {
	char str1ng[400]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
	printf("%s", izbaci_najcescu(str1ng));
	return 0;
 
}