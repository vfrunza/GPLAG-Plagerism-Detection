#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void izbaci_rijec(char tekst[], char rijec[]) {
	int i=0, j=0, k, z, t, p, znakovi_tekst=0, znakovi_rijec=0;
	while(tekst[i]!='\0') {
		znakovi_tekst++;
		i++;
	}
	while(rijec[j]!='\0') {
		znakovi_rijec++;
		j++;
	}
	i=0;
	
	while(tekst[i]!='\0') {
		j=0;
		z=i;
		while(rijec[j]!='\0') {
			if(tekst[i]==rijec[j]) {
				i++;
				j++;
			}
			else break;
		}
		if(rijec[j]=='\0' && (tekst[i]<65 || (tekst[i]>90 && tekst[i]<97) || tekst[i]>122) && (tekst[i-j-1]<65 || (tekst[i-j-1]>90 && tekst[i-j-1]<97) || tekst[i-j-1]>122)) {
			k=z;
			t=0;
			while(t<znakovi_rijec) {
				p=k;
				while(p<znakovi_tekst) {
					
					tekst[p]=tekst[p+1];
					p++;
					
				}
				
				t++;
				znakovi_tekst--;
				
			}
			
		}
		else{
			if(tekst[i]!='\0') i++;
			
		}
	}
	
	tekst[znakovi_tekst]='\0';
	
}



char* izbaci_najcescu(char* s) {
	
	char rijec[100];
	int brojac, i, max_ponavljanja=0;
	char *p, *q, *z, *poc, *kraj, *poc_max, *kraj_max, *tekst=s;
	
	z=tekst;
	while(*z!='\0'){
		while((*z<65 || *z>122 || (*z<97 && *z>90)) && *z!='\0') z++;
		if(*z=='\0') return s;
		i=0;
		while((*z>=65 && *z<=90) || (*z>=97 && *z<=122)){
			if(i==0) poc=z;
			
			z++;
			i++;
			
		}
		kraj=z;
		if(*z!='\0') z++;
		
		q=tekst;
		brojac=0;
		while(*q!='\0'){
			
			p=poc;
			while(p<kraj) {
				if(*p==*q || *p==*q+32 || *p==*q-32){
					p++;
					q++;
				}
				else 
						break;
			}
			
			if((p==kraj) && (*q<65 || (*q>90 && *q<97) || *q>122) && ((*(poc-1)<65 || (*(poc-1)>90 && *(poc-1)<97) || *(poc-1)>122))) brojac++;
			else{
				if(*q!='\0')
					q++;
				
			}
			
		}
		if(brojac>max_ponavljanja){
			max_ponavljanja=brojac;
			poc_max=poc;
			kraj_max=kraj;
		}
		
	}
	
	i=0;
	if(max_ponavljanja!=0) {
		while(poc_max<kraj_max){
			rijec[i]=(*poc_max);
			i++;
			poc_max++;
		}
		rijec[i]='\0';
		
		izbaci_rijec(tekst, rijec);
		
	}
	
	return s;
	
}


int main() {
	
	char tekst[]="ovo je neki ovo";
	
	izbaci_najcescu(tekst);
	
	printf("%s",tekst);
	
		return 0;
}
