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

int strcmp (char *a1, char *a2){
	while(*a1>='A' && *a1<='Z' || *a1>='a' && *a1<='z' || *a2>='A' && *a2<='Z' || *a2>='a' && *a2<='z'){
		if(*a1<*a2 || *a1>*a2 || (*a1<'A' || *a1>'Z' && *a1<'a' || *a1>'z') && (*a2>='A' && *a2<='Z' || *a2>='a' && *a2<='z') || 
		(*a2<'A' || *a2>'Z' && *a2<'a' || *a2>'z') && (*a1>='A' && *a1<='Z' || *a1>='a' && *a1<='z')){
			return 0;
		}
		a1++;
		a2++;
	}
	return 1;
}

int duzina_rijeci(char *a1){
	int duzina=0;
	while(*a1>='A' && *a1<='Z' || *a1>='a' && *a1<='z'){
		duzina++;
	}
	return duzina;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* temp;
	temp=tekst;
	int i,j;
	int k,l;
	char *pomocni_tekst;
	pomocni_tekst=tekst;
	char *pomocni_tekst2;
	char *pomocni_rijeci;
	int duzina1;
	int duzina2;
	int pomjeranje;
	
	
	
	// trazenje rijeci u stringu koja se treba zamijeniti 
	
	for(k=0;k<broj_rijeci;k++){
		pomocni_rijeci=&rijeci[k][0];
		
	    while(*tekst!='\0'){
	        if(strcmp(tekst,rijeci)){
	        	
	        	// trazenje razlike izmedju duzina dvije rijeci koje se mijenjaju 
	        	
	        	pomjeranje=duzina_rijeci(&rijeci[k][0])-duzina_rijeci(&zamjene[k][0]);
	        	pomocni_tekst2=tekst;
	        	
	        	// pomjeranje elemenata da bi se rijec zamijenila
	        	
	        	while(*(pomocni_tekst2+pomjeranje)!='\0'){
	        		*pomocni_tekst2=*(pomocni_tekst2+pomjeranje);
	        		pomocni_tekst2++;
	        	}
	        	
	        	pomocni_tekst2=tekst;
	        	
	        	// zamjena rijeci 
	        	
	        	for(l=0;l<duzina_rijeci(&rijeci[k][0]);l++){
	        		*pomocni_tekst2=rijeci[k][l];
	        		pomocni_tekst2++;
	        	}
	        }
	        i=0;
	        if(i==0){
	        	tekst++;
	        }
	        i++;
	        while( (*tekst>='A' && *tekst<='Z' || *tekst>='a' && *tekst<='z') && ( *(tekst-1)<'A' || *(tekst-1)>'Z' && *(tekst-1)<'a' || *(tekst-1)>'z' ) ){
	        	tekst++;
	        }
	    }    
	}
	
	return temp;
}

int main() {
	char recenica[200];
	unesi(&recenica[0],200);
	char* pok;
	char *rijeci[2]={"beli", "sneg"};
	char *zamjena[2]={"bijeli", "snijeg"};
	pok=zamjena_rijeci(&recenica[0],&rijeci[0],&zamjena[0],2);
	return 0;
}
