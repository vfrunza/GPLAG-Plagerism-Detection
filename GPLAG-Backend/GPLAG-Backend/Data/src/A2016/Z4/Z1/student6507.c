#include <stdio.h>

char* izbaci_najcescu(char* niz){
	char* p= niz;
	char* q=niz;
	char* s=niz;
	char* maxi=niz;
	char* x=niz;
	int istina=0, brojac=1, max=0;
	/*Pronalazak rijeci koja se najvise ponavlja*/
	while(*p != '\0'){
		while(*q != '\0'){
			istina=0;
			while((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) q++;
			while((!((*q>='A' && *q<='Z') || (*q>='a' && *q<='z'))) && *q != '\0') q++;
			if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && (*p==*q || *p==*q-32 || *p==*q+32)){
				s=p;
				while(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && (*p==*q || *p==*q-32 || *p==*q+32)){
					p++;
					q++;
				}
				if((!((*q>='A' && *q<='Z') || (*q>='a' && *q<='z'))) && (!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')))){
					brojac++;
					istina=1;
				}
				if(istina==1) p=s;
			}
		}
		if(brojac>max){
			max=brojac;
			maxi=s;
		}
		brojac=1;
		while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) p++;
		while((!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) && *p!='\0') p++;
		q=p;
	}
	q=maxi;
	s=maxi;
	/*Izbacivanje rijeci koja se najvise ponavlja*/
	while(*q != '\0'){
		maxi=s;
		istina=0;
		while((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) q++;
		while((!((*q>='A' && *q<='Z') || (*q>='a' && *q<='z'))) && *q != '\0') q++;
		if((*q==*maxi || *q==*maxi-32 || *q==*maxi+32) && ((*q>='A' && *q<='Z') || (*q>='a' && *q<='z'))){
			p=q;
			while((*q==*maxi || *q==*maxi-32 || *q==*maxi+32) && ((*q>='A' && *q<='Z') || (*q>='a' && *q<='z'))){
				maxi++;
				q++;
			}
			if((!((*q>='A' && *q<='Z') || (*q>='a' && *q<='z'))) && (!((*maxi>='A' && *maxi<='Z') || (*maxi>='a' && *maxi<='z')))){
				istina=1;
			}
			
			x=p;
			if(istina==1){
				while(*q != '\0'){
					*p=*q;
					 p++;
					 q++;
				}
				*p='\0';
			}
			q=x;
		}
			
	}
	/* izbacivanje rijeci koja se ponavlja jednom ili je odmah na pocetku u tekstu*/
	
	while((*maxi>='A' && *maxi<='Z') || (*maxi>='a' && *maxi<='z')) maxi++;
	while(*maxi != '\0'){
		*s=*maxi;
		 s++;
		 maxi++;
	}
	*s='\0';
	
	return niz;
}

int main(){
	char niz[]="Ovo je neki primjer.";
	izbaci_najcescu(niz);
	printf("%s", niz);
	return 0;
}