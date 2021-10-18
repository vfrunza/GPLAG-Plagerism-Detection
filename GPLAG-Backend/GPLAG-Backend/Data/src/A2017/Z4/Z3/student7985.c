#include <stdio.h>

int Slovo(char c){
	if (c>='A' && c<='Z') return 1;
	else if(c>='a' && c<='z') return 2;
	return 0;
}


void najduzi_bp(char *t, char *s){
	int max_duzina=0;
	char *krajR, *pocR, *pmax=t, *qmax=t, *kraj;
	
	kraj=t;
	while(*kraj != '\0') kraj++; 	/* kraj će pokazivati na '\0' */
	
	while(t < kraj){
		
		int ht[26]={0};
		
		while(t != kraj && !Slovo(*t)) t++; /* idi sve do početka riječi */
		pocR=t;
		
		krajR=t;
		while(krajR != kraj && Slovo(*krajR)) krajR++; /* pokazuje iza kraja riječi */
		
		
		while(t != krajR){ /* t je na početku riječi */
			
			char slovo1 = *t;
			if(Slovo(slovo1)==1) slovo1+=32;
			
				
			if(ht[slovo1-'a']==0){ /* ako se prvi put javlja */
				
				ht[slovo1-'a']=1;
				if(t+1-pocR>max_duzina){  /* +1 jer qmax će da pokazuje IZA zadnjeg validnog slova */
					max_duzina=t+1-pocR;
					pmax=pocR;
					qmax=t+1;
				}
				
			}
			else {
				if(pocR+1 != krajR) pocR++; 
				t=pocR-1; /* jer će se t povećati (t++) */
				{ int i;
				  for(i=0; i<26; i++) ht[i]=0;
				}
				
			}
			
			t++; 
		}
		
		
		t++;
	}
	
	
	while(pmax < qmax)	 *s++ = *pmax++;
	*s = '\0';
	
}

int main() {
	char podniz[100];
	char tekst[]="l4li4";
	najduzi_bp(tekst, podniz);
	printf("Niz: '%s'", podniz);
	return 0;
}
