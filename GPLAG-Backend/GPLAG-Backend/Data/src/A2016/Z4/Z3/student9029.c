#include <stdio.h>

int da_li_je_ista(char *niz, int vel, char* rijeci, char *pocetak){
	
	int i=0;
	
	if(niz!=pocetak) 
		if(*(niz-1)!=' ')
	       return 0;
	       
	for(i=0;i<vel;i++){
		if(*niz!=*rijeci) return 0;
		if(*niz=='\0') return 0;
		niz++; ++rijeci;
	}
	
    if(*(niz)!='\0')
	    if(*niz!=' ')
	       return 0;
	    
	return 1;
}

char * zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	
	int i=0,duzina_rijeci=0,duzina_zamjene=0, ista=0, razlika;
	char *pocetak, *temp_rijeci, *temp_zamjena,*kraj,*temp;
	
	pocetak=tekst; kraj=pocetak;
	
	for(i=0;i<broj_rijeci;i++){
		tekst=pocetak;
		duzina_rijeci=0;
		duzina_zamjene=0;
		
		temp_rijeci=rijeci[i];
		temp_zamjena=zamjene[i];
		while(*rijeci[i]!='\0'){duzina_rijeci++; ++rijeci[i];}
		while(*zamjene[i]!='\0'){duzina_zamjene++; ++zamjene[i];}
	    rijeci[i]=temp_rijeci;
	    zamjene[i]=temp_zamjena;
	    
	    razlika=duzina_zamjene-duzina_rijeci;
	    
	    while(*tekst!='\0'){
        	kraj=pocetak;
        	temp_zamjena=zamjene[i];
        	
        	ista=da_li_je_ista(tekst, duzina_rijeci, temp_rijeci, pocetak);
        	
        	if(ista==1){
        		while(*kraj!='\0') kraj++;
        		if(razlika>=0){
        		for(;kraj>(tekst+duzina_rijeci-1);kraj--){ *(kraj+razlika)=*kraj;}
                while(*temp_zamjena!='\0'){
                	*tekst=*temp_zamjena;
                	tekst++;
                	++temp_zamjena;
                    }
        		}
        		if(razlika<0){
        			while(*temp_zamjena!='\0'){
        				*tekst=*temp_zamjena;
                	    tekst++;
                	    ++temp_zamjena;
        			}
        			temp=tekst;
        			while(*tekst!='\0'){ *tekst=*(tekst+(razlika*(-1)));tekst++;}
                    *tekst='\0';
                    tekst=temp;
        		}
        	}
        	if(*tekst=='\0')break;
        	tekst++;
        }
	}
	
	return pocetak;
}

int main() {

	char* rijeci[100] ;
    char* zamjene[100];
    char tekst[1000000] ;
    int broj_rijeci;
    printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, broj_rijeci));
	
    return 0;
}
