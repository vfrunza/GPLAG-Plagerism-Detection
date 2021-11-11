#include <stdio.h>

//funkcija koja izbacuje rijec iz stringa 

void izbacivanje(char* str1ng, int vel) {
	while(*(str1ng+vel)) {
		*str1ng=*(str1ng+vel);
		str1ng++;
	}
	*str1ng=*(str1ng+vel);
}

char* izbaci_najcescu(char* str) {
	
	char *max = str, *p = str, *pocetak, *kraj, *temp, *sljpocetak, *sljkraj, *tempoc, *p2, *p3;
	int vel1, broj_rijeci=0, vel2, jednaka, vel3, max_broj_rijeci=0, maxvel=0, znak;
	char c1,c2;
	
	
	if (*p == '\0') return str;
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
				broj_rijeci=1;
				temp=kraj+1;
				
				while (*temp != '\0') {
					//Odredivanje prvog i posljednjeg slova sljedece rijeci
					sljpocetak=temp;
					
					while ((*sljpocetak < 'A' || (*sljpocetak > 'Z' && *sljpocetak < 'a') || *sljpocetak > 'z') && *(sljpocetak+1) != '\0') sljpocetak++;
					sljkraj = sljpocetak;
					vel2=1;
					
					while(((*(sljkraj+1) >= 'A' && *(sljkraj+1) <= 'Z') || (*(sljkraj+1) >= 'a' && *(sljkraj+1) <= 'z')) && *(sljkraj+1) != '\0') {
						vel2++;
						sljkraj++;
					
					}
					
					jednaka=1; vel3=0;
					
					tempoc=pocetak;
					
					if (vel1 != vel2 ) jednaka=0;
					else 
					while (vel3 < vel2) {
						
						if(*tempoc >= 'A' && *tempoc <= 'Z') c1=(*tempoc) + ('a' - 'A');
						else c1=*tempoc;
						
						if(*sljpocetak >= 'A' && *sljpocetak <= 'Z') c2=(*sljpocetak) + ('a' - 'A');
						else c2=*sljpocetak;
						
						if(c1 != c2) jednaka=0;
						
						tempoc++; sljpocetak++; vel3++;
						
					}
					
					if(jednaka) broj_rijeci++;
					temp=sljkraj+1;
					
				}
				
				if(broj_rijeci>max_broj_rijeci ) {
				max_broj_rijeci=broj_rijeci;
				max=kraj;
				maxvel=vel1;
				}
			}
			p=kraj+1;
	}
	//izbacivanje najcesce rijeci
	p=temp-1;
	while (p>=str) {
		znak=0;
		if((*(p+1) < 'A' || (*(p+1)>'Z' && *(p+1)<'a') || *(p+1)>'z') || *(p+1)=='\0') znak=1;
		
		if(*p>='A' && *p<='Z') c1=(*p)+('a'-'A'); 
		else c1=*p;
		
		if(*max >= 'A' && *max <='Z') c2=(*max)+('a'-'A'); else c2=*max;
		
		
		
		if(c1==c2 && znak){
			p3=p;
			p2=max;
			vel2=0;
			jednaka=1;
			
			while(p3>=str && (( *p3>='A' && *p3  <= 'Z') || (*p3>= 'a' && *p3 <= 'z'))) {
				if(p2>=str) {
					if(*p2>='A' && *p2<= 'Z') c1=(*p2)+('a'-'A'); 
					else c1=*p2;
					if(*p2>='A' && *p2<= 'Z') c2=(*p2)+('a'-'A'); 
					else c2=*p2;
					if(c1!=c2) jednaka=0;
					
				}
				vel2++;
				p3--;
				p2--;
			}
			p3++;
			if(maxvel!=vel2) jednaka=0;
			if(jednaka==1) {
				izbacivanje(p3,vel2);
			}
		}
		p--;
	}
	return str;
}

int main() {
	char str1ng[400]=" zghklkvedza zvezda zdvdwa";
	printf("%s", izbaci_najcescu(str1ng));
	return 0;
	
}
