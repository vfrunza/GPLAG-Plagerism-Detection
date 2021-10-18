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

char* izbaci_najcescu(char *s){
	char* restart=s;
	int prviPut = 1;
	int prvaNajcesca=1;
	int obrisiPrvuNajcescu=1;
	int br,max_br_ponavljanja=0,iste;
	char *nastavak, *pocetak_reci, *kraj_reci, *pocetak_reci1, *kraj_reci1, *prva_rijec, *druga_rijec, *pocetak_najcesce_rijeci, *kraj_najcesce_rijeci;
	
	while(*s!='\0'){
		/*Prepoznajemo pocetak neke rijeci*/
		if(((*s>='a'&& *s<='z') || (*s>='A'&& *s<='Z')) && (s==restart || (!(*(s-1)>='a'&& *(s-1)<='z') && !(*(s-1)>='A'&& *(s-1)<='Z')))){
			pocetak_reci=s;
		/*Prolazimo kroz rijec*/	
			while((*s>='a'&& *s<='z') || (*s>='A'&& *s<='Z')){
				s++;
			}
		/*Kad naidjemo na nesto sto nije slovo, prepoznamo kraj rijeci*/	
			if(!(*s>='a'&& *s<='z') && !(*s>='A'&& *s<='Z')) {
				kraj_reci=s;
				br=0;
		/*Obiljezenu rijec trazimo u ostatku stringa*/		
				nastavak=s;
				
				while(*nastavak!='\0'){
				    if(((*nastavak>='a'&& *nastavak<='z') || (*nastavak>='A'&& *nastavak<='Z')) && (nastavak==s || (!(*(nastavak-1)>='a'&& *(nastavak-1)<='z') && !(*(nastavak-1)>='A'&& *(nastavak-1)<='Z')))){
				    	pocetak_reci1=nastavak;
				    	while((*nastavak>='a'&& *nastavak<='z') || (*nastavak>='A'&& *nastavak<='Z')){
				    		nastavak++;
				    	}	
				    	if(!(*nastavak>='a'&& *nastavak<='z') && !(*nastavak>='A'&& *nastavak<='Z')){
				    		kraj_reci1=nastavak;
				    		/*Poredimo dvije rijeci*/
				    		iste=1;
				    		prva_rijec=pocetak_reci;
				    		druga_rijec=pocetak_reci1;
				    		while(*druga_rijec!=*kraj_reci1){
				    			if(*prva_rijec++!=*druga_rijec++)iste=0;
				    		}
				    		if(iste==1){
				    			br++;
				    			
				    		}
				    	}
				    }
		      if(*nastavak=='\0')break;
			  else
		      nastavak++;}
		      /*Rijec koja se javlja maksimalan broj puta obiljezimo kao najcescu rijec*/
		      if(br>max_br_ponavljanja){
		      	max_br_ponavljanja=br;
		      	pocetak_najcesce_rijeci=pocetak_reci;
		      	kraj_najcesce_rijeci=kraj_reci;
		      }
		      else
		      /*Ukoliko se nema najcesce rijeci*/
		      if(br==0 && prviPut){
		      	prviPut = 0;
		      	pocetak_najcesce_rijeci=pocetak_reci;
		      	kraj_najcesce_rijeci=kraj_reci;
		      }
			}
		}
		
     if(*s=='\0')break;
     else
     s++;}
     
     
    s=restart;
	 /* Dalje izbacujemo najcescu rijec ponovo prolazeci kroz string*/
	while(*s!='\0'){
		if(((*s>='a'&& *s<='z') || (*s>='A'&& *s<='Z')) && (s==restart || (!(*(s-1)>='a'&& *(s-1)<='z') && !(*(s-1)>='A'&& *(s-1)<='Z')))){
			pocetak_reci=s;
			while((*s>='a'&& *s<='z') || (*s>='A'&& *s<='Z')){
				s++;
			}
			if(!(*s>='a'&& *s<='z') && !(*s>='A'&& *s<='Z')){
				kraj_reci=s;
			
				iste=1; 
				prva_rijec=pocetak_reci;
				druga_rijec=pocetak_najcesce_rijeci;
				
                 while(druga_rijec!=kraj_najcesce_rijeci){
                 	if(*prva_rijec++!=*druga_rijec++)iste=0;
                 }
                 if((*prva_rijec>='A' && *prva_rijec<='Z') || (*prva_rijec>='a' && *prva_rijec<='z')) iste=0;
                 if(iste==1 && !prvaNajcesca){
                 	while(*kraj_reci!='\0'){
                 		*pocetak_reci++=*kraj_reci++;
                 	
                 	}
                 	*pocetak_reci='\0';
                    s=s-(kraj_reci-pocetak_reci);
                 	
                 }
                 if(iste==1) prvaNajcesca=0;
				}
			}
			if(*s=='\0'){
				if(!obrisiPrvuNajcescu)break;
				s=restart;
				obrisiPrvuNajcescu=0;
			}
			else
	        s++;
		}
    
     return restart;
} 




int main() {
	char s[100];
	unesi(s,100);
	
	printf("%s",izbaci_najcescu(s));
	
	return 0;
}

