#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int istiStringovi(char *s1, char *s2){
	
	while(*s1 != '\n' && *s2 != '\n'){
		if(*s1 != *s2) return 0;
		s1++; 
		s2++;
	}
	
	if(*s1 != '\n' || *s2 != '\n') return 0;
	return 1;
}

char* izbaci_najcescu(char* s){
	
	char niz_rijeci[100][100];
	char niz_razmaka[100][100];
	char tekst[1000];
	char *pom = s;
	int br1=0, kol=0, k=0, i, j, najveci=-1, najInd=0;
	int br2=0, kol1=0;
	
	/*while(*pom != '\n'){
		tekst[k] = *pom;
		k++;
		pom++;
	}
	
	for(i=0; i<k; i++){
		if(tekst[i] >= 'a' && tekst[i] <= 'z') tekst[i] = tekst[i] - 32; 
	}
	
	pom = s;
	
	for(i=0; i<k; i++){
		
		if(tekst[i]>='A' && tekst[i]<='Z'){
			niz_rijeci[br1][kol] = tekst[i];
			kol++;
		}
		
		if(!(tekst[i]>='A' && tekst[i]<='Z') && kol!=0){
			niz_rijeci[br1][kol] = '\n';
			br1++;
			kol=0;
			
			for(;;){
				if((tekst[i]>='A' && tekst[i]<='Z')) break;
				
				niz_razmaka[br2][kol1] = tekst[i];
				kol1++;
				i++;
			}
			
			niz_razmaka[br2][kol1] = '\n';
			br2++;
			kol1=0;
			i--;
		}
	}
	
	if(br1 == 0) return s;
	
	for(i=0; i<br1; i++){
		
		int brojac = 1;
		
		for(j=i+1; j<br1; j++){
			if(istiStringovi(niz_rijeci[i],niz_rijeci[j])) brojac++;
		}
		
		if(brojac > najveci){
			najveci = brojac;
			najInd = i;
		}
	}
	
	pom = s;
	j=0;
	
	for(i=0; i<br1; i++){
		
		char *p = niz_rijeci[i];
		
		if(istiStringovi(niz_rijeci[i],niz_rijeci[najInd])) goto a;
		
		while(*p != '\n'){
			*pom = *p;
			pom++;
			p++;
		}
		
		a: if(j<br2){
			
			p=niz_razmaka[j];
			
			while(*p != '\n'){
				*pom = *p;
				pom++;
				p++;
			}
			
			j++;
		}
	}
	
	*pom = '\n';*/
	
	return s;
}

int main() {
	

	
	return 0;
}
