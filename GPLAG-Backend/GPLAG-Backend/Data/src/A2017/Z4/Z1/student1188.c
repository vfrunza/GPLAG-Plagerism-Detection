#include <stdio.h>

int obrni_broj(int n){
	int broj=0;
	while(n!=0){
		broj = n%10 + broj*10;
		n/=10;
	}
	return broj;
}

char* ubaci_broj(char *s, int n){
	int br_rijeci=0, duzina=0, br_razmaka=0, br_nula=0;
	int razmak=1, pozitivan=1;
	int obrnuti, temp;
	char *q, *p_pom=s;
	
	
	if(n<0)	{
		duzina++; /*jer brojac uključuje minus */
		pozitivan=0;
		n=-n;
	}
	
	obrnuti=obrni_broj(n);
	temp=n;
	while(temp != 0 && temp%10==0) {
		br_nula++;		 /* za slučaj kad je broj npr 320.. fji obrni cifre treba pomoć a to je brojač nula */
		temp/=10;
	}
	temp=n;
	do{
		duzina++;
		temp/=10;
	}while(temp != 0);
	
	
	while(*s != '\0' && *s == ' ') s++; 	/* zbog razmaka ispred prve riječi */

	while(*s != '\0'){
		if(*s == ' ') {
			br_razmaka++;
			razmak=1;
		}
		else if(razmak==1){
			razmak=0;
			br_rijeci++;
			if(br_rijeci>1){
				q=s;
				while(*q != '\0') q++;
				
				while(q>=s-br_razmaka+1){ 	
					if(br_razmaka==1)	*(q+duzina+1)=*q;		 /* +1 zbog razmaka nakon broja */
					else *(q+duzina)=*q; 						/* neće se dodavati razmak nakon broja */
					q--;
				}
				
				q++; 	/*pomjeri q iza (prvog) razmaka */
			
			
				if(!pozitivan)	*q++='-';
				
			
				temp=obrnuti;
				do{
					*q++=temp%10 + '0';
					temp/=10;
				}while(temp != 0);
				
				
				{   int i=br_nula;
					while(i>0){
						*q++='0';
						i--;
					}
				}
				
				if(br_razmaka==1) *q++=' ';
				s=q+br_razmaka-1;
				br_razmaka=0;
				
			}
		}
		
		s++;
	}
	
	
	return p_pom;
}

int main() {
	char tekst[44] ="O      e e f d dd .      "; /*"  Dv   rij   jos  ";"Ovdje  izmedju    rijeci ima      po nekoliko   razmaka"; */
	printf("/%s/", ubaci_broj(tekst, 322));
	return 0;
}
