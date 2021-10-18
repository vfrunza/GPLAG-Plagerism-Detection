#include <stdio.h>

void unesi(char* s, int broj){
	char znak = getchar();
	int i;
	if(znak == '\n') znak=getchar();
	i=0;
	while(i<broj && znak!='\n'){
		s[i]=znak;
		znak= getchar();
		i++;
	}
	s[i]='\0';
}

int rijec(char* s){
	if((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')){
		return 1;
	}else{
		return 0;
	}
}

int veliko_malo(char* s, char* p){
	if(*s == *p){
		return 1;
	}else if(*s + 32 == *p){
		return 1;
	}else if(*s == *p + 32){
		return 1;
	}
	return 0;
}

char* izbaci_najcescu(char* s){
	char* pocetak = s;
	char* p;
	char* poc;
	char* q;
	char* kraj;
	char* niz[100000];
	char* niz1[100000];
	
	int neslovo=1, broj=0, k=1, i=0, j=0, brojaci[50000], max=0, f, index;
	
	while(*s != '\0'){
		if(!(rijec(s))){
			neslovo = 1;
		}else if(neslovo == 1){
		    neslovo=0;
		    niz[broj]=s;
		    kraj=s;
		    while(*kraj != '\0' && rijec(kraj)){
		    	kraj++;
		    }
		    niz1[broj]=kraj;
			broj++;
		}
		s++;
	}
	
	s=pocetak;
	neslovo=1;
	for(f=0; f<50000; f++){
		brojaci[f]=1;
	}
	
	for(f=0; f<broj; f++){   						 /* Brojimo koliko se svaka od rijeci ponavlja u stringu */
		    k=f+1;
			while(k<broj){
				p = niz[f];
				kraj = niz1[f];
				poc=niz[k];
				q=niz1[k];
				j=0;
				while(*p != '\0' && *poc != '\0' && *p != *kraj && *poc != *q){
					if(veliko_malo(p, poc)){
						j++;
						p++;
				    	poc++;
					}else{
						break;
					}
				}
				if((j==(niz1[f]-niz[f]))&&(j==(niz1[k]-niz[k]))){
			        brojaci[f]++;
				}
				k++;
			}
			
    }
	
	max=-1;
	for(i=0; i<broj; i++){                            /* Trazimo index rijeci koja se najvise ponavlja. */
		if(brojaci[i]>max && brojaci[i]>1){
			max=brojaci[i];
			index = i;
		}
	}
	
	for(f=0; f<50000; f++){
		brojaci[f] = -1;
	}
	
    if(max != -1){
    	i=index;
		f = i+1;                                       /* Pronalazimo i pamtimo index rijeci koje se ponavljaju. */
		brojaci[i]=0;
		while(f<broj){
			p=niz[i];
			kraj=niz1[i];
			poc=niz[f];
			q=niz1[f];
			j=0;
			while(*p != '\0' && *poc != '\0' && *p != *kraj && *poc != *q){
					if(veliko_malo(p,poc)){
						j++;
						p++;
						poc++;
					}else{
						break;
					}	
			}
			if((j==niz1[i] - niz[i]) && (j==niz1[f] - niz[f])){
				brojaci[f]++;
			}else{
				brojaci[f]=-1;
			}
		
			f++;
		}
		
		i=broj-1;
		while(i>=0){                				/* Izbacujemo rijeci koje se nalaze pod zapamcenim indexima. */
			if(brojaci[i] != -1){
				p = niz[i];
				kraj = niz1[i];
				while(*kraj != '\0'){
					*p = *kraj;
					p++;
					kraj++;
				}
				*p=*kraj;
			}
			i--;
		}
		
    }else if(max==-1 && broj>0){    				/* Ako se svaka rijec u stringu pojavljuje jedamput, izbacujemo prvu po redu. */
    	p=niz[0];
    	kraj=niz1[0];
    	while(*kraj != '\0'){
    		*p = *kraj;
    		p++;
    		kraj++;
    	}
    	*p=*kraj;
    }
	return pocetak;
}

int main() {
	char tekst[200];
	printf("Unesite string: ");
	unesi(tekst, 200);
    printf("Novi string je: %s", izbaci_najcescu(tekst));
	
	return 0;
}
